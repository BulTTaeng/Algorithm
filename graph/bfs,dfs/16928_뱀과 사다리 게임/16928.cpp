#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int snack[102];
int ladder[102];
bool visit[102];

int N , M;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >>M;
    int x , y;
    memset(ladder , 0 , sizeof(ladder));
    memset(snack , 0 , sizeof(snack));
    for(int i =0; i<N; i++){
        cin >> x >> y;
        ladder[x] = y;
    }

    for(int i =0; i<M; i++){
        cin >> x >> y;
        snack[x] = y;    
    }
    memset(visit , false ,sizeof(visit));

    queue<pair<int , int>>q;
    q.push(make_pair(1,0));
    int f , d;
    int ans = 0;

    visit[1] = true;

    while(!q.empty()){
        f = q.front().first;
        d = q.front().second;
        q.pop();

        if(f == 100){
            ans = d;
            break;
        }


            for(int i =1; i<=6 ; i++){
                if(f+i <=100){
                    if(ladder[f+i] != 0){
                        if(!visit[ladder[f+i]] && !visit[f+i]){
                            q.push(make_pair(ladder[f+i] , d+1));
                            visit[ladder[f+i]] = true;
                            visit[f+i] = true;
                        }
                    }

                    else if(snack[f+i] != 0){
                        if(!visit[snack[f+i]] && !visit[f+i]){
                            q.push(make_pair(snack[f+i] , d+1));
                            visit[snack[f+i]] = true;
                            visit[f+i] = true;
                        }
                    }

                    else if(!visit[f+i]){
                        q.push(make_pair(f+i , d+1));
                        visit[f+i] = true;
                    }
                }
            }
        

        

    }

    cout << ans;
    return 0;

}
