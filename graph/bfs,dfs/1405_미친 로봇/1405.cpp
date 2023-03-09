#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool visit[30][30];
vector<double> v;
int dx[] = {0,0,1, -1};
int dy[] = {1,-1 , 0 ,0};
int N , e ,w, s ,n;

double ans;

double dfs(int x, int y, int num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> e >> w >> s >> n;

    v.push_back(double(e)/100);
    v.push_back(double(w)/100);
    v.push_back(double(s)/100);
    v.push_back(double(n)/100);

    memset(visit ,false ,sizeof(visit));
    
    //visit[15][15] = -1;

    ans = dfs(15 , 15 ,0);
    
    /*for(int i =0; i<30; i++){
        for(int j =0; j<30 ; j++){
            cout << visit[i][j] << " ";
        }
        cout <<"\n";
    }*/

    cout.precision(10);
    cout << fixed << ans << endl;
    return 0;
}

double dfs(int x, int y, int num)
{
    if (num == N) return 1.0;
 
    visit[x][y] = true;
    double Result = 0.0;
 
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        if (visit[nx][ny] == true) continue;
        Result = Result + v[i] * dfs(nx, ny, num + 1);
    }
 
    visit[x][y] = false;
    return Result;
}
