#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> v;
bool visit[9];
int ans = 0;
vector<int> p;

void dfs(int sum , int c);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t;

    cin >> N;

    for(int i =0; i<N; i++){
        cin >> t;
        v.push_back(t);
    }

    dfs(0,0);

    cout << ans;
    return 0;
}

void dfs(int sum , int c){

    if(c == N){
        int temp = 0;
        for(int i =1; i<N; i++){
            temp += abs(p[i-1] - p[i]);
        }
        ans = max(temp, ans);
        return;
    }

    for(int i =0; i<N; i++){
        if(!visit[i]){
            visit[i] = true;
            p.push_back(v[i]);
            dfs(v[i] , c+1);
            p.pop_back();
            visit[i] = false;
        }
    }
}
