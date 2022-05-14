#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N , M;
vector<int> v;
vector<int> ans;

void dfs(int num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    int temp ;

    for(int i =0 ; i<N; i++){
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin() , v.end());

    dfs(0);
}

void dfs(int num){

    if(ans.size() == M){
        for(int i =0; i<M; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = num; i<N; i++){
        ans.push_back(v[i]);
        dfs(i);
        ans.pop_back();
    }
}
