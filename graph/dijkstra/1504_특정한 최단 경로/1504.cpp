#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N1 , N2 , N  , E;
vector<pair<int , int>>v[801];
priority_queue<pair<int , int > , vector<pair<int , int>> , greater<> > pq;

long long dis[801];

void dij(int start);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> E;
    int x, y , w;

    for(int i =0; i<E; i++){
        cin >> x >> y >> w;
        v[x].push_back(make_pair(y, w));
        v[y].push_back(make_pair(x,w)); 
    }

    cin >> N1 >> N2;

    for(int i =1 ; i<=N; i++){
        dis[i] = 98765432;
    }

    dij(1);

    int toN1 = dis[N1];
    int toN2 = dis[N2];

    for(int i =1 ; i<=N; i++){
        dis[i] = 98765432;
    }

    dij(N1);
    
    int N1_N = dis[N];
    int N1_N2 = dis[N2];

    for(int i =1 ; i<=N; i++){
        dis[i] = 98765432;
    }

    dij(N2);
    
    int N2_N = dis[N];
    int N2_N1 = dis[N1];

    long long ans;
    long long op1 = toN1 + N1_N2 + N2_N;
    long long op2 =  toN2 + N2_N1 + N1_N;

    ans =  min(op1 , op2);

    if(ans >= 98765432 ){
        cout << -1;
    }
    else{
        cout << ans;
    }

    return 0;
}

void dij(int start){
    pq.push(make_pair(0, start));
    dis[start] = 0;

    while(!pq.empty()){
        int curr = pq.top().second;
        int currdis = pq.top().first;
        pq.pop();


        for(int i =0; i<v[curr].size(); i++){
            int next = v[curr][i].first;
            int nextdis = v[curr][i].second;

            if(nextdis + currdis < dis[next]){
                dis[next] = nextdis + currdis;
                pq.push(make_pair(dis[next] , next));
            }
        } 
    }

    
}
