#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int inp[100002];
int indegree[100002];

int N , T ,ans;

int topo();

int main(){

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;

    while(T--){
        cin >> N;

        memset(inp , 0, sizeof(inp));
        memset(indegree , 0 , sizeof(indegree));
        
        for(int i =1 ; i<=N; i++){
            cin >> inp[i];
            indegree[inp[i]]++;
        }

        ans = topo();
        cout << N-ans << "\n";
    }

    return 0;
}


int topo(){

    int re = N;
    queue<int> q;

    for(int i =1; i<=N; i++){
        if(indegree[i] == 0){
            q.push(i);
            re--;
        }
    }
    int x;

    while(!q.empty()){
        x = q.front();
        q.pop();
        indegree[inp[x]]--;
        if(indegree[inp[x]] == 0){
            
            q.push(inp[x]);
            re--;
        }
    }

    return re;
}
