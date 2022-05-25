#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> v[32001];
vector<int> ans;
int indegree[32001];
int N , M;

void topo();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    memset(indegree , 0, sizeof(indegree));

    cin >> N >> M;
    int s,e ;

    for(int i=0; i<M; i++){
        cin >> s >> e;
        v[s].push_back(e);
        indegree[e]++;
        
    }    
    
    topo();

    for(int i =0; i< ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}

void topo(){
    priority_queue<int , vector<int> , greater<>> pq;

    for(int i=1; i<=N; i++){
        if(indegree[i] == 0){
            pq.push(i);
        }
    }
    int curr , next;
    while(!pq.empty()){
        curr =pq.top();
        ans.push_back(curr);
        pq.pop();

        for(int i =0; i<v[curr].size(); i++){
            next = v[curr][i];
            indegree[next]--;
            if(indegree[next] == 0){
                pq.push(next);
            }
        }
    }
}
