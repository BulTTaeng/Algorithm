#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int num[10002];
bool visit[10002];

vector<int> v[10002];
int maxi = 0;
int n , m;
void dfs(int curr);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int a ,b;

    cin >> n >> m;

    for(int i =0; i<m; i++){
        cin >>a >> b;
        v[b].push_back(a);
    }
    
    memset(num , 0 , sizeof(num));

    int mm = 0;
    
    for(int i =1; i<=n; i++){
        memset(visit , false ,sizeof(visit));
        maxi = 0;
        visit[i] = true;
        dfs(i);
        num[i] = maxi;

        if(mm < maxi){
            mm = maxi;
        }
    }

    for(int i =1; i<=n; i++){
        if(num[i] == mm)
            cout << i << " ";
    }
    return 0;
}

void dfs(int curr){
    maxi++;

    visit[curr] =true;

    for(int i =0; i<v[curr].size(); i++){
        if(!visit[v[curr][i]]){
            dfs(v[curr][i]);
        }
        
    }
    return;
}
