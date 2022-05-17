#include <iostream>

using namespace std;

int N;
char ans[3072][6143];

void solve(int size , int x, int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i<N; i++){
        for(int j =0; j<N*2-1; j++){
            ans[i][j] = ' ';
        }
    }

    solve(N , 0, N-1);

    for(int i = 0; i<N; i++){
        for(int j =0; j<N*2-1; j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}

void solve(int size , int x, int y){
    if(size == 3){
        ans[x][y] = '*';
        ans[x+1][y-1] = '*';
        ans[x+1][y+1] = '*';

        for(int i =y-2; i<=y+2; i++){
            ans[x+2][i] = '*';
        }

        return;
    }

    solve(size/2 , x , y);
    solve(size/2 , x+size/2 , y-size/2);
    solve(size/2 , x+size/2 , y+size/2);
}
