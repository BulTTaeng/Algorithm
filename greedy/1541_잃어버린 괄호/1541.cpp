#include <iostream>
#include <string>

using namespace std;

string inp;

int ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> inp;

    string temp = "";

    int t = 0;
    char x = 'x';

    for(int i =0; i<inp.length(); i++){
        if(inp[i] == '+'){
            if(x == 'x'){
                ans += stoi(temp);
                temp.clear();
            }
            else{
                t -= stoi(temp);
                temp.clear();
            }
        }
        else if(inp[i] == '-'){
    
            if(x == 'x'){
                x ='-';                
                ans += stoi(temp);
                temp.clear();
            }
            else{
                t -= stoi(temp);
                temp.clear();
            }
        }
        else{
            temp+= inp[i];
        }
    }

    if(x == 'x'){
        ans += stoi(temp);
    }
    else{
        t -= stoi(temp);
    }

    ans = ans+t;

    cout << ans;
    return 0;
}
