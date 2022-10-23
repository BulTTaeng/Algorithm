#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int T , N , C , D;
int dis[10001];

priority_queue<pair<int , int> , vector<pair<int , int>> , greater<> >pq;
vector<pair<int , int>> v[10001];

void dij();

#define INF 987654321

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int x, y ,w;
 
    cin >> T;
    
    while(T--){
        cin >> N >> D >> C;


        for(int i =0; i<D; i++){
            cin >> x >> y >> w;
            v[y].push_back(make_pair(w, x));
        }

        for(int i = 1 ; i<=N ; i++){
            dis[i] = INF;
        }

        dij();
        int ans  = 0, num = 0;

        for(int i =1; i<=N; i++){
            v[i].clear();

            if(dis[i] == INF) continue;
            num++;
            ans = max(ans , dis[i]);
        }

        cout << num << " " << ans << "\n";

    }

    return 0;   
}

void dij(){
    dis[C] = 0;
    pq.push(make_pair(0 , C));

    while(!pq.empty()){
        int curr = pq.top().second;
        int cdis = pq.top().first;
        pq.pop();

        for(int i =0; i<v[curr].size() ; i++){
            int next = v[curr][i].second;
            int ndis = v[curr][i].first;

            if(dis[next] > ndis + cdis){
                dis[next] = ndis + cdis;
                pq.push(make_pair(dis[next] , next));
            }
        }
    }
}
