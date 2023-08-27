#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N, M;
bool board[5][5];
bool visit[5][5];
int ans = 0;

int dx[] = {-1,1,0,0};
int dy[] {0,0,1,-1};


vector<pair<int,int>> destinations;

void dfs(int x, int y, int tx , int ty, int idx){

	visit[x][y] = true;
	int nx, ny;

	if(x == tx && y == ty){
		if(idx == (M-1)) {
			ans++;
			visit[x][y] = false;
			return;
		}
		else{
			for(int i = 0;i<4; i++){
				nx = x +dx[i];
				ny = y + dy[i];
				if(!visit[nx][ny] && board[nx][ny]){
					dfs(nx,ny,destinations[idx+1].first,destinations[idx+1].second, idx+1);
				}
			}
		}
	} else{
		for(int i = 0;i<4; i++){
			nx = x +dx[i];
			ny = y + dy[i];
			if(!visit[nx][ny] && board[nx][ny]){
				dfs(nx,ny,tx,ty, idx);
			}
		}
	}

	visit[x][y] = false;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	cin >> N >> M;

	int temp;
	

	for(int i =1; i<=N; i++){
		for(int j =1; j<=N; j++){
			cin >> temp;
			if(temp == 1) board[i][j] = false;
			else board[i][j] = true;
		}
	}

	int x, y;

	for(int i=0; i<M; i++){
		cin >> x >> y;
		destinations.push_back({x,y});
	}

	memset(visit ,false, sizeof(visit));


	dfs(destinations[0].first , destinations[0].second , destinations[1].first , destinations[1].second, 1);

	cout << ans;

	return 0;
}
