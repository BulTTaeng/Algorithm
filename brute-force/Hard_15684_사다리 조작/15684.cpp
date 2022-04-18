#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N , M , H;
bool con[11][31];

int ans = 4;

void combination(int loc , int num , int depth);
bool simulation();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M >> H;
    int a , b;
    memset(con ,  false ,sizeof(con));

    for(int i =0; i<M; i++){
        cin>> a >> b;
        con[b][a] = true;
    }

    for(int i =0; i<4 ; i++){
        combination(1,0,i);
    }

    cout << -1;
    return 0;

}

bool simulation(){
    int result = 0;

    for(int i = 1 ; i<=N; i++){
        result = i;
        for(int j =1 ; j<=H; j++){
            if(con[result][j]){
                result++;
            }
            else if(con[result-1][j]){
                result--;
            }
        }
        if(result != i){
            return false;
        }
    }

    return true;
}

void combination(int loc , int num , int depth){
    if(depth == num){
        if(simulation()){
            cout << depth;
            exit(0);
        }
        return;
    }

    for(int i =1; i<N; i++){
        for(int j =loc ; j<=H; j++){
            if(con[i][j]) continue;
            if(con[i-1][j]) continue;
            if(con[i+1][j]) continue;

            con[i][j] = true;
            combination( j , num+1 , depth);
            con[i][j] = false;
        }
    }
}
