#include <iostream>
#include <cstring>

using namespace std;

int N , M;
int money;
int root[10001];
int mini[10001];
int cost[10001];

void _union(int x , int y);
int _find(int x);

#define INF 987654321

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M >> money;

    for(int i =1; i<=N; i++){
        cin >> cost[i];
        root[i] = i;
        mini[i] = INF;
    }

    int x, y;

    for(int i =0; i <M ; i++){
        cin >> x >> y;
        _union(x,y); 
    }

    int idx;

    for(int i =1; i<=N; i++){
        idx = _find(i);

        mini[idx] = min(mini[idx] , cost[i]);
    }

    int temp = 0;

    for(int i=1; i<=N; i++){
        if(mini[i] != INF){
            temp += mini[i];
        }
    }

    if(temp > money){
        cout << "Oh no";
    }
    else{
        cout << temp;
    }

    return 0;
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
