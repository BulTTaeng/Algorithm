#include <iostream>
#include <math.h>

using namespace std;

int N;

double x[10001];
double y[10001];

double ccw (double x1, double x2 , double x3 , double y1 , double y2 , double y3);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =0 ; i<N; i++){
        cin >> x[i] >> y[i];
    } 

    double ans = 0;

    for(int i=1; i<N; i++){
        ans += ccw(x[0] , x[i-1] , x[i] , y[0] , y[i-1] , y[i]);
    }

    cout.precision(1);
    cout << fixed;
    cout << abs(ans);
    return 0;
}

double ccw (double x1, double x2 , double x3 , double y1 , double y2 , double y3){
    double a = x1*y2 + x2*y3 + x3*y1;
    double b = x2*y1 + x3*y2 + x1*y3;

    return (a-b)/2.0;
}
