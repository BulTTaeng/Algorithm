#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N;
string str ,ans;
stack <char> s;
stack <char> temp;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    char t;
    while(N--){
        str = "";
        ans = "";
        ans.clear();
        cin >> str;

        for(int i =0; i<str.length(); i++){

            if(str[i] == '<'){
                if(!s.empty()){
                    t = s.top();
                    s.pop();
                    temp.push(t);
                }
            }
            else if(str[i] == '>'){
                if(!temp.empty()){
                    t = temp.top();
                    temp.pop();
                    s.push(t);
                }
            }
            else if(str[i] == '-'){
                if(!s.empty()){
                    s.pop();
                }
            }
            else{
                s.push(str[i]);
            }
            
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        for(int i =ans.length()-1; i>=0; i--){
            cout << ans[i];
        }

        while(!temp.empty()){
            cout << temp.top();
            temp.pop();
        }

        cout << "\n";
    }
    return 0;
}
