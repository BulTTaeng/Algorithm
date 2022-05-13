#include <iostream>

using namespace std;

int N;
int sdp[2][4];
int bdp[2][4];
int inp[4];

int mini = 987654321;
int maxi = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =0; i<3; i++){
        sdp[1][i] = 987654321;
        bdp[1][i] = 0;
    }
    
    for(int i=0; i<N; i++){
        for(int j =0; j<3; j++){
            cin>> inp[j];
        }

        if(i == 0){
            for(int j =0; j<3; j++){
                sdp[0][j] = inp[j];
                bdp[0][j] = inp[j];
            }
        } else{
            bdp[i%2][0] = max(bdp[(i+1)%2][0] + inp[0] , bdp[(i+1)%2][1] + inp[0]);

            bdp[i%2][1] = max(bdp[(i+1)%2][0] + inp[1] , bdp[(i+1)%2][1] + inp[1]);
            bdp[i%2][1] = max(bdp[i%2][1], bdp[(i+1)%2][2] + inp[1]);

            bdp[i%2][2] = max(bdp[(i+1)%2][1] + inp[2] , bdp[(i+1)%2][2] + inp[2]);


            sdp[i%2][0] = min(sdp[(i+1)%2][0] + inp[0] , sdp[(i+1)%2][1] + inp[0]);

            sdp[i%2][1] = min(sdp[(i+1)%2][0] + inp[1] , sdp[(i+1)%2][1] + inp[1]);
            sdp[i%2][1] = min(sdp[i%2][1], sdp[(i+1)%2][2] + inp[1]);

            sdp[i%2][2] = min(sdp[(i+1)%2][1] + inp[2] , sdp[(i+1)%2][2] + inp[2]);
            
        }
    }

    for(int i =0; i<3; i++){
        maxi  = max(maxi , bdp[(N-1)%2][i]);
        mini = min(mini , sdp[(N-1)%2][i]);
    }

    cout << maxi << " " << mini;

    return 0;
}
