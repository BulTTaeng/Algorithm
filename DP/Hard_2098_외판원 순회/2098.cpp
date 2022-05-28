#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int inp[17][17];
int dp[17][65537];
int bit;

void solve();

#define MAX 987654321

int ans = MAX;

int dfs(int curr ,int bits);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> N;
    bit = (1 << N) -1;

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            cin >> inp[i][j];
        }
    }
    memset(dp , -1 , sizeof(dp));
    ans = dfs(0,1);

    cout << ans;
    return 0;
}

int dfs(int curr ,int bits){
    
    if(bits == bit){
        if(inp[curr][0] != 0){
            return inp[curr][0];
        }
        else{
            return MAX;
        }
    }

    if(dp[curr][bits] != -1){
        return dp[curr][bits];
    }

    dp[curr][bits] = MAX;

    for(int i =0; i<N; i++){
        if(inp[curr][i] != 0 && !(bits & 1 << i) ){ // 방문하지도 않았고 , 방문 가능하면
            dp[curr][bits] = min(dp[curr][bits] , inp[curr][i] + dfs(i, bits | (1 << i) ));
        }
    }
    
    return dp[curr][bits];
}
