#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int N , M;

int inp[51][51];
vector<pair<int, int> > home;
vector<pair<int, int>> chicken;
vector<pair<int,int>>vv;

int ans = 987654321;

void dfs(int idx ,vector<pair<int , int>> v);
int chicken_dis(vector<pair<int , int>> v);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            cin >> inp[i][j];

            if(inp[i][j] == 2){
                chicken.push_back(make_pair(i,j));
            }
            else if(inp[i][j] == 1){
                home.push_back(make_pair(i,j));
            }
        }
    }

    int c =0;
    dfs(0,vv);

    cout << ans;
    return 0;
}

void dfs(int idx ,vector<pair<int , int>> v){

    if(v.size() == M){
        ans = min(chicken_dis(v) , ans);
        return;
    }

    if(idx>=chicken.size()){
        return;
    }

    dfs(idx+1 , v);
    v.push_back(make_pair(chicken[idx].first , chicken[idx].second));
    dfs(idx+1 , v);
}

int chicken_dis(vector<pair<int , int>> v){
    int re = 0;
    int temp = 987654321;
    for(int i =0;i<home.size(); i++){
        temp  = 987654321;
        for(int j =0; j<v.size(); j++){
            temp = min ( abs(home[i].first - v[j].first) + abs(home[i].second - v[j].second) , temp); 
        }
        re += temp;
    }

    return re;
}
