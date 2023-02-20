#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int L , R , C;
char inp[31][31][31];
bool visit[31][31][31];

int x , y ,z;

int depth;

int dx[] = {1,-1 , 0 , 0 , 0 ,0};
int dy[] = { 0 , 0 , 1 ,-1, 0 ,0};
int dz[] = {0 , 0 , 0 ,0 , 1, -1 };

struct st{
    int x;
    int y;
    int z;
    int d;
}typedef st;


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    while(true){
        memset(visit , false ,sizeof(visit));

        cin >> L >> R >> C;

        if(L == 0 && R == 0 && C == 0){
            break;
        }

        depth = -1;

        for(int i =0; i<L; i++){
            for(int j = 0; j<R; j++){
                for(int k =0; k <C; k++){
                    cin >> inp[i][j][k];
                    if(inp[i][j][k] == 'S'){
                        x = j;
                        y = k;
                        z = i;
                    }
                }
            }
        }

        queue<st> q;
        st temp , newone;

        temp.x = x;
        temp.y = y;
        temp.z = z;
        temp.d = 0;

        q.push(temp);
        int tx , ty , tz , td;

        visit[z][x][y] = true;
        
        while(!q.empty()){
            tx = q.front().x;
            ty = q.front().y;
            tz = q.front().z;
            td = q.front().d;
            q.pop();

            if(inp[tz][tx][ty] == 'E'){
                depth = td;
                break;
            }

            for(int i =0; i<6; i++){
                int nx = tx + dx[i];
                int ny = ty + dy[i];
                int nz = tz +dz[i];

                if(nx >=0 && ny >=0 && nz >=0 && nx <R && ny < C && nz <L){
                    if(!visit[nz][nx][ny] && inp[nz][nx][ny] != '#'){
                        newone.x = nx;
                        newone.y = ny;
                        newone.z = nz;
                        newone.d = td+1;
                        visit[nz][nx][ny] = true;
                        q.push(newone);
                    }
                }
            }
        }

        if(depth == -1){
            cout << "Trapped!"<< "\n";
        }
        else{
            cout << "Escaped in " << depth <<" minute(s)." <<"\n";
        }
    }
    
}
