#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N , M;
int inp[51][51];
int cnp[51][51];
bool visit[51][51];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0,0, 1, -1};

#define MAX 987654321
int ans = MAX;


void simulation(vector<pair<int, int>>v);
void combination(int idx, vector<pair<int, int>>v);
void copy();

struct st{
    int x;
    int y;
    int d;
}typedef st;

vector<pair<int,int>> virus;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >>M;

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            cin >> inp[i][j];

            if(inp[i][j] == 2){
                virus.push_back(make_pair(i,j));
            }
        }
    }
    vector<pair<int , int>> v;
    combination(0,v);
    if(ans == MAX){
        cout << -1;
    }
    else{
        cout << ans;
    }
    return 0 ;
}

void copy(){
    memset(visit ,false ,sizeof(visit));

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            cnp[i][j] = inp[i][j];
            if(cnp[i][j] == 2){
                cnp[i][j] = 0;
            }
        }
    }
}

void combination(int idx, vector<pair<int, int>>v){
    
    if(v.size() == M){
        copy();
        simulation(v);
        return;
    }

    if(idx >=virus.size()){
        return;
    }

    combination(idx+1 , v);
    v.push_back(make_pair(virus[idx].first , virus[idx].second));
    combination(idx+1 , v);
}

void simulation(vector<pair<int, int>>v){
    
    queue<st>q;
    st temp;

    

    for(int i =0; i<v.size(); i++){
        temp.x = v[i].first;
        temp.y = v[i].second;
        temp.d = 0;
        visit[temp.x][temp.y] = true;
        cnp[temp.x][temp.y] = 2;
        q.push(temp);
    }

    int x , d, y;
    int nx, ny;

    while(!q.empty()){
        x= q.front().x;
        y = q.front().y;
        d = q.front().d;
        q.pop();

        for(int i =0; i<4; i++){
            nx = x +dx[i];
            ny = y + dy[i];

            if(nx >=0 && ny>=0 && nx<N && ny<N){
                if(!visit[nx][ny] && cnp[nx][ny] == 0){
                    temp.x = nx;
                    temp.y = ny;
                    temp.d = d+1;
                    cnp[nx][ny] = d+1;
                    q.push(temp);
                    visit[nx][ny] = true;
                }
            }
        }
    }

    bool filled = true;

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            if(cnp[i][j] == 0){
                filled = false;
                break;
            }
        }
    }

    if(filled)
        ans = min(ans, d);
}

