#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int S[9];
int W[9];

bool visit[9];
int ans = 0;
int N;

void dfs(int num , int grab);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =0; i<N; i++){
        cin >> S[i] >> W[i];
    }

    memset(visit ,false , sizeof(visit));
    dfs(0,0);

    cout << ans;
    return 0;

}

void dfs(int num , int grab){

    ans = max(ans , num);

    if(grab == N){
        return;
    }

    
    if(visit[grab]){ // if next egg is breaked
        dfs(num , grab+1);
    }
    else{
        int inc = 0;
                
        for(int j=0; j<N; j++){
            if(grab == j){
                continue;
            }

            if(!visit[j]){ // if j is not breaked
                inc = 0;
                S[j] = S[j] - W[grab];
                S[grab] = S[grab] - W[j];

                if(S[j] <= 0){
                    visit[j] = true;
                    inc++;
                }

                if(S[grab] <=0){
                    visit[grab] = true;
                    
                    inc++;
                }

                dfs(num+inc , grab+1);
                

                visit[j] = false;
                visit[grab] = false;
                S[j] = S[j] + W[grab];
                S[grab] = S[grab] + W[j];
            }
        }
    }

}
