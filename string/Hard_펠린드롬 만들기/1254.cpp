#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

string str;
vector<char> v;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> str;

    int loc = 0;
    bool poss;
    int ii = 0;

    while(true){
        poss = true;
        ii = 0;
        for(int i =loc; i<str.length() ; i++){
            if(str[i] == str[str.length()-1-ii]){
                ii++;
                continue; 
            }
            else{
                poss = false;
                break;
            }
        }

        if(poss){
            cout << str.length() + loc;
            break;
        }

        loc++;
            
    }
    
    return 0;
}
