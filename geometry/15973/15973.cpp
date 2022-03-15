#include <iostream>

using namespace std;

int x1, y1 ,p1, q1;
int x2, y2 , p2 , q2;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

    int xr , xl , yr , yl ,xdiff , ydiff;

    xl = max(x1 , x2);
    xr = min(p1 , p2);
    yl = max(y1 , y2);
    yr = min(q1 , q2);

    xdiff = xr-xl;
    ydiff = yr -yl;

    if(xdiff > 0 && ydiff > 0){
        cout << "FACE";
    }
    else if(xdiff <0 || ydiff < 0 ){
        cout << "NULL";
    }
    else if(xdiff == 0 && ydiff == 0){
        cout << "POINT";
    }
    else{
        cout << "LINE";
    }

    return 0;
}
