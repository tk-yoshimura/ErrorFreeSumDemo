#include "kahan_sum.h"

#include <math.h>

void floatfloat_add(float& hi, float& lo, float val) {
    float tmp = hi;
    hi = (hi + lo) + val;
    lo += (tmp - hi) + val;
}

void floatfloat_sub(float& hi, float& lo, float val) {
    float tmp = hi;
    hi = (hi + lo) - val;
    lo -= (hi - tmp) + val;
}

void floatfloat_fma(float& hi, float& lo, float val_x, float val_y) {
    float tmp = hi;
    hi = fmaf(val_x, val_y, hi + lo);
    lo += fmaf(val_x, val_y, tmp - hi);
}

void floatfloat_fms(float& hi, float& lo, float val_x, float val_y) {
    float tmp = hi;
    hi = fmaf(-val_x, val_y, hi + lo);
    lo -= fmaf(val_x, val_y, hi - tmp);
}