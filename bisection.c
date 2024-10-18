#include "bisection.h"

double bisection(double (*f)(double), double (*g)(double), double a, double b, double tolerance) {
    double midpoint, f_mid, f_a;
    while ((b - a) / 2.0 > tolerance) {
        midpoint = (a + b) / 2.0;
        f_mid = f(midpoint) - g(midpoint);  // Різниця між функціями
        f_a = f(a) - g(a);                  // Різниця на лівій межі

        if (fabs(f_mid) < tolerance) {
            return midpoint;  // Знайдено точку перетину
        } else if ((f_a > 0 && f_mid < 0) || (f_a < 0 && f_mid > 0)) {
            b = midpoint;  // Зменшення правої межі
        } else {
            a = midpoint;  // Зменшення лівої межі
        }
    }
    return (a + b) / 2.0;  // Повернення наближеної точки перетину
}
