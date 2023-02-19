#include<iostream>
#include<cstring>
#include <queue>
#include <vector>

using namespace std;

int M , N , H;

int inp[101][101][101];

struct st{
    int x;
    int y;
    int z;
    int d;
}typedef st;

queue<st> q;

int dx[] = {1,-1 , 0 , 0 , 0 ,0};
int dy[] = { 0 , 0 , 1 ,-1, 0 ,0};
int dz[] = {0 , 0 , 0 ,0 , 1, -1 };

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> M >> N >>H;
    queue<st> q;
    st temp , newone;

    int count=0;
    int num = 0;

    for(int i =0; i<H; i++){
        for(int j =0; j<N; j++){
            for(int k=0; k<M; k++){
                cin >> inp[i][j][k];
                if(inp[i][j][k] == 1){
                    count++;
                    temp.x = j;
                    temp.y = k;
                    temp.z = i;
                    temp.d = 0;
                    q.push(temp);
                }

                if(inp[i][j][k] != -1){
                    num++;
                }
            }
        }
    }

    int tx ,ty ,tz ,td;

    while(true){

    while(!q.empty()){

        tx = q.front().x;
        ty = q.front().y;
        tz = q.front().z;
        td = q.front().d;
        q.pop();

        for(int w =0; w<6; w++){
            int nx = tx + dx[w];
            int ny = ty + dy[w];
            int nz = tz +dz[w];

            if(nx >=0 && ny >=0 && nz >=0 && nx <N && ny < M && nz <H){
                if(inp[nz][nx][ny] == 0){
                    count++;
                    inp[nz][nx][ny] = 1;
                    newone.x = nx;
                    newone.y = ny;
                    newone.z = nz;
                    newone.d = td+1;
                    q.push(newone);
                }
            }
        }


    }

        if(count == num){
            cout << td;
            return 0;
        }
        else{
            cout << -1;
            return 0;
        }

    
    }

    return 0;

}
