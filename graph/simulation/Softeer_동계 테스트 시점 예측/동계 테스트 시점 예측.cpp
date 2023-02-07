#include<iostream>
#include <cstring>

using namespace std;

int N, M, ans = 0;
int board[101][101];
int check[101][101];
bool visit[101][101];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0 , 0 , 1 , -1};

void dfs(int x, int y){
	visit[x][y] = true;
	int nx,ny;

	for(int i = 0; i<4; i++){
		nx = x+dx[i];
		ny = y+dy[i];

		if(nx >=0 && nx<N && ny>=0 && ny<M){
			
			if(board[nx][ny] == 1){
				check[nx][ny]++;
			}
			else{
				if(!visit[nx][ny]) dfs(nx , ny);
			}
		
		}	
	}
}

void melt(){
	for(int i =0; i<N; i++){
		for(int j =0; j<M; j++){
			if(check[i][j] >= 2) board[i][j] = 0;
		}
	}
}

bool ends(){
	for(int i =0; i<N; i++){
		for(int j =0; j<M; j++){
			if(board[i][j] == 1) return false;
		}
	}

	return true;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;

	int temp = 0;

	for(int i =0 ;i<N; i++){
		for(int j =0 ; j<M; j++){
			cin >> board[i][j];
			temp += board[i][j];
		}
	}

	if(temp == 0){
		cout << 0;
		return 0;
	}

	while(true){
		memset(check , 0 , sizeof(check));
		memset(visit ,false ,sizeof(visit));
		ans++;
		dfs(0,0);
		melt();
		if(ends()) break;
	}
	cout << ans;
	return 0;
}
