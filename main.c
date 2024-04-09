#include <stdio.h>
#include <stdlib.h>

const int lx = 1920 << 2, ly = 1080 << 2;

void bresenham_line(int x1, int y1, int x2, int y2, FILE *fp);
void bresenham_circle(int xc, int yc, int r, FILE *fp);

int main(int argc, char **argv) {
    int x1, x2, y1, y2, succ;
    do {
        printf("Enter 2 points of the line(eg. x1 y1 x2 y2): ");
        succ = scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (!((0 <= x1 && x1 <= lx) && (0 <= y1 && y1 <= ly) && (0 <= x2 && x2 <= lx) && (0 <= y2 && y2 <= ly) && succ == 4)) {
            printf("\nThe points you entered were not qualified to the screen, please retry.\n");
        }
    } while (!(0 <= x1 && x1 <= lx) && (0 <= y1 && y1 <= ly) && (0 <= x2 && x2 <= lx) && (0 <= y2 && y2 <= ly) && succ == 4);

    FILE *fp = fopen("Bresenham_Line.txt", "w");
    if (fp == NULL) {
        printf("There is an error occurred when opening a file, please retry later.\n");
        exit;
    }
    bresenham_line(x1, y1, x2, y2, fp);
    fclose(fp);

    return 0;
}
