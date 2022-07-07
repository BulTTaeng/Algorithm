#include <iostream>

using namespace std;

int N , M;

bool inp[51][51];
bool target[51][51];

void change(int n , int m);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    char temp;

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            cin >> temp;
            if(temp == '0'){
                inp[i][j] = false;
            }
            else{
                inp[i][j] = true;
            }
        }
    }

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            cin >> temp;
            if(temp == '0'){
                target[i][j] = false;
            }
            else{
                target[i][j] = true;
            }
        }
    }

    int ans = 0;

    for(int i=0; i<N-2; i++){
        for(int j =0; j<M-2; j++){
            if(inp[i][j] != target[i][j]){
                change(i,j);
                ans++;
            }
        }
    }

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            if(inp[i][j] != target[i][j]){
                cout << -1;
                return 0;
            }
        }
    }

    cout << ans;
    return 0;

}

void change(int n , int m){

    for(int i = n; i<=n+2; i++){
        for(int j =m ; j<=m+2 ; j++){
            inp[i][j] = !inp[i][j];
        }
    }

}
