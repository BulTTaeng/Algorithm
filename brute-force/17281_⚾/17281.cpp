#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
int inp[51][10];
bool visit[10];
int player[10];
bool loc[4];

int ans = 0;

void baseball();
void dfs(int num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    for(int i =1; i<=N; i++){
        for(int j =1; j<=9; j++){
            cin >> inp[i][j];
        }
    }

    memset(visit ,false ,sizeof(visit));
    visit[4] = true;
    player[4] =1;
    dfs(2);

    cout << ans;
    return 0;
}

void dfs(int num){
    if(num == 10){
        baseball();
        return;
    }

    for(int i =1; i<=9; i++){
        if(!visit[i]){
            visit[i] = true;
            player[i] = num;
            dfs(num+1);
            visit[i] = false;
        }
    }
}

void baseball(){
    int score = 0;
    int curr_player = 1;
    int action;

    for(int i =1; i<=N; i++){
        int num_out= 0;
        bool end = false;
        memset(loc , false ,sizeof(loc));

        while(true){
            for(int j =curr_player; j<=9 ; j++){
                action = inp[i][player[j]];

                if(action == 0){
                    num_out++;
                }
                else if(action == 1){
                    if(loc[3]){
                        loc[3] = false;
                        score++;
                    }
                    if(loc[2]){
                        loc[3] = true;
                        loc[2] = false;
                    }
                    if(loc[1]){
                        loc[2] = true;
                        loc[1] = false;
                    }

                    loc[1] = true;
                }
                else if(action == 2){
                    if(loc[3]){
                        loc[3] = false;
                        score++;
                    }
                    if(loc[2]){
                        loc[2] = false;
                        score++;
                    }
                    if(loc[1]){
                        loc[3] = true;
                        loc[1] = false;
                    }

                    loc[2] = true;
                }
                else if(action == 3){
                    if(loc[3]){
                        loc[3] = false;
                        score++;
                    }
                    if(loc[2]){
                        loc[2] = false;
                        score++;
                    }
                    if(loc[1]){
                        loc[1] = false;
                        score++;
                    }

                    loc[3] = true;
                }
                else{
                   if(loc[3]){
                        loc[3] = false;
                        score++;
                    }
                    if(loc[2]){
                        loc[2] = false;
                        score++;
                    }
                    if(loc[1]){
                        loc[1] = false;
                        score++;
                    }
                    score++;
                }

                if(num_out == 3){
                    end = true;
                    if(curr_player == 9){
                        curr_player=1;
                    }
                    else{
                        curr_player = j+1;
                    }
                    break;
                }

            }
            if(end){
                break;
            }

            curr_player = 1;

        }
    }

    ans = max(ans , score);
}
