
#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize,
                    int r, int c, int* returnSize,
                    int** returnColumnSizes) {

    int rows = matSize;
    int cols = matColSize[0];

    // Check if reshaping is possible
    if (rows * cols != r * c) {
        *returnSize = rows;
        *returnColumnSizes = matColSize;
        return mat;
    }

    // Allocate memory for reshaped matrix
    int** result = (int**)malloc(r * sizeof(int*));

    *returnColumnSizes = (int*)malloc(r * sizeof(int));

    for (int i = 0; i < r; i++) {
        result[i] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    *returnSize = r;

    // Fill the reshaped matrix
    for (int i = 0; i < rows * cols; i++) {
        result[i / c][i % c] = mat[i / cols][i % cols];
    }

    return result;
}

