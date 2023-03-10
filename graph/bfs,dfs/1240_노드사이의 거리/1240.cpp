#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N , M, dis = 0;
vector<pair<int , int>>v[1001];
bool visit[1001];

void dfs(int s , int d , int distance);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    int x , y ,l;
    for(int i =0; i<N-1; i++){
        cin >> x>> y >> l;
        v[x].push_back(make_pair(y,l));
        v[y].push_back(make_pair(x,l));
    }

    int s , d;

    for(int i =0; i<M; i++){
        cin >> s >> d;
        memset(visit ,false ,sizeof(visit));
        dis = 0;
        dfs(s,d,0);
        cout << dis << "\n";
    }
}

void dfs(int s , int d , int distance){

    if(s == d){
        dis =  distance;
        return;
    }
    visit[s] = true;
    
    for(int i =0; i<v[s].size(); i++){
        if(!visit[v[s][i].first]){
            dfs(v[s][i].first , d , distance + v[s][i].second);
        }
    }
}
