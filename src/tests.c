#include <check.h>
#include "decimal.h"

START_TEST(my_from_int_to_decimal_1) {
        my_decimal value;
        ck_assert_int_eq(my_from_int_to_decimal(0, &value), 0);
        ck_assert_int_eq(value.bits[0], 0b00000000000000000000000000000000);
        ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
        ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
        ck_assert_int_eq(value.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_from_int_to_decimal_2) {
    my_decimal value;
    ck_assert_int_eq(my_from_int_to_decimal(-128, &value), 0);
    ck_assert_int_eq(value.bits[0], 0b00000000000000000000000010000000);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_from_int_to_decimal_3) {
    my_decimal value;
    ck_assert_int_eq(my_from_int_to_decimal(127, &value), 0);
    ck_assert_int_eq(value.bits[0], 0b00000000000000000000000001111111);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_from_int_to_decimal_4) {
    my_decimal value;
    ck_assert_int_eq(my_from_int_to_decimal(-2147483648, &value), 0);
    ck_assert_int_eq(value.bits[0], 0b10000000000000000000000000000000);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_from_int_to_decimal_5) {
    my_decimal value;
    ck_assert_int_eq(my_from_int_to_decimal(2147483647, &value), 0);
    ck_assert_int_eq(value.bits[0], 0b01111111111111111111111111111111);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_from_float_to_decimal_1) {
    my_decimal value;
    ck_assert_int_eq(my_from_float_to_decimal(0.03, &value), 0);
    ck_assert_int_eq(value.bits[0], 0b00000000000000000000000000000011);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[3], 0b00000000000000100000000000000000);
}
END_TEST

START_TEST(my_from_float_to_decimal_2) {
    my_decimal value;
    ck_assert_int_eq(my_from_float_to_decimal(127.1234, &value), 0);
    ck_assert_int_eq(value.bits[0], 0b00000000000100110110010111000010);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[3], 0b00000000000001000000000000000000);
}
END_TEST

START_TEST(my_from_float_to_decimal_3) {
    my_decimal value;
    ck_assert_int_eq(my_from_float_to_decimal(-128.023, &value), 0);
    ck_assert_int_eq(value.bits[0], 0b00000000110000110101100011111011);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[3], 0b10000000000001010000000000000000);
}
END_TEST

START_TEST(my_from_float_to_decimal_4) {
    my_decimal value;
    ck_assert_int_eq(my_from_float_to_decimal(-2.147483648e9, &value), 0);
    ck_assert_int_eq(value.bits[0], 0b10000000000000000000000000000000);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_from_float_to_decimal_5) {
    my_decimal value;
    ck_assert_int_eq(my_from_float_to_decimal(22.14836e3, &value), 0);
    ck_assert_int_eq(value.bits[0], 0b00000000001000011100101110110100);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[3], 0b00000000000000100000000000000000);
}
END_TEST

START_TEST(my_from_float_to_decimal_6) {
    my_decimal value;
    ck_assert_int_eq(my_from_float_to_decimal(1.02e9, &value), 0);
    ck_assert_int_eq(value.bits[0], 0b00111100110010111111011100000000);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_from_float_to_decimal_7) {
    my_decimal value;
    ck_assert_int_eq(my_from_float_to_decimal(-333.2222, &value), 0);
    ck_assert_int_eq(value.bits[0], 0b00000000001100101101100001111110);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[3], 0b10000000000001000000000000000000);
}
END_TEST

START_TEST(my_from_float_to_decimal_8) {
    my_decimal value;
    float a = 1.0 / 0.0;
    ck_assert_int_eq(my_from_float_to_decimal(a, &value), 1);
}
END_TEST

START_TEST(my_from_float_to_decimal_9) {
    my_decimal value;
    float a = -1.0 / 0.0;
    ck_assert_int_eq(my_from_float_to_decimal(a, &value), 1);
}
END_TEST

START_TEST(my_from_float_to_decimal_10) {
    my_decimal value;
    float a = 1 / 0.0;
    ck_assert_int_eq(my_from_float_to_decimal(a, &value), 1);
}
END_TEST

START_TEST(my_from_float_to_decimal_11) {
    my_decimal value;
    ck_assert_int_eq(my_from_float_to_decimal(1e-30, &value), 1);
    ck_assert_int_eq(value.bits[0], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_from_float_to_decimal_12) {
    my_decimal value;
    ck_assert_int_eq(my_from_float_to_decimal(0, &value), 0);
    ck_assert_int_eq(value.bits[0], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_from_float_to_decimal_13) {
    my_decimal value;
    ck_assert_int_eq(my_from_float_to_decimal(1.844674407371e19, &value), 0);
    ck_assert_int_eq(value.bits[0], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000001);
    ck_assert_int_eq(value.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_from_float_to_decimal_14) {
    my_decimal value;
    ck_assert_int_eq(my_from_float_to_decimal(4294967295, &value), 0);
    ck_assert_int_eq(value.bits[0], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000001);
    ck_assert_int_eq(value.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(value.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_from_decimal_to_float_1) {
    my_decimal src;
    float value;
    src.bits[0] = 0b00000000000000000100011011001010;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000000110000000000000000;
    ck_assert_int_eq(my_from_decimal_to_float(src, &value), 0);
    ck_assert_float_eq(value, -18.122);
}
END_TEST

START_TEST(my_from_decimal_to_float_2) {
    my_decimal src;
    float value;
    src.bits[0] = 0b00000000000000000000011100010100;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_from_decimal_to_float(src, &value), 0);
    ck_assert_float_eq(value, -1812);
}
END_TEST

START_TEST(my_from_decimal_to_float_3) {
    my_decimal src;
    float value;
    src.bits[0] = 0b00000000111111111111111111111111;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_from_decimal_to_float(src, &value), 0);
    ck_assert_float_eq(value, 16777215);
}
END_TEST

START_TEST(my_from_decimal_to_float_4) {
    my_decimal src;
    float value;
    src.bits[0] = 0b00000001011001011101010101101011;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000001000000000000000000;
    ck_assert_int_eq(my_from_decimal_to_float(src, &value), 0);
    ck_assert_float_eq(value, -2345.0987);
}
END_TEST

START_TEST(my_from_decimal_to_float_5) {
    my_decimal src;
    float value;
    src.bits[0] = 0b11111111111111111111111111111111;
    src.bits[1] = 0b11111111111111111111111111111111;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_from_decimal_to_float(src, &value), 0);
    ck_assert_float_eq(value, 0xFFFFFFFFFFFFFFFF);
}
END_TEST

START_TEST(my_from_decimal_to_float_6) {
    my_decimal src;
    float value;
    src.bits[0] = 0b00000000000000000000000001100100;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000000100000000000000000;
    ck_assert_int_eq(my_from_decimal_to_float(src, &value), 0);
    ck_assert_float_eq(value, -1);
}
END_TEST

START_TEST(my_from_decimal_to_float_7) {
    my_decimal src;
    float value;
    src.bits[0] = 0b00000000100000000000000000000000;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_from_decimal_to_float(src, &value), 0);
    ck_assert_float_eq(value, 8388608);
}
END_TEST

START_TEST(my_from_decimal_to_float_8) {
    my_decimal src;
    float value;
    src.bits[0] = 0b00000000000000000000000000000000;
    src.bits[1] = 0b00000000000000000000000000000001;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_from_decimal_to_float(src, &value), 0);
    ck_assert_float_eq(value, 4294967296);
}
END_TEST

START_TEST(my_from_decimal_to_int_1) {
    my_decimal src;
    int value;
    src.bits[0] = 0b00000000000000000100011011001010;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000000110000000000000000;
    ck_assert_int_eq(my_from_decimal_to_int(src, &value), 0);
    ck_assert_float_eq(value, -18);
}
END_TEST

START_TEST(my_from_decimal_to_int_2) {
    my_decimal src;
    int value;
    src.bits[0] = 0b00000000000000000000011100010100;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_from_decimal_to_int(src, &value), 0);
    ck_assert_float_eq(value, -1812);
}
END_TEST

START_TEST(my_from_decimal_to_int_3) {
    my_decimal src;
    int value;
    src.bits[0] = 0b00000000111111111111111111111111;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_from_decimal_to_int(src, &value), 0);
    ck_assert_float_eq(value, 16777215);
}
END_TEST

START_TEST(my_from_decimal_to_int_4) {
    my_decimal src;
    int value;
    src.bits[0] = 0b00000001011001011101010101101011;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000001000000000000000000;
    ck_assert_int_eq(my_from_decimal_to_int(src, &value), 0);
    ck_assert_float_eq(value, -2345);
}
END_TEST

START_TEST(my_from_decimal_to_int_5) {
    my_decimal src;
    int value;
    src.bits[0] = 0b00000000000000000000000000000000;
    src.bits[1] = 0b00000000000000000000000000000001;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_from_decimal_to_int(src, &value), 1);
}
END_TEST

START_TEST(my_from_decimal_to_int_6) {
    my_decimal src;
    int value;
    src.bits[0] = 0b00000000000000000000000001100100;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000000100000000000000000;
    ck_assert_int_eq(my_from_decimal_to_int(src, &value), 0);
    ck_assert_float_eq(value, -1);
}
END_TEST

START_TEST(my_from_decimal_to_int_7) {
    my_decimal src;
    int value;
    src.bits[0] = 0b00000000100000000000000000000000;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_from_decimal_to_int(src, &value), 0);
    ck_assert_float_eq(value, 8388608);
}
END_TEST

