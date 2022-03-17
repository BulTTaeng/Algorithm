#include <iostream>
#include <cstring>

using namespace std;

int a[27];
string inp;

int dfs(string s);

int ans =0 ;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> inp;

    memset(a , 0 , sizeof(a));

    for(int i =0; i<inp.length(); i++){
        a[inp[i] - 'a']++;
    }

    dfs("");

    cout << ans;
    return 0;

}

int dfs(string s){

    if(s.length() == inp.length()){
        //cout << s <<"\n";
        return 1;
    }

    for(int i =0; i<26; i++){
        if(a[i] != 0){
            if(s == ""){
                a[i]--;
                ans += dfs(s+char('a' + i));
                a[i]++;
            }
            else if(s[s.length()-1] != char('a' + i) ){
                a[i]--;
                ans += dfs(s+char('a' + i));
                a[i]++;
            }
        }
    }

    return 0;
}
