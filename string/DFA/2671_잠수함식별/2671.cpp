#include <iostream>
#include <regex>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    
    string str;
    
    cin >> str;

    if(regex_match(str, regex("(100+1+|01)+"))){
        cout << "SUBMARINE";
    }
    else{
        cout << "NOISE";
    }


    return 0;
}
