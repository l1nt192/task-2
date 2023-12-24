#include <stdio.h>
#include <stdlib.h>


void displayMatrix(double** matrix, int size) 
{
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%0.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

double calculateDeterminant(double** matrix, int size)
{
    double det = 0;
    int i, j, k, sub_i, sub_j;
    double** submatrix;
    if (size == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    else 
    {
        submatrix = (double**)malloc((size - 1) * sizeof(double*));
        if (submatrix == NULL) {
            printf("Error: Memory could not be allocated\n");
            exit(1);
        }

        for (i = 0; i < size - 1; i++) 
        {
            submatrix[i] = (double*)malloc((size - 1) * sizeof(double));
            if (submatrix[i] == NULL) {
                printf("Error: Memory could not be allocated\n");
                exit(1);
            }
        }
        for (k = 0; k < size; k++)
        {
            sub_i = 0;
            for (i = 1; i < size; i++)
            {
                sub_j = 0;
                for (j = 0; j < size; j++)
                {
                    if (j == k)
                    {
                        continue;
                    }
                    submatrix[sub_i][sub_j] = matrix[i][j];
                    sub_j++;
                }
                sub_i++;
            }
            det += (k % 2 == 0 ? 1 : -1) * matrix[0][k] * calculateDeterminant(submatrix, size - 1);
        }

        for (i = 0; i < size - 1; i++) 
        {
            free(submatrix[i]);
        }
        free(submatrix);
    }
    return det;
}
void solveSystem(double** A, double* B, int N)
{
    double detA, * detX, * unknowns, ** A_copy;
    int i, j, k;

    detX = (double*)malloc(N * sizeof(double));
    if (detX == NULL) 
    {
        printf("Error: Memory could not be allocated\n");
        exit(1);
    }
    unknowns = (double*)malloc(N * sizeof(double));
    if (unknowns == NULL)
    {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    A_copy = (double**)malloc(N * sizeof(double*));
    if (A == NULL) 
    {
        printf("Error: Memory could not be allocated..\n");
        exit(1);
    }
    for (i = 0; i < N; i++)
    {
        A_copy[i] = (double*)malloc(N * sizeof(double));
        if (A_copy[i] == NULL) 
        {
            printf("Error: Memory could not be allocated..\n");
            exit(1);
        }
    }
    for (i = 0; i < N; i++) 
    {
        for (j = 0; j < N; j++)
        {
            A_copy[i][j] = A[i][j];
        }
    }
    detA = calculateDeterminant(A_copy, N);
    if (detA == 0)
    {
        printf("Система уравнений не имеет решения.\n");
        return;
    }
    for (i = 0; i < N; i++) 
    {
        // Заменяем i-ый столбец матрицы A на столбец B
        for (j = 0; j < N; j++) {
            A_copy[j][i] = B[j];
        }
        detX[i] = calculateDeterminant(A_copy, N);
        unknowns[i] = detX[i] / detA;
        for (j = 0; j < N; j++) {
            A_copy[j][i] = A[j][i];
        }
    }
    printf("Solving a system of equations:\n");
    for (i = 0; i < N; i++) 
    {
        printf("x%d = %f\n", i + 1, unknowns[i]);
    }

    free(detX);
    free(unknowns);
    for (i = 0; i < N; i++) 
    {

        free(A_copy[i]);
    }
    free(A_copy);
}