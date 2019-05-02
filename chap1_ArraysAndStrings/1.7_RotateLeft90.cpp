#include <stdio.h>

void printMatrix(int mat[], const int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            printf("%4d ", mat[i*n+j]);
        }
        printf("\n");
    }
}

void rotateLeft90(int mat[], const int n) {
    // The rotation can be done layer by layer
    for (int m = n; m > 1; m -= 2) {
        const int p1 = (n-m)/2*(n+1);
        const int p2 = p1 + m - 1;
        const int p3 = p1 + n*(m-1);
        const int p4 = p3 + m - 1;
        for (int i = 0; i < m-1; i++) {
            const int tmp = mat[p1+i];
            mat[p1+i] = mat[p2+i*n];
            mat[p2+i*n] = mat[p4-i];
            mat[p4-i] = mat[p3-i*n];
            mat[p3-i*n] = tmp;
        }
    }
}

int main()
{
    const int n = 5;
    int mat[n*n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            mat[i*n+j] = n*i+j;
        }
    }

    printMatrix(mat, n);

    rotateLeft90(mat, n);

    printMatrix(mat, n);

}
