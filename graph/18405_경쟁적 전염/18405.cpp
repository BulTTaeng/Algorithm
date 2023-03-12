#include<iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

vector<pair<int , int>> v[1001];

int N ,K , S ,X ,Y , virus = 0;
int inp[202][202];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >>K;

    

    for(int i =1; i<=N; i++){
        for(int j =1; j<=N ; j++){
            cin >> inp[i][j];
            if(inp[i][j] != 0){
                v[inp[i][j]].push_back(make_pair(i,j));
                virus++;
            }
        }
    }

    cin >> S >> X >> Y;
    vector<pair<int , int>> newv;

    for(int i=1; i<=S; i++){// i -> second
        
        int nx, ny;

        for(int j=1; j<=K ; j++){ // j -> the number of virus
            
            newv.clear();
            for(int k = 0; k<v[j].size(); k++){//k -> the number of j virus
                for(int t =0; t<4; t++){
                    nx = v[j][k].first + dx[t];
                    ny = v[j][k].second + dy[t];

                    if(nx>=1 && ny>=1 && nx<=N && ny<=N){
                        if(inp[nx][ny] == 0){
                            inp[nx][ny] = j;
                            newv.push_back(make_pair(nx , ny));
                        }
                    }
                }
            }

            v[j].clear();
            v[j] = {newv.begin(), newv.end()};
        }//end of j loop
    }

    /*for(int i =1 ;i<=N; i++){
        for(int j =1; j<=N; j++){
            cout << inp[i][j] << " ";
        }
        cout <<"\n";
    }*/

    cout<< inp[X][Y];
    return 0;
}
