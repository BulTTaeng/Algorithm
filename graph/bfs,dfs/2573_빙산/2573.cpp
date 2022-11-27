#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

struct st{
    int x;
    int y;
    int d;
}typedef st;

int inp[301][301];
bool visit[301][301];
vector<pair <int , int>> v;
queue<st> q;

int N , M;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0 , 1 ,-1};

void dfs(int x, int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    st temp;

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            cin >> inp[i][j];
            if(inp[i][j] != 0){
                v.push_back(make_pair(i,j));
                temp.x = i;
                temp.y = j;
                temp.d = 0;
                q.push(temp);
            }
        }
    }

    int x , y , d;
    int ans = 0;
    int depth = 1;
    int num = 0;
    int t =0;

    st newone;

    queue<st> save;

    int  a , b, c;

    while(!q.empty()){
        x = q.front().x;
        y= q.front().y;
        d = q.front().d;

        q.pop();

        num = 0;

        if(d == depth){
            while(!save.empty()){
                a = save.front().x;
                b = save.front().y;
                c= save.front().d;
                save.pop();

                inp[a][b] = c;
            }
            memset(visit ,false ,sizeof(visit));
            for(int i =0; i<N; i++){
                for(int j =0; j<M; j++){
                    if(!visit[i][j] && inp[i][j] > 0){
                        num++;
                        dfs(i , j);
                    }
                }
            }

            /*cout << "\n";
            for(int i =0; i<N; i++){
                for(int j =0; j<M; j++){
                    cout << inp[i][j] << " ";
                }
                cout <<"\n";
            }*/
            
            depth++;
        }

        if(num >= 2){
            ans = d;
            break;
        }

        t = inp[x][y];

        for(int i =0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx >=0 && ny>=0 && nx<N && ny<M){
                if(inp[nx][ny] <= 0){
                    t--;
                }
            }

        }

        newone.x = x;
        newone.y = y;
        newone.d = t;
        save.push(newone);

        if(t>0){
            temp.x = x;
            temp.y = y;
            temp.d = d+1;
            q.push(temp);
        }
        
        
    }
    

    cout << ans;
    return 0;
}

void dfs(int x, int y){
    visit[x][y] = true;

    for(int i =0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx >=0 && ny>=0 && nx<N && ny<M){
            if(inp[nx][ny] > 0 && !visit[nx][ny]){
                dfs(nx, ny);
            }
        }

    }
}
