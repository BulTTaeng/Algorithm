#include <iostream>
#include <queue>
#include <cstring>
#include <deque>

using namespace std;

bool visit[101][101];
char inp[101][101];

struct st{
    int x;
    int y;
    int n;
}typedef st;

queue<st> q;
int dx[] = {-1, 1, 0 , 0};
int dy[] = {0, 0 , 1 , -1};
deque<st> dq;

int N , M;
int ans = 987654321;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> M >> N;

    for(int i =0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> inp[i][j];
        }
    }

    memset(visit ,false ,sizeof(visit));
    st temp , newone;
    temp.x = 0;
    temp.y = 0;
    temp.n = 0;

    dq.push_front(temp);

    int x, y, n;

    while(!dq.empty()){
        temp = dq.front();
        dq.pop_front();
        x = temp.x;
        y = temp.y;
        n = temp.n;

        if(x == N-1 && y == M-1){
            ans = min(ans , n);
            break;
        }

        for(int i =0; i<4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny >=0 && nx <N && ny <M){

                if(!visit[nx][ny]){
                    if(inp[nx][ny] == '0'){
                        newone.x = nx;
                        newone.y = ny;
                        newone.n = n;
                        dq.push_front(newone);
                        visit[nx][ny] = true;
                        
                    }
                    else{
                        newone.x = nx;
                        newone.y = ny;
                        newone.n = n+1;
                        dq.push_back(newone);
                        visit[nx][ny] = true;
                    }
                }
            }
        }
        
        
    }
    
    cout << ans;
    return 0;
}
