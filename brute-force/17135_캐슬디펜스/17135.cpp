#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N , M , D;
int inp[17][17];
int inp1[17][17];
bool visit[17][17];
bool check[17][17];

int ans = 0;
int num = 0;

int dx[] = {0, -1 ,0};
int dy[] = {-1, 0, 1};

struct st{
    int x;
    int y;
    int depth;
}typedef st;

void combination(int idx , vector<int> v);
void simulate(vector<int> v );
void find_enemy(int x, int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M >> D;

    for(int i =0; i<N ; i++){
        for(int j =0; j<M; j++){
            cin >> inp1[i][j];
        }
    }

    vector<int> v;

    combination(0,v);

    cout << num;
    return 0;
}

void combination(int idx , vector<int> v){ // 조합 만들기

    if(v.size() == 3){
        for(int i =0; i<N; i++){
            for(int j =0; j<M; j++){
                inp[i][j] = inp1[i][j];
            }
        }
        simulate(v);
        return;
    }

    if(idx >=M){
        return;
    }

    
    combination(idx+1 , v);
    v.push_back(idx);
    combination(idx+1, v);
}

void simulate(vector<int> v){ // 시뮬레이션 돌리기

    memset(check ,false ,sizeof(check));

    for(int j = 1; j<=N; j++){ // 궁수 바로 앞(유일하게 거리가 1 인곳) 부터 시작
        for(int i =0; i<3; i++){
            memset(visit ,false ,sizeof(visit)); // bfs를 위한 방문 처리 
            find_enemy(N-j,v[i]);
        }

        for(int ii =0; ii<N; ii++){ // 타켓팅 된 적들 사살 , queue사용하는게 더 좋을 듯
            for(int jj =0; jj<M; jj++){
                if(check[ii][jj]){
                    inp[ii][jj] = 0;
                }
            }
        }
    }

    for(int i =0; i<N; i++){ // 한번의 시뮬레이션이 끝나고 죽었다고 표시되는 얘들을 다 체크
        for(int j =0; j<M; j++){
            if(check[i][j]){
                ans++;
            }
        }
    }
    num = max(num , ans); // 최대값 비교
    ans = 0;
}

void find_enemy(int x, int y){

    queue<st>q;

    st temp;
    temp.x=x;
    temp.y=y;
    temp.depth=1; // 궁수 바로 앞 (거리가 1 인곳) 부터 시작했으니 길이는 1

    q.push(temp);
    int nx , ny;
    int cx,cy;
    int d;

    while(!q.empty()){
        
        cx = q.front().x;
        cy = q.front().y;
        d = q.front().depth;
        q.pop();

        if(d>D){
            break;
        }

        visit[cx][cy] = true;

        if(inp[cx][cy] == 1){
            check[cx][cy] = true;
            break;
        }

        for(int i =0; i<3; i++){
            nx = cx+dx[i];
            ny = cy +dy[i];
            if(nx>=0 && ny>=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    temp.x = nx;
                    temp.y = ny;
                    temp.depth=d+1;
                    q.push(temp);
                }
            }
        }

    }

    return;
}

