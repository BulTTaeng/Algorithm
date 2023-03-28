#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<pair<int , int>> v;
int inp[502][502];
bool visit[502][502];

int n , m , temp;

int dx[] = {-1, 1 ,0 ,0};
int dy[] ={0 , 0 ,1 , -1};

void dfs(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i =0; i<n;i++){
        for(int j =0; j<m; j++){
            cin >> inp[i][j];
            if(inp[i][j] == 1) v.push_back(make_pair(i,j));
        }
    }

    int f ,s ,ans = 0 , num_img = 0;

    for(int i =0; i<v.size(); i++){
        f = v[i].first;
        s = v[i].second;

        if(visit[f][s]){
            continue;
        }

        visit[f][s] = true;
        temp = 1;
        num_img++;
        dfs(f,s);
        ans = max(temp, ans);
    }
    cout << num_img << "\n" << ans ;
    return 0;
}

void dfs(int x ,int y){
    visit[x][y] = true;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && ny>=0 && nx<n && ny<m){
            if(!visit[nx][ny] && inp[nx][ny] == 1){
                temp++;
                dfs(nx, ny);
            }
        }
    }    
}