START_TEST(my_negate_1) {
    my_decimal origin, result;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_negate(origin, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_negate_2) {
    my_decimal origin, result;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_negate(origin, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_negate_3) {
    my_decimal origin, result;
    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_negate(origin, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000001);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_negate_4) {
    my_decimal origin, result;
    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_negate(origin, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000001);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_negate_5) {
    my_decimal origin, result;
    origin.bits[0] = 0b00011001111100010110101111111100;
    origin.bits[1] = 0b10000000001010001011111000010111;
    origin.bits[2] = 0b00000000001000111110101101000100;
    origin.bits[3] = 0b10000000000010110000000000000000;
    ck_assert_int_eq(my_negate(origin, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00011001111100010110101111111100);
    ck_assert_int_eq(result.bits[1], 0b10000000001010001011111000010111);
    ck_assert_int_eq(result.bits[2], 0b00000000001000111110101101000100);
    ck_assert_int_eq(result.bits[3], 0b00000000000010110000000000000000);
}
END_TEST

START_TEST(my_negate_6) {
    my_decimal origin, result;
    origin.bits[0] = 0b10001011100010111000001111011100;
    origin.bits[1] = 0b10001000011110010001111011100000;
    origin.bits[2] = 0b10001000110100110011111111100000;
    origin.bits[3] = 0b00000000000010110000000000000000;
    ck_assert_int_eq(my_negate(origin, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b10001011100010111000001111011100);
    ck_assert_int_eq(result.bits[1], 0b10001000011110010001111011100000);
    ck_assert_int_eq(result.bits[2], 0b10001000110100110011111111100000);
    ck_assert_int_eq(result.bits[3], 0b10000000000010110000000000000000);
}
END_TEST

START_TEST(my_negate_7) {
    my_decimal origin, result;
    origin.bits[0] = 0b01101101111110011010100000000000;
    origin.bits[1] = 0b00000000000001000110001011000101;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000010110000000000000000;
    ck_assert_int_eq(my_negate(origin, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b01101101111110011010100000000000);
    ck_assert_int_eq(result.bits[1], 0b00000000000001000110001011000101);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000010110000000000000000);
}
END_TEST

START_TEST(my_negate_8) {
    my_decimal origin, result;
    origin.bits[0] = 0b10111110100011111111111111111111;
    origin.bits[1] = 0b11000111101011101100100011100010;
    origin.bits[2] = 0b00000000000000000001101000100100;
    origin.bits[3] = 0b10000000000100110000000000000000;
    ck_assert_int_eq(my_negate(origin, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b10111110100011111111111111111111);
    ck_assert_int_eq(result.bits[1], 0b11000111101011101100100011100010);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000001101000100100);
    ck_assert_int_eq(result.bits[3], 0b00000000000100110000000000000000);
}
END_TEST

START_TEST(my_round1) {
    my_decimal src, origin, result;
    //  src = 5.0;
    src.bits[0] = 0b00000000000000000000000000110010;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000010000000000000000;
    //  origin = 5;
    origin.bits[0] = 0b00000000000000000000000000000101;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round2) {
    my_decimal src, origin, result;
    //  src = 3.4;
    src.bits[0] = 0b00000000000000000000000000100010;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000010000000000000000;
    //  origin = 3;
    origin.bits[0] = 0b00000000000000000000000000000011;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round3) {
    my_decimal src, origin, result;
    //  src = 0.0;
    src.bits[0] = 0b00000000000000000000000000000000;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000010000000000000000;
    //  origin = 0;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round4) {
    my_decimal src, origin, result;
    //  src = -2.4363463;
    src.bits[0] = 0b00000001011100111100000111000111;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000001110000000000000000;
    //  origin = -2;
    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round5) {
    my_decimal src, origin, result;
    //  src = -0.0;
    src.bits[0] = 0b00000000000000000000000000000000;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000000010000000000000000;
    //  origin = 0;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round6) {
    my_decimal src, origin, result;
    //  src = -0.45;
    src.bits[0] = 0b00000000000000000000000000101101;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000000100000000000000000;
    //  origin = 0;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round7) {
    my_decimal src, origin, result;
    //  src = 652.34631;
    src.bits[0] = 0b00000011111000110110011011000111;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000001010000000000000000;
    //  origin = 652;
    origin.bits[0] = 0b00000000000000000000001010001100;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round8) {
    my_decimal src, origin, result;
    //  src = 4.97623323;
    src.bits[0] = 0b00011101101010010010000100011011;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000010000000000000000000;
    //  origin = 5;
    origin.bits[0] = 0b00000000000000000000000000000101;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round9) {
    my_decimal src, origin, result;
    //  src = 65658654.59;
    src.bits[0] = 0b10000111010110110010011111110011;
    src.bits[1] = 0b00000000000000000000000000000001;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000100000000000000000;
    //  origin = 65658655;
    origin.bits[0] = 0b00000011111010011101111100011111;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round10) {
    my_decimal src, origin, result;
    //  src = -364748.110;
    src.bits[0] = 0b00010101101111011001110101001110;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000000110000000000000000;
    //  origin = -364748;
    origin.bits[0] = 0b00000000000001011001000011001100;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round11) {
    my_decimal src, origin, result;
    //  src = 1.9874565432111;
    src.bits[0] = 0b01101000011010011010001100101111;
    src.bits[1] = 0b00000000000000000001001000010011;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000011010000000000000000;
    //  origin = 2;
    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round12) {
    my_decimal src, origin, result;
    //  src = -98.78798789312;
    src.bits[0] = 0b00010110010010101110101011000000;
    src.bits[1] = 0b00000000000000000000100011111100;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000010110000000000000000;
    //  origin = -99;
    origin.bits[0] = 0b00000000000000000000000001100011;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round13) {
    my_decimal src, origin, result;
    //  src = 999999999999999999911.3;
    src.bits[0] = 0b10110010001111111111110010001001;
    src.bits[1] = 0b00011001111000001100100110111010;
    src.bits[2] = 0b00000000000000000000001000011110;
    src.bits[3] = 0b00000000000000010000000000000000;
    //  origin = 999999999999999999911;
    origin.bits[0] = 0b11011110100111111111111110100111;
    origin.bits[1] = 0b00110101110010011010110111000101;
    origin.bits[2] = 0b00000000000000000000000000110110;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round14) {
    my_decimal src, origin, result;
    //  src = -545454512454545.35265454545645;
    src.bits[0] = 0b10000010111000100101101011101101;
    src.bits[1] = 0b11111001111010000010010110101101;
    src.bits[2] = 0b10110000001111101111000010010100;
    src.bits[3] = 0b10000000000011100000000000000000;
    //  origin = -545454512454545;
    origin.bits[0] = 0b10000110011101001011101110010001;
    origin.bits[1] = 0b00000000000000011111000000010110;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round15) {
    my_decimal src, origin, result;
    //  src = 545454512454545.35265454545645;
    src.bits[0] = 0b10000010111000100101101011101101;
    src.bits[1] = 0b11111001111010000010010110101101;
    src.bits[2] = 0b10110000001111101111000010010100;
    src.bits[3] = 0b00000000000011100000000000000000;
    //  origin = 545454512454545;
    origin.bits[0] = 0b10000110011101001011101110010001;
    origin.bits[1] = 0b00000000000000011111000000010110;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round16) {
    my_decimal src, origin, result;
    //  src = 7961327845421.879754123131254;
    src.bits[0] = 0b01001110111001000011100101110110;
    src.bits[1] = 0b01001011001101011010000111011001;
    src.bits[2] = 0b00011001101110010111010010111111;
    src.bits[3] = 0b00000000000011110000000000000000;
    //  origin = 7961327845422;
    origin.bits[0] = 0b10100100000111100100000000101110;
    origin.bits[1] = 0b00000000000000000000011100111101;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round17) {
    my_decimal src, origin, result;
    //  src = 0;
    src.bits[0] = 0b00000000000000000000000000000000;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000000000000000000000;
    //  origin = 0;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round18) {
    my_decimal src, origin, result;
    //  src = 0;
    src.bits[0] = 0b00000000000000000000000000000000;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000000000000000000000;
    //  origin = 0;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_round19) {
    my_decimal src, origin, result;
    //  src = 0;
    src.bits[0] = 0b00000000000000000000000000000000;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000000000000000000000;
    //  origin = 0;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_round(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_truncate1) {
    my_decimal src1, origin, result;
    //  src1 = 2.1234;
    src1.bits[0] = 0b00000000000000000101001011110010;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000001000000000000000000;
    //  origin = 2;
    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_truncate(src1, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_truncate2) {
    my_decimal src1, origin, result;
    //  src1 = 457.000001;
    src1.bits[0] = 0b00011011001111010100010001000001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000001100000000000000000;
    //  origin = 457;
    origin.bits[0] = 0b00000000000000000000000111001001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_truncate(src1, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_truncate3) {
    my_decimal src1, origin, result;
    //  src1 = 2.000;
    src1.bits[0] = 0b00000000000000000000011111010000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000110000000000000000;
    //  origin = 2;
    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_truncate(src1, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_truncate4) {
    my_decimal src1, origin, result;
    //  src1 = 0.000000000000000000000000000;
    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000110110000000000000000;
    //  origin = 0;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_truncate(src1, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_truncate5) {
    my_decimal src1, origin, result;
    //  src1 = 2.222212;
    src1.bits[0] = 0b00000000001000011110100010000100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000001100000000000000000;
    //  origin = 2;
    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_truncate(src1, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_truncate6) {
    my_decimal src1, origin, result;
    //  src1 = 2.22221200000001000;
    src1.bits[0] = 0b00000111100011111010001111101000;
    src1.bits[1] = 0b00000011000101010111110100000001;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000100010000000000000000;
    //  origin = 2;
    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_truncate(src1, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_truncate7) {
    my_decimal src1, origin, result;
    //  src1 = 987456543210.0;
    src1.bits[0] = 0b00011001111101110000001100100100;
    src1.bits[1] = 0b00000000000000000000100011111011;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000010000000000000000;
    //  origin = 987456543210;
    origin.bits[0] = 0b11101000111111110001100111101010;
    origin.bits[1] = 0b00000000000000000000000011100101;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_truncate(src1, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_truncate8) {
    my_decimal src1, origin, result;
    //  src1 = -9878798789.5867800;
    src1.bits[0] = 0b11001110100110111101100110011000;
    src1.bits[1] = 0b00000001010111101111011100100110;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000001110000000000000000;
    //  origin = -9878798789;
    origin.bits[0] = 0b01001100110100101000000111000101;
    origin.bits[1] = 0b00000000000000000000000000000010;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_truncate(src1, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_truncate9) {
    my_decimal src1, origin, result;
    //  src1 = 13436577854.000000000000;
    src1.bits[0] = 0b00100110011110011110000000000000;
    src1.bits[1] = 0b01100101111110011111000000101100;
    src1.bits[2] = 0b00000000000000000000001011011000;
    src1.bits[3] = 0b00000000000011000000000000000000;
    //  origin = 13436577854;
    origin.bits[0] = 0b00100000111000011110100000111110;
    origin.bits[1] = 0b00000000000000000000000000000011;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_truncate(src1, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_truncate10) {
    my_decimal src1, origin, result;
    //  src1 = 79228162514264337593543950335;
    src1.bits[0] = 0b11111111111111111111111111111111;
    src1.bits[1] = 0b11111111111111111111111111111111;
    src1.bits[2] = 0b11111111111111111111111111111111;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  origin = 79228162514264337593543950335;
    origin.bits[0] = 0b11111111111111111111111111111111;
    origin.bits[1] = 0b11111111111111111111111111111111;
    origin.bits[2] = 0b11111111111111111111111111111111;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_truncate(src1, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_truncate11) {
    my_decimal src1, origin, result;
    //  src1 = 0.5456465465486476846545465485;
    src1.bits[0] = 0b00001011000011110111000010001101;
    src1.bits[1] = 0b10010110101100000101100101010001;
    src1.bits[2] = 0b00010001101000010111101110000001;
    src1.bits[3] = 0b00000000000111000000000000000000;
    //  origin = 0;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_truncate(src1, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_truncate12) {
    my_decimal src1, origin, result;
    //  src1 = 0;
    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  origin = 0;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_truncate(src1, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_truncate13) {
    my_decimal src1, origin, result;
    //  src1 = 0;
    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  origin = 0;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_truncate(src1, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_truncate14) {
    my_decimal src1, origin, result;
    //  src1 = 0;
    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  origin = 0;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_truncate(src1, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_floor_1) {
    my_decimal src, origin, result;
    //  src = 5.0;
    src.bits[0] = 0b00000000000000000000000000110010;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000010000000000000000;
    //  origin = 5;
    origin.bits[0] = 0b00000000000000000000000000000101;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_floor(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_floor_2) {
    my_decimal src, origin, result;
    //  src = 3.4;
    src.bits[0] = 0b00000000000000000000000000100010;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000010000000000000000;
    //  origin = 3;
    origin.bits[0] = 0b00000000000000000000000000000011;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_floor(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_floor_3) {
    my_decimal src, origin, result;
    //  src = 0.0;
    src.bits[0] = 0b00000000000000000000000000000000;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000010000000000000000;
    //  origin = 0;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_floor(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_floor_4) {
    my_decimal src, origin, result;
    //  src = -2.4363463;
    src.bits[0] = 0b00000001011100111100000111000111;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000001110000000000000000;
    //  origin = -3;
    origin.bits[0] = 0b00000000000000000000000000000011;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_floor(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_floor_5) {
    my_decimal src, origin, result;
    //  src = -0.0;
    src.bits[0] = 0b00000000000000000000000000000000;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000000010000000000000000;
    //  origin = 0;
    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_floor(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_floor_6) {
    my_decimal src, origin, result;
    //  src = -0.45;
    src.bits[0] = 0b00000000000000000000000000101101;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000000100000000000000000;
    //  origin = -1;
    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_floor(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_floor_7) {
    my_decimal src, origin, result;
    //  src = 652.34631;
    src.bits[0] = 0b00000011111000110110011011000111;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000001010000000000000000;
    //  origin = 652;
    origin.bits[0] = 0b00000000000000000000001010001100;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_floor(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_floor_8) {
    my_decimal src, origin, result;
    //  src = 4.97623323;
    src.bits[0] = 0b00011101101010010010000100011011;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000010000000000000000000;
    //  origin = 4;
    origin.bits[0] = 0b00000000000000000000000000000100;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_floor(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_floor_9) {
    my_decimal src, origin, result;
    //  src = 65658654.59;
    src.bits[0] = 0b10000111010110110010011111110011;
    src.bits[1] = 0b00000000000000000000000000000001;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000000100000000000000000;
    //  origin = 65658654;
    origin.bits[0] = 0b00000011111010011101111100011110;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_floor(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_floor_10) {
    my_decimal src, origin, result;
    //  src = -364748.110;
    src.bits[0] = 0b00010101101111011001110101001110;
    src.bits[1] = 0b00000000000000000000000000000000;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000000110000000000000000;
    //  origin = -364749;
    origin.bits[0] = 0b00000000000001011001000011001101;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_floor(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_floor_11) {
    my_decimal src, origin, result;
    //  src = 1.9874565432111;
    src.bits[0] = 0b01101000011010011010001100101111;
    src.bits[1] = 0b00000000000000000001001000010011;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b00000000000011010000000000000000;
    //  origin = 1;
    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_floor(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_floor_12) {
    my_decimal src, origin, result;
    //  src = -98.78798789312;
    src.bits[0] = 0b00010110010010101110101011000000;
    src.bits[1] = 0b00000000000000000000100011111100;
    src.bits[2] = 0b00000000000000000000000000000000;
    src.bits[3] = 0b10000000000010110000000000000000;
    //  origin = -99;
    origin.bits[0] = 0b00000000000000000000000001100011;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_floor(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_floor_13) {
    my_decimal src, origin, result;
    //  src = 999999999999999999911.3;
    src.bits[0] = 0b10110010001111111111110010001001;
    src.bits[1] = 0b00011001111000001100100110111010;
    src.bits[2] = 0b00000000000000000000001000011110;
    src.bits[3] = 0b00000000000000010000000000000000;
    //  origin = 999999999999999999911;
    origin.bits[0] = 0b11011110100111111111111110100111;
    origin.bits[1] = 0b00110101110010011010110111000101;
    origin.bits[2] = 0b00000000000000000000000000110110;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_floor(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_floor_14) {
    my_decimal src, origin, result;
    //  src = 2.7986531268974139743;
    src.bits[0] = 0b11111110100100001101100101011111;
    src.bits[1] = 0b10000100011001000010000111101000;
    src.bits[2] = 0b00000000000000000000000000000001;
    src.bits[3] = 0b00000000000100110000000000000000;
    //  origin = 2;
    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_floor(src, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_add_1) {
    my_decimal src1, src2, result;
    //    src1 = -1234
    src1.bits[0] = 0b00000000000000000000010011010010;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = 1.234
    src2.bits[0] = 0b00000000000000000000010011010010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000110000000000000000;
    //    result = -1232.766;
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000100101100111101111110);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000110000000000000000);
}
END_TEST

START_TEST(my_add_2) {
    my_decimal src1, src2, result;
    //    src1 = -1234
    src1.bits[0] = 0b00000000000000000000010011010010;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = -1.234
    src2.bits[0] = 0b00000000000000000000010011010010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000110000000000000000;
    //    result = -1235.234;
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000100101101100100100010);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000110000000000000000);
}
END_TEST

START_TEST(my_add_3) {
    my_decimal src1, src2, result;
    //    src1 = -221.234
    src1.bits[0] = 0b00000000000000110110000000110010;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000110000000000000000;
    //    src2 = -1234
    src2.bits[0] = 0b00000000000000000000010011010010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000000000000000000000;
    //    result = -1455.234;
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000101100011010010000010);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000110000000000000000);
}
END_TEST

START_TEST(my_add_4) {
    my_decimal src1, src2, result;
    //    src1 = -9403
    src1.bits[0] = 0b00000000000000000010010010111011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = 0.002340
    src2.bits[0] = 0b00000000000000000000000011101010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000001010000000000000000;
    //    result = -9402.99766;
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00111000000010111101010111110110);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000001010000000000000000);
}
END_TEST

START_TEST(my_add_5) {
    my_decimal src1, src2, result;
    //    src1 = -9403
    src1.bits[0] = 0b00000000000000000010010010111011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = 234
    src2.bits[0] = 0b00000000000000000000000011101010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = -9169;
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000010001111010001);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_add_6) {
    my_decimal src1, src2, result;
    //    src1 = 9403000000000000000000000
    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b10101000000000000000000000000000;
    src1.bits[2] = 0b00000000000001111100011100101001;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = -0.00000000000000000000234
    src2.bits[0] = 0b00000000000000000000000011101010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000101110000000000000000;
    //    result = 9403000000000000000000000;
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[1], 0b10101000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000001111100011100101001);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_add_7) {
    my_decimal src1, src2, result;
    //    src1 = 79000000000000000000000000000
    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b11111111010000110100010100000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 79000000000000000000000000000
    src2.bits[0] = 0b00000000000000000000000000000000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b11111111010000110100010100000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_add(src1, src2, &result), 1);
}
END_TEST

START_TEST(my_add_8) {
    my_decimal src1, src2, result;
    //    src1 = -79000000000000000000000000000
    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b11111111010000110100010100000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = -79000000000000000000000000000
    src2.bits[0] = 0b00000000000000000000000000000000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b11111111010000110100010100000000;
    src2.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_add(src1, src2, &result), 2);
}
END_TEST

START_TEST(my_add_9) {
    my_decimal src1, src2, result;
    //    src1 = 79000000000000000000000000000
    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b11111111010000110100010100000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = -79000000000000000000000000000
    src2.bits[0] = 0b00000000000000000000000000000000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b11111111010000110100010100000000;
    src2.bits[3] = 0b10000000000000000000000000000000;
    //    result = 0;
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_add_10) {
    my_decimal src1, src2, result;
    //    src1 = -940
    src1.bits[0] = 0b00000000000000000000001110101100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = -11200
    src2.bits[0] = 0b00000000000000000010101111000000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000000000000000000000;
    //    result = -12140;
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000010111101101100);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_add_11) {
    my_decimal src1, src2, result;
    //    src1 = 9403
    src1.bits[0] = 0b00000000000000000010010010111011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 202
    src2.bits[0] = 0b00000000000000000000000011001010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = 9605;
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000010010110000101);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_add_12) {
    my_decimal src1, src2, result;
    //     src1 = 0.00000000000000000000000000000000000006616757
    src1.bits[0] = 0b01100111111001001111111011101111;
    src1.bits[1] = 0b00000000000000000000000000001111;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000001100000000000000000000;
    //     src2 = 0.00000000000000000000000000000000000109695975
    src2.bits[0] = 0b01100111111001001111111111111111;
    src2.bits[1] = 0b00000000000000000000000011111111;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000001100000000000000000000;
    //    result = 0.00000000000000000000000000000000000116312732
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b11001111110010011111111011101110);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000100001110);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000001100000000000000000000);
}
END_TEST

START_TEST(my_add_13) {
    my_decimal src1, src2, result;
    //     src1 = 1095217024
    src1.bits[0] = 0b00000000000001100111111001001111;
    src1.bits[1] = 0b00000000000000000000000011111111;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000110000000000000000;
    //     src2 = 1005022
    src2.bits[0] = 0b00000000000001100111111001001111;
    src2.bits[1] = 0b00000000000000000000000011101010;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000001100000000000000000;
    //    result = 1096222080
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00011001011000111110001011100111);
    ck_assert_int_eq(result.bits[1], 0b00000000000000111110010100000010);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000001100000000000000000);
}
END_TEST

START_TEST(my_add_14) {
    my_decimal src1, src2, result;
    //     src1 = 281474957312
    src1.bits[0] = 0b11111111100000110111111001001111;
    src1.bits[1] = 0b00000000000000001111111111111111;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000110000000000000000;
    //     src2 = -1759217.75
    src2.bits[0] = 0b11111111100000110111111001001111;
    src2.bits[1] = 0b00000000000000000000111111111111;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000001110000000000000000;
    //    result = 281473198094.25
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000111100100110111110100001);
    ck_assert_int_eq(result.bits[1], 0b00100111000011111110111111101101);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000001110000000000000000);
}
END_TEST

START_TEST(my_add_15) {
    my_decimal src1, src2, result;
    //     src1 = -281474957312
    src1.bits[0] = 0b11111111100000110111111001001111;
    src1.bits[1] = 0b00000000000000001111111111111111;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000110000000000000000;
    //     src2 = -1759217.75
    src2.bits[0] = 0b11111111100000110111111001001111;
    src2.bits[1] = 0b00000000000000000000111111111111;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000001110000000000000000;
    //    result = -281476726784
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b11111111111110010110110000111111);
    ck_assert_int_eq(result.bits[1], 0b00100111000100000000111111101100);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000001110000000000000000);
}
END_TEST

START_TEST(my_add_16) {
    my_decimal src1, src2, result;
    //     src1 = -281474957312
    src1.bits[0] = 0b11111111100000110111111001001111;
    src1.bits[1] = 0b00000000000000001111111111111111;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000110000000000000000;
    //     src2 = 1759217.75
    src2.bits[0] = 0b11111111100000110111111001001111;
    src2.bits[1] = 0b00000000000000000000111111111111;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000001110000000000000000;
    //    result = 281473198094.25
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000111100100110111110100001);
    ck_assert_int_eq(result.bits[1], 0b00100111000011111110111111101101);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000001110000000000000000);
}
END_TEST

START_TEST(my_add_17) {
    my_decimal src1, src2, result;
    //     src1 = 18446744949882880
    src1.bits[0] = 0b11111111100000110111111001001111;
    src1.bits[1] = 0b11111111111111111111111111111111;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000110000000000000000;
    //     src2 = 0.0175921786576509475708007812
    src2.bits[0] = 0b11111111100000110111111001001111;
    src2.bits[1] = 0b00000000000000000000111111111111;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000011110000000000000000;
    //     result = 18446744949882880
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b11111111100000110111111001100000);
    ck_assert_int_eq(result.bits[1], 0b11111111111111111111111111111111);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000110000000000000000);
}
END_TEST

START_TEST(my_add_18) {
    my_decimal src1, src2, result;
    //    src1 = 79228162514264337593543950336
    src1.bits[0] = 0b11111111111111111111111111111111;
    src1.bits[1] = 0b11111111111111111111111111111111;
    src1.bits[2] = 0b11111111111111111111111111111111;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 0.1
    src2.bits[0] = 0b00000000000000000000000000000001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000010000000000000000;
    //    result = 79228162514264337593543950336;
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b11111111111111111111111111111111);
    ck_assert_int_eq(result.bits[1], 0b11111111111111111111111111111111);
    ck_assert_int_eq(result.bits[2], 0b11111111111111111111111111111111);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_add_19) {
    my_decimal src1, src2, result;
    //    src1 = 36893488147419103232
    src1.bits[0] = 0b11111111111111111111111111111111;
    src1.bits[1] = 0b11111111111111111111111111111111;
    src1.bits[2] = 0b00000000000000000000000000000001;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 0.1
    src2.bits[0] = 0b00000000000000000000000000000001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000010000000000000000;
    //    result = 36893488147419103232;
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b11111111111111111111111111110111);
    ck_assert_int_eq(result.bits[1], 0b11111111111111111111111111111111);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000010011);
    ck_assert_int_eq(result.bits[3], 0b00000000000000010000000000000000);
}
END_TEST

