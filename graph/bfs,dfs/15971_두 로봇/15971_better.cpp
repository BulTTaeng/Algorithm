#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool visit[100001];
vector<pair<int , int >> v[100001];
vector<pair<int , int>> path;

int N , S ,E;
bool check = false;

void dfs(int x , int w);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> S >> E;
    int x, y ,w;
    for(int i =1; i<N ; i++){
        cin >> x>> y >> w;
        v[x].push_back(make_pair(y,w));
        v[y].push_back(make_pair(x,w));
    }

    dfs(S , 0);
    int ans = 0;
    int maxi = 0;

    for(int i =0; i<path.size(); i++){
        ans += path[i].second;
        maxi = max(maxi , path[i].second);
    }

    cout << ans - maxi;
    return 0;

}

void dfs(int x , int w){
    visit[x] = true;

    if(!check)
        path.push_back(make_pair(x, w));

    for(int i =0; i<v[x].size(); i++){
        if(!visit[v[x][i].first]){
            if(v[x][i].first == E){
                path.push_back(make_pair(E , v[x][i].second));
                check = true;
                return;
            }
            else if(!check){
                dfs(v[x][i].first , v[x][i].second);
            }

        }
    }

    if(!check)
        path.pop_back();
}
