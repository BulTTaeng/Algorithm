#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str , target;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> str >> target;

    while(true){

        if(target.length() == str.length()){
            if(target == str){
                cout << 1;
                return 0;
            }
            else{
                cout << 0;
                return 0;        
            }
        }

        
    
        if(target[target.length()-1] == 'B'){
            target.pop_back();
            reverse(target.begin() , target.end());
        }
        else{
            target.pop_back();
        }
    }

    return 0;
}
