#include <iostream>
#include <cstring>

using namespace std;

int N , M;
int ans =0;
int root[500001];


void _union(int x , int y);
int _find(int x);

#define INF 987654321

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    
    for(int i =0; i<N; i ++){
        root[i] = i;
    }

    int x , y;

    for(int i =0; i<M; i++){
        cin >> x >> y;

        if(ans != 0 ){
            continue;
        }

        if(_find(x) == _find(y)){
            if(ans == 0){
                ans = i+1;
            }   
        }

        _union(x,y);
    }

    cout << ans;
    return 0;
}

void _union(int x ,int y ){
    x = _find(x);
    y = _find(y);

    root[y] = x;
}

int _find(int x){
    if(root[x] == x) return x;
    else{
        return root[x] = _find(root[x]);
    }
}
