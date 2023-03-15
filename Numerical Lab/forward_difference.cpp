#include <iostream>
using namespace std;
 
// calculating u mentioned in the formula
float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u - i);
    return temp;
}
 
int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}
 
int main()
{
    int n = 5;
    float x[] = { 1891, 1901, 1911, 1921, 1931 };
     
    // first column of y is the input vals for y, through users
    float y[n][n];
    y[0][0] = 46;
    y[1][0] = 66;
    y[2][0] = 81;
    y[3][0] = 93;
    y[4][0] = 101;
 
    // Calculating forward difference
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    }
 
    // printing table
    for (int i = 0; i < n; i++) {
        cout << x[i]
             << "\t";
        for (int j = 0; j < n - i; j++)
            cout << y[i][j]
                 << "\t";
        cout << endl;
    }
 
    // Output generation
    float value;
    cout << "Enter value for interpolation: ";
    cin >> value;
 
    // initializing u and sum
    float sum = y[0][0];
    float u = (value - x[0]) / (x[1] - x[0]); // del(X)/h
    for (int i = 1; i < n; i++) {
        sum = sum + (u_cal(u, i) * y[0][i]) /
                                 fact(i);
    }
 
    cout << endl << "Value at " << value << " is approximately "
         << sum << endl;
    return 0;
}