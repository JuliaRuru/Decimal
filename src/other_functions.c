#include "decimal.h"

int my_truncate(my_decimal value, my_decimal *result) {
    int err = 0;
    if (result != NULL) {
        *result = value;
        for (int i = my_get_decimal_exponent(value); i > 0; i--) {
            *result = my_div_ten(*result);
        }
        my_set_sign(result, my_get_sign(value));
    } else {
        err = 1;
    }
    return err;
}

int my_negate(my_decimal value, my_decimal *result) {
    int flag = 1;
    if (result != NULL) {
        *result = value;
        result->bits[3] ^= (1u << 31);
        flag = 0;
    }
    return flag;
}

int my_floor(my_decimal value, my_decimal *result) {
    int err = 0;
    if (result != NULL) {
        my_init_zero_decimal(result);
        err = my_truncate(value, result);
        if (my_get_sign(value) && !my_is_equal(value, *result)) {
            err = my_sub(*result, (my_decimal){{1, 0, 0, 0}}, result);
    }
    } else {
        err = 1;
    }
    return err;
}

int my_round(my_decimal value, my_decimal *result) {
    int err = 0;
    if (result != NULL) {
        my_init_zero_decimal(result);
        *result = value;
        int sign = my_get_sign(value);
        if (my_get_decimal_exponent(value) > 0) {
            my_set_sign(result, 0);
            int mem = 0;
            for (int i = my_get_decimal_exponent(value); i > 0; i--) {
                mem = my_mod_div_10(*result);
                *result = my_div_ten(*result);
            }
            if (mem >= 5) {
                my_add(*result, (my_decimal){{1, 0, 0, 0}}, result);
            }
            my_set_sign(result, sign);
        }
    } else {
        err = 1;
    }
    return err;
}
