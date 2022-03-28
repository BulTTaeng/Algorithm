#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;

char inp[52][52];

int ans = 0;

void solve();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            cin >> inp[i][j];
        }
    }
    
    for(int i =0; i<N; i++){
        for(int j =0; j<N-1; j++){
            swap(inp[i][j] , inp[i][j+1]);
            solve();
            swap(inp[i][j] , inp[i][j+1]);
        }
    }

    for(int i =0; i<N; i++){
        for(int j =0; j<N-1; j++){
            swap(inp[j][i] , inp[j+1][i]);
            solve();
            swap(inp[j][i] , inp[j+1][i]);
        }
    }

    cout << ans;
    return 0;
}

void solve(){
    int temp = 0;
    char tempc = inp[0][0];

    for(int i =0; i<N; i++){
        temp = 0;
        tempc = inp[i][0];
        for(int j =0; j<N; j++){
            if(inp[i][j] == tempc){
                temp++;
            }
            else{
                ans = max(ans , temp);
                temp = 1;
                tempc = inp[i][j];
            }
        }
        ans = max(ans , temp);
    }

    for(int i =0; i<N; i++){
        temp = 0;
        tempc = inp[0][i];
        for(int j =0; j<N; j++){
            if(inp[j][i] == tempc){
                temp++;
            }
            else{
                ans = max(ans , temp);
                temp = 1;
                tempc = inp[j][i];
            }
        }
        ans = max(ans , temp);
    }
}

