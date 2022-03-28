#include <iostream>
#include <vector>

using namespace std;

int N;

bool visit[10];

void dfs( vector<int> v);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    vector<int> vv;
    cin >> N;
    dfs(vv);

    return 0;
}

void dfs( vector<int> v){

    if(v.size() == N){
        for(int i=0; i<N; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=1;i<=N; i++){
        if(!visit[i]){
            visit[i] = true;
            v.push_back(i);
            dfs(v);
            v.pop_back();
            visit[i] = false;
        }
    }
}
