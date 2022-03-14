#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

int N;

set<string> s[51];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    string st;

    for(int i =0; i<N; i++){
        cin >> st;
        s[st.length()].insert(st);
    }

    set<string>::iterator iter;

    for(int i = 1; i<=50; i++){
        for(iter = s[i].begin(); iter != s[i].end(); iter++){
            cout << *iter << "\n";
        }       
    }
    return 0;
}
