#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

char inp[251][251];
int visit[251][251];
vector<pair<int , int>> v;
int r , c;
int sheep = 0;
int wolf = 0;
int ts =0;
int tw = 0;

void DFS(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> r >> c;

    for(int i=0;i<r; i++){
        for(int j =0; j<c ; j++){
            cin >> inp[i][j];
            if(inp[i][j] == 'v'){
                v.push_back(make_pair(i,j) );
                wolf ++;
            }

            if(inp[i][j] == 'k'){
                sheep ++;
            }
        }
    }

    for(int i =0; i < v.size(); i++){
        ts = 0; tw = 0;
        if( !visit[v[i].first][v[i].second] ){
            DFS(v[i].first , v[i].second);

            if(ts > tw){
                wolf -= tw;
            }
            else{
                sheep -= ts;
            }
        }
    }

    cout << sheep << " " << wolf;
    return 0;
}

void DFS(int x , int y){

    visit[x][y] = true;

    queue<pair<int , int> > q;

    q.push(make_pair(x,y));

    while(!q.empty()){
        int f = q.front().first;
        int s = q.front().second;
        q.pop();

        if(inp[f][s] == 'v'){
            tw++;
        }

        if(inp[f][s] == 'k'){
            ts++;
        }

        if(inp[f][s] == '#'){
            continue;
        }
        else{
            if(f>0){
                if(!visit[f-1][s]){
                    q.push(make_pair(f-1 , s));
                    visit[f-1][s] = true;
                }
            }

            if(s>0){
                if(!visit[f][s-1]){
                    q.push(make_pair(f , s-1));
                    visit[f][s-1] = true;
                }
            }
            if(f<r-1){
                if(!visit[f+1][s]){
                    q.push(make_pair(f+1 , s));
                    visit[f+1][s] = true;
                }
            }
            if(s < c-1){
                if(!visit[f][s+1]){
                    q.push(make_pair(f , s+1));
                    visit[f][s+1] = true;
                }
            }
        }
    }

}
