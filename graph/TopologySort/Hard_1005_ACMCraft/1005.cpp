#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int  T , N , K;
int inp[1001];
int indgree[1001];
int dist[1001];
int target;

void topo(vector<int> v[1001]);

#define INF 987654321

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;
    int t1 ,t2;

    while(T--){
        cin >> N >> K;

        for(int i =1; i<=N; i++){
            cin>> inp[i];
        }

        memset(indgree  , 0 , sizeof(indgree));
        memset(dist , 0 , sizeof(dist));

        vector<int> v[1001];

        for(int i =0; i<K; i++){
            cin >> t1 >> t2;
            indgree[t2]++;
            v[t1].push_back(t2);
        }

        cin >> target;
        topo(v);
        cout << dist[target] << "\n";
    }
}

void topo(vector<int> v[1001]){
    queue<int> q;

    for(int i =1 ; i<=N; i++){
        if(indgree[i] == 0){
            q.push(i);
            dist[i] = inp[i];
        }
    }
    int temp;

    while(!q.empty()){
        temp = q.front();
        q.pop();

        for(int i =0; i<v[temp].size(); i++){
            
            if(dist[v[temp][i]] < dist[temp] + inp[v[temp][i]]){
                dist[v[temp][i]] = dist[temp] + inp[v[temp][i]];
            }   

            if(--indgree[v[temp][i]] == 0){
                q.push(v[temp][i]);
            }

        }
    }
}
