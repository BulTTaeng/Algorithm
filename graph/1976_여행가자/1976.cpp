#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int parent[201];
vector<int>v;

int N , M;

void _union(int x, int y );
int _find(int x);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    int num;

    for(int i =1 ; i<=N; i++){
        parent[i]= i;
    }

    for(int i =1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> num;
            if(num == 1){
                _union(i,j);
            }
        }
    }

    for(int i =0; i<M; i++){
        cin >> num;
        v.push_back(num);
    }

    for(int i =0; i<v.size()-1 ; i++){
        if(_find(v[i]) != _find(v[i+1])){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;

}

void _union(int x, int y ){
    x = _find(x);
    y = _find(y);

    parent[y] = x;
}

int _find(int x){
    if(parent[x] == x) return x;
    else{
        return parent[x] = _find(parent[x]);
    }
}