START_TEST(my_add_20) {
    my_decimal src1, src2, result;
    //    src1 = 940
    src1.bits[0] = 0b00000000000000000000001110101100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b0000000000000000000000000000000;
    //    src2 = -11200
    src2.bits[0] = 0b00000000000000000010101111000000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000000000000000000000;
    //    result = -10260;
    ck_assert_int_eq(my_add(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000010100000010100);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_sub_1) {
    my_decimal src1, src2, result;
    //    src1 = 9403
    src1.bits[0] = 0b00000000000000000010010010111011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b0000000000000000000000000000000;
    //    src2 = 202
    src2.bits[0] = 0b00000000000000000000000011001010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = 9201;
    ck_assert_int_eq(my_sub(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000010001111110001);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_sub_2) {
    my_decimal src1, src2, result;
    //    src1 = 9403
    src1.bits[0] = 0b00000000000000000010010010111011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b0000000000000000000000000000000;
    //    src2 = 202.098
    src2.bits[0] = 0b00000001001101000110000010001000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000001010000000000000000;
    //    result = 9200.902;
    ck_assert_int_eq(my_sub(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00110110110101110111011001011000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000001010000000000000000);
}
END_TEST

START_TEST(my_sub_3) {
    my_decimal src1, src2, result;
    //    src1 = -9403
    src1.bits[0] = 0b00000000000000000010010010111011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = 202.098
    src2.bits[0] = 0b00000001001101000110000010001000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000001010000000000000000;
    //    result = -9605.098;
    ck_assert_int_eq(my_sub(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00111001010000000011011101101000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000001010000000000000000);
}
END_TEST

START_TEST(my_sub_4) {
    my_decimal src1, src2, result;
    //    src1 = 9403
    src1.bits[0] = 0b00000000000000000010010010111011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 20209000448
    src2.bits[0] = 0b10110100100011001110000000000000;
    src2.bits[1] = 0b00000000000000000000000000000100;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = -20208990208;
    ck_assert_int_eq(my_sub(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b10110100100011001011101101000101);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000100);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_sub_5) {
    my_decimal src1, src2, result;
    //    src1 = 940300
    src1.bits[0] = 0b00000000000011100101100100001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 20209000000
    src2.bits[0] = 0b10110100100011001110000000000000;
    src2.bits[1] = 0b00000000000000000000000000000100;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = -20208059700;
    ck_assert_int_eq(my_sub(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b10110100011111101000011011110100);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000100);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_sub_6) {
    my_decimal src1, src2, result;
    //    src1 = -940300
    src1.bits[0] = 0b00000000000011100101100100001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = -202
    src2.bits[0] = 0b00000000000000000000000011001010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000000000000000000000;
    //    result = -940098;
    ck_assert_int_eq(my_sub(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000011100101100001000010);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST
START_TEST(my_sub_7) {
    my_decimal src1, src2, result;
    //    src1 = -940300
    src1.bits[0] = 0b00000000000011100101100100001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = -202
    src2.bits[0] = 0b00000000000000000000000011001010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000000000000000000000;
    //    result = -940098;
    ck_assert_int_eq(my_sub(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000011100101100001000010);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_sub_8) {
    my_decimal src1, src2, result;
    //    src1 = 79000000000000000000000000000
    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b11111111010000110100010100000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = -79000000000000000000000000000
    src2.bits[0] = 0b00000000000000000000000000000000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b11111111010000110100010100000000;
    src2.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_sub(src1, src2, &result), 1);
}
END_TEST

START_TEST(my_sub_9) {
    my_decimal src1, src2, result;
    //    src1 = -79000000000000000000000000000
    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b11111111010000110100010100000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = 79000000000000000000000000000
    src2.bits[0] = 0b00000000000000000000000000000000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b11111111010000110100010100000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_sub(src1, src2, &result), 2);
}
END_TEST

START_TEST(my_sub_10) {
    my_decimal src1, src2, result;
    //    src1 = 2635.199951
    src1.bits[0] = 0b00000000000000000110011011110000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000010000000000000000;
    //    src2 = 283.093994
    src2.bits[0] = 0b00000000000001000101000111010110;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000110000000000000000;
    //    result = 2352.105957;
    ck_assert_int_eq(my_sub(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000001000111110001111101010);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000110000000000000000);
}
END_TEST

START_TEST(my_sub_11) {
    my_decimal src1, src2, result;
    //    src1 = 283.093994
    src1.bits[0] = 0b00000000000001000101000111010110;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000110000000000000000;
    //    src2 = 300.399994
    src2.bits[0] = 0b00000000000000000000101110111100;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000010000000000000000;
    //    result = -17.306000;
    ck_assert_int_eq(my_sub(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000100001110011010);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000110000000000000000);
}
END_TEST

START_TEST(my_sub_12) {
    my_decimal src1, src2, result;
    //    src1 = -281474957312
    src1.bits[0] = 0b11111111100000110111111001001111;
    src1.bits[1] = 0b00000000000000001111111111111111;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000110000000000000000;
    //    src2 = -1759217.75
    src2.bits[0] = 0b11111111100000110111111001001111;
    src2.bits[1] = 0b00000000000000000000111111111111;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000001110000000000000000;
    //    result = -281476716529.75
    ck_assert_int_eq(my_sub(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000111100100110111110100001);
    ck_assert_int_eq(result.bits[1], 0b00100111000011111110111111101101);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000001110000000000000000);
}
END_TEST

START_TEST(my_sub_13) {
    my_decimal src1, src2, result;
    //    src1 = 281474957312
    src1.bits[0] = 0b11111111100000110111111001001111;
    src1.bits[1] = 0b00000000000000001111111111111111;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000110000000000000000;
    //    src2 = -1759217.75
    src2.bits[0] = 0b11111111100000110111111001001111;
    src2.bits[1] = 0b00000000000000000000111111111111;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000001110000000000000000;
    //    result = 281476716529.75
    ck_assert_int_eq(my_sub(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b11111111111110010110110000111111);
    ck_assert_int_eq(result.bits[1], 0b00100111000100000000111111101100);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000001110000000000000000);
}
END_TEST

START_TEST(my_sub_14) {
    my_decimal src1, src2, result;
    //    src1 = -30.4
    src1.bits[0] = 0b00000000000000000000000100110000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000010000000000000000;
    //    src2 = -287.382111
    src2.bits[0] = 0b00010001001000010001101001100000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000001100000000000000000;
    //    result = 256.982111
    ck_assert_int_eq(my_sub(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00001111010100010011110001100000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000001100000000000000000);
}
END_TEST

START_TEST(my_sub_15) {
    my_decimal src1, src2, result;
    //    src1 = -281474957312
    src1.bits[0] = 0b11111111100000110111111001001111;
    src1.bits[1] = 0b00000000000000001111111111111111;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000110000000000000000;
    //    src2 = 1759217.75
    src2.bits[0] = 0b11111111100000110111111001001111;
    src2.bits[1] = 0b00000000000000000000111111111111;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000001110000000000000000;
    //    result = 281476716529.75
    ck_assert_int_eq(my_sub(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b11111111111110010110110000111111);
    ck_assert_int_eq(result.bits[1], 0b00100111000100000000111111101100);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000001110000000000000000);
}
END_TEST

START_TEST(my_mul_1) {
    my_decimal src1, src2, result;
    //    src1 = 940300
    src1.bits[0] = 0b00000000000011100101100100001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 202
    src2.bits[0] = 0b00000000000000000000000011001010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = 189940600;
    ck_assert_int_eq(my_mul(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00001011010100100100001101111000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_mul_2) {
    my_decimal src1, src2, result;
    //    src1 = 940300
    src1.bits[0] = 0b00000000000011100101100100001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 940300
    src2.bits[0] = 0b00000000000011100101100100001100;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = 884164090000;
    ck_assert_int_eq(my_mul(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b11011100010010010101100010010000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000011001101);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_mul_3) {
    my_decimal src1, src2, result;
    //    src1 = 9403
    src1.bits[0] = 0b00000000000000000010010010111011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 202
    src2.bits[0] = 0b00000000000000000000000011001010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = 1899406;
    ck_assert_int_eq(my_mul(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000111001111101110001110);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_mul_4) {
    my_decimal src1, src2, result;
    //    src1 = 9403
    src1.bits[0] = 0b00000000000000000010010010111011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 2020.29
    src2.bits[0] = 0b00000000000000110001010100101101;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000100000000000000000;
    //    result = 1899406;
    ck_assert_int_eq(my_mul(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b01110001001110101100101111011111);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000100000000000000000);
}
END_TEST

START_TEST(my_mul_5) {
    my_decimal src1, src2, result;
    //    src1 = 940300
    src1.bits[0] = 0b00000000000011100101100100001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 2020.29
    src2.bits[0] = 0b00000000000000110001010100101101;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000100000000000000000;
    //    result = 1899678720;
    ck_assert_int_eq(my_mul(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00111010111101111010001100011100);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000101100);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000100000000000000000);
}
END_TEST

START_TEST(my_mul_6) {
    my_decimal src1, src2, result;
    //    src1 = -940300
    src1.bits[0] = 0b00000000000011100101100100001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = 2020.29
    src2.bits[0] = 0b00000000000000110001010100101101;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000100000000000000000;
    //    result = -1899678720;
    ck_assert_int_eq(my_mul(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00111010111101111010001100011100);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000101100);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000100000000000000000);
}
END_TEST

START_TEST(my_mul_7) {
    my_decimal src1, src2, result;
    //    src1 = -940300
    src1.bits[0] = 0b00000000000011100101100100001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = -2020.29
    src2.bits[0] = 0b00000000000000110001010100101101;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000100000000000000000;
    //    result = 1899678720;
    ck_assert_int_eq(my_mul(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00111010111101111010001100011100);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000101100);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000100000000000000000);
}
END_TEST

START_TEST(my_mul_8) {
    my_decimal src1, src2, result;
    //    src1 = -32768
    src1.bits[0] = 0b00000000000000001000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = 2
    src2.bits[0] = 0b00000000000000000000000000000010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = -65536;
    ck_assert_int_eq(my_mul(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000010000000000000000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_mul_9) {
    my_decimal src1, src2, result;
    //    src1 = -32768
    src1.bits[0] = 0b00000000000000001000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = 32768
    src2.bits[0] = 0b00000000000000001000000000000000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = -1073741824
    ck_assert_int_eq(my_mul(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b01000000000000000000000000000000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_mul_10) {
    my_decimal src1, src2, result;
    //    src1 = -27993366
    src1.bits[0] = 0b11000101011110000001110010001100;
    src1.bits[1] = 0b00000000000000000000001010001011;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000001010000000000000000;
    //    src2 = 33283374
    src2.bits[0] = 0b11000110011000100110010110011111;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000100000000000000000;
    //    result = -931713697972224
    ck_assert_int_eq(my_mul(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00111110011101001111011011110100);
    ck_assert_int_eq(result.bits[1], 0b00010101001111110011011111000111);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000111111001);
    ck_assert_int_eq(result.bits[3], 0b10000000000001110000000000000000);
}
END_TEST

START_TEST(my_mul_11) {
    my_decimal src1, src2, result;
    //    src1 = 12345679020032
    src1.bits[0] = 0b10000110000011110011000100001010;
    src1.bits[1] = 0b00000000000000000111000001001000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000010000000000000000;
    //    src2 = 33283374
    src2.bits[0] = 0b11000110011000100110010110011111;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000100000000000000000;
    //    result = 410905826357749481472
    ck_assert_int_eq(my_mul(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b11000011100111000110011100110110);
    ck_assert_int_eq(result.bits[1], 0b01000000000001010110101110101101);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000101011100000011);
    ck_assert_int_eq(result.bits[3], 0b00000000000000110000000000000000);
}
END_TEST

START_TEST(my_mul_12) {
    my_decimal src1, src2, result;
    //    src1 = -36832632897536
    src1.bits[0] = 0b10100111110101101100000010110111;
    src1.bits[1] = 0b00000000000000010100111011111101;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000010000000000000000;
    //    src2 = -987633287168
    src2.bits[0] = 0b00100001000110100011010110011111;
    src2.bits[1] = 0b00000000000000000101100111010011;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000100000000000000000;
    //    result = 36377133804836853104246784
    ck_assert_int_eq(my_mul(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b11011101110111011001010010101001);
    ck_assert_int_eq(result.bits[1], 0b11111101100100001100001111000110);
    ck_assert_int_eq(result.bits[2], 0b01110101100010100111010110111011);
    ck_assert_int_eq(result.bits[3], 0b00000000000000110000000000000000);
}
END_TEST

START_TEST(my_mul_13) {
    my_decimal src1, src2, result;
    //    src1 = 3683626461450731520
    src1.bits[0] = 0b10010010110001011001001011110000;
    src1.bits[1] = 0b00110011000111101101111011010000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = -9841157120
    src2.bits[0] = 0b00111010100011010100010010011011;
    src2.bits[1] = 0b00000000000000000101100110000001;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000001000000000000000000;
    //    result = 36377133804836853104246784
    ck_assert_int_eq(my_mul(src1, src2, &result), 2);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_mul_14) {
    my_decimal src1, src2, result;
    //    src1 = 3683626461450731520
    src1.bits[0] = 0b10010010110001011001001011110000;
    src1.bits[1] = 0b00110011000111101101111011010000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 9841157120
    src2.bits[0] = 0b00111010100011010100010010011011;
    src2.bits[1] = 0b00000000000000000101100110000001;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000001000000000000000000;
    //    result = 36377133804836853104246784
    ck_assert_int_eq(my_mul(src1, src2, &result), 1);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_div_1) {
    my_decimal src1, src2, result;
    //    src1 = 940300
    src1.bits[0] = 0b00000000000011100101100100001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 202
    src2.bits[0] = 0b00000000000000000000000011001010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = 4654.950495
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b01001101111001101010011101001001);
    ck_assert_int_eq(result.bits[1], 0b11000101110001110110010110110000);
    ck_assert_int_eq(result.bits[2], 0b10010110011010001101100100010111);
    ck_assert_int_eq(result.bits[3], 0b00000000000110010000000000000000);
}
END_TEST

START_TEST(my_div_2) {
    my_decimal src1, src2, result;
    //    src1 = -32768
    src1.bits[0] = 0b00000000000000001000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = 2
    src2.bits[0] = 0b00000000000000000000000000000010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = -16384
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000100000000000000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_div_3) {
    my_decimal src1, src2, result;
    //    src1 = -940300
    src1.bits[0] = 0b00000000000011100101100100001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = -2020.290039
    src2.bits[0] = 0b00000000000000110001010100101101;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000100000000000000000;
    //    result = 465.428223
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b11110000110101111001001110101010);
    ck_assert_int_eq(result.bits[1], 0b11000100000110110110010110010010);
    ck_assert_int_eq(result.bits[2], 0b10010110011000110101001000100101);
    ck_assert_int_eq(result.bits[3], 0b00000000000110100000000000000000);
}
END_TEST

START_TEST(my_div_4) {
    my_decimal src1, src2, result;
    //    src1 = -940300
    src1.bits[0] = 0b00000000000011100101100100001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = 2020.290039
    src2.bits[0] = 0b00000000000000110001010100101101;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000100000000000000000;
    //    result = -465.428223
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b11110000110101111001001110101010);
    ck_assert_int_eq(result.bits[1], 0b11000100000110110110010110010010);
    ck_assert_int_eq(result.bits[2], 0b10010110011000110101001000100101);
    ck_assert_int_eq(result.bits[3], 0b10000000000110100000000000000000);
}
END_TEST

START_TEST(my_div_5) {
    my_decimal src1, src2, result;
    //    src1 = -9403.0e20
    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b11000100000000000000000000000000;
    src1.bits[2] = 0b00000000000000001100011100011101;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = 2.28e17
    src2.bits[0] = 0b00000000000000000000000000000000;
    src2.bits[1] = 0b00000011001010100000010011001100;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = -4124122.75
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b11100101111111110000010010101000);
    ck_assert_int_eq(result.bits[1], 0b01000100010010011111001010000001);
    ck_assert_int_eq(result.bits[2], 0b10000101010000011111000110011110);
    ck_assert_int_eq(result.bits[3], 0b10000000000101100000000000000000);
}
END_TEST

START_TEST(my_div_6) {
    my_decimal src1, src2, result;
    //    src1 = -0.900000
    src1.bits[0] = 0b00000000000000000000000000001001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000010000000000000000;
    //    src2 = 30.323
    src2.bits[0] = 0b00000000000000000111011001110011;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000110000000000000000;
    //    result = -0.02968
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00110101101101001110000100010011);
    ck_assert_int_eq(result.bits[1], 0b11010110100100000000010100111011);
    ck_assert_int_eq(result.bits[2], 0b00001001100101110001101111000110);
    ck_assert_int_eq(result.bits[3], 0b10000000000111010000000000000000);
}
END_TEST

START_TEST(my_div_7) {
    my_decimal src1, src2, result;
    //    src1 = -0.9e3
    src1.bits[0] = 0b00000000000000000000001110000100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = 30.32
    src2.bits[0] = 0b00000000000000000000101111011000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000100000000000000000;
    //    result = -29.683378
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b10010110001010011110000011101101);
    ck_assert_int_eq(result.bits[1], 0b00111101100010000011001011110111);
    ck_assert_int_eq(result.bits[2], 0b01011111111010011000001110100100);
    ck_assert_int_eq(result.bits[3], 0b10000000000110110000000000000000);
}
END_TEST

START_TEST(my_div_8) {
    my_decimal src1, src2, result;
    //    src1 = -0.9e3
    src1.bits[0] = 0b00000000000000000000001110000100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = 30
    src2.bits[0] = 0b00000000000000000000000000011110;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = -29.683378
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000011110);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_div_9) {
    my_decimal src1, src2, result;
    //    src1 = -0.9
    src1.bits[0] = 0b00000000000000000000000000001001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000010000000000000000;
    //    src2 = 0.000076
    src2.bits[0] = 0b00000000000000000000000001001100;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000001100000000000000000;
    //    result = -11842.105469
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b11111110101111001010000110101111);
    ck_assert_int_eq(result.bits[1], 0b10100111111010000111010101010111);
    ck_assert_int_eq(result.bits[2], 0b00100110010000111000111101010100);
    ck_assert_int_eq(result.bits[3], 0b10000000000110000000000000000000);
}
END_TEST

START_TEST(my_div_10) {
    my_decimal src1, src2, src3;
    my_from_int_to_decimal(10, &src1);
    my_from_int_to_decimal(0, &src2);
    ck_assert_int_eq(my_div(src1, src2, &src3), 3);
}
END_TEST

START_TEST(my_div_11) {
    my_decimal src1, src2, result;
    //    src1 = 9725622
    src1.bits[0] = 0b01110001001110010011101000100111;
    src1.bits[1] = 0b00000000000000000000000011100010;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000001010000000000000000;
    //    src2 = 972.429993
    src2.bits[0] = 0b00000000000000010111101111011011;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000100000000000000000;
    //    result = 10001.359375
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00100000111100011100110110110000);
    ck_assert_int_eq(result.bits[1], 0b01011000000100101111110011101001);
    ck_assert_int_eq(result.bits[2], 0b00100000010100001110111000110111);
    ck_assert_int_eq(result.bits[3], 0b00000000000110000000000000000000);
}
END_TEST

START_TEST(my_div_12) {
    my_decimal src1, src2, result;
    //    src1 = 7643756032
    src1.bits[0] = 0b00010001100000110100010101000111;
    src1.bits[1] = 0b00000000000000101011011100110010;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000001010000000000000000;
    //    src2 = 934562240
    src2.bits[0] = 0b01111001000001000011011001001011;
    src2.bits[1] = 0b00000000000000000101010011111111;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000001010000000000000000;
    //    result = 8.178969
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b01000111110000001001001101101010);
    ck_assert_int_eq(result.bits[1], 0b10111000000101111000101110100000);
    ck_assert_int_eq(result.bits[2], 0b00011010011011010111110000110100);
    ck_assert_int_eq(result.bits[3], 0b00000000000110110000000000000000);
}
END_TEST

START_TEST(my_div_13) {
    my_decimal src1, src2, result;
    //    src1 = 2
    src1.bits[0] = 0b00000000000000000000000000000010;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 3
    src2.bits[0] = 0b00000000000000000000000000000011;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = 0.666667
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b01101010101010101010101010101010);
    ck_assert_int_eq(result.bits[1], 0b10011110010011000000111111011100);
    ck_assert_int_eq(result.bits[2], 0b11010111011010010101111111001001);
    ck_assert_int_eq(result.bits[3], 0b00000000000111010000000000000000);
}
END_TEST

START_TEST(my_div_14) {
    my_decimal src1, src2, result;
    //    src1 = 3
    src1.bits[0] = 0b00000000000000000000000000000011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 2
    src2.bits[0] = 0b00000000000000000000000000000010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = 1.5
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000001111);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000010000000000000000);
}
END_TEST

