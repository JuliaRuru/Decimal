#include "decimal.h"

int my_add(my_decimal value_1, my_decimal value_2, my_decimal *result) {
    int flag = 0;                  //  flag = 0 - OK; 1 - P_INFINITY; 2 - N_INFINITY; 3 - NAN
    int sign_1 = my_get_sign(value_1), sign_2 = my_get_sign(value_2);        //  1 - 0 +
    my_init_zero_decimal(result);
    my_decimal copy_1 = value_1, copy_2 = value_2;
    my_normalize_exponent(&copy_1, &copy_2);
    if (!sign_1 && !sign_2) {                           //  оба числа положительные
        if (my_addition(result, &copy_1, &copy_2)) {        //  1 - ошибка переполнения
            flag = 1;
        } else {
            result->bits[3] = copy_1.bits[3];
        }
    } else if (sign_1 == 1 && sign_2 == 1) {            //  оба числа отрицательные
        if (my_addition(result, &copy_1, &copy_2)) {        //  1 - ошибка переполнения
            flag = 2;
        } else {
            result->bits[3] = copy_1.bits[3];
        }
    } else {
        my_decimal module_1 = copy_1, module_2 = copy_2;
        my_set_sign(&module_1, 0);
        my_set_sign(&module_2, 0);
        if (my_is_less(module_1, module_2)) {       //  module_1 < module_2
            my_subtraction(result, &copy_2, copy_1);
        } else {
            my_subtraction(result, &copy_1, copy_2);
        }
    }
    return flag;
}

int my_sub(my_decimal value_1, my_decimal value_2, my_decimal *result) {
    int flag = 0;                    //  flag = 0 - OK; 1 - P_INFINITY; 2 - N_INFINITY; 3 - NAN
    int sign_1 = my_get_sign(value_1), sign_2 = my_get_sign(value_2);        //  1 - 0 +
    my_init_zero_decimal(result);
    my_decimal copy_1 = value_1, copy_2 = value_2;
    my_normalize_exponent(&copy_1, &copy_2);
    my_decimal module_1 = copy_1, module_2 = copy_2;
    my_set_sign(&module_1, 0);
    my_set_sign(&module_2, 0);
    if (!sign_1 && !sign_2) {                                               //  оба числа положительные
        if (my_is_less(module_1, module_2)) {      //  module_1 < module_2
            my_subtraction(result, &copy_2, copy_1);
            my_set_sign(result, 1);                            //  sign
        } else {                                                           //  module_1 > module_2
            my_subtraction(result, &copy_1, copy_2);
        }
    } else if (sign_1 && !sign_2) {          //  первое - отрицательное, второе - положительное
        if (my_addition(result, &copy_1, &copy_2)) {
            flag = 2;
        } else {
            result->bits[3] = module_1.bits[3];
            my_set_sign(result, 1);                            //  sign
        }
    } else if (!sign_1 && sign_2) {          //  первое - положительное, второе - отрицательное
        if (my_addition(result, &copy_1, &copy_2)) {
            flag = 1;
        } else {
            result->bits[3] = module_1.bits[3];
        }
    } else if (sign_1 && sign_2) {                                          //  оба числа отрицательные
        if (my_is_less(module_1, module_2)) {      //  module_1 < module_2
            my_subtraction(result, &copy_2, copy_1);
            my_set_sign(result, 0);                             //  sign
        } else {
            my_subtraction(result, &copy_1, copy_2);
        }
    }
    return flag;
}

int my_mul(my_decimal value_1, my_decimal value_2, my_decimal *result) {
    int flag = 0;                              //  flag = 0 - OK; 1 - P_INFINITY; 2 - N_INFINITY; 3 - NAN
    my_decimal copy_1 = value_1;
    copy_1.bits[3] = 0;
    my_init_zero_decimal(result);
    int sign_1 = my_get_sign(value_1), sign_2 = my_get_sign(value_2);        //  1 - 0 +
    int exponent_1 = my_get_decimal_exponent(value_1);
    int exponent_2 = my_get_decimal_exponent(value_2);
    for (int i = 0; i < 96; i++) {             //  проходим по всем битам первых трех битсов
        if (my_get_bit(value_2, i)) {    //  если бит множителя = 1, кладем в result умножаемое
            if (my_addition(result, result, &copy_1)) {  //  1 - ошибка переполнения
                if (sign_1 || sign_2) {
                    flag = 2;
                } else {
                    flag = 1;
                }
                break;
            } else {
                my_set_exponent(result, exponent_1 + exponent_2);
                my_set_sign(result, sign_1 ^ sign_2);
            }
        }
        my_shift_left(&copy_1);                      //  сдвигаем умножаемое влево
    }
    return flag;
}

int my_mod(my_decimal value_1, my_decimal value_2, my_decimal *result) {
    int flag = 0;                              //  flag = 0 - OK; 1 - P_INFINITY; 2 - N_INFINITY; 3 - NAN
    my_init_zero_decimal(result);
    if (!decimal_is_zero(&value_2)) {
        int sign = my_get_sign(value_1);
        my_normalize_exponent(&value_1, &value_2);
        my_decimal temp_1 = value_1, temp_2 = value_2;
        my_set_sign(&temp_1, 0);                              //  оставляем модули
        my_set_sign(&temp_2, 0);                              //  оставляем модули
        if (!decimal_is_zero(&value_2)) {
            my_decimal mod;                                              //  сюда положим остаток
            my_init_zero_decimal(&mod);
            *result = my_division(temp_1, temp_2, &mod);
            *result = mod;
            my_set_sign(result, sign);
        }
    } else {
        flag = 3;
    }
    return flag;
}

