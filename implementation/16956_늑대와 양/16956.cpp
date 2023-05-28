#include <iostream>

using namespace std;

char inp[502][502];

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int r , c;

    cin >> r >> c;

    for(int i = 1 ; i<=r; i++){
        for(int j =1; j<=c; j++){
            cin >> inp[i][j];
        }
    }

    int possible = 1;

    for(int i = 1 ; i<=r; i++){
        for(int j =1; j<=c; j++){
            if(inp[i][j] == 'W'){
                if(inp[i-1][j] == 'S'){
                    possible = 0;
                    break;
                }
                else if(inp[i][j-1] == 'S'){
                    possible = 0;
                    break;
                }
                else if(inp[i][j+1] == 'S'){
                    possible = 0;
                    break;
                }
                else if(inp[i+1][j] == 'S'){
                    possible = 0;
                    break;
                }
                else{
                    if(inp[i-1][j] != 'W'){
                        inp[i-1][j] = 'D';
                    }
                    if(inp[i][j-1] != 'W'){
                        inp[i][j-1] = 'D';
                    }
                    if(inp[i+1][j] != 'W'){
                        inp[i+1][j] = 'D';
                    }
                    if(inp[i][j+1] != 'W'){
                        inp[i][j+1] = 'D';
                    }
                }

            }
        }
        if(possible == 0){
            break;
        }
    }
    
    cout << possible<<"\n";

    if(possible == 1){
        for(int i =1; i<=r; i++){
            for(int j=1; j<=c; j++){
                cout << inp[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
