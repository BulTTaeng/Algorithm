#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N , M;
int indegree[32002];
vector<int> v[32002];
vector<int> ans;
queue<int> q;

void topology();

int main(){

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> M;
    
    int t1 , t2;
    memset(indegree , 0 , sizeof(indegree));

    for(int i =0; i<M; i++){
        cin >> t1 >> t2;
        indegree[t2]++;
        v[t1].push_back(t2);
    }

    topology();

    for(int i =0; i<ans.size() ; i++){
        cout << ans[i] << " ";
    }

    return 0;
}

void topology(){
    for(int i =1; i<=N; i++){
        if(indegree[i] == 0){
            q.push(i);
            ans.push_back(i);
        }
    }

    int curr , next;

    while(!q.empty()){
        curr = q.front();
        q.pop();

        for(int i =0; i<v[curr].size(); i++){
            next = v[curr][i];
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
                ans.push_back(next);
            }
        }
    }


}
