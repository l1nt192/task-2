#include <stdio.h>
#include <stdlib.h>
#include "Kramer.h"
int main() {
    double** A, * B;
    int N = 0;
    int   i = 0;
    int j = 0;
    printf("Enter the number of unknowns: ");
    scanf_s("%d", &N);
    if (N <= 0) {
        printf("Error.\n");
        return 1;
    }
    A = (double**)malloc(N * sizeof(double*));
    if (A == NULL) {
        printf("Error: Memory could not be allocated.\n");
        return 1;
    }
    for (i = 0; i < N; i++) {
        A[i] = (double*)malloc(N * sizeof(double));
        if (A[i] == NULL) {
            printf("Error: Memory could not be allocated.\n");
            return 1;
        }
    }
    B = (double*)malloc(N * sizeof(double));
    if (B == NULL) {
        printf("Error: Memory could not be allocated.\n");
        return 1;
    }
    printf("Enter the coefficients of the system of equations:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf_s("%lf", &A[i][j]);
        }
        printf("B[%d]: ", i);
        scanf_s("%lf", &B[i]);
    }
    solveSystem(A, B, N);
    for (i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
    free(B);
    return 0;
}