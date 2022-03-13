#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N , M;
long long dis[501];

struct st{
    int x;
    int y;
    int w;
}typedef st;

vector<st> edge;

#define INF 98765432

bool bell();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    int x, y , w;
    st temp;

    for(int i =0; i<M; i++){
        cin >> x >> y >> w;
        temp.x = x;
        temp.y = y;
        temp.w = w;

        edge.push_back(temp);
    }

    for(int i =1 ; i<=N; i++){
        dis[i] = INF;
    }

    bool p = bell();

    if(p){
        for(int i =2; i<=N; i++){
            if(dis[i] == INF) cout << -1 << "\n";
            else{
                cout << dis[i] << "\n";
            }
        }
    }
    else{
        cout << -1; 
    }

    return 0;
}   

bool bell(){

    dis[1] = 0;

    for(int i =1; i<N; i++){
        for(int j =0; j<edge.size(); j++){
            int curr = edge[j].x;
            int next = edge[j].y;
            int ndis = edge[j].w;

            if(dis[curr]  == INF) continue;

            if(dis[next] > dis[curr] + ndis){
                dis[next] = dis[curr] + ndis;
            }
        }
    }

    for(int j =0; j<edge.size(); j++){
        int curr = edge[j].x;
        int next = edge[j].y;
        int ndis = edge[j].w;

        if(dis[curr]  == INF) continue;

        if(dis[next] > dis[curr] + ndis){
            return false;
        }
    }

    return true;
}
