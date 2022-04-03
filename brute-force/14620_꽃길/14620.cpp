#include <iostream>
#include <cstring>

using namespace std;

int dx[] = {-1 ,1 , 0, 0};
int dy[] = {0 , 0 ,1 , -1};

int N ;
int inp[11][11];
bool visit[11][11];
int cost[11][11];

int ans = 987654321;

void dfs(int costs , int num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >>N;

    for(int i =0; i<N; i++){
        for(int j =0; j<N ; j++){
            cin >> inp[i][j];
        }
    }

    int val = 0;
    int nx , ny;
    for(int i =1; i<N-1 ; i++){
        for(int j =1 ; j<N-1 ; j++){
            val = inp[i][j];
            for(int k =0 ; k<4 ; k++){
                nx = i+dx[k];
                ny = j+dy[k];
                val += inp[nx][ny];
            }
            cost[i][j] = val;
        }
    }
    memset(visit , false ,sizeof(visit));

    dfs(0,0);

    cout << ans;
    return 0;
}

void dfs(int costs , int num){
    
    int nx , ny;

    if(num == 3){
        ans = min(ans , costs);
    }
    else{
        for(int i = 1; i<N-1 ; i++){
            for(int j =1; j<N-1; j++){

                if(!visit[i][j] && !visit[i+1][j] &&!visit[i-1][j] && !visit[i][j+1] && !visit[i][j-1]){
                    for(int k =0 ; k<4 ; k++){
                        nx = i+dx[k];
                        ny = j+dy[k];
                        visit[nx][ny] = true;
                    }
                    visit[i][j] = true;

                    dfs(costs + cost[i][j] , num+1);
                    
                    for(int k =0 ; k<4 ; k++){
                        nx = i+dx[k];
                        ny = j+dy[k];
                        visit[nx][ny] = false;
                    }
                    visit[i][j] = false;
                }

            }
        }

    }

    

}
