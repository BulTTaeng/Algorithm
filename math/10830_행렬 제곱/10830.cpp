#include <iostream>
#include <cstring>

using namespace std;

int N;
long long B;
long long A[6][6];
long long ans[6][6];
long long t[6][6];

void solve();
void mul(long long a[6][6] , long long b[6][6]);


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> B;

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            cin >> A[i][j];
        }
    }

    memset(ans , 0 , sizeof(ans));
    for(int i =0; i<6; i++){
        ans[i][i] = 1;
    }

    solve();

    for(int i =0 ;i<N; i++){
        for(int j =0; j<N; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

void solve(){
    while(B>0){
        if(B%2 == 1){
            B--;
            mul(ans,A);
        }
        else{
            B /= 2;
            mul(A,A);
        }
    }
}

void mul(long long a[6][6] , long long b[6][6]){
    memset(t, 0 , sizeof(t));

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){

            for(int k =0; k<N; k++){
                t[i][j] += a[i][k] * b[k][j];
            }
            t[i][j] = t[i][j] % 1000;
        }
    }

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            a[i][j] = t[i][j];
        }
    }
}
