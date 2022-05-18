#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N , M;
int S , D;
vector<pair<int , int>> v[1001];
int dist[1001];
int path[1001];
vector<int> ans;
priority_queue<pair<int , int> , vector<pair<int , int>> , greater<>> pq;

#define INF 1087654321

void dij();
void find_path(int curr);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    int a,b,c;

    for(int i = 1; i<=M; i++){
        cin >> a >> b >> c;
        v[a].push_back({c,b});
    }

    cin >> S >> D;

    for(int i=1; i<=N; i++){
        dist[i] = INF;
    }

    dij();
    find_path(D);
    
    cout << dist[D] << "\n";
    cout << ans.size() << "\n";

    for(int i = ans.size()-1 ; i>=0 ; i--){
        cout << ans[i] << " ";
    }

    return 0;

}

void dij(){
    dist[S] = 0;

    pq.push({0,S});
    int dis , curr , next , ndis;

    while(!pq.empty()){
        dis = pq.top().first;
        curr = pq.top().second;
        pq.pop();

        if(dis > dist[curr]){
            continue;
        }

        for(int i =0; i<v[curr].size() ; i++){
            ndis = v[curr][i].first;
            next = v[curr][i].second;

            if(dist[next] > dis + ndis){
                dist[next] = dis + ndis;
                pq.push({dist[next] , next});
                path[next] = curr;
            }
        }    
    }
}

void find_path(int curr){
    ans.push_back(curr);

    if(path[curr] == S){
        ans.push_back(S);
        return;
    }
    else{
        find_path(path[curr]);       
    }
}
