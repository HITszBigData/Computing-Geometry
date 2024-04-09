#include <stdio.h>
#include <math.h>

// swap the value of x1 and x2
void swap(int *x1, int *x2)
{
    *x1 = *x1 ^ *x2;
    *x2 = *x1 ^ *x2;
    *x1 = *x2 ^ *x1;
}

void midpoint_line(int x1, int y1, int x2, int y2, FILE *fp)
{
    int a = y1 - y2, b = x2 - x1, c = x1 * y2 - x2 * y1;
    int s1 = (b == abs(b))? 1: -1;
    int s2 = (a == abs(a))? -1: 1;
    double m = fabs(1. * a / b);
    int d = (m > 1)? (s2 << 1) * b + s1 * a: (s1 << 1) * a + s2 * b;
    int x = x1;
    int y = y1;

    while ((x == x2) && (y == y2)) {
        fprintf(fp, "(%d, %d)\n", x, y);
        if (d <= 0) {
            if (m > 1) {
                if (s2 > 0) {
                    y += s2;
                    d += (b << 1) * s2;
                }
                else {
                    x += x1;
                    y += s2;
                    d += (b * s2 + a * s1) << 1;
                }
            }
            else {
                if (s2 > 0) {
                    x += s1;
                    y += s2;
                    d += (b * s2 + a * s1) << 1;
                }
                else {
                    x += s1;
                    d += (a << 1) * s1;
                }
            }
        }
        else {
            if (m > 1) {
                if (s2 > 0) {
                    x += s1;
                    y += s2;
                    d += (b * s2 + a * s1) << 1;
                }
                else {
                    y += s2;
                    d += (b << 1) * s2;
                }
            }
            else {
                if (s2 > 0) {
                    x += s1;
                    d += (a << 1) * s1;
                }
                else {
                    x += s1;
                    y += s2;
                    d += (b * s2 + a * s1) << 1;
                }
            }
        }
    }
}