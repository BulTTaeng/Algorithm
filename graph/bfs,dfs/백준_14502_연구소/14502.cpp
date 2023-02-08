#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N , M;
int ans = 0;
int inp[9][9];
int cinp[9][9];
bool visit[9][9];

int num_0  = 0;
int temp = 0;
vector<pair<int , int > > v;
vector<pair<int , int >> virus;

int dx[] = {-1, 1, 0 , 0};
int dy[] = {0,0, 1, -1};

void copyinp(int x1 , int y1 , int x2 , int y2, int x3 , int y3);
void BFS();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            cin >> inp[i][j];
            if(inp[i][j] == 0){
                num_0++;
                v.push_back(make_pair(i,j));
            }
            if(inp[i][j] == 2){
                virus.push_back(make_pair(i , j));
            }
        }
    }

    int fx , fy, sx , sy ,tx ,ty;

    

    for(int i =0; i<v.size(); i++){
        fx = v[i].first;
        fy = v[i].second;

        for(int j =i+1; j <v.size(); j++){
            sx = v[j].first;
            sy = v[j].second;

            for(int k =j+1; k<v.size(); k++){
                tx = v[k].first;
                ty = v[k].second;

                copyinp(fx , fy , sx , sy, tx , ty);
                temp = num_0-3;
                BFS();

                ans = max(ans , temp);
            }
        }
    }
    
    cout << ans;
    return 0;
}

void copyinp(int x1 , int y1 , int x2 , int y2, int x3 , int y3){

    for(int i =0; i<N ; i++){
        for(int j =0; j<M ; j++){
            cinp[i][j] = inp[i][j];
        }
    }

    cinp[x1][y1] = 1;
    cinp[x2][y2] = 1;
    cinp[x3][y3] = 1;
}

void BFS(){
    memset(visit ,false , sizeof(visit));

    queue<pair<int , int>> q;

    int x , y , nx , ny;

    for(int i =0; i<virus.size(); i++){
        if(!visit[virus[i].first][virus[i].second] ){
            q.push(make_pair(virus[i].first , virus[i].second));
            visit[virus[i].first][virus[i].second] = true;

            while(!q.empty()){
                x = q.front().first;
                y = q.front().second;
                q.pop();

                for(int j =0; j<4 ; j++){
                    nx = x+dx[j];
                    ny = y +dy[j];

                    if(nx>=0 && ny>=0 && nx<N && ny <M){
                        if(!visit[nx][ny] && cinp[nx][ny] == 0){
                            q.push(make_pair(nx , ny));
                            visit[nx][ny]  = true;
                            temp--;
                        }
                        
                    }
                }
            }
        }
    }
    
}
