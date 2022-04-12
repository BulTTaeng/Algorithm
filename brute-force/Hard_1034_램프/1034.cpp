#include <iostream>

using namespace std;

int N , M , K;

string inp[52];
int ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i =0; i<N; i++){
        cin >> inp[i];
    }

    cin >> K;

    int num_zero = 0;
    int same_pattern = 0;

    for(int i =0; i<N; i++){
        num_zero = 0;
        same_pattern = 0;

        for(int j =0; j<M; j++){
            if(inp[i][j] == '0'){
                num_zero++;
            }
        }

        if(num_zero <= K && (num_zero %2) == (K%2)){
            for(int j=0; j<N; j++){
                if(inp[i] == inp[j]){
                    same_pattern++;
                }
            }        
        }

        ans = max(ans , same_pattern);
    }


    cout << ans;
    return 0;
}
