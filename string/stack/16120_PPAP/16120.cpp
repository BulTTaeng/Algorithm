#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;

stack<char> s;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> str;

    for(int i =0; i<str.length(); i++){
        
        if(str[i] == 'P'){
            if(s.empty()){
              s.push(str[i]);
            }
            else if(s.top() == 'A'){
                s.pop();
                s.pop();
            }
            else{
                s.push(str[i]);
            }
        }
        else if(str[i] == 'A'){
            if(s.size() <2 || s.top() == 'A'){
                cout << "NP";
                return 0;
            }
            else{
                s.push(str[i]);
            }
        }
        else{
            cout << "NP";
            return 0;
        }
    }

    if(s.size() == 1 && s.top() == 'P'){
        cout << "PPAP";
    }
    else{
        cout << "NP";
    }
    return 0;
}
