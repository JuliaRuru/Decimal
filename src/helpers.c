#include "decimal.h"

void my_init_zero_decimal(my_decimal *dec) {               //  инициализирует нулевой децимал
    dec->bits[0] = dec->bits[1] = dec->bits[2] = dec->bits[3] = 0;
}

int my_get_sign(my_decimal dec) {                         //  1 +; 0 -
    return (dec.bits[3] >> 31);
}

void my_set_sign(my_decimal *dst, int value) {            //  устанавливает заданный знак
    if (value) {
        dst->bits[3] += value << 31;
    } else {
        dst->bits[3] = ((dst->bits[3] << 1) >> 1);
    }
}

int my_get_decimal_exponent(my_decimal src) {              //  возвращает экспоненту децимала
    unsigned int exp_mask = 0x00ff0000;                      //  0 000000011111111 0000000000000000
    int exponent = (src.bits[3] & exp_mask) >> 16;
    return exponent;
}

unsigned int my_get_exponent(float *src) {                 //  возвращает экспоненту флоата
    unsigned int mask_exponent = 0x7F800000;                //  0 11111111 00000000000000000000000
    unsigned int result = *(unsigned int *)src & mask_exponent;
    result >>= 23;
    return result - 127;
}

void my_set_exponent(my_decimal *dst, unsigned int exponent) {    //  устанавливает экспоненту
    unsigned int mask = 0x00800000, mask_exp = 0x00000080;
    for (int i = 0; i < 8; i++, mask >>= 1, mask_exp >>= 1) {
        if (!!(mask_exp & exponent)) {
            dst->bits[3] |= mask;
        }
    }
}

int my_get_bit(my_decimal src, int i) {                   //  возвращает значение бита по индексу
    unsigned int getMask = 1u << (i % 32);
    return !!(src.bits[i / 32] & getMask);
}

void my_set_bit(my_decimal *dst, int index) {             //  устанавливает 1 в бит с указанным индексом
    if (dst != NULL && index < 96) {
        unsigned int mask = 1;
        mask <<= index % 32;
        dst->bits[index/32] |= mask;
    }
}

int decimal_is_zero(my_decimal *dec) {                      //  1 is zero
    return dec->bits[0] == 0 && dec->bits[1] == 0 && dec->bits[2] == 0;
}

int my_compare_decimal_bits(my_decimal left_decimal, my_decimal right_decimal) {  //  побитово сравнивает
    int result;                                                     //  0 - >, 1 - <, 2 - =
    for (int i = 95; i >= 0; i--) {                                 //  идем по битсам, начиная со старших
        if (my_get_bit(left_decimal, i) < my_get_bit(right_decimal, i)) {     //  сравниваем текущие биты
            result = 1;
            break;
        } else if (my_get_bit(left_decimal, i) > my_get_bit(right_decimal, i)) {
            result = 0;
            break;
        } else {
            result = 2;
        }
    }
    return result;
}

void my_normalize_exponent(my_decimal *src1, my_decimal *src2) {     //  выравнивает экспоненты
    int exponent_1, exponent_2, exponent_diff;
    exponent_1 = my_get_decimal_exponent(*src1);
    exponent_2 = my_get_decimal_exponent(*src2);
    exponent_diff = exponent_1 - exponent_2;
    if (exponent_diff != 0) {
        if (exponent_diff < 0) {
            exponent_diff = abs(exponent_diff);
            if (!my_norm_exponent_overflow(*src1, exponent_diff)) {  //  проверяем на переполнение 0 - OK
                my_exponent_mult_ten(src1, exponent_diff, exponent_2);   //  умножаем на 10
            } else {
                my_exponent_div_ten(src2, exponent_diff, exponent_1);
            }
        } else {
            if (!my_norm_exponent_overflow(*src2, exponent_diff)) {
                my_exponent_mult_ten(src2, exponent_diff, exponent_1);
            } else {
                my_exponent_div_ten(src1, exponent_diff, exponent_2);
            }
        }
    }
}

