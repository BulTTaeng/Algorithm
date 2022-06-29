#include <iostream>
#include <cmath>

using namespace std;

int h = 19;
int dp[200001][19];
int M , Q , n,x;
int arr[200001];

int query(int nn ,int xx);
void maketable();


int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> M;

    for(int i =1; i<=M; i++){
        cin >> arr[i];
    }

    maketable();

    cin >> Q;
    for(int i =0; i<Q; i++){
        cin >> n >> x;
        cout << query(n,x) << "\n";
    }

    return 0;
}

void maketable(){

    for(int i = 1; i<=M; i++){ // 한번만 이동하면 인덱스 값 -> 인덱스에 저장된 값
        dp[i][0] = arr[i];
    }

    for(int i =1 ; i<h; i++){
        for(int j = 1; j<=M; j++){
            dp[j][i] = dp[ dp[j][i-1] ][i-1];
        }
    }
}



int query(int nn ,int xx){
    int curr = xx;

    for(int i = 0; i <h; i++){
        if(nn & (1 << i)){
            curr = dp[curr][i];
        }
    }

    return curr;
}
