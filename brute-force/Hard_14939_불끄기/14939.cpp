#include<iostream>
#include <cstring>
#include <cmath>

using namespace std;

char inp[11][11];
char cinp[11][11];

int nx, ny;

int dx[] = {-1, 1 , 0, 0 , 0};
int dy[] = {0,0,1,-1 , 0};

bool ok();
void press(int x , int y);
void copyinp();


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    for(int i =0; i<10; i++){
        for(int j =0; j<10 ;j++){
            cin >> inp[i][j];
        }
    }

    int ans =987654321;
    int temp = 0;
    bool find_ans = false;
    int p;

    for(int i=0; i<1024; i++){
        temp =0;
        copyinp();

        for(int j =0; j<10; j++){
            p = pow(2,j);
            
            if(i & p){
                temp++;
                press(0,j);
            }
        }

        for(int j=1; j<10; j++){
            for(int k =0; k<10; k++){
                if(cinp[j-1][k] == 'O'){
                    press(j,k);
                    temp++;
                }
            }
        }

        if(ok()){
            find_ans = true;
            ans = min(ans, temp);
        }

    }

    if(find_ans){
        cout << ans;
    }
    else{
        cout << -1;
    }
    
    return 0;
}

bool ok(){
    for(int i =0 ; i<10; i++){
        for(int j =0; j<10; j++){
            if(cinp[i][j] == 'O'){
                return false;
            }
        }
    }

    return true;
}

void press(int x , int y){

    for(int i =0; i<5; i++){
        nx = x+dx[i];
        ny = y+dy[i];
        if(nx>=0 && ny>=0 && nx<10 && ny <10){
            if(cinp[nx][ny] == '#'){
                cinp[nx][ny] = 'O';
            }
            else{
                cinp[nx][ny] = '#';
            }
        }    
    }
}

void copyinp(){
    for(int i =0 ; i<10; i++){
        for(int j =0; j<10; j++){
            cinp[i][j] = inp[i][j];
        }
    }
}
