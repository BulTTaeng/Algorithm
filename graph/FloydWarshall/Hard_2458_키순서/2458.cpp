#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int V ,E;
int inp[501][501];

void floyd();

#define INF 9876543

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> V >> E;
    int x , y;

    for(int i =1; i<=V; i++){
        for(int j =1 ; j<=V; j++){
            inp[i][j] = INF;
        }
    }

    for(int i =0; i<E; i++){
        cin >> x >> y;
        inp[x][y] = 1;
    }

    floyd();

    int c = 0;
    int ans = 0;

    for(int i =1; i<=V; i++){
        c = 0;
        for(int j =1 ; j<=V; j++){
            if(inp[i][j] != INF || inp[j][i] != INF){
                c++;
            }
        }
        if (c == V-1) ans++; 
    }

    cout << ans;
    return 0;
}

void floyd(){
    for(int k = 1; k<=V; k++){
        for(int i = 1; i<=V; i++){
            for(int j =1 ; j<=V; j++){
                if(inp[i][k] + inp[k][j] < inp[i][j]){
                    inp[i][j] = inp[i][k] + inp[k][j];
                }
            }
        }
    }
}
