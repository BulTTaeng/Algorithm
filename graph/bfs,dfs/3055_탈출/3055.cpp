#include<iostream>
#include <cstring>
#include <queue>

using namespace std;

queue<pair<int , int>> q;

int R ,C;
char inp[51][51];
char cinp[51][51];

int dx[] = {-1,  1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> R >> C;

    for(int i =0;i <R; i++){
        for(int j= 0 ; j<C; j++){
            cin >> inp[i][j];
            cinp[i][j] = inp[i][j];

            if(inp[i][j] == 'S'){
                q.push(make_pair(i,j));
            }
        }
    }

    int ans = 0 ;
    bool found = false;
    int nx , ny , f , s;

    while(true){

        found = false;
        ans++;

        while(!q.empty()){
            f= q.front().first;
            s = q.front().second;
            q.pop();

            for(int k =0; k<4; k++){
                nx = f+dx[k];
                ny = s + dy[k];

                if(nx>=0 && ny>=0 && nx<R && ny < C){
                    if(inp[nx][ny] == '.'){
                        cinp[nx][ny] = 'S';
                    }
                    else if(inp[nx][ny] == 'D'){
                        cout << ans;
                        return 0;
                    }
                }
            }

            cinp[f][s] = '.';
        }

        for(int i =0;i <R; i++){
            for(int j= 0 ; j<C; j++){

                if(inp[i][j] == '*'){

                    for(int k =0; k<4; k++){
                        nx = i+dx[k];
                        ny = j + dy[k];

                        if(nx>=0 && ny>=0 && nx<R && ny < C){
                            if(inp[nx][ny] == '.' || inp[nx][ny] == 'S'){
                                cinp[nx][ny] = '*';
                            }
                        }
                    }
                }
            }
        }

        for(int i =0; i<R ; i++){
            for(int j =0; j<C; j++){
                inp[i][j] = cinp[i][j];

                if(inp[i][j] == 'S'){
                    found = true;
                    q.push(make_pair(i,j));
                }
            }
        }

        if(!found){
            cout << "KAKTUS";
            return 0;
        }


        /*cout << "\n";
        for(int i =0; i<R; i++){
            for(int j =0; j<C; j++){
                cout << inp[i][j];
            }
            cout <<"\n";
        }*/

    }

    
    return 0;
}
