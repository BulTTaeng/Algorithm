#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[42][42];
string str1 , str2;

string ans;

void LCS();
void LCSstr();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> str1;
    cin >> str2;
    memset(dp , 0, sizeof(dp));

    LCS();
    LCSstr();
    for(int i =ans.length()-1 ; i>=0 ; i--){
        cout << ans[i];
    }
    return 0;
}

void LCS(){
    for(int i =1 ; i<=str1.length(); i++){
        for(int j = 1 ; j <=str2.length(); j++){
            if(str1[i-1] == str2[j-1]){
               dp[i][j] = dp[i-1][j-1] +1;
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
}

void LCSstr(){
    int i = str1.length();
    int j = str2.length();

    while(dp[i][j] != 0){
        if(dp[i-1][j] == dp[i][j]){
            i--;
        }
        else if(dp[i][j] == dp[i][j-1]){
            j--;
        }
        else{
            ans += str1[i-1];
            i--;
            j--;
        }
    }
}
