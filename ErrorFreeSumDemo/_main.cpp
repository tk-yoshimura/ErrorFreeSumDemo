#include <iostream>
#include <random>

#include "errfree_sum.h"

int main() {
    const int N = 65536, seed = 12345678;

    float* xs = (float*)malloc(sizeof(float) * N);
    float* ys = (float*)malloc(sizeof(float) * N);

    if (xs == nullptr || ys == nullptr) {
        exit(-1);
    }

    double expected;

    std::mt19937 mt(seed);
    std::uniform_real_distribution<float> ud(-4, 4);

    for (int i = 0; i < N; i++) {
        xs[i] = ud(mt);
        ys[i] = ud(mt);
    }

    std::cout << "add" << std::endl;
    {
        expected = 0;
        for (int i = 0; i < N; i++) {
            expected += (double)xs[i];
        }

        std::cout << "expected: " << expected << std::endl;
    }
    {
        float actual = 0;
        for (int i = 0; i < N; i++) {
            actual += xs[i];
        }

        std::cout << "actual(float):      " << actual << std::endl;
        std::cout << "errord(float):      " << abs(expected - actual) << std::endl;
        std::cout << "errorf(float):      " << abs((float)expected - actual) << std::endl;
    }
    {
        float hi = 0, lo = 0;
        for (int i = 0; i < N; i++) {
            floatfloat_add(hi, lo, xs[i]);
        }

        std::cout << "actual(floatfloat): " << hi << std::endl;
        std::cout << "errord(floatfloat): " << abs(expected - hi) << std::endl;
        std::cout << "errorf(floatfloat): " << abs((float)expected - hi) << std::endl;
    }

    std::cout << "sub" << std::endl;
    {
        expected = 0;
        for (int i = 0; i < N; i++) {
            expected -= (double)ys[i];
        }

        std::cout << "expected: " << expected << std::endl;
    }
    {
        float actual = 0;
        for (int i = 0; i < N; i++) {
            actual -= ys[i];
        }

        std::cout << "actual(float):      " << actual << std::endl;
        std::cout << "errord(float):      " << abs(expected - actual) << std::endl;
        std::cout << "errorf(float):      " << abs((float)expected - actual) << std::endl;
    }
    {
        float hi = 0, lo = 0;
        for (int i = 0; i < N; i++) {
            floatfloat_sub(hi, lo, ys[i]);
        }

        std::cout << "actual(floatfloat): " << hi << std::endl;
        std::cout << "errord(floatfloat): " << abs(expected - hi) << std::endl;
        std::cout << "errorf(floatfloat): " << abs((float)expected - hi) << std::endl;
    }

    std::cout << "fma" << std::endl;
    {
        expected = 0;
        for (int i = 0; i < N; i++) {
            expected += (double)xs[i] * (double)ys[i];
        }

        std::cout << "expected: " << expected << std::endl;
    }
    {
        float actual = 0;
        for (int i = 0; i < N; i++) {
            actual = fmaf(xs[i], ys[i], actual);
        }

        std::cout << "actual(float):      " << actual << std::endl;
        std::cout << "errord(float):      " << abs(expected - actual) << std::endl;
        std::cout << "errorf(float):      " << abs((float)expected - actual) << std::endl;
    }
    {
        float hi = 0, lo = 0;
        for (int i = 0; i < N; i++) {
            floatfloat_fma(hi, lo, xs[i], ys[i]);
        }

        std::cout << "actual(floatfloat): " << hi << std::endl;
        std::cout << "errord(floatfloat): " << abs(expected - hi) << std::endl;
        std::cout << "errorf(floatfloat): " << abs((float)expected - hi) << std::endl;
    }

    std::cout << "fms" << std::endl;
    {
        expected = 0;
        for (int i = 0; i < N; i++) {
            expected -= (double)xs[i] * (double)ys[i];
        }

        std::cout << "expected: " << expected << std::endl;
    }
    {
        float actual = 0;
        for (int i = 0; i < N; i++) {
            actual = fmaf(-xs[i], ys[i], actual);
        }

        std::cout << "actual(float):      " << actual << std::endl;
        std::cout << "errord(float):      " << abs(expected - actual) << std::endl;
        std::cout << "errorf(float):      " << abs((float)expected - actual) << std::endl;
    }
    {
        float hi = 0, lo = 0;
        for (int i = 0; i < N; i++) {
            floatfloat_fms(hi, lo, xs[i], ys[i]);
        }

        std::cout << "actual(floatfloat): " << hi << std::endl;
        std::cout << "errord(floatfloat): " << abs(expected - hi) << std::endl;
        std::cout << "errorf(floatfloat): " << abs((float)expected - hi) << std::endl;
    }

    free(xs);
    free(ys);

    std::cout << "end";
    auto _ = getchar();

    return 0;
}