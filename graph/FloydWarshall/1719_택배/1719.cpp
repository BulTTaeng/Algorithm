#include <iostream>
#include <cstring>

using namespace std;

int N , M;

int inp[201][201];
int path[201][201];

void floyd_warshall();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    int x, y , w;
    for(int i =1; i<=N; i++){
        for(int j = 1 ; j<=N; j++){
            inp[i][j] = 98765432;
        }
    }

    for(int i =0; i<M; i++){
        cin >> x >> y >> w;
        inp[x][y] = w;
        inp[y][x] = w;
        path[x][y] =y;
        path[y][x] =x;
    }

    floyd_warshall();

    for(int i =1; i<=N; i++){
        for(int j =1 ; j<=N; j++){
            if( i == j){
                cout << '-' << " ";
            }
            else{
                cout << path[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}

void floyd_warshall(){
    for(int i =1 ; i<=N; i++){
        for(int j =1; j<=N; j++){
            for(int k =1 ; k <=N; k++){
                if(inp[j][i] + inp[i][k] < inp[j][k]){
                    inp[j][k] = inp[j][i] + inp[i][k];
                    path[j][k] = path[j][i];
                }
            }
        }
    }
}
