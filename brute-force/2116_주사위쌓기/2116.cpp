#include <iostream>
#include <vector>

using namespace std;

int N;

int inp[10001][6];

int ans = 0;

void solve(int sum , int bt , int num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =0; i<N; i++){
        for(int j =0; j<6; j++){
            cin >> inp[i][j];
        }
    }
    for(int i =1; i<=6; i++){
        solve(0,i,0);
    }

    cout << ans;
    return 0;
}

void solve(int sum , int bt , int num){
    if(num == N){
        ans = max(ans , sum);
        return;
    }

    int temp=0;
    int bloc;
    int tloc;
    int newbt;

    for(int i =0; i<6; i++){
        if(inp[num][i] == bt){
            bloc = i;
            break;  
        }
    }

    if(bloc == 0){
        newbt = inp[num][5];
        tloc = 5;
    }
    else if(bloc == 1){
        newbt = inp[num][3];
        tloc = 3;
    }
    else if(bloc == 2){
        newbt = inp[num][4];
        tloc = 4;
    }
    else if(bloc == 3){
        newbt = inp[num][1];
        tloc = 1;
    }
    else if(bloc == 4){
        newbt = inp[num][2];
        tloc = 2;
    }
    else if(bloc == 5){
        newbt = inp[num][0];
        tloc = 0;
    }

    for(int i =0; i<6; i++){
        if(i == tloc || i == bloc) continue;
        
        temp = max(temp,inp[num][i]);
        
    }

    solve(sum+temp , newbt , num+1);

}
