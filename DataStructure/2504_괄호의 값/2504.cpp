#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
int ans = 0;
bool check = true;
stack<char> s;
stack<pair<int , int>> val;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> str;

    char c;
    int temp = 0;

    for(int i =0; i<str.length(); i++){

        if(s.empty()){
            s.push(str[i]);
        }
        else{
           if(str[i] == '('){
               s.push(str[i]);
           }
           else if(str[i] == '['){
               s.push(str[i]);
           }
           else if(str[i] == ')'){
               if(s.top() != '('){
                   check = false;
                   break;
               }
               else{
                   s.pop();
                   if(val.empty()){
                       val.push({2 , s.size()});
                   }
                   else{
                       int t = 0;
                       while(!val.empty()){
                           
                           if(val.top().second > s.size()){
                               t += val.top().first;
                               val.pop();
                           }
                           else{
                               break;
                           }
                       }
                       if(t == 0){
                           val.push({2 , s.size()} );
                       }else{
                            val.push({t*2 , s.size()});
                       }

                   }
               }
           }
           else if(str[i] == ']'){
               if(s.top() != '['){
                   check = false;
                   break;
               }
               else{
                   s.pop();
                   if(val.empty()){
                       val.push({3 , s.size()});
                   }
                   else{
                       int t = 0;
                       while(!val.empty()){
                           
                           if(val.top().second > s.size()){
                               t += val.top().first;
                               val.pop();
                           }
                           else{
                               break;
                           }
                       }

                       if(t == 0){
                           val.push({3 , s.size()} );
                       }else{
                            val.push({t*3 , s.size()});
                       }

                   }
               }
           }

        }
    }

    while(!val.empty()){
        ans += val.top().first;
        val.pop();
    }

    if(!check || !s.empty()){
        cout << 0;
    }
    else{
        cout << ans;
    }
    return 0;
}
