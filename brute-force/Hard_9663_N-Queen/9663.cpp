#include <iostream>
#include <cmath>

using namespace std;

int N;
int loc[16];
int ans = 0;

void dfs(int num);
bool possible(int y);


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    dfs(0);

    cout << ans;
    return 0 ;
}

void dfs(int num){

    if(num == N){
        ans++;
        return;
    }

    for(int i=0; i <N; i++){
        loc[num] = i;
        if(possible(num)){
            dfs(num+1);
        }
    }
}

bool possible(int y){
    for(int i =0; i<y; i++){
        if(loc[y] == loc[i] || abs(loc[i] - loc[y]) == y-i){
            return false;
        }
    }

    return true;
}
