#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool visit[500002];
vector<int> v[500002];
int depth[500002];
bool is_leaf[500002];

int N;
void dfs(int x , int d);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int x ,y;

    for(int i =1; i<N; i++){
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(visit , false ,sizeof(visit));
    memset(is_leaf , false ,sizeof(is_leaf));

    dfs(1,0);
    int num = 0;

    for(int i =1 ; i<=N ; i++){
        if(is_leaf[i]) {
            num+= depth[i];
        }
    }

    if(num%2 == 0){
        cout << "No";
    }
    else{
        cout << "Yes";
    }

    return 0;
}

void dfs( int x , int d){
    visit[x] = true;
    depth[x] = d;
    bool check = true;

    for(int i =0; i<v[x].size() ; i++){
        if(!visit[v[x][i]]){
            dfs(v[x][i] , d+1);
            check = false; 
        }
    }

    if(check){
        is_leaf[x] = true;
    }

}
