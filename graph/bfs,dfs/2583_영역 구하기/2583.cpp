#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int m , n ,k,nx , ny;
bool visit[102][102];

int dx[] = {-1, 1, 0,0};
int dy[] = {0 , 0 ,1 ,-1};

vector<int> v;
void dfs(int x , int y);
int temp =0;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> m >> n >> k;
    int x1,x2,y1,y2;
    
    memset(visit, false , sizeof(visit));
    
    for(int i =0; i<k; i++){
        cin >> x1 >> y1 >> x2 >> y2;

        for(int j = y1; j<y2; j++){
            for(int kk = x1; kk<x2; kk++){
                visit[j][kk] = true;
            }
        }
    }

    int a=0;

    for(int i =0; i<m; i++){
        for(int j = 0 ; j<n; j++){

            if(visit[i][j] == false){
                temp = 0;
                dfs(i,j);
                a++;
                v.push_back(temp);
            }
            
        }
    }

    cout << a << "\n";
    sort(v.begin() , v.end() , less<int>());
    for(int i =0; i<v.size(); i++){
        cout << v[i] <<" ";
    }
    return 0;

}

void dfs(int x , int y){
    visit[x][y] = true;
    temp++;
    for(int i =0; i<4 ; i++){
        nx = x+dx[i];
        ny = y+dy[i];

        if(nx>=0 && ny>=0 && nx<m && ny<n){
            if(!visit[nx][ny] ){
                dfs(nx,ny);
            }
        }
    }

    return;
}
