#include <iostream>
#include <vector>

using namespace std;

int N , M;
int inp[9][9];
vector<pair<int , int>>camera;

int ans = 9999;

int monitoring(int x, int y , int dir);
void cm(int x, int y , int dir);
void simulate(int depth , int num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    int n = 0;

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            cin >> inp[i][j];

            if(inp[i][j] != 0 && inp[i][j] != 6){
                camera.push_back({i,j});
            }

            if(inp[i][j] == 0){
                n++;
            }
        }
    }

    simulate(0 , n);

    cout << ans;

    return 0;
}

int monitoring(int x, int y , int dir){
    
    int re = 0;
    
    if(dir == 0){
        //동
        for(int i =y; i<M; i++){
            if(inp[x][i] == 0){
                inp[x][i] = 7;
                re++;
            }
            else if(inp[x][i] == 6){
                break;
            }
            else if(inp[x][i] >= 7){
                inp[x][i] += 7;
            }
        }
    }
    else if(dir == 1){
        //서
        for(int i =y; i>=0; i--){
            if(inp[x][i] == 0){
                inp[x][i] = 7;
                re++;
            }
            else if(inp[x][i] == 6){
                break;
            }
            else if(inp[x][i] >= 7){
                inp[x][i] += 7;
            }
        }
    }
    else if(dir == 2){
        //남
        for(int i =x; i<N; i++){
            if(inp[i][y] == 0){
                inp[i][y] = 7;
                re++;
            }
            else if(inp[i][y] == 6){
                break;
            }
            else if(inp[i][y] >= 7){
                inp[i][y] += 7;
            }
        }
    }
    else if(dir == 3){
        //북
        for(int i =x; i>=0; i--){
            if(inp[i][y] == 0){
                inp[i][y] = 7;
                re++;
            }
            else if(inp[i][y] == 6){
                break;
            }
            else if(inp[i][y] >= 7){
                inp[i][y] += 7;
            }
        }
    }

    return re;
}

void cm(int x, int y , int dir){
    
    
    if(dir == 0){
        //동
        for(int i =y; i<M; i++){
            if(inp[x][i] >= 7){
                inp[x][i] = inp[x][i] - 7;
                
            }
            else if(inp[x][i] == 6){
                break;
            }
        }
    }
    else if(dir == 1){
        //서
        for(int i =y; i>=0; i--){
            if(inp[x][i] >= 7){
                inp[x][i] = inp[x][i] - 7;
            }
            else if(inp[x][i] == 6){
                break;
            }
        }
    }
    else if(dir == 2){
        //남
        for(int i =x; i<N; i++){
            if(inp[i][y] >= 7){
                inp[i][y] = inp[i][y]-7;
            }
            else if(inp[i][y] == 6){
                break;
            }
        }
    }
    else if(dir == 3){
        //북
        for(int i =x; i>=0; i--){
            if(inp[i][y] >= 7){
                inp[i][y] = inp[i][y]-7;
            }
            else if(inp[i][y] == 6){
                break;
            }
        }
    }

    return;
}

void simulate(int depth , int num){
    
    if(depth == camera.size()){
        ans = min(ans , num);
        return;
    }


    int c = inp[camera[depth].first][camera[depth].second];
    int re = 0;
    int re1 , re2 , re3;
    if(c == 1){
        for(int i =0; i<4; i++){
            re = monitoring(camera[depth].first , camera[depth].second , i);
            simulate(depth+1 , num - re);
            cm(camera[depth].first , camera[depth].second , i);
        }
    }
    else if(c == 2){
        re = monitoring(camera[depth].first , camera[depth].second , 0);
        re1 =monitoring(camera[depth].first , camera[depth].second , 1);
        simulate(depth+1 , num - re - re1);
        cm(camera[depth].first , camera[depth].second , 0);
        cm(camera[depth].first , camera[depth].second , 1);

        re2 = monitoring(camera[depth].first , camera[depth].second , 2);
        re3 = monitoring(camera[depth].first , camera[depth].second , 3);
        simulate(depth+1 , num - re2 - re3);
        cm(camera[depth].first , camera[depth].second , 2);
        cm(camera[depth].first , camera[depth].second , 3);
    }
    else if(c == 3){
        re3 = monitoring(camera[depth].first , camera[depth].second , 3);
        re = monitoring(camera[depth].first , camera[depth].second , 0);
        simulate(depth+1 , num - re - re3);
        cm(camera[depth].first , camera[depth].second , 3);

        //re = monitoring(camera[depth].first , camera[depth].second , 0);
        re2 =monitoring(camera[depth].first , camera[depth].second , 2);
        simulate(depth+1 , num - re2 - re);
        cm(camera[depth].first , camera[depth].second , 0);
        //cm(camera[depth].first , camera[depth].second , 2);

        //re = monitoring(camera[depth].first , camera[depth].second , 2);
        re1 =monitoring(camera[depth].first , camera[depth].second , 1);
        simulate(depth+1 , num - re1 - re2);
        cm(camera[depth].first , camera[depth].second , 2);
        //cm(camera[depth].first , camera[depth].second , 1);

        //re = monitoring(camera[depth].first , camera[depth].second , 1);
        re3 =monitoring(camera[depth].first , camera[depth].second , 3);
        simulate(depth+1 , num - re1 - re3);
        cm(camera[depth].first , camera[depth].second , 1);
        cm(camera[depth].first , camera[depth].second , 3);
    }
    else if(c == 4){
        re1 = monitoring(camera[depth].first , camera[depth].second , 1);
        re3 =monitoring(camera[depth].first , camera[depth].second , 3);
        re =monitoring(camera[depth].first , camera[depth].second , 0);
        simulate(depth+1 , num - re1 - re3 - re);
        cm(camera[depth].first , camera[depth].second , 1);

        re2 =monitoring(camera[depth].first , camera[depth].second , 2);
        simulate(depth+1 , num - re2 - re3 - re);
        cm(camera[depth].first , camera[depth].second , 3);

        re1 = monitoring(camera[depth].first , camera[depth].second , 1);
        simulate(depth+1 , num - re1 - re2 - re);
        cm(camera[depth].first , camera[depth].second , 0);

        re3 = monitoring(camera[depth].first , camera[depth].second , 3);
        simulate(depth+1 , num - re1 - re2 - re3);
        cm(camera[depth].first , camera[depth].second , 3);
        cm(camera[depth].first , camera[depth].second , 1);
        cm(camera[depth].first , camera[depth].second , 2);
        
    }
    else{
        re = 0;

        for(int i =0; i<4; i++){
            re += monitoring(camera[depth].first , camera[depth].second , i);
        }
        simulate(depth+1 , num - re);
        for(int i =0; i<4; i++){
            cm(camera[depth].first , camera[depth].second , i);
        }

    }
}
