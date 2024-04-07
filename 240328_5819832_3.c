#include <stdio.h>
#define MAX_DEGREE 101

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

void print_poly(polynomial p);

polynomial poly_mult(polynomial a, polynomial b) {
    polynomial result;
    int i, j;


    result.degree = a.degree + b.degree;


    for (i = 0; i <= result.degree; i++)
        result.coef[i] = 0;


    for (i = 0; i <= a.degree; i++) {
        for (j = 0; j <= b.degree; j++) {
            result.coef[i + j] += a.coef[i] * b.coef[j];
        }
    }

    return result;
}

int main() {
    polynomial a = { 6, {7, 5, 9, 1} };
    polynomial b = { 3, {5, 2, 1, 10} };
    polynomial c;

    print_poly(a);
    print_poly(b);

    c = poly_mult(a, b);
    printf("--------------------------------\n");
    print_poly(c);

    return 0;
}

void print_poly(polynomial p) {
    for (int i = p.degree; i > 0; i--)
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    printf("%3.1f \n", p.coef[p.degree]);
}
