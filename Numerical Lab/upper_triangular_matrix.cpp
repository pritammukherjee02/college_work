#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of rows in the square matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    //Create zeros in the lower triangle region
    for(int row = 1; row < n; row++)
    {
        for(int col = 0; col < row; col++)
        {
            matrix[row][col] = 0;
        }
    }

    //Take input from user and put in the upper matrix row wise
    //n(n-1)/2 number of non-zero elements

    cout << "Enter values row wise:" << endl;
    int count = 0;
    for(int row = 0; row < n; row++)
    {
        for(int col = row; col < n; col++)
        {
            cout << "Enter value " << ++count << " : ";
            cin >> matrix[row][col];
        }
    }

    cout << endl << endl;
    //print the matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}