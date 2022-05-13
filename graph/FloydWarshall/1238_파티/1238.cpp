#include <iostream>

using namespace std;

int N , M , X;
int dist[1001][1001];

#define INF 987654321

void floyd();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    cin.tie(0);

    cin >> N >> M >> X;
    int s,e,c;

    for(int i =1; i<=N; i++){
        for(int j =1 ; j<=N; j++){
            dist[i][j] = INF;
        }
    }

    for(int i =0; i < M; i++){
        cin >>s >> e >> c;
        dist[s][e] = c;
    }

    floyd();

    int temp;
    int ans = 0;
    for(int i =1; i<=N; i++){
        if(i == X){
            continue;
        }
        temp  = dist[i][X] + dist[X][i];
        ans = max(ans , temp);
    }

    cout << ans;
    return 0;
}

void floyd(){
    for(int k = 1; k<=N; k++){
        for(int i =1 ; i<=N; i++){
            for(int j = 1; j<=N; j++){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    if(dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}
