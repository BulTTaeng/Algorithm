#include <iostream>
#include <vector>

using namespace std;

int N;
int inp[502][2];
long long dp[502][502];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >>  N;
    int f , s;

    for(int i =1; i<=N; i++){
        cin >> inp[i][0] >> inp[i][1];
    }

    for(int i =1; i<N ; i++){
        for(int j =1; i+j<=N; j++){
            dp[j][i+j] = 9876543211;
            for(int k=j; k<=i+j; k++){
                dp[j][i+j] =  min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + inp[j][0] * inp[k][1] * inp[i+j][1]);
            }
        }
    }

    
    cout << dp[1][N];
    return 0;

}
