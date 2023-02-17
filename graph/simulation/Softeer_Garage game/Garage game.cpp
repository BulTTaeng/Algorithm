#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>

using namespace std;

int N;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


int ans =0;

void dfs(int time , int b[46][16] , int score){
	
	int num = -1;
	int minx, miny, maxx, maxy;
	int x,y,nx,ny;

	
	int w,h;
	int cboard[46][16];
	bool visit[16][16] = {false, };

	for(int i =0; i<3*N; i++){
		for(int j =0; j<N; j++){
			cboard[i][j] = b[i][j];
		}
	}

	for(int i =2*N; i<3*N;i++){
		for(int j =0; j<N; j++){
			if(!visit[i - 2*N][j] && cboard[i][j] != -1) {

				int temps = score;

				num = cboard[i][j];
				visit[i - 2*N][j] = true; 
				cboard[i][j] = -1;
				queue<pair<int,int>> q;
				q.push({i,j});
				minx = i;
				maxx = i;
				miny = j;
				maxy = j;
				temps++;

				while(!q.empty()){
					x = q.front().first;
					y = q.front().second;
					q.pop();

					for(int k =0; k<4; k++){
						nx = x + dx[k];
						ny = y + dy[k];
						if(nx>=2*N && nx<3*N && ny >= 0 && ny<N){
							if(!visit[nx - 2*N][ny] && num == cboard[nx][ny] ){
								visit[nx - 2*N][ny] = true;
								cboard[nx][ny] = -1;
								q.push({nx,ny});
								minx = min(minx , nx);
								miny = min(miny , ny);
								maxx = max(maxx , nx);
								maxy = max(maxy , ny);
								temps++;
							}
						}
					}	
				} // 같은 색 모두 삭제 완료

				//넓이 계산
				w = (maxx - minx+1);
				h = (maxy - miny+1);
				temps += (w*h);

				//아래로 이동

				if(time < 2){
					for(int ii =minx; ii<=maxx; ii++){
						for(int jj = miny ; jj<=maxy; jj++){
							if(cboard[ii][jj] == -1){
								int ti = ii;
								while(ti >0){
									cboard[ti][jj] = cboard[ti-1][jj];
									ti--;
								}
							}
						}
					}
						
					dfs(time+1 , cboard, temps);

					for(int i =0; i<3*N; i++){
						for(int j =0; j<N; j++){
							cboard[i][j] = b[i][j];
						}
					}
				}
				else{
					ans = max(ans , temps) ;
				}

			}
		}// j loop
	}
	
	
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int board[46][16];

	cin >> N;

	for(int i =0; i<3*N; i++){
		for(int j =0; j<N; j++){
			cin >> board[i][j];
		}
	}

	dfs(0,board,0);
	cout << ans;

	return 0;
}
