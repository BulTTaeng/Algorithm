#include <iostream>
#include <cstring>

using namespace std;

int N;

int dp[32];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    memset(dp, 0 , sizeof(dp));

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;


    for (int i = 4; i<=N; i++) {
        if (i % 2 == 1) continue;
        dp[i] = dp[i-2] * dp[2]; // 맨 처음 좌측 2칸을 제외하고 나머지 타일을 채우는 case
        for (int j = 0; j<i-2; j+=2 ){
            dp[i] += dp[j] * 2; 
            // 2의 배수마다 추가되는 2가지 유일 케이스 + j 만큼의 넓이를 가능한 case 로 채우고, 
            // 나머지 공간을 유일 케이스로 채우기
        }
    }

    cout << dp[N];
    return 0;
}
