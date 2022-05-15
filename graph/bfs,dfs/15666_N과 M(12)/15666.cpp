#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N , M;

vector<int> inp;
vector<int> ans;

void dfs(int curr , int c);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >>M;
    int temp;

    for(int i =0; i<N; i++){
        cin >> temp;
        inp.push_back(temp);
    }

    sort(inp.begin() , inp.end());
    inp.erase(unique(inp.begin() , inp.end()) , inp.end());

    dfs(0,0);
    
}

void dfs(int curr , int c){

    if(c == M){
        for(int i =0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prevn = 10001;

    for(int i = curr; i<inp.size(); i++){
        if(prevn != inp[i]){
            ans.push_back(inp[i]);
            prevn = inp[i];
            dfs(i , c+1);
            ans.pop_back();
        }
    }
}

