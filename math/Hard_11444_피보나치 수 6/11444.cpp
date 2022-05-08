#include <iostream>

using namespace std;

#define MOD 1000000007

long long N;
long long mat[2][2] = {1, 1, 1, 0};
long long res[2][2] = {1, 0, 0, 1};

void solve(long long m1[2][2], long long m2[2][2]);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    while(N > 0){
        if(N % 2 == 1){
            solve(res, mat);
        }
 
        N /= 2;
        solve(mat, mat);
    }

    
    cout << res[1][0];

    return 0;
}

void solve(long long m1[2][2], long long m2[2][2] ){
    long long tmp[2][2];
    long long temp;
 
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            temp = 0;
            for(int k=0;k<2;++k){
                temp += (m1[i][k] * m2[k][j]);
            }
            tmp[i][j] = temp % MOD;
        }
    }
 
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            m1[i][j] = tmp[i][j];
        }
    }
}
