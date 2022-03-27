#include <iostream>

using namespace std;

int N;
int hp[21];
int joy[21];
int dp[101];

int ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =0; i<N; i++){
        cin >> hp[i];
    }

    for(int i =0; i<N; i++){
        cin >> joy[i];
    }

    for(int i =0; i<N; i++){
        for(int j=100; j>hp[i]; j--){
            dp[j]  = max(dp[j] , dp[j-hp[i]] + joy[i]);
        }
    }

    cout << dp[100];
    return 0;
}
