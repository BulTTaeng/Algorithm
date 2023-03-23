#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[27][27];
char inp[27][27];
int n ;
vector<int> v;

int dx[] = {-1, 1 , 0,0};
int dy[] = {0,0,1,-1};
int temp;

void dfs(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int ans =0;

    cin >> n;

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin >> inp[i][j];
        }
    }

    memset(visit ,false ,sizeof(visit));

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            if(!visit[i][j] && inp[i][j] == '1'){
                temp =0;
                dfs(i,j);
                ans++;
                v.push_back(temp);
            }
        }
    }

    sort(v.begin() , v.end() , less<int>());
    cout << ans << "\n";
    for(int i =0; i<v.size() ; i++){
        cout << v[i]<<"\n";
    }
    return 0;
}

void dfs(int x , int y){
    visit[x][y] = true;
    temp++;

    for(int i =0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && ny>=0 && nx<n && ny <n){
            if(!visit[nx][ny] && inp[nx][ny] == '1'){
                dfs(nx, ny);
            }
        }
    }

}
