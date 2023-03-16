#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

char inp[202][202];

int dx[] = {-1, 1, 0, 0 , 0};
int dy[] = {0, 0, 1, -1, 0};

int R ,C ,N;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> R >> C >> N;
    queue<pair<int , int>> q;

    for(int i =0; i<R ; i++){
        for(int j =0; j<C; j++){
            cin >> inp[i][j];
            if(inp[i][j] == 'O'){
                q.push(make_pair(i , j) );
            }
        }
    }

    int num = N % 4;
    if(N == 1){
         for(int i =0; i<R ; i++){
            for(int j =0; j<C; j++){
                cout << inp[i][j];
            }
            cout << "\n";
        }
    }
    else if(num == 2 || num == 0){
        for(int i =0; i<R ; i++){
            for(int j =0; j<C; j++){
                cout << 'O';
            }
            cout << "\n";
        }
    }
    else if(num == 1){
        int x,y,nx,ny;

		while (!q.empty())
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				nx = x + dx[i];
				ny = y + dy[i];

				if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
					inp[nx][ny] = 'O';
				}
			}
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (inp[i][j] == '.') {
					q.push(make_pair(i, j));
				}
			}
		}
        //처음 폭탄 주변을 모두 폭탄으로 만들고, 터지지 않는 부분만 .  으로 표기 함.
        //이제 폭탄을 모두 채웠다 가정하면 .으로 된 부분만 남고 나머지가 모두 터짐.
        //이제 . 으로 표기된 부분 주위를 터트려야 함.

		while (!q.empty())
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				nx = x + dx[i];
				ny = y + dy[i];

				if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
					inp[nx][ny] = '.';
				}
			}
		}

        for(int i =0; i<R; i++){
                for(int j=0; j<C; j++){
                    cout << inp[i][j];
                }
                cout <<"\n";
            }
        
    }

    else{

            char output[202][202];

            int nx , ny , x, y;

            for(int i =0; i<R; i++){
                for(int j=0; j<C; j++){
                    output[i][j] = 'O';
                }
            }

            while(!q.empty()){
                x = q.front().first;
                y = q.front().second;
                q.pop();

                for(int i =0; i<5 ; i++){
                    nx = x+dx[i];
                    ny = y+dy[i];

                    if(nx >=0 && ny >=0 && nx<R && ny <C){
                        output[nx][ny] = '.';
                    }
                }

            }

            for(int i =0; i<R; i++){
                for(int j=0; j<C; j++){
                    cout << output[i][j];
                }
                cout <<"\n";
            }


    }

    return 0;
}
