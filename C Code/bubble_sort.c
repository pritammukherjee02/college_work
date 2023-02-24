#include <stdlib.h>

int main(){
    int arr[100], elem, i, j;

    printf("Enter the number of elements: ");
    scanf("%d", &elem);

    printf("Enter the elements:\n");
    for(i = 0; i < elem; i++){
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < elem - 1; i++){
        for(j = 0; j < elem - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted array in Ascending order:\n");
    for(i = 0; i < elem; i++)
        printf("%d\n", arr[i]);

    return 0;
}