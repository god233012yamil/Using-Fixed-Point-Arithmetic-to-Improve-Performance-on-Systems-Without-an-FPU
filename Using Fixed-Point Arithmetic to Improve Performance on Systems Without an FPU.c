#include <stdint.h>
#include <stdio.h>
#include <time.h>

#define FIXED_POINT_SHIFT 16
#define FIXED_POINT_SCALE (1 << FIXED_POINT_SHIFT)
#define TO_FIXED_POINT(x) ((int32_t)((x) * FIXED_POINT_SCALE))
#define FROM_FIXED_POINT(x) ((x) / (float)FIXED_POINT_SCALE)

int32_t fixed_point_multiply(int32_t a, int32_t b) {
    return (int32_t)(((int64_t)a * b) >> FIXED_POINT_SHIFT);
}

void test_fixed_point() {
    int32_t a = TO_FIXED_POINT(3.25);
    int32_t b = TO_FIXED_POINT(2.5);
    int32_t result;

    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        result = fixed_point_multiply(a, b);
    }
    clock_t end = clock();
    printf("Fixed-point multiplication result: %f\n", FROM_FIXED_POINT(result));
    printf("Fixed-point time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void test_floating_point() {
    float a = 3.25;
    float b = 2.5;
    float result;

    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        result = a * b;
    }
    clock_t end = clock();
    printf("Floating-point multiplication result: %f\n", result);
    printf("Floating-point time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}


int main() {
    test_fixed_point();
    test_floating_point();
    return 0;
}