#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

char inp[12][6];
bool visit[12][6];

priority_queue<pair<int , int > ,  vector<pair<int , int >> , greater<>> pq;
queue<pair<int , int >>q;


int dx[] = {-1, 1 , 0 , 0};
int dy[] = {0 , 0 , 1 ,-1};

int temp;
bool ok = false;

void dfs(int x , int y , char c);
void swapline(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i<12; i++){
        for(int j =0 ; j<6 ; j++){
            cin >> inp[i][j];
        }
    }

    int ans = 0;
    int x, y;

    while(true){
        
        memset(visit ,false , sizeof(visit));
        ok = false;

        for(int i =0; i<12; i++){
            for(int j =0; j<6; j++){
                if(!visit[i][j] && inp[i][j] != '.'){
                    temp = 0;
                    dfs(i,j , inp[i][j]);

                    if(temp>=4){
                        ok = true;
                        while(!q.empty()){
                            x = q.front().first;
                            y = q.front().second;
                            q.pop();

                            pq.push(make_pair(x,y));
                        }
                    }
                    else{
                        while(!q.empty()){
                            q.pop();
                        }
                    }
                    
                }
            }
        }

        if(ok){
            while(!pq.empty()){
                x = pq.top().first;
                y = pq.top().second;
                pq.pop();

                swapline(x,y);
            }
        }
        else{
            break;
        }
        /*cout << "\n";
        for(int i =0; i<12; i++){
            for(int j =0; j<6; j++){
                cout << inp[i][j];
            }
            cout <<"\n";
        }*/

        ans++;


    }
    cout << ans;
    return 0;
}


void dfs(int x , int y , char c){
    
    q.push(make_pair(x,y));
    visit[x][y] = true;
    temp++;

    for(int i =0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0 && ny>=0 && nx <12 && ny<6){
            if(!visit[nx][ny] && inp[nx][ny] == c){
                dfs(nx , ny, c);
            }
        }
    }

}

void swapline(int x , int y){
    inp[x][y] = '.';

    for(int i =x; i>0; i--){
        swap(inp[i][y] , inp[i-1][y]);
    }
}
