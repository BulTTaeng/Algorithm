#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

string str;

int ans = 0;

void kmp(string s);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> str;
    
    string temp;

    for(int i =0; i<str.length(); i++){
        temp = str.substr(i,str.length());
        kmp(temp);
    }

    cout << ans ;
}

void kmp(string s){
    int j =0;
    vector<int> table(s.size() , 0);
    for(int i =1; i<s.length(); i++){
        while(s[i] != s[j] && j > 0){
            j = table[j-1];
        }
        if(s[i] == s[j]){
            table[i] = ++j;
        }
    }

    for(int i =0; i<s.length(); i++){
        ans = max(ans , table[i]);
    }
}
