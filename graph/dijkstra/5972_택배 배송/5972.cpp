#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<int , int > , vector<pair<int , int>>, greater<> > pq;

int N , M;
vector<pair<int , int>> v[50001];
int cost[50001];

void dij(int start);

#define INF 987654321

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int a , b , c;

    cin >> N >> M;

    for(int i =1; i<=N ; i++){
        cost[i] = INF;
    }

    for(int i =0; i<M ;i++){
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c)); 
    }

    dij(1);
    
    cout << cost[N];
    return 0;
}

void dij(int start){
    cost[start] = 0;
    pq.push(make_pair(0, start));

    int f , s , next ,cos;

    while(!pq.empty()){
        f = pq.top().first;
        s = pq.top().second;
        pq.pop();

        for(int i =0 ;i<v[s].size(); i++){
            next = v[s][i].first;
            cos = v[s][i].second;

            if(f + cos < cost[ next ]){
                cost[next] = f+cos;
                pq.push(make_pair(cost[next] , next ));
            }
        }
    }


}
