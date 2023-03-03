#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<pair<int , long long>>v[1002];
long long d[1002];

int N , M , S ,E;

#define INF 98765432111111111

void dij(int start);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    cin >> N;
    cin >> M;

    int s,e,w;

    for(int i =0; i<M; i++){
        cin >>s >> e >>w;
        v[s].push_back(make_pair(e,w));
    }

    cin >> S >> E;

    for(int i =1 ;  i <=N; i++){
        d[i] = INF;
    }

    d[S] = 0;

    dij(S);

    cout << d[E] ;

    return 0;
}

void dij(int start){
    priority_queue<pair<int, int> , vector<pair<int , int >>, greater<>>pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()){
        long long curr_dis = pq.top().first;
        int curr_loc = pq.top().second;
        pq.pop();

        if(d[curr_loc] < curr_dis) continue;

        for(int i =0; i<v[curr_loc].size(); i++){
            int next = v[curr_loc][i].first;
            long long dist = v[curr_loc][i].second;

            if(d[next] > dist + curr_dis){
                d[next] = dist + curr_dis;
                pq.push(make_pair(d[next] , next));
            }
        }
    }
}
