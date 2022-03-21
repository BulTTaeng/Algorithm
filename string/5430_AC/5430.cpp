#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int T , N;
string p , str;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;
    char c , op;
    int t;

    string ans = "";
    bool r = false;
    bool err = false;

    while(T--){
        r= false;
        err = false;

        cin >> p;
        cin >> N;
        cin >> str;

        deque<int> dq;
        string temp = "";

        for(int i =0; i<str.length(); i++){
            if(isdigit(str[i])){
                temp += str[i];
            }
            else{
                if(!temp.empty()){
                    dq.push_back(stoi(temp));
                    temp = "";
                }
            }
        }

        for(int i =0; i<p.length(); i++){
            op =p[i];

            if(op == 'R'){
                r = !r;
            }
            else if(op == 'D') {
                if(dq.empty()){
                    err = true;
                    break;
                }
                else{
                     if(r){
                        dq.pop_back();
                    }
                    else{
                        dq.pop_front();
                    }
                }
               
            }

        }

        if(err){
            cout << "error" << "\n";
        }
        else{
            cout << '[';

            if(r){
                reverse(dq.begin() , dq.end());
            }

            for(auto iter = dq.begin(); iter != dq.end() ; iter ++){
                if(iter == dq.end()-1){
                    cout << *iter;
                }
                else{
                    cout << *iter << ',';
                }
            }
            cout <<']' << "\n";
        }
       
    }

    return 0;
}
