#include <iostream>

#define e 0.001

double x(float y, float z){
    return (0.5)*(y + 7);
}
double y(float x, float z){
    return (0.5)*(1+x+z);
}
double z(float x, float y){
    return (0.5)*(1+x);
}

using namespace std;

int main()
{
    double x0 = 0, y0 = 0, z0 = 0, x1 = 0, y1 = 0, z1 = 0, ex = 0, ey = 0, ez = 0;
    do{

        x0 = x1;
        x1 = x(y1, z1);

        y0 = y1;
        y1 = y(x1, z1);

        z0 = z1;
        z1 = z(x1, y1);

        ex = fabs(x1 - x0);
        ey = fabs(y1 - y0);
        ez = fabs(z1 - z0);

    } while (ex >= e && ey >= e && ez >= e);

    cout << "X, Y, Z values: " << x1 << ", " << y1 << ", " << z1 << endl;

    return 0;
}