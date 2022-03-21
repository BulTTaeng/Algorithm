#include <iostream>
#include <regex>

using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    string str;
    for(int i =0; i<N; i++){
        cin >> str;

        if(regex_match(str, regex("(100+1+|01)+"))){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }

    return 0;
}
