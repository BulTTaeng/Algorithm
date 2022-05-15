#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N , M;
bool num[9];

vector<int> inp;
vector<int> ans;

void dfs(int c);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >>M;
    int temp;

    memset(num , false ,sizeof(num));

    for(int i =0; i<N; i++){
        cin >> temp;
        inp.push_back(temp);
    }

    sort(inp.begin() , inp.end());

    dfs(0);
    
}

void dfs(int c){

    if(c == M){
        for(int i =0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prevn = 10001;

    for(int i = 0; i<N; i++){
        if(!num[i] && prevn != inp[i]){
            ans.push_back(inp[i]);
            num[i] = true;
            prevn = inp[i];
            dfs(c+1);
            num[i] = false;
            ans.pop_back();
        }
    }
}

