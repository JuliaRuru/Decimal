#include "decimal.h"

int my_is_less(my_decimal left_decimal, my_decimal right_decimal) {
    int result;
    int left_sign = my_get_sign(left_decimal), right_sign = my_get_sign(right_decimal);   //  знаки
    my_decimal left_copy = left_decimal, right_copy = right_decimal;
    my_normalize_exponent(&left_copy, &right_copy);
    if (decimal_is_zero(&left_decimal) && decimal_is_zero(&right_decimal)) {
        result = 0;
    } else {
        if (left_sign > right_sign) {              //  x < 0, y > 0 (x < y)
            result = 1;
        } else if (left_sign < right_sign) {       //  x > 0, y < 0 (x > y)
            result = 0;
        } else {
            result = my_compare_decimal_bits(left_copy, right_copy);    //  0 - >, 1 - <, 2 - =
            if (!left_sign && !right_sign) {       //  оба числа положительные
                if (result == 2) {
                    result = 0;
                }
            } else if (left_sign && right_sign) {  //  оба числа отрицательные
                result = !result;
            }
        }
    }
    return result;
}

int my_is_greater(my_decimal left_decimal, my_decimal right_decimal) {
    return my_is_less(right_decimal, left_decimal);
}

int my_is_equal(my_decimal left_decimal, my_decimal right_decimal) {
    int result = 0;
    int left_sign = my_get_sign(left_decimal), right_sign = my_get_sign(right_decimal);   //  знаки
    my_decimal left_copy = left_decimal, right_copy = right_decimal;
    my_normalize_exponent(&left_copy, &right_copy);
    if (decimal_is_zero(&left_decimal) && decimal_is_zero(&right_decimal)) {
        result = 1;
    } else {
        if (left_sign == right_sign) {
            if (my_compare_decimal_bits(left_copy, right_copy) == 2) {       //  x < 0, y > 0 (x < y)
                result = 1;
            }
        }
    }
    return result;
}

int my_is_not_equal(my_decimal left_decimal, my_decimal right_decimal) {
    return !my_is_equal(left_decimal, right_decimal);
}


int my_is_less_or_equal(my_decimal left_decimal, my_decimal right_decimal) {
    return (my_is_equal(left_decimal, right_decimal) || my_is_less(left_decimal, right_decimal));
}

int my_is_greater_or_equal(my_decimal left_decimal, my_decimal right_decimal) {
    return (my_is_equal(left_decimal, right_decimal) || my_is_greater(left_decimal, right_decimal));
}
