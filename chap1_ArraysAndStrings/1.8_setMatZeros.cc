#include <stdio.h>
#include <stdlib.h>
#include <time.h>

template <class MatType>
void printMatrix(MatType mat[], const int m, const int n) {
    printf("\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n ; j++) {
            printf("%4d ", mat[i*n+j]);
        }
        printf("\n");
    }
}

void setMatZeros(int mat[], const int m, const int n) {
    bool zeroPos[m*n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i*n+j] == 0) zeroPos[i*n+j] = true;
            else                 zeroPos[i*n+j] = false;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (zeroPos[i*n+j]) {
                // Set row to zeros
                for (int k = 0; k < n; k++) {
                    mat[i*n+k] = 0;
                }
                for (int k = 0; k < m; k++) {
                    mat[k*n+j] = 0;
                }
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    const int m = 3, n = 5;
    int mat[m*n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n ; j++) {
            mat[i*n+j] = rand()%4;
        }
    }

    printMatrix(mat, m, n);
    setMatZeros(mat, m, n);
    printMatrix(mat, m, n);

    return 0;
}
