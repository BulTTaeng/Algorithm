#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int N , M , R;
int item[101];
int dist[101][101];
bool visit[101];

void floyd();

#define INF 987654321

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M >> R;

    for(int i =1; i<=N ; i++){
        cin >> item[i];
    }

    for(int i = 1 ; i<=N; i++){
        for(int j =1; j<=N; j++){
            if( i == j){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = INF;
            }
        }
    }

    int a,b,l;

    for(int i = 0; i<R; i++){
        cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
    }

    floyd();

    int temp = 0;
    int ans = 0;

    for(int i =1; i<=N; i++){
        temp = 0;
        for(int j =1 ; j<=N; j++){
            if(dist[i][j] <=M){
                temp += item[j];
            }
        }

        ans = max(ans ,temp);
    }
    

    cout << ans;
    return 0;


}

void floyd(){
    for(int k = 1; k<=N; k++){
        for(int i = 1; i<=N; i++){
            for(int j =1 ; j<=N ; j++){
                if(dist[i][k] != INF && dist[k][j] !=INF){
                    if(dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}
