#include <stdio.h>
#include <math.h>

void bresenham_line(int x1, int y1, int x2, int y2, FILE *fp)
{
    int dx = x2 - x1, dy = y2 - y1;
    if (dx == 0) {
        while (dy + 1 != 0) {
            fprintf(fp, "(%d, %d)\n", x1, y2 - dy);
            dy--;
        }
    }
    else {
        int s1 = dx == abs(dx)? 1: -1;
        int s2 = dy == abs(dy)? 1: -1;
        int e = (abs(dy) << 1) - (abs(dx) << 1);
        fprintf(fp, "(%d, %d)\n", x1, y1);
        if (abs(dx) >= abs(dy)) {
            while (x1 != x2 && y1 != y2) {
                if (e < 0) {
                    x1 += s1;
                    e += abs(dy) << 1;
                }
                else {
                    x1 += s1;
                    y1 += s2;
                    e += (abs(dy) - abs(dx)) << 1;
                }
                fprintf(fp, "(%d, %d)\n", x1, y1);
            }
        }
        else {
            while (x1 != x2 && y1 != y2) {
                if (e < 0) {
                    y1 += s2;
                    e += abs(dx) << 1;
                }
                else {
                    x1 += s1;
                    y1 += s2;
                    e += (abs(dx) - abs(dy)) << 1;
                }
                fprintf(fp, "(%d, %d)\n", x1, y1);
            }
        }
    }
}