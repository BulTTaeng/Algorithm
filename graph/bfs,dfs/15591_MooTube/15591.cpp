#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N , Q;
vector<pair<int , int >> v[5001];
bool visit[5001];

int ans = 0 , minw = 0;

void dfs(int video , int usa ,int mini);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> Q;
    
    int x , y , w;

    for(int i =1; i<N; i++){
        cin >> x >> y >> w;
        v[x].push_back(make_pair(y,w));
        v[y].push_back(make_pair(x,w));
    }

    int usa , video;

    for(int i = 0 ; i<Q; i++){
        cin >> usa >> video;
        memset(visit ,false, sizeof(visit));
        ans = 0;
        dfs(video , usa ,987654321);
        cout << ans << "\n";
    }
}

void dfs(int video , int usa ,int mini){

    visit[video] = true;

    for(int i =0; i<v[video].size(); i++){
        
        if(!visit[v[video][i].first]){
            if(min(mini , v[video][i].second) >= usa){
                ans++;
                dfs(v[video][i].first , usa , min(mini , v[video][i].second) );
            }
        }
    }

}
