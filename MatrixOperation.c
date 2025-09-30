#include <stdio.h>

#define MAX 10  

void readMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Enter elements of %dx%d matrix:\n", rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}


void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}


void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}


void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int r2, int c2) {
    
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

 
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            for(int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


void transposeMatrix(int A[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[j][i] = A[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int rows1, cols1, rows2, cols2;
    int choice;

    while (1) {
        printf("\n--- Matrix Operations Menu ---\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter rows and columns of matrices: ");
                scanf("%d%d", &rows1, &cols1);
                printf("Matrix A:\n");
                readMatrix(A, rows1, cols1);
                printf("Matrix B:\n");
                readMatrix(B, rows1, cols1);

                addMatrix(A, B, result, rows1, cols1);

                printf("Result of Addition:\n");
                displayMatrix(result, rows1, cols1);
                break;

            case 2:
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d%d", &rows1, &cols1);
                printf("Enter rows and columns of Matrix B: ");
                scanf("%d%d", &rows2, &cols2);

                if (cols1 != rows2) {
                    printf("Matrix multiplication not possible! (cols of A != rows of B)\n");
                    break;
                }

                printf("Matrix A:\n");
                readMatrix(A, rows1, cols1);
                printf("Matrix B:\n");
                readMatrix(B, rows2, cols2);

                multiplyMatrix(A, B, result, rows1, cols1, rows2, cols2);

                printf("Result of Multiplication:\n");
                displayMatrix(result, rows1, cols2);
                break;

            case 3:
                printf("Enter rows and columns of matrix: ");
                scanf("%d%d", &rows1, &cols1);
                printf("Matrix A:\n");
                readMatrix(A, rows1, cols1);

                transposeMatrix(A, result, rows1, cols1);

                printf("Transpose of Matrix:\n");
                displayMatrix(result, cols1, rows1);
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
