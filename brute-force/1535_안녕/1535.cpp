#include <iostream>

using namespace std;

int N;
int hp[21];
int joy[21];

int ans = 0;

void dfs(int health , int index , int happy);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =0; i<N; i++){
        cin >> hp[i];
    }

    for(int i =0; i<N; i++){
        cin >> joy[i];
    }


    dfs(100 , 0, 0);

    cout << ans;
    return 0;
}

void dfs(int health , int index , int happy){

    ans = max(happy , ans);

    if(index == N){
        return;
    }

    if(health-hp[index] > 0){
        dfs(health-hp[index] , index+1 , happy+ joy[index]);
    }
    dfs(health, index+1 , happy);
}
