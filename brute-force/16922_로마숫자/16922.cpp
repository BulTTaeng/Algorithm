#include <iostream>
#include <cstring>
using namespace std;

int N;

bool visit[1002][21];
int ans = 0;

void dfs(int num , int len);

int dx[] = {1 , 5 ,10 , 50};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    memset(visit, false , sizeof(visit));
    dfs(0, 0);
    cout << ans;
    return 0;
}

void dfs(int num , int len){
    
    visit[num][len] = true;

    if(len == N){
        ans++;
        return;
    }

    for(int i =0; i<4; i++){
        int nx = num+dx[i];
        if(!visit[nx][len+1]){
            dfs(nx , len+1);
        }
    }


}
