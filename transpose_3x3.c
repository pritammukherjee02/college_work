#include <stdio.h>

int main()
{
    int A[3][3];
    
    printf("Row-wise: Enter Row1Col1 Row1Col2 Row1Col3\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &A[i][j]);
        }
    }
    
    int swapCache;
    for(int i = 0; i < 3; i++){
        for(int j = i; j < 3; j++){
            swapCache = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = swapCache;
        }
    }
    
    printf("Transpose:\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}