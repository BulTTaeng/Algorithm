#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int R, C , T;

int inp[51][51];
int c[51][51];

vector<int> clean;
queue<pair<int , int>> q;

int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0,0,1, -1};

void solve();
void save_inp();
void copy_inp();
void print();
int find_sum();
void rotate();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> R >> C >> T;

    for(int i =0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> inp[i][j];

            if(inp[i][j] == -1){
                clean.push_back(i);
            }
        }
    }

    while(T--){
        solve();
        rotate();
    }

    cout << find_sum();
    return 0;
}

int find_sum(){
    int re = 2;

    for(int i =0; i<R; i++){
        for(int j =0 ; j<C; j++){
            re += inp[i][j];
        }
    }

    return re;
}

void rotate(){
    int x = clean[0];

    for(int i = x-1 ; i>0; i--){
        inp[i][0] = inp[i-1][0];
    }

    for(int i =0; i<C-1; i++){
        inp[0][i] = inp[0][i+1];
    }

    for(int i =0 ; i<x; i++){
        inp[i][C-1] = inp[i+1][C-1];
    }

    for(int i = C-1; i>1; i--){
        inp[x][i] = inp[x][i-1];
    }

    inp[x][1] = 0;

    x = clean[1];

    for(int i =x+1; i<R-1; i++){
        inp[i][0] = inp[i+1][0];
    }

    for(int i =0; i<C-1; i++){
        inp[R-1][i] = inp[R-1][i+1];
    }

    for(int i = R ; i>x; i--){
        inp[i][C-1] = inp[i-1][C-1]; 
    }

    for(int i =C; i>1; i--){
        inp[x][i] = inp[x][i-1];
    }

    inp[x][1] = 0;
    
}

void print(){
    for(int i =0; i<R ;i++){
        for(int j =0; j<C; j++){
            cout << inp[i][j] << " ";

        }
        cout << "\n";
    }
}

void copy_inp(){
    for(int i =0 ; i<R; i++){
        for(int j=0; j<C; j++){
            c[i][j] = inp[i][j];
            
            if(inp[i][j] >= 5){
                q.push({i,j});
            }
            
        }
    }
}

void save_inp(){
    for(int i =0 ; i<R; i++){
        for(int j=0; j<C; j++){
            inp[i][j] = c[i][j];
        }
    }
}

void solve(){
    copy_inp();
    int x, y, val , v2 , nx, ny;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        val = inp[x][y];
        q.pop();

        v2 = val/5;

        for(int i =0; i<4; i++){
            nx = x+dx[i];
            ny = y+dy[i];

            if(nx>=0 && ny>=0 && nx<R && ny<C){
                if(inp[nx][ny] != -1){
                    c[nx][ny] += v2;
                    c[x][y] -= v2; 
                }
            }
        }
    }

    save_inp();
}
