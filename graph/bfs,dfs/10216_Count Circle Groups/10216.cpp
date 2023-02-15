#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

int T , N;

bool visit[5001][5001];
int inp[5001][5001];

struct st{
    int x;
    int y;
    int r;
}typedef st;

vector<st> v;
double dis;
int xdis , ydis;
st nextone;

void dfs(st curr);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;
    int sx , sy , r;
    st temp;

    for(int qq = 0;  qq< T ;qq++){
        cin >> N;
        v.clear();
        int ans = 0;
        memset(visit ,false ,sizeof(visit));

        for(int i =0; i<N; i++){
            cin >> sx >> sy >> r;
            temp.x = sx;
            temp.y = sy;
            temp.r = r;
            v.push_back(temp);        
        }

        for(int i =0; i<v.size(); i++){
            if(!visit[v[i].x][v[i].y]){
                ans++;
                dfs(v[i]);
            }
        }

        cout << ans << "\n";

    }// end of qq


}

void dfs(st curr){
    
    visit[curr.x][curr.y] = true;

    for(int i =0; i<v.size(); i++){

        xdis = (curr.x - v[i].x) * (curr.x - v[i].x);
        ydis = (curr.y - v[i].y) * (curr.y - v[i].y);

        dis = sqrt(xdis+ydis);

        if(dis <= curr.r + v[i].r){
            if(!visit[v[i].x][v[i].y]){
                
                nextone.x = v[i].x;
                nextone.y = v[i].y;
                nextone.r = v[i].r;
                dfs(nextone);
            }
        }
        
    }
}
