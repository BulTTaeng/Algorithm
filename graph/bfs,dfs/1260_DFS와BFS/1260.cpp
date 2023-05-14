#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> v[1001];
bool visit[1001];

void BFS(int start);
void DFS(int start);

bool comp(int &x , int &y){
    return x < y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int N , M ,V;

    cin >> N >> M >> V;
    
    int x, y;

    for(int i = 0; i<M; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i =1; i<=N; i++){
        sort(v[i].begin(), v[i].end() , comp);
    }
    
    memset(visit, false ,sizeof(visit));
    DFS(V);
    cout << "\n";
    memset(visit, false ,sizeof(visit));
    BFS(V);

    return 0;
}

void BFS(int start){
    queue<int> q;

    q.push(start);

    int temp;

    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout << temp <<" ";
        visit[temp] = true;

        for(int i =0; i<v[temp].size(); i++){
            if(!visit[v[temp][i]]){
                q.push(v[temp][i]);
                visit[v[temp][i]] = true;
            }
        }
    }
}

void DFS(int start){
    if(visit[start]){
        return;
    }

    else{
        cout << start<< " ";
        visit[start] = true;
        for(int i =0; i<v[start].size(); i++){
            DFS(v[start][i]);
        }
    }
}
