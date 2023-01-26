#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int  N , L ,R;
int inp[51][51];
bool visit[51][51];
vector<pair<int , int >> v[51][51];

queue<pair<int , int >> q;

int sum = 0;
int num = 0;
bool poss = false;

int dx[] = {-1, 1 , 0 , 0};
int dy[] = {0, 0 , 1 , -1};

void dfs(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> L >> R;

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            cin >> inp[i][j];
        }
    }

    int nx , ny , diff , avg;

    int day =0;

    while(true){

        memset(visit ,false ,sizeof(visit));
        poss = false;
        
        for(int i =0 ; i<=N; i++){
            for(int j =0; j<=N; j++){
              v[i][j].clear();
            }
        }

        for(int i =0; i<N; i++){
            for(int j =0; j<N; j++){
                
                for(int k=0; k<4; k++){
                    nx = i+dx[k];
                    ny = j+dy[k];

                    
                    if(nx>=0 && ny>=0 && nx<N && ny<N){
                      diff = abs(inp[nx][ny] - inp[i][j]);
                    
                        if(diff <= R && diff >= L){

                            v[i][j].push_back(make_pair(nx , ny));

                            poss = true;
                        }
                    }
                }

              
            }
        }

        

        for(int i =0; i<N; i++){
            for(int j =0; j<N; j++){
                if(!visit[i][j]){
                    sum = 0;
                    num = 0;

                    dfs(i , j);

                    avg = sum/num;
                    while(!q.empty()){
                        int f = q.front().first;
                        int s = q.front().second;
                        q.pop();

                        inp[f][s] = avg;
                    }

                }
                
            
            }
        }

        if(poss){
            day ++;
        }
        else{
            cout << day;
            return 0;
        }
    }
  
    

}

void dfs(int x , int y){
    visit[x][y] =true;
    q.push(make_pair(x,y));
    sum+= inp[x][y];
    num ++;

    for(int i =0; i<v[x][y].size(); i++){
            if(!visit[v[x][y][i].first][v[x][y][i].second]){
                dfs(v[x][y][i].first , v[x][y][i].second);
            }
        
    }
    
}
