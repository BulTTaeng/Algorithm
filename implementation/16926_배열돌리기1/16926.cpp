#include <iostream>
#include <algorithm>

using namespace std;

int N , M , R;

int inp[301][301];
int ans[301][301];

void rotate(int x , int y , int c);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M >> R;

    for(int i =0 ;i<N; i++){
        for(int j =0; j<M; j++){
            cin >> inp[i][j];
        }
    }

    for(int r = 0; r <R; r++){
        for(int i =0; i<min(N,M)/2; i++){
            rotate(i,i,r);
        }
    }

    if(R%2 == 1){
        for(int i =0 ;i<N; i++){
            for(int j =0; j<M; j++){
                cout << ans[i][j] << " ";
            }
            cout <<"\n";
        }
    }

    else{
        for(int i =0 ;i<N; i++){
            for(int j =0; j<M; j++){
                cout << inp[i][j] << " ";
            }
            cout <<"\n";
        }
    }
}

void rotate(int x , int y , int c){

    if(c%2 == 0){
        for(int i= x; i<N-x-1; i++){
            ans[i+1][y] = inp[i][y];
        }

        for(int i=y ; i<M-y-1; i++){
            ans[N-x-1][i+1] = inp[N-x-1][i];
        }

        for(int i =N-x-1; i>x; i--){
            ans[i-1][M-y-1] = inp[i][M-y-1]; 
        }

        for(int i= M-y-1; i>y; i--){
            ans[x][i-1]= inp[x][i];
        }
    }

    else{
        for(int i= x; i<N-x-1; i++){
            inp[i+1][y] = ans[i][y];
        }

        for(int i=y ; i<M-y-1; i++){
            inp[N-x-1][i+1] = ans[N-x-1][i];
        }

        for(int i =N-x-1; i>x; i--){
            inp[i-1][M-y-1] = ans[i][M-y-1]; 
        }

        for(int i= M-y-1; i>y; i--){
            inp[x][i-1]= ans[x][i];
        }
    }
}
