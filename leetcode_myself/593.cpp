#include <stdio.h>

int Max(int a, int b) { return a > b ? a : b; }

int Min(int a, int b) { return a > b ? b : a; }

float distance(float *p1, int *p2) {
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) +
           (p1[1] - p2[1]) * (p1[1] - p2[1]);
}

/************************************************************************/
/* 求输入4个点左边能否组成一个正方形                              */
/************************************************************************/
bool validSquare(int *p1, int p1Size, int *p2, int p2Size, int *p3, int p3Size,
                 int *p4, int p4Size) {
    if (p1Size != 2 || p2Size != 2 || p3Size != 2 || p4Size != 2) {
        return 0;
    }

    //判断是否有重合的点
    if ((p1[0] == p2[0] && p1[1] == p2[1]) ||
        (p1[0] == p3[0] && p1[1] == p3[1]) ||
        (p1[0] == p4[0] && p1[1] == p4[1]) ||
        (p2[0] == p3[0] && p2[1] == p3[1]) ||
        (p2[0] == p4[0] && p2[1] == p4[1]) ||
        (p3[0] == p4[0] && p3[1] == p4[1])) {
        return 0;
    }
    int xMax = 0, yMax = 0, xMin = 0, yMin = 0;
    xMax = Max(Max(Max(p1[0], p2[0]), p3[0]), p4[0]);
    yMax = Max(Max(Max(p1[1], p2[1]), p3[1]), p4[1]);
    xMin = Min(Min(Min(p1[0], p2[0]), p3[0]), p4[0]);
    yMin = Min(Min(Min(p1[1], p2[1]), p3[1]), p4[1]);
    if ((yMax - yMin) * (yMax - yMin) != (xMax - xMin) * (xMax - xMin)) {
        return 0;
    } else {
        float midP[2];
        midP[0] = (xMax + xMin) / 2.0;
        midP[1] = (yMax + yMin) / 2.0;
        if (distance(midP, p1) != distance(midP, p2) ||
            distance(midP, p1) != distance(midP, p3) ||
            distance(midP, p3) != distance(midP, p4)) {
            return 0;
        } else {
            return 1;
        }
    }
}