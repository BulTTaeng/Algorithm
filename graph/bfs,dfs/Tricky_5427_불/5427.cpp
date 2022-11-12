#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T ,N , M;
char inp[1001][1001];
bool visit [1001][1001];

int dx[] = {-1, 1, 0 , 0};
int dy[] = {0, 0 , 1 , -1};

queue<pair<int , int>> fire;
queue<pair<int , int>> sang;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;

    int nx, ny , x, y;
    int time = 0;
    int ans = -1;

    while(T--){
        cin >> M >> N;
        time =0;

        memset(visit ,false, sizeof(visit));

        while(!fire.empty()){
            fire.pop();
        }

        while(!sang.empty()){
            sang.pop();
        }

        for(int i =0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> inp[i][j];

                if(inp[i][j] == '@'){
                    sang.push(make_pair(i,j));
                    visit[i][j] = true;
                }

                if(inp[i][j] == '*'){
                    fire.push(make_pair(i,j));
                }
            }
        }

        ans = -1;

        while(true){
            time++;

            int fs = fire.size();

            for(int i =0; i<fs ; i++){
                x = fire.front().first;
                y= fire.front().second;
                fire.pop();

                for(int j = 0 ;j <4; j++){
                    nx = x+dx[j];
                    ny = y + dy[j];

                    if(nx>=0 && ny>=0 && nx<N && ny <M){
                        if(inp[nx][ny] == '.' || inp[nx][ny] == '@'){
                            inp[nx][ny] = '*';
                            fire.push(make_pair(nx , ny));
                        }
                    }
                }
            }

            int ss = sang.size();
            
            for(int i =0; i<ss ; i++){
                x = sang.front().first;
                y = sang.front().second;
                sang.pop();

                if(ans != -1){
                    break;
                }

                for(int j =0; j<4 ; j++){
                    nx = x+dx[j];
                    ny = y+dy[j];

                    if(nx<0 || ny<0 || nx >=N  || ny >= M){
                        ans = time;
                        break;
                    }
                    else{
                        if(!visit[nx][ny] && inp[nx][ny] == '.'){
                            inp[nx][ny] = '@';
                            sang.push(make_pair(nx, ny));
                            visit[nx][ny] = true;
                        }
                    }
                }
            }

 

            if(ans != -1){
                cout << ans << "\n";
                break;
            }

            if(sang.empty()){
                cout << "IMPOSSIBLE" <<"\n";
                break;
            }
        }

        

    }

    return 0;
}
