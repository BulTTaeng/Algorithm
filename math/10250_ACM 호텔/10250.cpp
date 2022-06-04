#include <iostream>

using namespace std;

int H ,W , N;
int T;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;
    int ans = 0;
    while(T--){
        cin >> H >> W >>N;
        ans = 0;

        int x = (N/H)+1;
        int y = N%H;
        if(y ==0){
            y = H;
            x--;
        }
        ans = y*100 +x;
        cout << ans << "\n"; 
    }
    return 0;
}
