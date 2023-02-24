#include <stdio.h>

int main()
{
    int marks[5][3];
    
    for(int i = 0; i < 5; i++)
    {
        printf("Student %d -> \n", i + 1);
        for(int j = 0; j < 3; j++)
        {
            printf("\tMarks in Sub %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }
    
    //Highest marks in each subject
    int max = 0;
    for(int i = 0; i < 5; i++)
    {
        if(max < marks[i][0])
            max = marks[i][0];
    }
    printf("Max marks in Subject 1: %d\n", max);
    
    max = 0;
    for(int i = 0; i < 5; i++)
    {
        if(max < marks[i][1])
            max = marks[i][1];
    }
    printf("Max marks in Subject 2: %d\n", max);
    
    max = 0;
    for(int i = 0; i < 5; i++)
    {
        if(max < marks[i][2])
            max = marks[i][2];
    }
    printf("Max marks in Subject 3: %d\n", max);
    return 0;
}