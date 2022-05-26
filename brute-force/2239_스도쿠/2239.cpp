#include <iostream>
#include <cstring>

using namespace std;

char cinp[10][10];
int inp[10][10];
bool r[10][10];
bool c[10][10];
bool square[10][10];


void dfs(int loc);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    memset(r ,false ,sizeof(r));
    memset(c ,false ,sizeof(c));

    for(int i =0; i<9; i++){
        for(int j =0; j<9; j++){
            cin >> cinp[i][j];
            inp[i][j] = cinp[i][j] - '0';
            r[i][inp[i][j]] = true;
            c[j][inp[i][j]] = true;
            square[(i/3) *3 + (j/3)][inp[i][j]] = true;
        }
    }

    dfs(0);
    return 0;
}

void dfs(int loc){
    int x = loc / 9;
    int y = loc % 9;

    if(loc == 81){
        for(int i =0; i<9; i++){
            for(int j =0; j<9; j++){
                cout << inp[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }

    if(inp[x][y] == 0){
        for(int i =1; i<=9; i++){
            if(!r[x][i] && !c[y][i] && !square[(x/3) *3 + (y/3)][i] ){
                r[x][i] = c[y][i] = square[(x/3) *3 + (y/3)][i] = true;
                inp[x][y] = i;
                dfs(loc+1);
                r[x][i] = c[y][i] = square[(x/3) *3 + (y/3)][i] = false;
                inp[x][y] = 0;
            }
        }
    }
    else{
        dfs(loc+1);
    }
}