START_TEST(my_div_15) {
    my_decimal src1, src2, result;
    //    src1 = 0
    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 3
    src2.bits[0] = 0b00000000000000000000000000000011;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = 0
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_div_16) {
    my_decimal src1, src2, result;
    //    src1 = 2
    src1.bits[0] = 0b00000000000000000000000000000010;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 0.1
    src2.bits[0] = 0b00000000000000000000000000000001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000010000000000000000;
    //    result = 20
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000010100);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_div_17) {
    my_decimal src1, src2, result;
    //    src1 = -0.0
    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000010000000000000000;
    //    src2 = 3
    src2.bits[0] = 0b00000000000000000000000000000011;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = -0
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_div_18) {
    my_decimal src1, src2, origin, result;
    //  src1 = 2;
    src1.bits[0] = 0b00000000000000000000000000000010;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = -0.45;
    src2.bits[0] = 0b00000000000000000000000000101101;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000100000000000000000;

    origin.bits[0] = 0b10011100011100011100011100011100;
    origin.bits[1] = 0b00010100001100101011010100111101;
    origin.bits[2] = 0b10001111100110111001010100110001;
    origin.bits[3] = 0b10000000000111000000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_19) {
    my_decimal src1, src2, origin, result;
    //  src1 = 6521;
    src1.bits[0] = 0b00000000000000000001100101111001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = 74121;
    src2.bits[0] = 0b00000000000000010010000110001001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b00001001100111101111101101111111;
    origin.bits[1] = 0b10011001100100101100010001100100;
    origin.bits[2] = 0b00011100011011010101100110101001;
    origin.bits[3] = 0b00000000000111010000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_20) {
    my_decimal src1, src2, origin, result;
    //  src1 = 4;
    src1.bits[0] = 0b00000000000000000000000000000100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = 97623320;
    src2.bits[0] = 0b00000101110100011001110100011011;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    my_div(src1, src2, &result);

    origin.bits[0] = 0b11101101000100010010010001110010;
    origin.bits[1] = 0b00011110100101110110001101111011;
    origin.bits[2] = 0b00000000000000000000000011011110;
    origin.bits[3] = 0b00000000000111010000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_21) {
    my_decimal src1, src2, origin, result;
    //  src1 = 65658654;
    src1.bits[0] = 0b00000011111010011101111100011110;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = 5;
    src2.bits[0] = 0b00000000000000000000000000000101;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b00000111110100111011111000111100;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000010000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_22) {
    my_decimal src1, src2, origin, result;
    //  src1 = -364748;
    src1.bits[0] = 0b00000000000001011001000011001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //  src2 = 1;
    src2.bits[0] = 0b00000000000000000000000000000001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b00000000000001011001000011001100;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_23) {
    my_decimal src1, src2, origin, result;
    //  src1 = 1;
    src1.bits[0] = 0b00000000000000000000000000000001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = 98745655296;
    src2.bits[0] = 0b11111101101100110001110000110001;
    src2.bits[1] = 0b00000000000000000000000000010110;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b01001011100101000110101001110101;
    origin.bits[1] = 0b00001110000011011101011111010011;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000111010000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_24) {
    my_decimal src1, src2, origin, result;
    //  src1 = -9878798336;
    src1.bits[0] = 0b01001100110100101000000111000101;
    src1.bits[1] = 0b00000000000000000000000000000010;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //  src2 = -3;
    src2.bits[0] = 0b00000000000000000000000000000011;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000000000000000000000;

    origin.bits[0] = 0b00000010100000101010101010101010;
    origin.bits[1] = 0b00011000110010011011111011000100;
    origin.bits[2] = 0b01101010011001101000000010110110;
    origin.bits[3] = 0b00000000000100110000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_25) {
    my_decimal src1, src2, origin, result;
    //  src1 = 9999999999999999999;
    src1.bits[0] = 0b10001001111001111111111111111111;
    src1.bits[1] = 0b10001010110001110010001100000100;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = 1;
    src2.bits[0] = 0b00000000000000000000000000000001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b10001001111001111111111111111111;
    origin.bits[1] = 0b10001010110001110010001100000100;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_26) {
    my_decimal src1, src2, origin, result;
    //  src1 = 18446744073709551615.0;
    src1.bits[0] = 0b11111111111111111111111111110110;
    src1.bits[1] = 0b11111111111111111111111111111111;
    src1.bits[2] = 0b00000000000000000000000000001001;
    src1.bits[3] = 0b00000000000000010000000000000000;
    //  src2 = 965453154;
    src2.bits[0] = 0b00111001100010111010010101100010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b10001010010011110101000101010001;
    origin.bits[1] = 0b00010010001101000001111111010011;
    origin.bits[2] = 0b00111101101111001100101101111101;
    origin.bits[3] = 0b00000000000100100000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_27) {
    my_decimal src1, src2, origin, result;
    //  src1 = -545454512454545.35265454545645;
    src1.bits[0] = 0b10000010111000100101101011101101;
    src1.bits[1] = 0b11111001111010000010010110101101;
    src1.bits[2] = 0b10110000001111101111000010010100;
    src1.bits[3] = 0b10000000000011100000000000000000;
    //  src2 = 54564656;
    src2.bits[0] = 0b00000011010000001001011100101110;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b01111001011111001100111101000011;
    origin.bits[1] = 0b01101111110101101111010000100100;
    origin.bits[2] = 0b00100000010011001110010100100010;
    origin.bits[3] = 0b10000000000101010000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_28) {
    my_decimal src1, src2, origin, result;
    //  src1 = -545454512454545.35265454545645;
    src1.bits[0] = 0b10000010111000100101101011101101;
    src1.bits[1] = 0b11111001111010000010010110101101;
    src1.bits[2] = 0b10110000001111101111000010010100;
    src1.bits[3] = 0b10000000000011100000000000000000;
    //  src2 = -5.352654545456454545645464;
    src2.bits[0] = 0b01001000000110110001111110011000;
    src2.bits[1] = 0b11111011111111011000100101101101;
    src2.bits[2] = 0b00000000000001000110110101110111;
    src2.bits[3] = 0b10000000000110000000000000000000;

    origin.bits[0] = 0b01010101000010101110100101100100;
    origin.bits[1] = 0b11111001111111011000101011010011;
    origin.bits[2] = 0b00100000111011010100001110100111;
    origin.bits[3] = 0b00000000000011100000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_29) {
    my_decimal src1, src2, origin, result;
    //  src1 = 7961327845421.879754123131254;
    src1.bits[0] = 0b01001110111001000011100101110110;
    src1.bits[1] = 0b01001011001101011010000111011001;
    src1.bits[2] = 0b00011001101110010111010010111111;
    src1.bits[3] = 0b00000000000011110000000000000000;
    //  src2 = -0.78;
    src2.bits[0] = 0b00000000000000000000000001001110;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000100000000000000000;

    origin.bits[0] = 0b11101110111111010011010111111001;
    origin.bits[1] = 0b11110111011001011001010001101011;
    origin.bits[2] = 0b00100000111110101110010001110001;
    origin.bits[3] = 0b10000000000011110000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_30) {
    my_decimal src1, src2, origin, result;
    //  src1 = 79228162514264337593543950335;
    src1.bits[0] = 0b11111111111111111111111111111111;
    src1.bits[1] = 0b11111111111111111111111111111111;
    src1.bits[2] = 0b11111111111111111111111111111111;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = -79228162514264337593543950335;
    src2.bits[0] = 0b11111111111111111111111111111111;
    src2.bits[1] = 0b11111111111111111111111111111111;
    src2.bits[2] = 0b11111111111111111111111111111111;
    src2.bits[3] = 0b10000000000000000000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_31) {
    my_decimal src1, src2, origin, result;
    //  src1 = 0.0000000000000000000000000001;
    src1.bits[0] = 0b00000000000000000000000000000001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000111000000000000000000;
    //  src2 = 0.01;
    src2.bits[0] = 0b00000000000000000000000000000001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000100000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000110100000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_32) {
    my_decimal src1, src2, origin, result;
    //  src1 = 0.00000000000000000005;
    src1.bits[0] = 0b00000000000000000000000000000101;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000101000000000000000000;
    //  src2 = 0.0000000000345;
    src2.bits[0] = 0b00000000000000000000000101011001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000011010000000000000000;

    origin.bits[0] = 0b00001010000000001110110101110011;
    origin.bits[1] = 0b11011011010001100000101001011000;
    origin.bits[2] = 0b00000000000000000000000000000111;
    origin.bits[3] = 0b00000000000111010000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_33) {
    my_decimal src1, src2, origin, result;
    //  src1 = 0.0000000000000000000000001567;
    src1.bits[0] = 0b00000000000000000000011000011111;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000111000000000000000000;
    //  src2 = 0.000800090769;
    src2.bits[0] = 0b00101111101100000110101010010001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000011000000000000000000;

    origin.bits[0] = 0b00000001001010101101100011111101;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000111010000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_div_34) {
    my_decimal src1, src2, origin, result;
    //  src1 = 0.0000000000000000000000000001;
    src1.bits[0] = 0b00000000000000000000000000000001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000111000000000000000000;
    //  src2 = 0.0000000000000000000000000001;
    src2.bits[0] = 0b00000000000000000000000000000001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000111000000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_div(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_1) {
    my_decimal src1, src2, origin, result;
    //  src1 = 5;
    src1.bits[0] = 0b00000000000000000000000000000101;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = 3;
    src2.bits[0] = 0b00000000000000000000000000000011;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_2) {
    my_decimal src1, src2, origin, result;
    //  src1 = 3;
    src1.bits[0] = 0b00000000000000000000000000000011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = 2;
    src2.bits[0] = 0b00000000000000000000000000000010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_3) {
    my_decimal src1, src2, origin, result;
    //  src1 = 0;
    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = 3;
    src2.bits[0] = 0b00000000000000000000000000000011;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_4) {
    my_decimal src1, src2, origin, result;
    //  src1 = 2;
    src1.bits[0] = 0b00000000000000000000000000000010;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = 0.1;
    src2.bits[0] = 0b00000000000000000000000000000001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000010000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000010000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_5) {
    my_decimal src1, src2, origin, result;
    //  src1 = 2;
    src1.bits[0] = 0b00000000000000000000000000000010;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = -0.45;
    src2.bits[0] = 0b00000000000000000000000000101101;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000100000000000000000;

    origin.bits[0] = 0b00000000000000000000000000010100;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000100000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_6) {
    my_decimal src1, src2, origin, result;
    //  src1 = 6521;
    src1.bits[0] = 0b00000000000000000001100101111001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = 74121;
    src2.bits[0] = 0b00000000000000010010000110001001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b00000000000000000001100101111001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_7) {
    my_decimal src1, src2, origin, result;
    //  src1 = 4;
    src1.bits[0] = 0b00000000000000000000000000000100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = 97623323;
    src2.bits[0] = 0b00000101110100011001110100011011;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000100;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_8) {
    my_decimal src1, src2, origin, result;
    //  src1 = 65658654;
    src1.bits[0] = 0b00000011111010011101111100011110;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = 5;
    src2.bits[0] = 0b00000000000000000000000000000101;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000100;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_9) {
    my_decimal src1, src2, origin, result;
    //  src1 = -364748;
    src1.bits[0] = 0b00000000000001011001000011001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //  src2 = 1;
    src2.bits[0] = 0b00000000000000000000000000000001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_10) {
    my_decimal src1, src2, origin, result;
    //  src1 = 1;
    src1.bits[0] = 0b00000000000000000000000000000001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = 98745654321;
    src2.bits[0] = 0b11111101101100110001110000110001;
    src2.bits[1] = 0b00000000000000000000000000010110;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_11) {
    my_decimal src1, src2, origin, result;
    //  src1 = -9878798789;
    src1.bits[0] = 0b01001100110100101000000111000101;
    src1.bits[1] = 0b00000000000000000000000000000010;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //  src2 = -3;
    src2.bits[0] = 0b00000000000000000000000000000011;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000000000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000010;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_12) {
    my_decimal src1, src2, origin, result;
    //  src1 = 18446744073709551615;
    src1.bits[0] = 0b11111111111111111111111111111111;
    src1.bits[1] = 0b11111111111111111111111111111111;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = 1;
    src2.bits[0] = 0b00000000000000000000000000000001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_13) {
    my_decimal src1, src2, origin, result;
    //  src1 = 18446744073709551615.0;
    src1.bits[0] = 0b11111111111111111111111111110110;
    src1.bits[1] = 0b11111111111111111111111111111111;
    src1.bits[2] = 0b00000000000000000000000000001001;
    src1.bits[3] = 0b00000000000000010000000000000000;
    //  src2 = 965453154;
    src2.bits[0] = 0b00111001100010111010010101100010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b10101010000010000011011000010110;
    origin.bits[1] = 0b00000000000000000000000000000001;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000010000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_14) {
    my_decimal src1, src2, origin, result;
    //  src1 = -545454512454545.35265454545645;
    src1.bits[0] = 0b10000010111000100101101011101101;
    src1.bits[1] = 0b11111001111010000010010110101101;
    src1.bits[2] = 0b10110000001111101111000010010100;
    src1.bits[3] = 0b10000000000011100000000000000000;
    //  src2 = 54564654;
    src2.bits[0] = 0b00000011010000001001011100101110;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;

    origin.bits[0] = 0b10111101010000100101101011101101;
    origin.bits[1] = 0b00001001111110101010011110000010;
    origin.bits[2] = 0b00000000000000000000000011011001;
    origin.bits[3] = 0b10000000000011100000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_15) {
    my_decimal src1, src2, origin, result;
    //  src1 = 7961327845421.879754123131254;
    src1.bits[0] = 0b01001110111001000011100101110110;
    src1.bits[1] = 0b01001011001101011010000111011001;
    src1.bits[2] = 0b00011001101110010111010010111111;
    src1.bits[3] = 0b00000000000011110000000000000000;
    //  src2 = -0.78;
    src2.bits[0] = 0b00000000000000000000000001001110;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000100000000000000000;

    origin.bits[0] = 0b01001100110001100111100101110110;
    origin.bits[1] = 0b00000000000000011110101011100111;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000011110000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_16) {
    my_decimal src1, src2, origin, result;
    //  src1 = 12345677.987654345678987654346;
    src1.bits[0] = 0b10010001000010101111010011001010;
    src1.bits[1] = 0b11000000010001011101010111110010;
    src1.bits[2] = 0b00100111111001000001101100000000;
    src1.bits[3] = 0b00000000000101010000000000000000;
    //  src2 = 87654323456.9876545678987653;
    src2.bits[0] = 0b00010001110011011101000110000101;
    src2.bits[1] = 0b11110101101111000110111111000000;
    src2.bits[2] = 0b00000010110101010000111100111111;
    src2.bits[3] = 0b00000000000100000000000000000000;

    origin.bits[0] = 0b10110110011001101100010101110100;
    origin.bits[1] = 0b10011010111111101001101110101001;
    origin.bits[2] = 0b00000000000000000001101000100100;
    origin.bits[3] = 0b00000000000100000000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_17) {
    my_decimal src1, src2, origin, result;
    //  src1 = -12345677.987654345678987654346;
    src1.bits[0] = 0b10010001000010101111010011001010;
    src1.bits[1] = 0b11000000010001011101010111110010;
    src1.bits[2] = 0b00100111111001000001101100000000;
    src1.bits[3] = 0b10000000000101010000000000000000;
    //  src2 = 87654323456.9876545678987653;
    src2.bits[0] = 0b00010001110011011101000110000101;
    src2.bits[1] = 0b11110101101111000110111111000000;
    src2.bits[2] = 0b00000010110101010000111100111111;
    src2.bits[3] = 0b00000000000100000000000000000000;

    origin.bits[0] = 0b10110110011001101100010101110100;
    origin.bits[1] = 0b10011010111111101001101110101001;
    origin.bits[2] = 0b00000000000000000001101000100100;
    origin.bits[3] = 0b10000000000100000000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_18) {
    my_decimal src1, src2, origin, result;
    //  src1 = 1;
    src1.bits[0] = 0b00000000000000000000000000000001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //  src2 = -1;
    src2.bits[0] = 0b00000000000000000000000000000001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000000000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000000;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_19) {
    my_decimal src1, src2, origin, result;
    //  src1 = 0.0000000000000000000000000001;
    src1.bits[0] = 0b00000000000000000000000000000001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000111000000000000000000;
    //  src2 = 0.00000000001000010001;
    src2.bits[0] = 0b00111011100110101111000100010001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000101000000000000000000;

    origin.bits[0] = 0b00000000000000000000000000000001;
    origin.bits[1] = 0b00000000000000000000000000000000;
    origin.bits[2] = 0b00000000000000000000000000000000;
    origin.bits[3] = 0b00000000000111000000000000000000;
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(my_mod_20) {
    my_decimal src1, src2, result;
    //    src1 = 3
    src1.bits[0] = 0b00000000000000000000000000000011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 2
    src2.bits[0] = 0b00000000000000000000000000000010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = 1
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000001);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_mod_21) {
    my_decimal src1, src2, result;
    //    src1 = -98765
    src1.bits[0] = 0b00000000000000011000000111001101;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = 1234
    src2.bits[0] = 0b00000000000000000000010011010010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = -45
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000101101);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_mod_22) {
    my_decimal src1, src2, result;
    //    src1 = 30198
    src1.bits[0] = 0b00000000000000000111010111110110;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 20210
    src2.bits[0] = 0b00000000000000000100111011110010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = 9988
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000010011100000100);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_mod_23) {
    my_decimal src1, src2, result;
    //    src1 = -98765
    src1.bits[0] = 0b00000000000000011000000111001101;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    //    src2 = -1234
    src2.bits[0] = 0b00000000000000000000010011010010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000000000000000000000;
    //    result = -45
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000101101);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(my_mod_24) {
    my_decimal src1, src2, result;
    //    src1 = 98765
    src1.bits[0] = 0b00000000000000011000000111001101;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 127234
    src2.bits[0] = 0b00000000000000011111000100000010;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = 98765
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000011000000111001101);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_mod_25) {
    my_decimal src1, src2, result;
    //    src1 = 342576
    src1.bits[0] = 0b00000000000001010011101000110000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    //    src2 = 1542134
    src2.bits[0] = 0b00000000000101111000011111110110;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = 342576
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000001010011101000110000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_mod_26) {
    my_decimal src1, src2, result;
    //    src1 = 1.2
    src1.bits[0] = 0b00000000000000000000000000001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000010000000000000000;
    //    src2 = 0.3
    src2.bits[0] = 0b00000000000000000000000000000011;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000010000000000000000;
    //    result = 342576
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000010000000000000000);
}
END_TEST

