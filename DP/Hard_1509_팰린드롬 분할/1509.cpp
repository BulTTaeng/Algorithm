#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string inp;

bool palin[2501][2501];
int dp[2501];

void solve();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> inp;
    
    memset(palin , false, sizeof(palin));

    for(int i =0; i<inp.length(); i++){
        palin[i][i] = true;
    }

    for(int i =0; i<inp.length()-1; i++){
        if(inp[i] == inp[i+1]) palin[i][i+1] = true;
    }

    for(int i =2; i<inp.length(); i++){
        for(int j =0; i+j<inp.length(); j++){

            int end = i+j;
            if (inp[j] == inp[end] && palin[j+1][end-1]){
                palin[j][end] = true;
            }

        }
    }

    solve();
    cout << dp[inp.length()-1];
    return 0;
    
}

void solve(){

    for(int i =0; i<inp.length(); i++){
        dp[i] = 987654321;

        for(int j =0; j <=i; j++){
            if(palin[j][i]){
                if(j == 0){
                    dp[i] = min(dp[i] , 1);
                }
                else{
                    dp[i] = min(dp[i] , dp[j-1]+1);
                }
            }
        }

    }

}
