#include <iostream>

using namespace std;

int inp[102][102];
int ans[102][102];
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            cin >> ans[i][j];
        }
    }

    for(int k = 0; k<N; k++){
        
        for(int i =0; i<N;i++){
            for(int j =0; j<N; j++){
                if(ans[i][k] == 1 && ans[k][j] == 1){
                    ans[i][j] = 1;
                }        
            }
        }

    }

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