START_TEST(my_mod_27) {
    my_decimal src1, src2, result;
    //    src1 = 1.2
    src1.bits[0] = 0b00000000000000000000000000001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000010000000000000000;
    //    src2 = 3
    src2.bits[0] = 0b00000000000000000000000000000011;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    //    result = 1.2
    ck_assert_int_eq(my_mod(src1, src2, &result), 0);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000001100);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000010000000000000000);
}
END_TEST

START_TEST(my_mod_28) {
    my_decimal src1, src2, result;
    //    src1 = 1.2
    src1.bits[0] = 0b00000000000000000000000000001100;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000010000000000000000;
    //    src2 = -0
    src2.bits[0] = 0b00000000000000000000000000000000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b10000000000000000000000000000000;
    //    result = 1.2
    ck_assert_int_eq(my_mod(src1, src2, &result), 3);
    ck_assert_int_eq(result.bits[0], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[1], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[2], 0b00000000000000000000000000000000);
    ck_assert_int_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(my_less) {                         //  0 - false, 1 - true
    my_decimal value_1, value_2;

    my_from_float_to_decimal(1.2345, &value_1);
    my_from_float_to_decimal(1.2, &value_2);
    // 1.2345 < 1.2
    ck_assert_int_eq(my_is_less(value_1, value_2), 0);
    // 1.2 < 1.2345
    ck_assert_int_eq(my_is_less(value_2, value_1), 1);
    my_from_float_to_decimal(-1.2345, &value_1);
    my_from_float_to_decimal(-1.2, &value_2);
    // -1.2345 < -1.2
    ck_assert_int_eq(my_is_less(value_1, value_2), 1);
    // -1.2 < -1.2345
    ck_assert_int_eq(my_is_less(value_2, value_1), 0);
    my_from_float_to_decimal(1.2345, &value_1);
    my_from_float_to_decimal(-1.2, &value_2);
    //  1.2345 < -1.2
    ck_assert_int_eq(my_is_less(value_1, value_2), 0);
    //  -1.2 < 1.2345
    ck_assert_int_eq(my_is_less(value_2, value_1), 1);
    my_init_zero_decimal(&value_1);
    my_init_zero_decimal(&value_2);
    // 0 < 0
    ck_assert_int_eq(my_is_less(value_1, value_2), 0);
    my_from_float_to_decimal(9403, &value_1);
    my_from_float_to_decimal(20209000000, &value_2);
    //  9403 < 20209000000
    ck_assert_int_eq(my_is_less(value_1, value_2), 1);
    //  20209000000 < 9403
    ck_assert_int_eq(my_is_less(value_2, value_1), 0);
    my_from_float_to_decimal(281474957312, &value_1);
    my_from_float_to_decimal(1759217.75, &value_2);
    //  281474957312 < 1759217.75
    ck_assert_int_eq(my_is_less(value_1, value_2), 0);
    //  1759217.75 < 281474957312
    ck_assert_int_eq(my_is_less(value_2, value_1), 1);
}
END_TEST

START_TEST(my_greater) {                    //  0 - false, 1 - true
    my_decimal value_1, value_2;

    my_from_float_to_decimal(1.2345, &value_1);
    my_from_float_to_decimal(1.2, &value_2);
    // 1.2345 > 1.2
    ck_assert_int_eq(my_is_greater(value_1, value_2), 1);
    // 1.2 > 1.2345
    ck_assert_int_eq(my_is_greater(value_2, value_1), 0);
    my_negate(value_1, &value_1);
    my_negate(value_2, &value_2);
    // -1.2345 > -1.2
    ck_assert_int_eq(my_is_greater(value_1, value_2), 0);
    // -1.2 > 1.2345
    ck_assert_int_eq(my_is_greater(value_2, value_1), 1);
    my_negate(value_1, &value_1);
    //  1.2345 > -1.2
    ck_assert_int_eq(my_is_greater(value_1, value_2), 1);
    //  -1.2 > 1.2345
    ck_assert_int_eq(my_is_greater(value_2, value_1), 0);

    my_from_float_to_decimal(0.0, &value_1);
    my_from_float_to_decimal(0.0, &value_2);
    // 0 > 0
    ck_assert_int_eq(my_is_greater(value_1, value_2), 0);
}
END_TEST

START_TEST(my_less_or_equal) {               //  0 - false, 1 - true
    my_decimal value_1, value_2;

    my_from_float_to_decimal(1.2345, &value_1);
    my_from_float_to_decimal(1.2, &value_2);
    // 1.2345 <= 1.2
    ck_assert_int_eq(my_is_less_or_equal(value_1, value_2), 0);
    // 1.2 <= 1.2345
    ck_assert_int_eq(my_is_less_or_equal(value_2, value_1), 1);
    my_negate(value_1, &value_1);
    my_negate(value_2, &value_2);
    // -1.2345 <= -1.2
    ck_assert_int_eq(my_is_less_or_equal(value_1, value_2), 1);
    // -1.2 <= 1.2345
    ck_assert_int_eq(my_is_less_or_equal(value_2, value_1), 0);
    my_negate(value_1, &value_1);
    //  1.2345 <= -1.2
    ck_assert_int_eq(my_is_less_or_equal(value_1, value_2), 0);
    //  -1.2 <= 1.2345
    ck_assert_int_eq(my_is_less_or_equal(value_2, value_1), 1);
    // 0 <= 0
    my_from_float_to_decimal(0.0, &value_1);
    my_from_float_to_decimal(0.0, &value_2);
    ck_assert_int_eq(my_is_less_or_equal(value_1, value_2), 1);
    // 1726.73 <= 1726.73
    my_from_float_to_decimal(1726.73, &value_1);
    my_from_float_to_decimal(1726.73, &value_2);
    ck_assert_int_eq(my_is_less_or_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(my_greater_or_equal) {                //  0 - false, 1 - true
    my_decimal value_1, value_2;

    my_from_float_to_decimal(1.2345, &value_1);
    my_from_float_to_decimal(1.2, &value_2);
    // 1.2345 >= 1.2
    ck_assert_int_eq(my_is_greater_or_equal(value_1, value_2), 1);
    // 1.2 >= 1.2345
    ck_assert_int_eq(my_is_greater_or_equal(value_2, value_1), 0);

    my_negate(value_1, &value_1);
    my_negate(value_2, &value_2);
    // -1.2345 >= -1.2
    ck_assert_int_eq(my_is_greater_or_equal(value_1, value_2), 0);
    // -1.2 >= 1.2345
    ck_assert_int_eq(my_is_greater_or_equal(value_2, value_1), 1);

    my_negate(value_1, &value_1);
    //  1.2345 >= -1.2
    ck_assert_int_eq(my_is_greater_or_equal(value_1, value_2), 1);
    //  -1.2 >= 1.2345
    ck_assert_int_eq(my_is_greater_or_equal(value_2, value_1), 0);
    // 0 >= 0
    my_from_float_to_decimal(0.0, &value_1);
    my_from_float_to_decimal(0.0, &value_2);
    ck_assert_int_eq(my_is_greater_or_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(my_equal) {                                                   //  0 - false, 1 - true
    my_decimal value_1, value_2;
    // 1.2345 = 1.2
    my_from_float_to_decimal(1.2345, &value_1);
    my_from_float_to_decimal(1.2, &value_2);
    ck_assert_int_eq(my_is_equal(value_1, value_2), 0);
    // 1.2 = 1.2
    my_from_float_to_decimal(1.2, &value_1);
    my_from_float_to_decimal(1.2, &value_2);
    ck_assert_int_eq(my_is_equal(value_1, value_2), 1);
    //  -234.17 == 234.17
    my_from_float_to_decimal(-234.17, &value_1);
    my_from_float_to_decimal(234.17, &value_2);
    ck_assert_int_eq(my_is_equal(value_1, value_2), 0);
    //  234.17 == 234.17
    my_from_float_to_decimal(234.17, &value_1);
    my_from_float_to_decimal(234.17, &value_2);
    ck_assert_int_eq(my_is_equal(value_1, value_2), 1);
    // -0 == 0
    my_from_int_to_decimal(0, &value_1);
    my_from_int_to_decimal(0, &value_2);
    value_1.bits[3] = 0x80000000;
    ck_assert_int_eq(my_is_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(my_not_equal) {              //  0 - false, 1 - true
    my_decimal value_1, value_2;
    // 1.2345 != 1.2
    my_from_float_to_decimal(1.2345, &value_1);
    my_from_float_to_decimal(1.2, &value_2);
    ck_assert_int_eq(my_is_not_equal(value_1, value_2), 1);
    // 1.2 != 1.2
    my_from_float_to_decimal(1.2, &value_1);
    my_from_float_to_decimal(1.2, &value_2);
    ck_assert_int_eq(my_is_not_equal(value_1, value_2), 0);
    // -234.17 != 234.17
    my_from_float_to_decimal(-234.17, &value_1);
    my_from_float_to_decimal(234.17, &value_2);
    ck_assert_int_eq(my_is_not_equal(value_1, value_2), 1);
    // 234.17 != 234.17
    my_from_float_to_decimal(234.17, &value_1);
    my_from_float_to_decimal(234.17, &value_2);
    ck_assert_int_eq(my_is_not_equal(value_1, value_2), 0);
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Suite");
    SRunner *sr = srunner_create(s1);
    int nf;

    TCase *tc1_1 = tcase_create("tests");
    suite_add_tcase(s1, tc1_1);

    tcase_add_test(tc1_1, my_from_int_to_decimal_1);
    tcase_add_test(tc1_1, my_from_int_to_decimal_2);
    tcase_add_test(tc1_1, my_from_int_to_decimal_3);
    tcase_add_test(tc1_1, my_from_int_to_decimal_4);
    tcase_add_test(tc1_1, my_from_int_to_decimal_5);

    tcase_add_test(tc1_1, my_from_float_to_decimal_1);
    tcase_add_test(tc1_1, my_from_float_to_decimal_2);
    tcase_add_test(tc1_1, my_from_float_to_decimal_3);
    tcase_add_test(tc1_1, my_from_float_to_decimal_4);
    tcase_add_test(tc1_1, my_from_float_to_decimal_5);
    tcase_add_test(tc1_1, my_from_float_to_decimal_6);
    tcase_add_test(tc1_1, my_from_float_to_decimal_7);
    tcase_add_test(tc1_1, my_from_float_to_decimal_8);
    tcase_add_test(tc1_1, my_from_float_to_decimal_9);
    tcase_add_test(tc1_1, my_from_float_to_decimal_10);
    tcase_add_test(tc1_1, my_from_float_to_decimal_11);
    tcase_add_test(tc1_1, my_from_float_to_decimal_12);
    tcase_add_test(tc1_1, my_from_float_to_decimal_13);
    tcase_add_test(tc1_1, my_from_float_to_decimal_14);

    tcase_add_test(tc1_1, my_from_decimal_to_float_1);
    tcase_add_test(tc1_1, my_from_decimal_to_float_2);
    tcase_add_test(tc1_1, my_from_decimal_to_float_3);
    tcase_add_test(tc1_1, my_from_decimal_to_float_4);
    tcase_add_test(tc1_1, my_from_decimal_to_float_5);
    tcase_add_test(tc1_1, my_from_decimal_to_float_6);
    tcase_add_test(tc1_1, my_from_decimal_to_float_7);
    tcase_add_test(tc1_1, my_from_decimal_to_float_8);

    tcase_add_test(tc1_1, my_from_decimal_to_int_1);
    tcase_add_test(tc1_1, my_from_decimal_to_int_2);
    tcase_add_test(tc1_1, my_from_decimal_to_int_3);
    tcase_add_test(tc1_1, my_from_decimal_to_int_4);
    tcase_add_test(tc1_1, my_from_decimal_to_int_5);
    tcase_add_test(tc1_1, my_from_decimal_to_int_6);
    tcase_add_test(tc1_1, my_from_decimal_to_int_7);

    tcase_add_test(tc1_1, my_negate_1);
    tcase_add_test(tc1_1, my_negate_2);
    tcase_add_test(tc1_1, my_negate_3);
    tcase_add_test(tc1_1, my_negate_4);
    tcase_add_test(tc1_1, my_negate_5);
    tcase_add_test(tc1_1, my_negate_6);
    tcase_add_test(tc1_1, my_negate_7);
    tcase_add_test(tc1_1, my_negate_8);

    tcase_add_test(tc1_1, my_round1);
    tcase_add_test(tc1_1, my_round2);
    tcase_add_test(tc1_1, my_round3);
    tcase_add_test(tc1_1, my_round4);
    tcase_add_test(tc1_1, my_round5);
    tcase_add_test(tc1_1, my_round6);
    tcase_add_test(tc1_1, my_round7);
    tcase_add_test(tc1_1, my_round8);
    tcase_add_test(tc1_1, my_round9);
    tcase_add_test(tc1_1, my_round10);
    tcase_add_test(tc1_1, my_round11);
    tcase_add_test(tc1_1, my_round12);
    tcase_add_test(tc1_1, my_round13);
    tcase_add_test(tc1_1, my_round14);
    tcase_add_test(tc1_1, my_round15);
    tcase_add_test(tc1_1, my_round16);
    tcase_add_test(tc1_1, my_round17);
    tcase_add_test(tc1_1, my_round18);
    tcase_add_test(tc1_1, my_round19);

    tcase_add_test(tc1_1, my_truncate1);
    tcase_add_test(tc1_1, my_truncate2);
    tcase_add_test(tc1_1, my_truncate3);
    tcase_add_test(tc1_1, my_truncate4);
    tcase_add_test(tc1_1, my_truncate5);
    tcase_add_test(tc1_1, my_truncate6);
    tcase_add_test(tc1_1, my_truncate7);
    tcase_add_test(tc1_1, my_truncate8);
    tcase_add_test(tc1_1, my_truncate9);
    tcase_add_test(tc1_1, my_truncate10);
    tcase_add_test(tc1_1, my_truncate11);
    tcase_add_test(tc1_1, my_truncate12);
    tcase_add_test(tc1_1, my_truncate13);
    tcase_add_test(tc1_1, my_truncate14);

    tcase_add_test(tc1_1, my_floor_1);
    tcase_add_test(tc1_1, my_floor_2);
    tcase_add_test(tc1_1, my_floor_3);
    tcase_add_test(tc1_1, my_floor_4);
    tcase_add_test(tc1_1, my_floor_5);
    tcase_add_test(tc1_1, my_floor_6);
    tcase_add_test(tc1_1, my_floor_7);
    tcase_add_test(tc1_1, my_floor_8);
    tcase_add_test(tc1_1, my_floor_9);
    tcase_add_test(tc1_1, my_floor_10);
    tcase_add_test(tc1_1, my_floor_11);
    tcase_add_test(tc1_1, my_floor_12);
    tcase_add_test(tc1_1, my_floor_13);
    tcase_add_test(tc1_1, my_floor_14);

    tcase_add_test(tc1_1, my_add_1);
    tcase_add_test(tc1_1, my_add_2);
    tcase_add_test(tc1_1, my_add_3);
    tcase_add_test(tc1_1, my_add_4);
    tcase_add_test(tc1_1, my_add_5);
    tcase_add_test(tc1_1, my_add_6);
    tcase_add_test(tc1_1, my_add_7);
    tcase_add_test(tc1_1, my_add_8);
    tcase_add_test(tc1_1, my_add_9);
    tcase_add_test(tc1_1, my_add_10);
    tcase_add_test(tc1_1, my_add_11);
    tcase_add_test(tc1_1, my_add_12);
    tcase_add_test(tc1_1, my_add_13);
    tcase_add_test(tc1_1, my_add_14);
    tcase_add_test(tc1_1, my_add_15);
    tcase_add_test(tc1_1, my_add_16);
    tcase_add_test(tc1_1, my_add_17);
    tcase_add_test(tc1_1, my_add_18);
    tcase_add_test(tc1_1, my_add_19);
    tcase_add_test(tc1_1, my_add_20);

    tcase_add_test(tc1_1, my_sub_1);
    tcase_add_test(tc1_1, my_sub_2);
    tcase_add_test(tc1_1, my_sub_3);
    tcase_add_test(tc1_1, my_sub_4);
    tcase_add_test(tc1_1, my_sub_5);
    tcase_add_test(tc1_1, my_sub_6);
    tcase_add_test(tc1_1, my_sub_7);
    tcase_add_test(tc1_1, my_sub_8);
    tcase_add_test(tc1_1, my_sub_9);
    tcase_add_test(tc1_1, my_sub_10);
    tcase_add_test(tc1_1, my_sub_11);
    tcase_add_test(tc1_1, my_sub_12);
    tcase_add_test(tc1_1, my_sub_13);
    tcase_add_test(tc1_1, my_sub_14);
    tcase_add_test(tc1_1, my_sub_15);

    tcase_add_test(tc1_1, my_mul_1);
    tcase_add_test(tc1_1, my_mul_2);
    tcase_add_test(tc1_1, my_mul_3);
    tcase_add_test(tc1_1, my_mul_4);
    tcase_add_test(tc1_1, my_mul_5);
    tcase_add_test(tc1_1, my_mul_6);
    tcase_add_test(tc1_1, my_mul_7);
    tcase_add_test(tc1_1, my_mul_8);
    tcase_add_test(tc1_1, my_mul_9);
    tcase_add_test(tc1_1, my_mul_10);
    tcase_add_test(tc1_1, my_mul_11);
    tcase_add_test(tc1_1, my_mul_12);
    tcase_add_test(tc1_1, my_mul_13);
    tcase_add_test(tc1_1, my_mul_14);

    tcase_add_test(tc1_1, my_div_1);
    tcase_add_test(tc1_1, my_div_2);
    tcase_add_test(tc1_1, my_div_3);
    tcase_add_test(tc1_1, my_div_4);
    tcase_add_test(tc1_1, my_div_5);
    tcase_add_test(tc1_1, my_div_6);
    tcase_add_test(tc1_1, my_div_7);
    tcase_add_test(tc1_1, my_div_8);
    tcase_add_test(tc1_1, my_div_9);
    tcase_add_test(tc1_1, my_div_10);
    tcase_add_test(tc1_1, my_div_11);
    tcase_add_test(tc1_1, my_div_12);
    tcase_add_test(tc1_1, my_div_13);
    tcase_add_test(tc1_1, my_div_14);
    tcase_add_test(tc1_1, my_div_15);
    tcase_add_test(tc1_1, my_div_16);
    tcase_add_test(tc1_1, my_div_17);
    tcase_add_test(tc1_1, my_div_18);
    tcase_add_test(tc1_1, my_div_19);
    tcase_add_test(tc1_1, my_div_20);
    tcase_add_test(tc1_1, my_div_21);
    tcase_add_test(tc1_1, my_div_22);
    tcase_add_test(tc1_1, my_div_23);
    tcase_add_test(tc1_1, my_div_24);
    tcase_add_test(tc1_1, my_div_25);
    tcase_add_test(tc1_1, my_div_26);
    tcase_add_test(tc1_1, my_div_27);
    tcase_add_test(tc1_1, my_div_28);
    tcase_add_test(tc1_1, my_div_29);
    tcase_add_test(tc1_1, my_div_30);
    tcase_add_test(tc1_1, my_div_31);
    tcase_add_test(tc1_1, my_div_32);
    tcase_add_test(tc1_1, my_div_33);
    tcase_add_test(tc1_1, my_div_34);

    tcase_add_test(tc1_1, my_mod_1);
    tcase_add_test(tc1_1, my_mod_2);
    tcase_add_test(tc1_1, my_mod_3);
    tcase_add_test(tc1_1, my_mod_4);
    tcase_add_test(tc1_1, my_mod_5);
    tcase_add_test(tc1_1, my_mod_6);
    tcase_add_test(tc1_1, my_mod_7);
    tcase_add_test(tc1_1, my_mod_8);
    tcase_add_test(tc1_1, my_mod_9);
    tcase_add_test(tc1_1, my_mod_10);
    tcase_add_test(tc1_1, my_mod_11);
    tcase_add_test(tc1_1, my_mod_12);
    tcase_add_test(tc1_1, my_mod_13);
    tcase_add_test(tc1_1, my_mod_14);
    tcase_add_test(tc1_1, my_mod_15);
    tcase_add_test(tc1_1, my_mod_16);
    tcase_add_test(tc1_1, my_mod_17);
    tcase_add_test(tc1_1, my_mod_18);
    tcase_add_test(tc1_1, my_mod_19);
    tcase_add_test(tc1_1, my_mod_20);
    tcase_add_test(tc1_1, my_mod_21);
    tcase_add_test(tc1_1, my_mod_22);
    tcase_add_test(tc1_1, my_mod_23);
    tcase_add_test(tc1_1, my_mod_24);
    tcase_add_test(tc1_1, my_mod_25);
    tcase_add_test(tc1_1, my_mod_26);
    tcase_add_test(tc1_1, my_mod_27);
    tcase_add_test(tc1_1, my_mod_28);

    tcase_add_test(tc1_1, my_less);
    tcase_add_test(tc1_1, my_greater);
    tcase_add_test(tc1_1, my_less_or_equal);
    tcase_add_test(tc1_1, my_greater_or_equal);
    tcase_add_test(tc1_1, my_equal);
    tcase_add_test(tc1_1, my_not_equal);

    srunner_run_all(sr, CK_NORMAL);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
