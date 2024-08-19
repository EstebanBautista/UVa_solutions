#include <iostream>
#include <math.h>

using namespace std;

int main(){

    int a, b, c, d, p, n;

    while ( cin >> p >> a >> b >> c >> d >> n ){
        double maxpri = p * (sin((a * 1 + b)) + cos((c * 1 + d)) + 2);
        double ans = 0;
        for (int val = 2; val <= n; val++){
            double maxseg = p * (sin((a * val + b)) + cos((c * val + d)) + 2);
            if ( maxpri > maxseg ){
                if (ans < maxpri - maxseg){
                    ans = maxpri - maxseg;
                }
     
            }
            else{
                maxpri = maxseg;
            }
        }
        printf("%.8lf\n", ans);
    }
    return 0;
}