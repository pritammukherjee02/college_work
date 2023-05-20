#include <iostream>
#include <math.h>

using namespace std;

double func(double x){
    return pow(x, 4);
}

int main()
{
    float n = 200.0; // Intervals
    float low = -3.0;
    float high = 3.0;
    
    double delta_x = (high - low)/(double)n;
    double sum = 0.0;
    
    for(int i = 1; i <= n; i++)
    {
        sum += 2*func((double)(low + delta_x*i));
    }
    
    cout << "Estimated to be: " << (delta_x/2)*sum << endl;
    
    return 0;
}