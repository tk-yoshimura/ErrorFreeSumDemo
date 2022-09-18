#pragma once

// (hi, lo) += val
extern void floatfloat_add(float& hi, float& lo, float val);

// (hi, lo) -= val
extern void floatfloat_sub(float& hi, float& lo, float val);

// (hi, lo) += val_x * val_y
extern void floatfloat_fma(float& hi, float& lo, float val_x, float val_y);

// (hi, lo) -= val_x * val_y
extern void floatfloat_fms(float& hi, float& lo, float val_x, float val_y);