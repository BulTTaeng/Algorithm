#include <iostream>
#include <cstring>

using namespace std;

int N , M;
bool broken[11];
int dp[1000001];

void can_make();
int broken_digit(int num);
int solve(int num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> M;
    int temp;

    memset(broken , false, sizeof(broken));

    for(int i =0; i<M; i++){
        cin >> temp;
        broken[temp] = true;
    }

    can_make();
    dp[100] = 0;
    dp[101] = 1;
    dp[102] = 2;
    dp[99] = 1;
    dp[98] = 2;


    int ans = solve(N);
    
    cout << ans;
    return 0;
}

void can_make(){
    int save;

    for(int i =0 ; i<1000001; i++){
        save = broken_digit(i);
        dp[i] = save;
    }
}

int broken_digit(int num){
    int re = 0;

    if(num == 0){
        if(broken[0]){
            return -1;
        }
        else{
            return 1;
        }
    }

    while(num != 0){
        if(broken[num%10]){
            return -1;
        }
        re++;
        num = num/10;
    }

    return re;
}

int solve(int num){
    if(dp[num] != - 1){
        return dp[num];
    }
    else{
        int re = 0;
        int mini , maxi;
        mini = num;
        maxi = num;

        while(true){
            if(dp[mini] != -1){
                return re + dp[mini];
            }
            
            if(dp[maxi] != -1){
                return re+ dp[maxi];
            }
            if(mini-1 >=0)
                mini--;
            if(maxi+1 <=1000000)
                maxi++;
            re++;
        }
    }
}
