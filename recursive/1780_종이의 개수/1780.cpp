#include <iostream>

using namespace std;

int N;
int minus1 = 0;
int num0 = 0;
int num1 = 0;

int inp[2200][2200];

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

    cout << minus1 << "\n" << num0 << "\n" << num1;

    return 0;
}

void solve(int size  , int x1 , int y1 , int x2 , int y2){
    bool check = true;
    int size_3 = size/3;
    int firstnum = inp[x1][y1];

    for(int i =x1; i<x2; i++){
        for(int j =y1; j<y2; j++){
            if(inp[i][j] != firstnum){
                check = false;
                solve(size_3 , x1 , y1 , x1+size_3, y1 + size_3);
                solve(size_3 , x1 , y1+size_3 , x1+size_3, y1+size_3*2);
                solve(size_3 , x1 , y1+size_3*2 , x1+size_3, y2);

                solve(size_3 , x1+size_3 , y1, x1+size_3*2, y1 + size_3);
                solve(size_3 , x1+size_3 , y1+size_3, x1+size_3*2, y1 + size_3*2);
                solve(size_3 , x1+size_3 , y1+size_3*2, x1+size_3*2, y2);

                solve(size_3 , x1+size_3*2 , y1, x2, y1 + size_3);
                solve(size_3 , x1+size_3*2 , y1+size_3, x2, y1 + size_3*2);
                solve(size_3 , x1+size_3*2 , y1+size_3*2, x2, y2);
                
                break;
            }
        }
        if(check == false){
            break;
        }
    }
    if(check){
        if(firstnum == -1){
            minus1++;
        }
        else if(firstnum == 1){
            num1++;
        }
        else if(firstnum == 0){
            num0++;
        }
    }
}
