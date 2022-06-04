#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

//상 하 좌 우 : 0 , 1 , 2, 3

struct loc{
    int rx;
    int ry;
    int bx;
    int by;
    int depth;
    int before;
}typedef loc;



int N , M;
char inp[11][11];
int ans = 11;
int hx , hy;
queue<loc> q;

void solve();
int move_up(int x , int y);
int move_down(int x , int y);
int move_left(int x , int y);
int move_right(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    
    loc temp;

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            cin >> inp[i][j];

            if(inp[i][j] == 'R'){
                temp.rx = i;
                temp.ry = j;
                inp[i][j] = '.';
            }

            else if(inp[i][j] == 'B'){
                temp.bx = i;
                temp.by = j;
                inp[i][j] = '.';
            }
            else if(inp[i][j] == 'O'){
                hx = i;
                hy = j;
            }
        }
    }

    temp.depth = 0;
    temp.before = -1;
    q.push(temp);

    solve();
    if(ans > 10){
        cout << -1;
    }
    else{
        cout << ans;
    }
    return 0;
}

void solve(){
    int nrx , nry , nbx , nby , d , be;
    int brx , bry , bbx , bby;
    loc next;

    while(!q.empty()){
        brx = q.front().rx;
        bry = q.front().ry;
        bbx = q.front().bx;
        bby = q.front().by;
        d = q.front().depth;
        be = q.front().before;
        q.pop();
        /*if(d<=5){
        cout << " " << brx << " " <<bry << " " <<bbx << " " <<bby <<" " << d << "\n";
        }*/
        if(d > 10){
            ans = 999;
            break;
        }

        //up
        if(be != 0){
            if(bry == bby){
                if(brx < bbx){
                    nrx = move_up(brx , bry);
                    inp[nrx][bry] = 'R';
                    nbx = move_up(bbx , bby);
                    inp[nrx][bry] = '.';
                }
                else{
                    nbx = move_up(bbx , bby);
                    inp[nbx][bby] = 'B';
                    nrx = move_up(brx , bry);
                    inp[nbx][bby] = '.';
                }
            }
            else{
                nrx = move_up(brx , bry);
                inp[nrx][bry] = 'R';
                nbx = move_up(bbx , bby);
                inp[nrx][bry] = '.';
            }

            if(nrx == 999){
                if(nbx != 999){
                    ans = d+1;
                    break;
                }
                else{

                }
            }
            
            if(nbx != 999){
                next.rx = nrx;
                next.ry = bry;
                next.bx = nbx;
                next.by = bby;
                next.depth = d+1;
                next.before = 0;
                q.push(next);
            }
        }

        //down
        if(be != 1){
            if(bry == bby){
                if(brx > bbx){
                    nrx = move_down(brx , bry);
                    inp[nrx][bry] = 'R';
                    nbx = move_down(bbx , bby);
                    inp[nrx][bry] = '.';
                }
                else{
                    nbx = move_down(bbx , bby);
                    inp[nbx][bby] = 'B';
                    nrx = move_down(brx , bry);
                    inp[nbx][bby] = '.';
                }
            }
            else{
                nrx = move_down(brx , bry);
                inp[nrx][bry] = 'R';
                nbx = move_down(bbx , bby);
                inp[nrx][bry] = '.';
            }

            if(nrx == 999){
                if(nbx != 999){
                    ans = d+1;
                    break;
                }
                else{

                }
            }
            
            if(nbx != 999){
                next.rx = nrx;
                next.ry = bry;
                next.bx = nbx;
                next.by = bby;
                next.depth = d+1;
                next.before = 1;
                q.push(next);
            }
        }

        //left
         if(be != 2){
            if(brx == bbx){
                if(bry < bby){
                    nry = move_left(brx, bry);
                    inp[brx][nry] = 'R';
                    nby = move_left(bbx, bby);
                    inp[brx][nry] = '.';
                }
                else{
                    nby = move_left(bbx , bby);
                    inp[bbx][nby] = 'B';
                    nry = move_left(brx, bry);
                    inp[bbx][nby] = '.';
                }
            }
            else{
                nry = move_left(brx , bry);
                inp[brx][nry] = 'R';
                nby = move_left(bbx, bby);
                inp[brx][nry] = '.'; 
            }

            if(nry == 999){
                if(nby != 999){
                    ans = d+1;
                    break;
                }
                else{

                }
            }
            
            if(nby != 999){
                next.rx = brx;
                next.ry = nry;
                next.bx = bbx;
                next.by = nby;
                next.depth = d+1;
                next.before = 2;
                q.push(next);
            }
        }

        //right
         if(be != 3){
            if(brx == bbx){
                if(bry > bby){
                    nry = move_right(brx, bry);
                    inp[brx][nry] = 'R';
                    nby = move_right(bbx, bby);
                    inp[brx][nry] = '.';
                }
                else{
                    nby = move_right(bbx , bby);
                    inp[bbx][nby] = 'B';
                    nry = move_right(brx, bry);
                    inp[bbx][nby] = '.';
                }
            }
            else{
                nry = move_right(brx , bry);
                inp[brx][nry] = 'R';
                nby = move_right(bbx, bby);
                inp[brx][nry] = '.'; 
            }

            if(nry == 999){
                if(nby != 999){
                    ans = d+1;
                    break;
                }
                else{

                }
            }
            
            if(nby != 999){
                next.rx = brx;
                next.ry = nry;
                next.bx = bbx;
                next.by = nby;
                next.depth = d+1;
                next.before = 3;
                q.push(next);
            }
        }
        
    }
}

int move_up(int x , int y){

    for(int i = x; i>0; i--){
        if(inp[i-1][y] == 'O'){
            return 999;
        }
        else if(inp[i-1][y] !='.'){
            return i;
        }
    }

    return 111;
}

int move_down(int x , int y){

    for(int i = x; i<N-1; i++){
        if(inp[i+1][y] == 'O'){
            return 999;
        }
        else if(inp[i+1][y] !='.'){
            return i;
        }
    }

    return 111;
}

int move_left(int x, int y){

    for(int i = y; i>0; i--){
        if(inp[x][i-1] == 'O'){
            return 999;
        }
        else if(inp[x][i-1] !='.'){
            return i;
        }
    }

    return 111;
}

int move_right(int x, int y){

    for(int i = y; i<M-1; i++){
        if(inp[x][i+1] == 'O'){
            return 999;
        }
        else if(inp[x][i+1] !='.'){
            return i;
        }
    }

    return 111;
}
