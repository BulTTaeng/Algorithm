#include <iostream>
#include <cstring>

using namespace std;

int inp[11][11];
bool l[21];
bool r[21];

int N;
int ans[2];

void solve(int x , int y , int num , int color);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =0; i<N; i++){
        for(int j =0; j<N;j++){
            cin >> inp[i][j];
        }
    }

    memset(l , false, sizeof(l));
    memset(r , false, sizeof(r));
    memset(ans , 0 , sizeof(ans));

    solve(0,0,0,0);
    solve(0,1,0,1);

    cout << ans[0] + ans[1];
    return 0;
}


void solve(int x , int y , int num , int color){

    if(y>=N){
        x++;
        if(y%2 == 0) y =1;
        else y = 0;
    }

    if(x>= N){
        ans[color] = max(ans[color] , num);
        return;
    }

    if(inp[x][y] == 1 && !l[x-y+N-1] && !r[x+y]){
        l[x-y+N-1] = true;
        r[x+y] = true;
        solve(x, y+2 , num+1 , color);
        l[x-y+N-1] = false;
        r[x+y] = false;
    }
    solve(x, y+2 , num , color);


}
