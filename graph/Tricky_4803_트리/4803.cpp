#include <iostream>
#include <cstring>

using namespace std;

int N , M;

int parent[501];
bool check[501];

int _find(int x);
void _union(int x , int y);
void set_parent();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int x, y , ans = 0;
    int t = 1;

    while(true){
        cin >> N >> M;

        if(N == 0 && M == 0){
            break;
        }

        set_parent();
        ans = 0;

        for(int i =0; i<M; i++){
            cin >> x >> y;
            int px = _find(x);
            int py = _find(y);
            if(px == py || check[px] || check[py]){
                check[px] = true;
            }
            
            _union(x,y);
             
        }

        for(int i =1 ; i<=N; i++){
            int f = _find(i);
            if(!check[f] ){
                check[f] = true;
                ans++;
            }
        }

        if(ans == 0){
            cout << "Case " << t<<": No trees." << "\n";
        }
        else if (ans == 1){
            cout << "Case " << t<<": There is one tree." << "\n";
        }
        else{
            cout << "Case " << t<<": A forest of " << ans <<" trees." << "\n";
        }

        t++;
    }

    return 0;
}

int _find(int x){
    if( parent[x] == x) return x;
    else{
        return parent[x] = _find(parent[x]);
    }
}

void _union(int x , int y){
    x = _find(x);
    y = _find(y);

    parent[y] = x; 
}

void set_parent(){
    for(int i =1; i<=N; i++){
        parent[i] = i;
    }

    memset(check , false ,sizeof(check));
}
