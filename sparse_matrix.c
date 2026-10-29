#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_NONZERO (MAX_ROWS * MAX_COLS)

int main(void)
{
    int matrix[MAX_ROWS][MAX_COLS];
    int triplet[MAX_NONZERO + 1][3];
    int rows, cols, i, j, nonzero_count = 0, index = 1;

    printf("Enter rows and columns (maximum %d each): ", MAX_ROWS);
    if (scanf("%d%d", &rows, &cols) != 2 ||
        rows < 1 || rows > MAX_ROWS ||
        cols < 1 || cols > MAX_COLS) {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }

    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1)
                return 1;
            if (matrix[i][j] != 0)
                nonzero_count++;
        }
    }

    triplet[0][0] = rows;
    triplet[0][1] = cols;
    triplet[0][2] = nonzero_count;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                triplet[index][0] = i;
                triplet[index][1] = j;
                triplet[index][2] = matrix[i][j];
                index++;
            }
        }
    }

    printf("Triplet representation (row\tcolumn\tvalue):\n");
    for (i = 0; i <= nonzero_count; i++)
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);

    return 0;
}
