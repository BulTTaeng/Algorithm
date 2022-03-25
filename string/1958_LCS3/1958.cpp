#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s1,s2,s3;

int dp[101][101][101];


void LCS();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);


    cin >> s1; 
    cin >> s2; 
    cin >> s3;
    memset(dp, 0, sizeof(dp));
    LCS();
    

    cout << dp[s1.length()][s2.length()][s3.length()];
    
    return 0;
}

void LCS(){
  
    for(int i =0; i<s1.length() ;i++){
        for(int j=0; j<s2.length() ; j++){
            for(int k =0; k<s3.length(); k++){
                if(s1[i] == s2[j] && s2[j] == s3[k]){
                    dp[i+1][j+1][k+1] = dp[i][j][k]+1;
                }
                else{
                    dp[i+1][j+1][k+1] = max(dp[i][j+1][k+1] , dp[i+1][j][k+1]);
                    dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1] , dp[i+1][j+1][k]);
                }
            }
        }
    }

}
