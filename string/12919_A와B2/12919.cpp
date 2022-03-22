#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

string str , target;
queue<string>q;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> str >> target;
    string t2;

    q.push(target);

    while(!q.empty()){
        target = q.front();
        t2 = target;
        q.pop();

        //cout << target << "\n";
        
        if(target == str){
            cout << 1;
            return 0;
        }
        if(target.length() < str.length()){
            continue;
        }

        if(target[target.length()-1] == 'B'){
            if(target[0] == 'A'){
                continue;
            }
            reverse(target.begin() , target.end());
            target.pop_back();
            q.push(target);
        }

        else if(t2[t2.length()-1] == 'A'){
            if(t2[0] == 'B'){
                reverse(target.begin() , target.end());
                target.pop_back();
                q.push(target);
                t2.pop_back();
                q.push(t2);
            }
            else{
                target.pop_back();
                q.push(target);
            }
        }

    }
    cout << 0;
    return 0;
}
