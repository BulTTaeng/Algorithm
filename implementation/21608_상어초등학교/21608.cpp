#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;

vector<int> v;

int inp[401][5];
int emp[22][22];
int ans[22][22];

int dx[] = {-1, 1 , 0 , 0};
int dy[] = {0, 0 , 1 , -1};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int temp;
    int tt;

    for(int i =1; i <=N*N; i++){
        cin >> temp;
        v.push_back(temp);

        for(int j =0; j<4; j++){
           cin >> inp[temp][j]; 
        }
    }

    emp[0][0] = -1;

    for(int i =1; i<=N; i++){
        for(int j =1  ; j<=N; j++){
            emp[i][j] =4;
        }
    }
    
    for(int i =1; i<=N; i++){
            emp[i][1] = 3;
            emp[1][i] = 3;
            emp[N][i] = 3;
            emp[i][N] = 3;
    }

    emp[1][1] = 2;
    emp[1][N] = 2;
    emp[N][1] = 2;
    emp[N][N] = 2;

    int locx , locy;
    int maxi = 0;
    temp=0;

    int nx , ny;

    memset(ans , 0 , sizeof(ans));

    for(int i =0; i<v.size(); i++){
        maxi = -1;
        locx = 0;
        locy = 0;

        for(int j=1; j<=N; j++){
            for(int k =1 ; k<=N; k++){

                if(emp[j][k] <= -1) continue;

                temp = 0;

                for(int ii =0; ii<4; ii++){
                    nx = j+dx[ii];
                    ny = k+dy[ii];

                    if(nx>=1 && ny >=1 && nx<=N && ny<=N){
                        if(ans[nx][ny] == inp[v[i]][0] || ans[nx][ny] == inp[v[i]][1] || ans[nx][ny] == inp[v[i]][2] || ans[nx][ny] == inp[v[i]][3]){
                            temp++;
                        }
                    }

                }

                if(temp > maxi){
                    locx = j;
                    locy = k;
                    maxi = temp;
                }
                else if(temp == maxi){
                    if(emp[j][k] > emp[locx][locy]){
                        locx = j;
                        locy = k;
                    }
                }
            }
        }

        ans[locx][locy] = v[i];
        emp[locx][locy] = -1;

        for(int ii =0; ii<4; ii++){
            nx = locx+dx[ii];
            ny = locy+dy[ii];

            if(nx>=1 && ny >=1 && nx<=N && ny<=N){
                emp[nx][ny]--;
            }

        }
    }

    int score = 0;

    for(int j=1; j<=N; j++){
        for(int k =1 ; k<=N; k++){
            temp = 0;

            int val = ans[j][k];

            for(int ii =0; ii<4; ii++){
                nx = j+dx[ii];
                ny = k+dy[ii];

                if(nx>=1 && ny >=1 && nx<=N && ny<=N){
                    if(ans[nx][ny] == inp[val][0] || ans[nx][ny] == inp[val][1] || ans[nx][ny] == inp[val][2] || ans[nx][ny] == inp[val][3]){
                        temp++;
                    }
                }

            }

            if(temp == 1){
                score += 1;
            }
            else if(temp == 2){
                score += 10;
            }
            else if(temp == 3){
                score += 100;
            }
            else if(temp == 4){
                score += 1000;
            }

        }
    }

    cout << score;
    return 0;
}
