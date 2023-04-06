#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool visit[52][52];
int inp[52][52];
vector<pair<int , int>> v;

struct st{
    int x;
    int y;
    int depth;
}typedef st;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n ,  m;

    cin >> n >> m;

    int ans = 0;

    for(int i =0; i<n; i++){
        for(int j =0 ; j <m; j++){
            cin >> inp[i][j];
            if(inp[i][j] == 0){
                v.push_back(make_pair(i,j));
            }
        }
    }

    for(int i =0; i<v.size(); i++){
        memset(visit, false  ,sizeof(visit));
        queue<st> q;
        st temp , newone , tt;

        temp.x = v[i].first;
        temp.y = v[i].second;
        temp.depth = 0;

        q.push(temp);
        visit[v[i].first][v[i].second] = true;
        int f ,s ,x , y ;

        while(!q.empty()){
            tt = q.front();
            f = tt.x;
            s = tt.y;
            q.pop();

            if(inp[f][s] == 1){
                if(tt.depth> ans){
                    ans = tt.depth;
                }
                break;
            }

            for(int j =0; j<8; j++){
                x = f+dx[j];
                y = s+dy[j];

                if(x <n && y<n && x>=0 && y>=0){
                    if(!visit[x][y] ){
                        newone.x = x;
                        newone.y = y;
                        newone.depth = tt.depth+1;
                        q.push(newone);
                        visit[x][y] = true;
                    }
                }
            }

        }
    }

    cout << ans;
    return 0;
}
