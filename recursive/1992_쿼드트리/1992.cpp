#include <iostream>

using namespace std;

int N;
string ans = "";

char inp[65][65];

void solve(int size  , int x1 , int y1 , int x2 , int y2);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =0; i<N; i++){
        for(int j =0 ;j <N; j++){
            cin >> inp[i][j];
        }
    }

    solve(N , 0, 0 , N , N);

    cout << ans;

    return 0;
}

void solve(int size  , int x1 , int y1 , int x2 , int y2){
    bool check = true;
    int size_2 = size/2;
    char firstnum = inp[x1][y1];

    for(int i =x1; i<x2; i++){
        for(int j =y1; j<y2; j++){
            if(inp[i][j] != firstnum){
                check = false;
                ans += '(';
                
                solve(size_2 , x1  , y1 , x1+size_2 , y1 + size_2);
                solve(size_2 , x1  , y1+size_2 , x1+size_2 , y2);
                solve(size_2 , x1+size_2  , y1 , x2 , y1 + size_2);
                solve(size_2 , x1+size_2  , y1+size_2 , x2 , y2);

                break;
            }
        }
        if(check == false){
            break;
        }
    }
    if(!check){
        ans += ')';
    }
    else{
        ans += firstnum;
    }
}
