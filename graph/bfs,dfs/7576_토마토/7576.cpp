#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N , M;
int inp[1001][1001];

struct st{
    int x;
    int y;
    int d;
}typedef st;

int dx[] = {-1, 1 ,0 , 0};
int dy[] = {0 , 0 , 1 ,-1};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> M >> N;
    int num =0; 
    int count =0;
    queue<st> q;
    st temp , newone;
    for(int i =0; i<N ; i++){
        for(int j =0; j<M ; j++){
            cin >> inp[i][j];

            if(inp[i][j] == 1){
                count++;
                temp.x = i;
                temp.y = j;
                temp.d = 0;
                q.push(temp);
            }
            if(inp[i][j] != -1){
                num++;
            }
        }
    }

    int tx , ty ,td;

    while(!q.empty()){
        tx =q.front().x;
        ty = q.front().y;
        td = q.front().d;
        q.pop();

        for(int i =0; i<4 ; i++){
            int nx = tx+dx[i];
            int ny = ty + dy[i];

            if(nx>=0 && ny>=0 && nx<N && ny<M){
                if(inp[nx][ny] == 0){
                    count++;
                    inp[nx][ny] = 1;
                    newone.x = nx;
                    newone.y = ny;
                    newone.d = td+1;
                    q.push(newone);
                }
            }
        }
    }

    if(num == count){
        cout << td;
    }
    else{
        cout << -1;
    }

    return 0;
}
