#include <stdlib.h>

int main()
{
    int i, j, a = 1, b = -1, c = 0, num;
    printf("Enter matrix row number: ");
    scanf("%d", &num);

    for(i = 0; i < num; i++)
    {
        printf("\n");
        for(j = 0; j < num; j++){
            if(i < j){
                printf("%d\t", a);
            } else if(i == j){
                printf("%d\t", c);
            } else {
                printf("%d\t", b);
            }
        }
    }

    return 0;
}