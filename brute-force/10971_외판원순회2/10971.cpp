#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N , ans = 987654321;
int inp[11][11];
bool visit[11];

void dfs(int start , int curr , int cost , int num);

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

    for(int i =0; i <N; i++){
        memset(visit ,false ,sizeof(visit));
        dfs(i,i,0,1);
    }

    cout << ans;

    return 0;
}

void dfs(int start , int curr , int cost , int num){
    visit[curr] = true;

    if(num == N){
        if(inp[curr][start] != 0){
            ans = min(ans , cost + inp[curr][start]);
        }
    }else{
        for(int i =0; i<N; i++){
            if(!visit[i] && inp[curr][i] != 0){
                dfs(start, i, cost + inp[curr][i] , num+1);
            }
        }
    }

    visit[curr] = false;
}
