#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int N;
int dp[50001];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    
    int i = 1;

    for(int i = 1; i<=N; i++){
        dp[i] = 5;
    }

    while(true){
        if(i*i > 50000){
            break;
        }

        dp[i*i] = 1;
        
        i++;
    }

    for(int i =2; i<=N; i++){
        if(dp[i] == 1){
            continue;
        }
        for(int j = 1; j <=floor(sqrt(i)); j++){
            dp[i] = min(dp[i] , dp[i-(j*j)] + 1);
        }
    }

    cout << dp[N];
    return 0;
}