int my_norm_exponent_overflow(my_decimal src, int exponent_diff) {        //  проверяет на переполнение
    int flag = 0;                           // OK
    uint64_t bits_0, bits_1, bits_2;
    bits_0 = src.bits[0];
    bits_1 = src.bits[1];
    bits_2 = src.bits[2];
    for (int i = 0; i < exponent_diff; i++) {
        bits_0 *= 10;
        if (bits_0 >> 32 != 0) {            //  смотрим, остается ли что-то, что не вошло в битс0
            bits_1 += (bits_0 >> 32);       //  прибавляем к битс0 то, что осталось после сдвига
            bits_0 = (bits_0 << 32) >> 32;  //  тут у битс0 отрезаем старшие биты, которые не входят в размер
            if (bits_1 >> 32 != 0) {
                bits_2 += (bits_1 >> 32);
                bits_1 = (bits_0 << 32) >> 32;
                if (bits_2 >> 32 != 0) {
                    flag = 1;
                    break;
                }
            }
        }
        bits_1 *= 10;
        if (bits_1 >> 32 != 0) {
            bits_2 += (bits_1 >> 32);
            bits_1 = (bits_0 << 32) >> 32;
            if (bits_2 >> 32 != 0) {
                flag = 1;
                break;
            }
        }
        bits_2 *= 10;
        if (bits_2 >> 32 != 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}

void my_exponent_mult_ten(my_decimal *src, int exponent_diff, int exponent) {  //  умножает на 10
    my_decimal ten;
    my_from_int_to_decimal(10, &ten);
    int sign = my_get_sign(*src);
    for (int i = 0; i < exponent_diff; i++) {
        my_mul(*src, ten, src);
    }
    src->bits[3] = exponent << 16;        //  set exponent
    my_set_sign(src, sign);
}

void my_exponent_div_ten(my_decimal *src, int exponent_diff, int exponent) {  //  делит на 10
    my_decimal result = *src, ten;
    result.bits[3] = 0;
    my_from_int_to_decimal(10, &ten);
    int sign = my_get_sign(*src);
    for (int i = 0; i < exponent_diff; i++) {
        result = my_division(result, ten, NULL);
    }
    src->bits[0] = result.bits[0];
    src->bits[1] = result.bits[1];
    src->bits[2] = result.bits[2];
    src->bits[3] = exponent << 16;        //  set exponent
    my_set_sign(src, sign);
}

my_decimal my_division(my_decimal value_1, my_decimal value_2, my_decimal *mod) {
    my_decimal temp_1 = value_1, temp_2 = value_2, result;
    my_init_zero_decimal(&result);
    int older_bit_src = my_older_non_zero_bit(value_1);
    int older_bit_ten = my_older_non_zero_bit(value_2);
    int k = older_bit_src - older_bit_ten;
    for (int i = k; i > 0; i--) {
        my_shift_right(&temp_1);
    }
    my_division_algorythm(&result, &temp_1, &temp_2, &value_1, &k);
    if (older_bit_src >= older_bit_ten) {
        my_shift_right(&temp_1);
    }
    if (mod) {
        *mod = temp_1;
    }
    return result;
}

void my_division_algorythm(my_decimal *result, my_decimal *temp_1,
                            my_decimal *temp_2, my_decimal *value_1, int *k) {
    for (int i = 0; i < 95 && *k >= 0; i++) {
        my_shift_left(result);
        if (*k == 0) {
            *k = -1;
        }
        if (my_is_greater_or_equal(*temp_1, *temp_2)) {       //  temp_src >= temp_ten
            result->bits[0] += 1;
            my_subtraction(temp_1, temp_1, *temp_2);
            my_shift_left(temp_1);
            if (*k > 0) {
                temp_1->bits[0] += my_get_bit(*value_1, --*k);
            }
        } else {                                                              //  temp_src < temp_ten
            my_shift_left(temp_1);
            if (*k > 0) {
                temp_1->bits[0] += my_get_bit(*value_1, --*k);
            }
        }
    }
}

int my_addition(my_decimal* result, my_decimal* value_1, my_decimal* value_2) {  // складывает битсы
    int flag = 0;
    uint64_t res0, res1 = 0, res2 = 0;
    uint64_t left = (uint64_t)value_1->bits[0], right = (uint64_t)value_2->bits[0];
    res0 = left + right;
    if (res0 >> 32 != 0) {                  //  если есть что-то, что не влезло в 32 бита
        res1 = res0 >> 32;                  //  кладем это в res1
        res0 = (res0 << 32) >> 32;
    }
    left = (uint64_t)value_1->bits[1];
    right = (uint64_t)value_2->bits[1];
    res1 += left + right;
    if (res1 >> 32 != 0) {                  //  если есть что-то, что не влезло в 32 бита
        res2 = res1 >> 32;                  //  кладем это в res2
        res1 = (res1 << 32) >> 32;
    }
    left = (uint64_t)value_1->bits[2];
    right = (uint64_t)value_2->bits[2];
    res2 += left + right;
    if (res2 >> 32 != 0) {                  //  если есть что-то, что не влезло в 32 бита
        flag = 1;                           //  флаг ошибки переполнения
    }
    if (flag == 0) {
        result->bits[0] = res0;
        result->bits[1] = res1;
        result->bits[2] = res2;
    } else {
        my_init_zero_decimal(result);
    }
    return flag;
}

void my_subtraction(my_decimal *result, my_decimal *value_1, my_decimal value_2) {
    my_decimal left = *value_1, right = value_2;
    int sign = my_get_sign(left);                                  //  разность имеет знак большего числа
    int exponent = my_get_decimal_exponent(*value_1);
    uint64_t temp, temp_2, temp_1 = 0, temp_0 = 0;
    temp_2 = (uint64_t)left.bits[2] - (uint64_t)right.bits[2];           //  начинаем со старших битов
    temp_2 = (temp_2 << 32) >> 32;
    temp = temp_2;
    if ((uint32_t)left.bits[1] < (uint32_t)right.bits[1]) {    //  если bits[1] левого числа < bits[1] правого
        temp_1 += ((uint64_t) 1 << 32);                                  //  прибавляем 1 старший бит
        temp -= (uint64_t) 1;                                            //  и отнимаем его от temp
    }
    temp <<= 32;                                                         //  запоминаем старшие биты
    temp_1 += (uint64_t)left.bits[1];                                    //  повторяем для остальных битсов
    temp_1 -= (uint64_t)right.bits[1];
    temp_1 = (temp_1 << 32) >> 32;
    temp += temp_1;
    result->bits[2] = temp >> 32;
    if ((uint32_t)left.bits[0] < (uint32_t)right.bits[0]) {
        temp_0 += ((uint64_t) 1 << 32);
        temp -= (uint64_t) 1;
    }
    temp <<= 32;
    temp_0 += (uint64_t)left.bits[0];
    temp_0 -= (uint64_t)right.bits[0];
    temp_0 = (temp_0 << 32) >> 32;
    temp += temp_0;
    result->bits[1] = temp >> 32;
    result->bits[0] = temp;
    my_set_sign(result, sign);
    my_set_exponent(result, exponent);
}

int my_older_non_zero_bit(my_decimal dst) {               //  находит старший ненулевой бит
    int result = 0;
    for (int i = 95; i >= 0; i--) {                         //  идет по битам начиная со старшего
        if (my_get_bit(dst, i)) {                     //  как только встречает не ноль
            result = i;                                     //  возвращает номер этого бита
            break;                                          //  и выходит из цикла и функции
        }
    }
    return result;
}

void my_shift_left(my_decimal *dst) {                     //  сдвигает децимал влево
    my_decimal temp = *dst;
    int exponent = my_get_decimal_exponent(*dst);
    my_init_zero_decimal(&temp);
    for (int i = 95; i > 0; i--) {                          //  идем от старших битов dst к младшим
        if (my_get_bit(*dst, i - 1))                //  если следующий бит 1
            my_set_bit(&temp, i);               //  устанавливаем в текущий бит 1
    }
    *dst = temp;
    my_set_exponent(dst, exponent);
}

void my_shift_right(my_decimal *dst) {                    //  сдвигает децимал вправо
    my_decimal temp = *dst;
    int exponent = my_get_decimal_exponent(*dst);
    my_init_zero_decimal(&temp);
    for (int i = 95; i > 0; i--) {                          //  идем от старших битов dst к младшим
        if (my_get_bit(*dst, i))                       //  и если там 1
            my_set_bit(&temp, i - 1);           //  устанавливаем 1 в следующий бит
    }
    *dst = temp;
    my_set_exponent(dst, exponent);
}

my_decimal my_div_ten(my_decimal src) {
    my_decimal res, coefficient;
    my_init_zero_decimal(&res);
    my_init_zero_decimal(&coefficient);
    int div_id = 0, pos = 0, flag = 0;
    for (int i = 95; i >= 0; i--) {
        if (flag) pos++;
        div_id <<= 1;
        div_id |= my_get_bit(src, i);
        if (div_id >= 10) {
            my_set_bit(&coefficient, pos);
            div_id -= 10;
            flag = 1;
        }
    }
    for (int i = pos, j = 0; i >= 0; i--, j++) {
        int bit = my_get_bit(coefficient, i);
        if (bit) {
            my_set_bit(&res, j);
        }
    }
    return res;
}

int my_mod_div_10(my_decimal src) {
    int dev_id = 0;
    for (int i = 95; i >= 0; i--) {
        dev_id <<= 1;
        dev_id |= my_get_bit(src, i);
        if (dev_id >= 10) dev_id -= 10;
    }
    return dev_id;
}
