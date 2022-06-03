#include <iostream>
#include <algorithm>

using namespace std;

int N;
int inp[21][21];
int ans = -1;

void dfs(int count);
void move_left();
void move_right();
void move_up();
void move_down();
void copy_inp_save(int save[21][21]);
void copy_save_inp(int save[21][21]);
void find_max();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =0; i<N; i++){
        for(int j =0 ; j<N ; j++){
            cin >> inp[i][j];
        }
    }

    dfs(0);

    cout << ans;
    return 0;
}

void dfs(int count){
    
    if(count == 5){
        find_max();
        return;
    }

    int save[21][21];

    copy_inp_save(save);

    move_left();
    dfs(count+1);
    copy_save_inp(save);

    move_right();
    dfs(count+1);
    copy_save_inp(save);

    move_up();
    dfs(count+1);
    copy_save_inp(save);

    move_down();
    dfs(count+1);
    copy_save_inp(save);
}

void move_left(){

    bool check = true;

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            if(inp[i][j] == 0){
                check = true;
                for(int k=j; k<N; k++){
                    if(inp[i][k] != 0){
                        swap(inp[i][j] , inp[i][k]);
                        check = false;
                        break;
                    }
                }

                if(check){
                    break;
                }
            }

            if(j >0 && inp[i][j-1] == inp[i][j]){
                inp[i][j-1] = inp[i][j-1]*2;
                inp[i][j] = 0;

                for(int k=j; k<N; k++){
                    if(inp[i][k] != 0){
                        swap(inp[i][j] , inp[i][k]);
                        break;
                    }
                }
            }
        }
    }
}

void move_right(){

    bool check = true;

    for(int i =0; i<N; i++){
        for(int j =N-1; j>=0; j--){
            if(inp[i][j] == 0){
                check = true;
                for(int k=j; k>=0; k--){
                    if(inp[i][k] != 0){
                        swap(inp[i][j] , inp[i][k]);
                        check = false;
                        break;
                    }
                }

                if(check){
                    break;
                }
            }

            if(j != N-1 && inp[i][j+1] == inp[i][j]){
                inp[i][j+1] = inp[i][j+1]*2;
                inp[i][j] = 0;

                for(int k=j; k>=0; k--){
                    if(inp[i][k] != 0){
                        swap(inp[i][j] , inp[i][k]);
                        break;
                    }
                }
            }
        }
    }
}

void move_up(){

    bool check = true;

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            if(inp[j][i] == 0){
                check = true;
                for(int k=j; k<N; k++){
                    if(inp[k][i] != 0){
                        swap(inp[j][i] , inp[k][i]);
                        check = false;
                        break;
                    }
                }

                if(check){
                    break;
                }
            }

            if(j >0 && inp[j-1][i] == inp[j][i]){
                inp[j-1][i] = inp[j-1][i]*2;
                inp[j][i] = 0;

                for(int k=j; k<N; k++){
                    if(inp[k][i] != 0){
                        swap(inp[j][i] , inp[k][i]);
                        break;
                    }
                }
            }
        }
    }
}

void move_down(){

    bool check = true;

    for(int i =0; i<N; i++){
        for(int j =N-1; j>=0; j--){
            if(inp[j][i] == 0){
                check = true;
                for(int k=j; k>=0; k--){
                    if(inp[k][i] != 0){
                        swap(inp[j][i] , inp[k][i]);
                        check = false;
                        break;
                    }
                }

                if(check){
                    break;
                }
            }

            if(j !=N-1 && inp[j+1][i] == inp[j][i]){
                inp[j+1][i] = inp[j+1][i]*2;
                inp[j][i] = 0;

                for(int k=j; k>=0; k--){
                    if(inp[k][i] != 0){
                        swap(inp[j][i] , inp[k][i]);
                        break;
                    }
                }
            }
        }
    }
}



void copy_inp_save(int save[21][21]){
    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            save[i][j] = inp[i][j];
        }
    }
}

void copy_save_inp(int save[21][21]){
    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            inp[i][j] = save[i][j];
        }
    }
}

void find_max(){
    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            ans = max(ans , inp[i][j]);
        }
    }
}
