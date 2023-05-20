#include <iostream>
#include <math.h>

using namespace std;

double func(double x){
    return pow(x, 4);
}

int main()
{
    float n = 500.0; // Intervals
    float low = -3.0;
    float high = 3.0;
    
    double delta_x = (high - low)/(double)n;
    double sum = func((double)low);
    
    for(int i = 1; i <= n; i++)
    {
        if(i%2 == 1){
            sum += 4*func((double)(low + delta_x*i));
        } else {
            sum += 2*func((double)(low + delta_x*i));
        }
    }
    
    cout << "Estimated to be: " << (delta_x/3)*sum << endl;
    
    return 0;
}