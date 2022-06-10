#include <iostream>

using namespace std;

int N , M;
int root[1000001];

void _union(int x , int y);
int _find(int x);


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i =0; i<=N; i++){
        root[i] = i;
    }

    int op , f, s ;
    
    for(int i =0; i<M; i++){
        cin >> op >> f >> s;
        if(op == 0){
            _union(f,s);
        }
        else{
            if(_find(f) == _find(s)){
                cout << "YES" << "\n";
            }
            else{
                cout << "NO" << "\n";
            }
        }
    }
}

void _union(int x , int y){
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
