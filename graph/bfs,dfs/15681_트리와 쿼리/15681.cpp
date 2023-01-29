#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> v[100001];
int N , R ,Q;
int child[100001];

void dfs(int curr , int prev);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> R >> Q;
    int x , y;

    for(int i =1 ; i<N; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int rt = 0;
    memset(child , 0 , sizeof(child));

    dfs(R , R);

    for(int i =0 ;i<Q; i++){
        cin >> rt;
        cout << child[rt] << "\n";
    }

    return 0;
}

void dfs(int curr , int prev){

    child[curr] = 1;

    for(int i =0; i<v[curr].size(); i++){
        if(v[curr][i] != prev){
            dfs(v[curr][i] , curr);
            child[curr] += child[v[curr][i]];
        }
    }
}
