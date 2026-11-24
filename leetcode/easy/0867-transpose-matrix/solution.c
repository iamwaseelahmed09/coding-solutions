
#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize,
                int* returnSize, int** returnColumnSizes) {

    int rows = matrixSize;
    int cols = matrixColSize[0];

    // Allocate memory for result rows
    int** result = (int**)malloc(cols * sizeof(int*));

    // Allocate memory for column sizes
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));

    // Allocate memory for each row
    for (int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(rows * sizeof(int));
        (*returnColumnSizes)[i] = rows;
    }

    *returnSize = cols;

    // Transpose the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}
