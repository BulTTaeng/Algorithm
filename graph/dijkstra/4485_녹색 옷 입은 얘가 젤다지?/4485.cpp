#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct st{
    double x;
    double y;
    double dis;
}typedef st;

struct cmp{
    bool operator()(const st &s1 , const st &s2){
        return s1.dis > s2.dis;
    }
};

int N;
int inp[126][126];
int dist[126][126];

int dx[] = {-1, 1, 0 , 0};
int dy[] = {0, 0 , 1 , -1};

void dij(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int i =1;

    while(true){
        cin >> N;

        if( N == 0){
            return 0;
        }

        for(int i =0; i<=N; i++){
            for(int j =0; j<=N; j++){
                dist[i][j] = 987654321;
            }
        }
        
        for(int i =0 ; i<N; i++){
            for(int j =0 ; j<N ; j++){
                cin >> inp[i][j];
            }
        }

        dij(0,0);

        cout << "Problem " << i << ": " <<dist[N-1][N-1] << "\n";
        i++;
    }
    return 0;
}

void dij(int x , int y){
    int cdis = inp[x][y];
    priority_queue<st, vector<st> , cmp>pq;
    st temp;
    temp.x = x;
    temp.y = y;
    temp.dis = cdis;
    dist[x][y] = cdis;
    
    pq.push(temp);
    int f, s, nx , ny , ndis;
    while(!pq.empty()){
        f= pq.top().x;
        s = pq.top().y;
        ndis = pq.top().dis;
        pq.pop();

        for(int i =0;i<4 ; i++){
            nx = f+dx[i];
            ny = s+dy[i];

            if(nx>=0 && ny>=0 && nx<N && ny<N){
                if(dist[nx][ny] > inp[nx][ny] +ndis){
                    dist[nx][ny] = inp[nx][ny] +ndis;
                    temp.x = nx;
                    temp.y = ny;
                    temp.dis = dist[nx][ny];
                    pq.push(temp);
                }
            }
        }
    }
}
