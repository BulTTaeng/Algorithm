#include <iostream>

using namespace std;

int N , T;

int inp[22];
int ans = 0;

void dfs(int idx ,int num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> T;

    for(int i =0; i<N; i++){
        cin >> inp[i];
    }

    dfs(0,0);
    cout << ans;
    return 0;
    
}

void dfs(int idx ,int num){

    if(idx == N){
        return;
    }
    
    
    if(num + inp[idx] == T){
        ans++;
    }
    

    
    dfs(idx+1, num+inp[idx]);
    dfs(idx+1 , num);
    
}
