#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int h , w;
int T;
string keys;

char inp[105][105];
bool havekeys[28];

bool visit[105][105];

int dx[] = {-1, 1 , 0, 0};
int dy[] = {0 , 0 , 1 , -1};
int ans;

void bfs(int startx , int starty);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;

    while(T--){
        cin >> h >> w;
        memset(inp , 0 , sizeof(inp));
        memset(visit ,false ,sizeof(visit));
        memset(havekeys ,  false ,sizeof(havekeys));
        keys.clear();

        ans = 0;

        for(int i =1; i<=h; i++){
            for(int j =1; j<=w; j++){
                cin >> inp[i][j];
            }
        }

        cin >> keys;

        if(keys != "0"){
            for(int i =0; i<keys.length() ; i++){
                havekeys[keys[i] - 'a'] = true;
            }
        }

        bfs(0,0);

        cout << ans << "\n";
    }

    return 0;

}

void bfs(int startx , int starty){

    visit[startx][starty] = true;
    queue<pair<int , int>> q;
    queue<pair<int , int>> loc[27];
    q.push({startx , starty});
    int x , y , nx , ny;

    while(!q.empty()){
        x =q.front().first;
        y = q.front().second;
        q.pop();

        for(int i =0; i<4; i++){
            nx = x+dx[i];
            ny = y+dy[i];

            if(nx >=0 && ny>=0 && nx <=h+1 && ny<= w+1){
                if(!visit[nx][ny]){
                    if(inp[nx][ny] == '*'){
                        continue;
                    }
                    else if(inp[nx][ny] >='A' && inp[nx][ny] <='Z' ){

                        if(havekeys[inp[nx][ny] - 'A']){ //키를 이미 가지고 있으면
                            q.push({nx , ny});
                            visit[nx][ny] = true;
                        }
                        else{
                            loc[inp[nx][ny] - 'A'].push({nx, ny});
                        }
                    }
                    else if(inp[nx][ny] - 'a' >=0 && inp[nx][ny] - 'a' <26){
                        q.push({nx, ny});
                        visit[nx][ny] = true;
                        if(!havekeys[inp[nx][ny] - 'a'] ){

                            havekeys[inp[nx][ny] - 'a'] = true;

                            while(!loc[inp[nx][ny] - 'a'].empty()){
                                q.push({loc[inp[nx][ny] - 'a'].front().first , loc[inp[nx][ny] - 'a'].front().second});
                                loc[inp[nx][ny] - 'a'].pop();
                            }
                        }

                    }
                    else{
                        q.push({nx,ny});
                        visit[nx][ny] = true;
                        if(inp[nx][ny] == '$'){
                            ans++;
                        }
                    }
                }


            }
        }
        
    }
}
