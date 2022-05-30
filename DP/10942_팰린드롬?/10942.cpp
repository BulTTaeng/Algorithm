#include <iostream>
#include <cstring>

using namespace std;

int N , M;
int inp[2003];
bool dp[2003][2003];

void solve();

int main(){

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    cin >> N;

    for(int i =1 ; i<=N ; i++){
        cin >> inp[i];
    }

    solve();

    cin >> M;
    int t1 , t2;
    for(int i =1; i<=M; i++){
        cin >> t1 >>t2;
        cout << dp[t1][t2] << "\n"; 
    }

    return 0;
}

void solve(){

    memset(dp , false ,sizeof(dp));

    for(int i =1 ; i<=N; i++){
        dp[i][i] = true;
    }

    for(int i =1; i<N; i++){
        if(inp[i] == inp[i+1] ) dp[i][i+1] = true;
    }

    for(int len = 2; len <=N; len++){
        for(int start = 0; start+len<=N; start++){
            int end = start+len;
            if(dp[start+1][end-1] && inp[start] == inp[end]){
                dp[start][end] = true;
            }
        }
    }
}
