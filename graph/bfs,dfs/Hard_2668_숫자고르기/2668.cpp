#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> ans;

bool visit[101];

int inp[101];
int N;

void dfs(int start , int cur);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =1; i<=N; i++){
        cin >> inp[i];
    }

    for(int i=1 ; i<=N; i++){
        memset(visit , false, sizeof(visit));
        dfs(i,i);
    }

    cout << ans.size() << "\n";

    for(int i =0; i<ans.size(); i++){
        cout << ans[i] << "\n";
    }

    return 0;
    
}

void dfs(int start , int cur){

    
    if(!visit[cur]){
        visit[cur] = true;
        dfs(start , inp[cur]);
    }
    else if(cur == start){
        ans.push_back(start);
        return;
    }
}
