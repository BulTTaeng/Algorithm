#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int , int>> v[20002];
priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int,int>> >pq;
int d[20002];

int V , E ,K;

#define INF 987654321

void dij(int start);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> V >> E;
    cin >> K;
    int u,vv,w;

    for(int i =0; i<E; i++){
        cin >> u >> vv >> w;
        v[u].push_back(make_pair(vv,w));
    }

    for(int i =1; i<=V; i++){
        d[i] = INF;
    }

    dij(K);

    for(int i =1; i<=V; i++){
        if(d[i] == INF){
            cout << "INF" << "\n";
        }
        else{
            cout << d[i] << "\n";
        }
    }
    return 0;
}

void dij(int start){

    pq.push(make_pair( 0 , start));
    d[start] = 0;

    while(!pq.empty()){
        int curr_dis = pq.top().first;
        int curr_loc = pq.top().second;
        pq.pop();

        if(d[curr_loc] < curr_dis) continue;

        for(int i =0; i<v[curr_loc].size(); i++){
            int next = v[curr_loc][i].first;
            int dist = v[curr_loc][i].second;

            if(curr_dis+dist <d[next]){
                d[next] = curr_dis+dist;
                pq.push(make_pair( curr_dis+dist , next));
            }
        }

    }


}
