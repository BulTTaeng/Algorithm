#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T;
int inp[12][12];
int visit[12];
int maxi  = 0;
vector<int> v[11];

void dfs(int pst , int ans);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;
    int temp;

    while(T--){
        
        for(int i =0; i<=11 ; i++){
            v[i].clear();
        }        

        memset(inp, 0, sizeof(inp));
        maxi = 0;
        memset(visit ,false , sizeof(visit));

        for(int i =0 ; i<11; i++){
            for(int j =0; j<11; j++){
                cin >> inp[i][j];

                if(inp[i][j] != 0){
                    v[j].push_back(i);
                }
            }
        }

        dfs(0,0);

        cout << maxi << "\n";
    }
    
    return 0;
}

void dfs(int pst , int ans){
    if(pst == 11){
        maxi = max(maxi , ans);
        return;
    }

    for(int i =0 ; i<v[pst].size(); i++){
        if(!visit[v[pst][i]]){
            visit[v[pst][i]] = true;
            dfs(pst+1 , ans + inp[ v[pst][i]][pst] );
            visit[v[pst][i]] = false;
        }
    }
}
