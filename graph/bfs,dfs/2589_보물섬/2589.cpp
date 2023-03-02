#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N , M;
bool visit[51][51];
char inp[51][51];

int dx[] = {-1 ,1 ,0 ,0 };
int dy[] = {0, 0, 1 , -1};

int ans = 0;

struct st{
    int x ;
    int y;
    int d;
}typedef st;

void BFS(int x , int y);
 
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> N >>M;

    for(int i =0;i <N; i++){
        for(int j =0; j<M; j++){
            cin >> inp[i][j]; 
        }
    }

    for(int i = 0; i<N ; i++){
        for(int j =0; j<M; j++){
            if(inp[i][j] == 'L'){
                memset(visit , false ,sizeof(visit));
                visit[i][j] = true;
                BFS(i,j);
            }
        }
    }

    cout << ans;
    return 0;
}

void BFS(int x , int y){
    st temp , newone;
    queue<st> q;

    temp.x = x;
    temp.y = y;
    temp.d = 0;
    q.push(temp);


    while(!q.empty()){
        newone = q.front();
        q.pop();
        ans  = max(ans , newone.d);

        for(int i =0; i<4 ; i++){
            int nx = newone.x +dx[i];
            int ny = newone.y + dy[i];

            if(nx >=0 && ny>=0 && nx<N && ny < M){
                if(!visit[nx][ny] && inp[nx][ny] == 'L'){
                    visit[nx][ny] = true;
                    temp.x = nx;
                    temp.y = ny;
                    temp.d = newone.d+1;
                    q.push(temp);
                }
            }
        }

    }
}
