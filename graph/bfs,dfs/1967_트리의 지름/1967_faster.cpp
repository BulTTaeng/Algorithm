#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
bool visit[10001];
int dis[10001];
int maxi = 0;
int endp = -1;

vector<pair<int , int >> v[10001];

void dfs(int curr , int d);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int x , y ,w;
    for(int i=1; i<N; i++){
        cin >> x >> y >> w;
        v[x].push_back(make_pair(y,w));
        v[y].push_back(make_pair(x,w));
    }

    memset(visit ,false , sizeof(visit));

    dfs(1, 0);
    maxi =0;
    
    memset(visit ,false , sizeof(visit));
    dfs(endp, 0);
    int ans2 = maxi;

    cout << ans2;
    return 0;
}

void dfs(int curr , int d){
    visit[curr] = true;
    //dis[curr] = d;

    if(d > maxi){
        maxi = d;
        endp = curr;
    }


    for(int i =0; i<v[curr].size(); i++){
        if(!visit[v[curr][i].first]){
            dfs(v[curr][i].first , d+ v[curr][i].second);
        }
    }
}
