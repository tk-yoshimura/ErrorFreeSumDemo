# ErrorFreeSumDemo
 error-free summation c++ demo

## Add
```cpp
// (hi, lo) += val
void floatfloat_add(float& hi, float& lo, float val) {
    float tmp = hi;
    hi = (hi + lo) + val;
    lo += (tmp - hi) + val;
}
```

## Sub
```cpp
// (hi, lo) -= val
void floatfloat_sub(float& hi, float& lo, float val) {
    float tmp = hi;
    hi = (hi + lo) - val;
    lo -= (hi - tmp) + val;
}
```

## Fma
```cpp
// (hi, lo) += val_x * val_y
void floatfloat_fma(float& hi, float& lo, float val_x, float val_y) {
    float tmp = hi;
    hi = fmaf(val_x, val_y, hi + lo);
    lo += fmaf(val_x, val_y, tmp - hi);
}
```

## Fms
```cpp
// (hi, lo) -= val_x * val_y
void floatfloat_fms(float& hi, float& lo, float val_x, float val_y) {
    float tmp = hi;
    hi = fmaf(-val_x, val_y, hi + lo);
    lo -= fmaf(val_x, val_y, hi - tmp);
}
```
