#include <assert.h>
#include <math.h>
#include "bisection.h"

// Тестова функція f(x) = sin(x)
double test_f(double x) {
    return sin(x);
}

// Тестова функція g(x) = cos(x)
double test_g(double x) {
    return cos(x);
}

void test_bisection() {
    double tol = 0.001;
    double intersection = bisection(test_f, test_g, 0, M_PI, tol);
    assert(fabs(intersection - M_PI/4) < tol);  // Перевіряємо, чи наближається до PI/4

    printf("Тест пройдено успішно!\n");
}
void run_tests() {
    // Тест 1: Перетин функцій f(x) = sin(x) та g(x) = cos(x)
    double tol = 0.01;
    double intersection = bisection(sin, cos, 0, M_PI, tol);
    assert(fabs(intersection - M_PI/4) < tol);
}
void assert() {
    test_bisection();
    return 0;
}
