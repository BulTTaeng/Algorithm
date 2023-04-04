#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

bool visit[102][102];
char inp[102][102];
vector<pair<int , int>> w;
vector<pair<int , int>> b;

int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0, 0 , -1 , 1};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n , m;

    cin >> n >> m;

    for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            cin >> inp[i][j];
            if(inp[i][j] == 'W'){
                w.push_back(make_pair(i,j));
            }
            else{
                b.push_back(make_pair(i,j));
            }
        }
    }

    memset(visit ,false ,sizeof(visit));
    int f ,s;
    int ans_w =0, ans_b =0, num_w = 1 , num_b = 1;

    for(int i =0; i<w.size(); i++){
        f = w[i].first;
        s = w[i].second;

        if(visit[f][s]){
            continue;
        }    

        queue<pair<int , int>> q;
        q.push(make_pair(f,s));
        visit[f][s] = true;
        int x , y;
        
        num_w = 1;

        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();

            for(int j =0 ; j<4 ; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(nx >=0  && ny >=0 && nx <m && ny <n){
                    if(!visit[nx][ny] && inp[nx][ny] == 'W'){
                        num_w++;
                        q.push(make_pair(nx, ny));
                        visit[nx][ny] = true;
                    }
                }
            }


        }
        ans_w += (num_w * num_w);

    }

    for(int i =0; i<b.size(); i++){
        f = b[i].first;
        s = b[i].second;

        if(visit[f][s]){
            continue;
        }    

        queue<pair<int , int>> q;
        q.push(make_pair(f,s));
        visit[f][s] = true;
        int xx , xy;
        
        num_b = 1;

        while(!q.empty()){
            xx = q.front().first;
            xy = q.front().second;
            q.pop();

            for(int j =0 ; j<4 ; j++){
                int nx = xx + dx[j];
                int ny = xy + dy[j];

                if(nx >=0  && ny >=0 && nx <m && ny <n){
                    if(!visit[nx][ny] && inp[nx][ny] == 'B'){
                        num_b ++;
                        q.push(make_pair(nx, ny));
                        visit[nx][ny] = true;
                    }
                }
            }


        }
        ans_b += (num_b * num_b);

    }
    cout << ans_w << " " << ans_b;
    return 0;

}
