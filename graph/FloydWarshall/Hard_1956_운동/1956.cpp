#include <iostream>
#include <cstring>

using namespace std;

int dis[401][401];

int V ,E;

void floyd();

#define MAXX 987654321

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> V >> E;

    int x , y , w;

    for(int i =1; i<=V; i++){
        for(int j =1 ; j<=V; j++){
            dis[i][j] = MAXX; 
        }
    }


    for(int i =0; i<E; i++){
        cin >> x>> y >> w;
        dis[x][y] = w;
    }

    floyd();
    int ans = MAXX;
    for(int i =1; i<=V; i++){
        ans = min( dis[i][i] , ans) ;

    }

    if(ans == MAXX){
        cout << -1;
    }
    else{
        cout << ans;
    }


    return 0;

}

void floyd(){
    for(int k= 1; k<=V; k++){
        for(int i =1; i<=V; i++){
            for(int j =1 ; j<=V; j++){
                if(dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}
