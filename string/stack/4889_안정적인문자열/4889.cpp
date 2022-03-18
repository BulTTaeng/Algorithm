#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> s;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string str;

    int ii = 0;

    int ans = 0;

    while(getline(cin , str)){

        if(str[0] == '-'){
            break;
        }
        ans = 0;

        for(int i=0; i<str.length(); i++){
            if(str[i] == '{'){
                s.push(0);
            }
            else{
                if(s.empty()){
                    ans++;
                    s.push(0);
                }
                else{
                    s.pop();
                }
            }
        }

        while(!s.empty()){
            s.pop();
            s.pop();
            ans++;
        }
        ii++;

        cout << ii <<". " << ans << "\n";
    }

    return 0;
}
