#include<iostream>
#include <vector>
#include <queue>

using namespace std;

int N , M;
vector<int> v[1001];
int indgree[1001];
queue<int> q;
vector<int> ans;

void topo();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    int temp, t ;
    int prev = -1;

    for(int i =0; i<M; i++){
        prev = -1;
        cin >> temp;
        for(int j =0; j<temp; j++){
            cin >> t;
            if(prev == -1){
                prev=t;
            }
            else{
                indgree[t]++;
                v[prev].push_back(t);
                prev =t;
            }
        }
    }

    topo();

    if(ans.size() == N){
        for(int i =0; i<ans.size(); i++){
            cout << ans[i] << "\n";
        }
    }
    else{
        cout << 0;
    }

    return 0;
}

void topo(){
    for(int i =1 ; i<=N; i++){
        if(indgree[i] == 0){
            q.push(i);
            ans.push_back(i);
        }
    }
    int n , next;

    while(!q.empty()){
        n= q.front();
        q.pop();

        for(int i =0; i<v[n].size() ; i++){
            next = v[n][i];

            indgree[next]--;

            if(indgree[next] == 0){
                ans.push_back(next);
                q.push(next);
            }
        }
    }
}
