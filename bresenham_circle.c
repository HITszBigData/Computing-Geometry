#include <stdio.h>

void bresenham_circle(int xc, int yc, int r, FILE *fp)
{
    int x = 0, y = r;
    int delta = (1 - r) << 1;

    while (y > 0) {
        if (x == 0) {
            fprintf(fp, "(%d, %d)\n", xc, yc + y);
            fprintf(fp, "(%d, %d)\n", xc + y, yc);
            fprintf(fp, "(%d, %d)\n", xc, yc - y);
            fprintf(fp, "(%d, %d)\n", xc - y, yc);
        }
        else {
            fprintf(fp, "(%d, %d)\n", xc + x, yc + y);
            fprintf(fp, "(%d, %d)\n", xc + x, yc - y);
            fprintf(fp, "(%d, %d)\n", xc - x, yc + y);
            fprintf(fp, "(%d, %d)\n", xc - x, yc - y);
        }

        if (delta < 0) {
            int delta_HD = ((delta + y) << 1) - 1;
            if (delta_HD >= 0) {
                delta += (++x - (--y) + 1) << 1;
            }
            else {
                delta += ((++x) << 1) + 1;
            }
        }
        else if (delta > 0) {
            int delta_DV = ((delta - x) << 1) - 1;
            if (delta_DV < 0) {
                delta += (++x - (--y) + 1) << 1;
            }
            else {
                delta += 1 - ((--y) << 1);
            }
        }
        else {
            delta += (++x - (--y) + 1) << 1;
        }
    }
}