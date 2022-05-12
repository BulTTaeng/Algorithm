#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N;
int inp[21][21];
bool visit[21][21];

struct st
{
    int x;
    int y;
    int d;

}typedef st;


pair<int , int> bs;
int sizeofShart = 2;
int eat = 0;
int ans = 0;

int dx[] = {-1 , 0 , 0, 1};
int dy[] = {0, -1 , 1, 0};

struct compare{
	bool operator()(pair<int, int>a, pair<int, int>b){
		if(a.first == b.first){
            return a.second > b.second;
        }
        else{
            return a.first>b.first;
        }
	}
};

void solve();
int find_fish_eat();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >>N;

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            cin >> inp[i][j];
            if(inp[i][j] == 9){
                bs.first = i;
                bs.second = j;
                inp[i][j] = 0;
            }
        }
    }

    solve();
    return 0;
}

void solve(){
    int t;
    while(true){
        t = find_fish_eat();
        if(t == -1){
            cout << ans;
            break;
        }
        else{
            ans += t;
        }

        if(eat == sizeofShart){
            eat  = 0;
            sizeofShart++;
        }
    }
}

int find_fish_eat(){
    queue<st>q;
    memset(visit , false , sizeof(visit));
    priority_queue<pair<int, int> , vector<pair<int,int>> , compare>pq;

    st temp;
    int re = -1;

    temp.x = bs.first;
    temp.y = bs.second;
    temp.d = 0;

    q.push(temp);
    int x, y ,nx , ny , d;
    
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        d = q.front().d;
        q.pop();

        if(re != -1){
            if(re < d){
                break;
            }
            else{
                if(inp[x][y] < sizeofShart && inp[x][y] != 0){
                    pq.push(make_pair(x,y));
                }
            }
        }
        else{
            if(inp[x][y] < sizeofShart && inp[x][y] != 0){
                re = d;
                pq.push(make_pair(x,y));
            }
            else{
                for(int i =0; i<4;i++){
                    nx = x +dx[i];
                    ny = y+dy[i];
                    if(nx>=0 && ny>=0 && nx<N && ny<N){
                        if(!visit[nx][ny] && inp[nx][ny] <= sizeofShart){
                            temp.x = nx;
                            temp.y = ny;
                            temp.d = d+1;
                            q.push(temp);
                            visit[nx][ny] = true; 
                        }
                    }
                }
            }
        }
    }

    if(!pq.empty()){
        bs.first = pq.top().first;
        bs.second = pq.top().second;
        inp[bs.first][bs.second] = 0;
        pq.pop();
        eat++;
    }

    return re;
}
