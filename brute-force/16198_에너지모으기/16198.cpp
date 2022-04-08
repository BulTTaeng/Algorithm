#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
vector<int> v;
int ans = 0;
int temp = 0;

void dfs(vector<int> t , int score);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =0; i<N; i++){
        cin >> temp;
        v.push_back(temp);
    }

    dfs(v, 0);

    cout << ans;
    return 0;   

}

void dfs(vector<int> t , int score){

    int tt;

    if(t.size() == 2){
        ans = max(score,ans);
    }

    for(int i = 1; i<=t.size()-2; i++){
        temp = t[i-1] * t[i+1];
        tt = t[i];
        t.erase(t.begin() + i);
        dfs(t , score+temp);
        t.insert(t.begin()+i , tt);
    }
}
