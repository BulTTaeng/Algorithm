#include <iostream>

using namespace std;

string str;

bool solve();

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    while(true){
        cin >> str;

        if(str == "0"){
            break;
        }

        if(solve()){
            cout << "yes" << "\n";
        }
        else{
            cout << "no" << "\n";
        }
    }

    return 0;
}

bool solve(){

    int j = str.length()-1;

    for(int i =0; i<=str.length()/2; i++){
        if(str[i] != str[j]){
            return false;
        }
        j--;
    }

    return true;
}
