
#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(long long a[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);

            if (scanf("%lld", &a[i][j]) != 1) {
                printf("Invalid input!\n");
                return;
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(long long a[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%lld\t", a[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix addition
void addMatrix(long long a[MAX][MAX],
               long long b[MAX][MAX],
               long long result[MAX][MAX],
               int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplyMatrix(long long a[MAX][MAX],
                    long long b[MAX][MAX],
                    long long result[MAX][MAX],
                    int r1, int c1, int c2) {
    int i, j, k;

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;

            for (k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function for matrix transpose
void transposeMatrix(long long a[MAX][MAX],
                     long long result[MAX][MAX],
                     int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[j][i] = a[i][j];
        }
    }
}

// Function to validate matrix dimensions
int validSize(int rows, int cols) {
    return rows >= 1 && rows <= MAX &&
           cols >= 1 && cols <= MAX;
}

int main() {
    long long A[MAX][MAX], B[MAX][MAX];
    long long result[MAX][MAX];

    int choice;
    int r1, c1, r2, c2;

    while (1) {
        printf("\n===== MATRIX OPERATIONS =====\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {

            case 1:
                printf("Enter rows and columns: ");
                if (scanf("%d %d", &r1, &c1) != 2 ||
                    !validSize(r1, c1)) {
                    printf("Invalid matrix dimensions!\n");
                    break;
                }

                printf("\nEnter first matrix:\n");
                inputMatrix(A, r1, c1);

                printf("\nEnter second matrix:\n");
                inputMatrix(B, r1, c1);

                addMatrix(A, B, result, r1, c1);

                printf("\nAddition Result:\n");
                displayMatrix(result, r1, c1);
                break;

            case 2:
                printf("Enter rows and columns of first matrix: ");
                if (scanf("%d %d", &r1, &c1) != 2 ||
                    !validSize(r1, c1)) {
                    printf("Invalid matrix dimensions!\n");
                    break;
                }

                printf("Enter rows and columns of second matrix: ");
                if (scanf("%d %d", &r2, &c2) != 2 ||
                    !validSize(r2, c2)) {
                    printf("Invalid matrix dimensions!\n");
                    break;
                }

                if (c1 != r2) {
                    printf("Multiplication not possible!\n");
                    break;
                }

                printf("\nEnter first matrix:\n");
                inputMatrix(A, r1, c1);

                printf("\nEnter second matrix:\n");
                inputMatrix(B, r2, c2);

                multiplyMatrix(A, B, result, r1, c1, c2);

                printf("\nMultiplication Result:\n");
                displayMatrix(result, r1, c2);
                break;

            case 3:
                printf("Enter rows and columns: ");
                if (scanf("%d %d", &r1, &c1) != 2 ||
                    !validSize(r1, c1)) {
                    printf("Invalid matrix dimensions!\n");
                    break;
                }

                printf("\nEnter matrix:\n");
                inputMatrix(A, r1, c1);

                transposeMatrix(A, result, r1, c1);

                printf("\nTranspose Result:\n");
                displayMatrix(result, c1, r1);
                break;

            case 4:
                printf("Exiting program. Thank you!\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
