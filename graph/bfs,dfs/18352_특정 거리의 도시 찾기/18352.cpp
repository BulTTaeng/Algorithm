#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n , m , k, x;
vector<int> v[300002];
bool visit[300002];
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n >> m >> k >> x;
    int t1 ,t2;

    for(int i =0; i<m; i++){
        cin >> t1 >> t2;
        v[t1].push_back(t2);    
    }

    memset(visit, false ,sizeof(visit));
    queue<pair<int , int>> q;
    q.push(make_pair(x,0));
    visit[x] = true;
    int curr;
    int depth;

    while(!q.empty()){
        curr = q.front().first;
        depth = q.front().second;
        q.pop();

        if(depth == k){
            ans.push_back(curr);
        }

        for(int i =0; i<v[curr].size() ; i++){
            if(!visit[v[curr][i]]){
                q.push(make_pair(v[curr][i] , depth+1) );
                visit[v[curr][i]] = true;
            }
        }
    }

    sort(ans.begin() , ans.end() , less<int>());

    if(ans.empty()){
        cout << -1;
    }
    else{
        for(int i =0; i <ans.size() ; i++){
            cout << ans[i] << "\n";
        }
    }
    return 0;
}
