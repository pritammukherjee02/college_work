#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;

double f(double x){
    return exp(x);
}

//Newton's forward interpolation
double newton_forward_interpolation(vector<double>& x, vector<double>& y, double x0)
{
    int n = x.size();

    // Calculate the forward difference table
    vector<vector<double>> f(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        f[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            f[i][j] = f[i + 1][j - 1] - f[i][j - 1];
        }
    }

    // Use the forward difference table to calculate the interpolated value
    double p = (x0 - x[0]) / (x[1] - x[0]);
    double res = y[0];
    double prod = 1;
    for (int i = 1; i < n; i++) {
        prod *= (p - i + 1) / i;
        res += prod * f[0][i];
    }

    return res;
}

// Newton's backward interpolation
double newton_backward_interpolation(vector<double>& x, vector<double>& y, double x0) {
    int n = x.size();

    // Calculate the backward difference table
    vector<vector<double>> b(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        b[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            b[i][j] = b[i][j - 1] - b[i - 1][j - 1];
        }
    }

    // Use the backward difference table to calculate the interpolated value
    double p = (x0 - x[n - 1]) / (x[1] - x[0]);
    double res = y[n - 1];
    double prod = 1;
    for (int i = 1; i < n; i++) {
        prod *= (p + i - 1) / i;
        res += prod * b[n - 1][i];
    }

    return res;
}

int main(){
    int n;
    cout << "Input number of data points: ";
    cin >> n;

    // Input the data points
    vector<double> x(n), y(n);
    cout << "Enter the data points in the form (x, y): " << endl;
    for (int i = 0; i < n; i++) {
       cin >> x[i] >> y[i];
    }

    // Input the value of x for which the interpolated value is to be calculated
    double x0;
    cout << "Enter the value of x for which the interpolated value is to be calculated: ";
    cin >> x0;

    double res1 = newton_forward_interpolation(x, y, x0);
    cout << "Using Newton's forward interpolation: " << res1 << endl;

    double res2 = newton_backward_interpolation(x, y, x0);
    cout << "Using Newton's backward interpolation: " << res2 << endl;

    return 0;
}

