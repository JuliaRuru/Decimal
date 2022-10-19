#ifndef SRC_DECIMAL_H_
#define SRC_DECIMAL_H_

#ifndef POW_2_64
#define POW_2_64 18446744073709551616.0
#endif

#ifndef POW_2_32
#define POW_2_32 4294967295.0
#endif

#ifndef MAX_DEC_10
#define MAX_DEC_10 7922816251426433759354395033.5
#endif


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct {
    unsigned int bits[4];
} my_decimal;

//  Arithmetic
int my_add(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_sub(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_mul(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_div(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_mod(my_decimal value_1, my_decimal value_2, my_decimal *result);

//  Comparison
int my_is_less(my_decimal left_decimal, my_decimal right_decimal);
int my_is_less_or_equal(my_decimal left_decimal, my_decimal right_decimal);
int my_is_greater(my_decimal left_decimal, my_decimal right_decimal);
int my_is_greater_or_equal(my_decimal left_decimal, my_decimal right_decimal);
int my_is_equal(my_decimal left_decimal, my_decimal right_decimal);
int my_is_not_equal(my_decimal left_decimal, my_decimal right_decimal);

//  Convertors
int my_from_int_to_decimal(int src, my_decimal *dst);
int my_from_float_to_decimal(float src, my_decimal *dst);
int my_from_decimal_to_int(my_decimal src, int *dst);
int my_from_decimal_to_float(my_decimal src, float *dst);

//  Another
int my_floor(my_decimal value, my_decimal *result);
int my_round(my_decimal value, my_decimal *result);
int my_truncate(my_decimal value, my_decimal *result);
int my_negate(my_decimal value, my_decimal *result);

//  Helpers
void my_init_zero_decimal(my_decimal *dec);
int my_get_sign(my_decimal dec);
void my_set_sign(my_decimal *dst, int value);
int my_get_decimal_exponent(my_decimal src);
unsigned int my_get_exponent(float *src);
void my_set_exponent(my_decimal *dst, unsigned int exponent);
int my_get_bit(my_decimal src, int i);
void my_set_bit(my_decimal *dst, int index);
int decimal_is_zero(my_decimal *dec);
int my_compare_decimal_bits(my_decimal left_decimal, my_decimal right_decimal);
void my_normalize_exponent(my_decimal *src1, my_decimal *src2);
int my_norm_exponent_overflow(my_decimal src, int exponent_diff);
void my_exponent_mult_ten(my_decimal *src, int exponent_diff, int exponent);
void my_exponent_div_ten(my_decimal *src, int exponent_diff, int exponent);
my_decimal my_division(my_decimal value_1, my_decimal value_2, my_decimal *mod);
void my_division_algorythm(my_decimal *result, my_decimal *temp_1,
                            my_decimal *temp_2, my_decimal *value_1, int *k);
int my_addition(my_decimal* result, my_decimal* value_1, my_decimal* value_2);
void my_subtraction(my_decimal *result, my_decimal *value_1, my_decimal value_2);
int my_older_non_zero_bit(my_decimal dst);
void my_shift_left(my_decimal *dst);
void my_shift_right(my_decimal *dst);
void div_alg_float(my_decimal *result, my_decimal *tmp1, my_decimal *tmp2);
my_decimal my_div_ten(my_decimal src);
int my_mod_div_10(my_decimal src);

#endif  // SRC_DECIMAL_H_
