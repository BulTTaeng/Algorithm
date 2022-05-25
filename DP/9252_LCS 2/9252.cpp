#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string str1 , str2;
int dp[1001][1001];
string ans;

void lcs();
void printlcs();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> str1;
    cin >> str2;

    memset(dp , 0 ,sizeof(dp));

    lcs();
    
    cout << dp[str1.length()][str2.length()] << "\n";
    printlcs();

    for(int i = ans.length()-1; i>=0; i--){
        cout << ans[i];
    }
    return 0;
    
}

void lcs(){
    for(int i=1; i<=str1.length(); i++){
        for(int j =1 ; j<=str2.length() ; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }

            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
}

void printlcs(){
    int x = str1.length();
    int y = str2.length();

    while(dp[x][y] != 0){

        if(dp[x-1][y] == dp[x][y]){
            x--;
        }
        else if(dp[x][y-1] == dp[x][y]){
            y--;
        }
        else{
            ans += str1[x-1];
            x--;
            y--;
        }
    }
}
