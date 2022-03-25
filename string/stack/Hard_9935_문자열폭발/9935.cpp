#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

stack<pair<char , int>> s;

string str , bomb;
bool del[1000002];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int c = -1;
    memset(del , false ,sizeof(del));

    cin >> str >> bomb;

    for(int i =0; i<str.length(); i++){
        if(c == -1){
            if(str[i] == bomb[0]){
                s.push(make_pair(str[i] , i));
                c = 0;
            }
        }
        else if(c >= 0){
            if(str[i] == bomb[c+1]){
                s.push(make_pair(str[i] , i));
                c++;
            }
            else if(str[i] == bomb[0]){
                s.push(make_pair(str[i] , i));
                c=0;
            }
            else{
                while(!s.empty()){
                    s.pop();
                }
                c= -1;
            }
        }

        if(c == bomb.length()-1){
            for(int j =0; j<bomb.length(); j++){
                del[s.top().second] =true;
                s.pop();
            }

            if(!s.empty()){
                
                for(int j =0; j<bomb.length(); j++){
                    if(s.top().first == bomb[j]){
                        c = j;
                        break;
                    }
                }

            }
            else{
                c = -1;
            }

        }
        
    }

    bool printed = false;

    string ans = "";

    for(int i =0; i<str.length(); i++){
        if(!del[i]){
            ans += str[i];
            printed = true;
        }
    }

    if(!printed){
        cout << "FRULA";
    }
    else{
        cout << ans;
    }

    return 0;
}
