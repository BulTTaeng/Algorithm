#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int N;
stack<int> s;
vector<int> v;
string ans ="";
bool check[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    cin>> N;
    int temp;
    memset(check , false , sizeof(check));

    for(int i =0; i<N; i++){
        cin >> temp;
        v.push_back(temp);
    }

    int num = 1;
    bool flag = true;

    for(int i = 0 ; i<N; i++){

        if(!s.empty()){

            if(s.top() == v[i]){
            }
            else if(v[i] > s.top() && v[i]< num){
                flag = false;
                break;
            }
            else if(s.top() < v[i]){
                while(num <= v[i]){
                    s.push(num);
                    num++;
                    ans+='+';
                }
            }
            else{
                while(!s.empty()){
                    if(s.top() < v[i]){
                        flag = false;
                        break;
                    }
                    else{
                        s.pop();
                        ans+='-';      
                    }
                }   
            }

            if(flag == false){
                break;
            }

        }
        else{

            if(v[i] < num){
                flag = false;
                break;
            }

            while(num <= v[i]){
                s.push(num);
                //check[num] = true;
                num++;
                ans+='+';
            }
        }
        if(s.empty()){
            flag = false;
            break;
        }
        s.pop();
        ans +='-';
    }

    if(flag){
        for(int i =0; i<ans.length(); i++){
            cout << ans[i] << "\n";
        }
    }
    else{
        cout << "NO";
    }
    return 0;
}