int my_div(my_decimal value_1, my_decimal value_2, my_decimal *result) {
    int flag = 0;                              //  flag = 0 - OK; 1 - P_INFINITY; 2 - N_INFINITY; 3 - NAN
    my_init_zero_decimal(result);
    if (!decimal_is_zero(&value_2)) {
        int sign_1 = my_get_sign(value_1);
        int sign_2 = my_get_sign(value_2);
        my_normalize_exponent(&value_1, &value_2);
        my_decimal module_1 = value_1, module_2 = value_2;
        my_set_sign(&module_1, 0);                              //  оставляем модули
        my_set_sign(&module_2, 0);                              //  оставляем модули
        if (!decimal_is_zero(&value_2)) {
            *result = my_division(module_1, module_2, &module_1);
            if (!decimal_is_zero(&module_1)) {
                my_decimal result_tmp;
                my_init_zero_decimal(&result_tmp);
                int tmp_exp = 0;
                my_decimal ten;
                my_init_zero_decimal(&ten);
                ten.bits[0] = 10;
                while (my_is_greater_or_equal(*result, ten)) {
                    my_mul(ten, ten, &ten);
                    tmp_exp++;
                }
                int dst_exp = 0;
                my_init_zero_decimal(&ten);
                ten.bits[0] = 10;
                my_decimal max_value_10;
                float max_value_10_float = MAX_DEC_10;
                my_from_float_to_decimal(max_value_10_float, &max_value_10);
                while (dst_exp + tmp_exp < 29 && !decimal_is_zero(&module_1) &&
                       my_is_less(*result, max_value_10)) {     //  пока экспонента < 29 и есть остаток
                    my_mul(module_1, ten, &module_1);         //  умножаем остаток от деления на 10
                    if (my_mul(*result, ten, result)) {             //  умножаем результат деления на 10
                        if (sign_1 || sign_2) {
                            flag = 2;
                        } else {
                            flag = 1;
                        }
                        break;
                    }
                    result_tmp = my_division(module_1, module_2, &module_1);   //  делим остаток
                    my_add(*result, result_tmp, result);                            //  складываем их
                    dst_exp++;
                }
                my_set_exponent(result, dst_exp);
            }
            my_set_sign(result, sign_1 ^ sign_2);
        }
    } else {
        flag = 3;
    }
    return flag;
}

int my_from_int_to_decimal(int src, my_decimal *dst) {
    int flag = 1;
    if (dst != NULL) {
        flag = 0;
        my_init_zero_decimal(dst);
        if (src < 0) {
            src = abs(src);
            dst->bits[3] ^= (1u << 31);     // invert sign
        }
        dst->bits[0] = src;
    }
    return flag;
}

int my_from_float_to_decimal(float src, my_decimal *dst) {
    int flag = 1;
    if (dst != NULL) {
        int sign = 0;
        my_init_zero_decimal(dst);
        float module_src = fabs(src);
        if (src < 0) {
            sign = 1;
        }
        if (module_src < 1e-28) {
            if (src == 0) {
                flag = 0;
            }
        } else {
            int scale = 0;
            int exponent = my_get_exponent(&module_src);
            double src_double = (double) module_src;
            for (; scale < 28 && (int) src_double / (int) pow(2, 21) == 0; src_double *= 10, scale++) {
            }
            src_double = round(src_double);
            if (scale <= 28 && (exponent > -94 && exponent < 96)) {
                for (; fmod(src_double, 10) == 0 && scale > 0; scale--, src_double /= 10) {
                }
                float src_float = (float) src_double;
                my_init_zero_decimal(dst);
                unsigned int fbits = *((unsigned int *) &src_float);
                exponent = my_get_exponent(&src_float);
                my_set_bit(dst, exponent--);
                for (unsigned int mask = 0x400000;
                     mask > 0; mask >>= 1, exponent--) {      //  0 00000000 10000000000000000000000
                    if (!!(mask & fbits)) my_set_bit(dst, exponent);
                }
                my_set_exponent(dst, scale);
                dst->bits[3] |= (sign << 31);
                flag = 0;
            }
        }
    }
    return flag;
}

int my_from_decimal_to_int(my_decimal src, int *dst) {
    int flag = 1;
    if (dst != NULL) {
        *dst = 0;
        int scale = my_get_decimal_exponent(src);
        double temp;
        temp = POW_2_64 * src.bits[2];              //  18446744073709551616
        temp += POW_2_32 * src.bits[1];             //  4294967295
        temp += src.bits[0];
        for (int i = 0; i < scale; i++) {
            temp /= 10;
        }
        if (temp <= 2147483648 && temp >= -2147483648) {
            *dst = (int)temp;
            if ((unsigned int) src.bits[3] >> 31 == 1) {
                *dst *= -1;
            }
            flag = 0;
        }
    }
    return flag;
}

int my_from_decimal_to_float(my_decimal src, float *dst) {
    int flag = 1;
    if (dst != NULL) {
        *dst = 0;
        int scale = my_get_decimal_exponent(src);
        double temp;
        temp = POW_2_64 * src.bits[2];              //  18446744073709551616
        temp += POW_2_32 * src.bits[1];             //  4294967295
        temp += src.bits[0];
        for (int i = 0; i < scale; i++) {
            temp /= 10;
        }
        if (temp <= 3.4028235e38 && temp >= -3.4028235e38) {
            *dst = (float)temp;
            if (my_get_sign(src)) {
                *dst *= -1;
            }
            flag = 0;
        }
    }
    return flag;
}
