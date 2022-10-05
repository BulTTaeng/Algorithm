#include <iostream>

using namespace std;

int dis[101][101];
int N , M;

void floyd();

#define INF 987654321

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N ;
    cin >> M;
    int x, y, w;
    
    for(int i =1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            dis[i][j] = INF;
        }
    }

    for(int i =0; i<M; i++){
        cin >> x >> y >> w;
        dis[x][y]= min(w , dis[x][y]);
    }

    floyd();

    for(int i =1; i<=N; i++){
        for(int j =1 ; j <=N; j++){
            if(dis[i][j] == INF || i==j){
                cout << 0 << " ";
            }
            else{
                cout << dis[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

void floyd(){
    for(int k = 1; k<= N ; k++){
        for(int i =1; i<=N ; i++){
            for(int j =1; j<=N; j++){
                if(dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}
