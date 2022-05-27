#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N , M;
int dp[101][10001];

vector<int> memory;
vector<int> cost;
int ans = 987654321;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    int temp;
    for(int i =0; i<N; i++){
        cin >> temp;
        memory.push_back(temp);
    }

    for(int i =0; i<N; i++){
        cin >> temp;
        cost.push_back(temp);
    }
    
    memset(dp , 0 ,sizeof(dp));
    
    for(int i =1; i<=N; i++){
        for(int j=0; j<=10000 ; j++){
            if(j<cost[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i-1][j-cost[i-1]]+ memory[i-1]);
            }
            if(dp[i][j] >= M){
                ans = min(ans , j);
            }
        }                
    }   

    cout << ans;
    return 0;


}
