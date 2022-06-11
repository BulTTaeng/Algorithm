#include <iostream>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int N , K, L , X;
char dir;
int time = 0;
int board[101][101];
queue<pair <int , char>> q;

struct snake{
    int x;
    int y;
    int dir; //동 0,서 1, 남 2, 북 3
}typedef snake;

deque<snake> sloc;

void simulation();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    cin >> N;
    cin >> K;
    memset(board  , 0  , sizeof(board));
    int r, c;

    for(int i =0; i<K ; i++){
        cin >> r >> c;
        board[r][c] = 1; // apple
    }

    cin >> L;

    for(int i =0; i<L; i++){
        cin >> X >> dir;
        q.push({X,dir});
    }

    board[1][1] = 2; // snake 2
    snake temp;
    temp.x = 1;
    temp.y = 1;
    temp.dir = 0;
    sloc.push_back(temp);

    simulation();

    cout << time;
    return 0;
}

void simulation(){
    
    int x, y , d;
    int nx , ny;

    snake next;

    while(!sloc.empty()){
        x = sloc.front().x;
        y = sloc.front().y;
        d = sloc.front().dir;
        time++;

        if(d == 0){
            nx = x;
            ny = y+1;

            if(nx <1 || ny <1 || nx>N || ny>N || board[nx][ny] == 2){
                break;
            }

            if(board[nx][ny] == 0){ // no apple
                board[sloc.back().x][sloc.back().y] = 0;
                sloc.pop_back();
            }

        }
        else if(d == 1){
            nx = x;
            ny = y-1;

            if(nx <1 || ny <1 || nx>N || ny>N || board[nx][ny] == 2){
                break;
            }

            if(board[nx][ny] == 0){ // no apple
                board[sloc.back().x][sloc.back().y] = 0;
                sloc.pop_back();
            }
        }
        else if(d ==2){
            nx = x+1;
            ny = y;

            if(nx <1 || ny <1 || nx>N || ny>N || board[nx][ny] == 2){
                break;
            }

            if(board[nx][ny] == 0){ // no apple
                board[sloc.back().x][sloc.back().y] = 0;
                sloc.pop_back();
            }

        }
        else{
            nx = x-1;
            ny = y;

            if(nx <1 || ny <1 || nx>N || ny>N || board[nx][ny] == 2){
                break;
            }

            if(board[nx][ny] == 0){ // no apple
                board[sloc.back().x][sloc.back().y] = 0;
                sloc.pop_back();
            }


        }

        if(!q.empty() && q.front().first == time){ //방향 조절
            if(q.front().second == 'D'){
                if(d == 0){
                    d=2;
                }
                else if(d ==1){
                    d=3;
                }
                else if(d == 2){
                    d=1;
                }
                else{
                    d=0;
                }
            }

            else{
                if(d == 0){
                    d=3;
                }
                else if(d ==1){
                    d=2;
                }
                else if(d == 2){
                    d=0;
                }
                else{
                    d=1;
                }
            }

            q.pop();
        }

        next.x = nx;
        next.y = ny;
        next.dir = d;
        sloc.push_front(next);
        board[nx][ny] = 2;
    }

    return;
}
