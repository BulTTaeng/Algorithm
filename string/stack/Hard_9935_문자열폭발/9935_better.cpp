#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

string str , bomb;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> str >> bomb;

    string ans = "";
    int cnt = 0;
    for(int i =0; i<str.length(); i++){
        ans+=str[i];
        cnt = 0;
        if(ans.length() >= bomb.length()){
            if(str[i] == bomb[bomb.length()-1]){
                for(int j =0; j<bomb.length(); j++){
                    if(ans[ans.length() -j -1] == bomb[bomb.length()-j-1]){
                        cnt++;
                    }
                }

                if(cnt == bomb.length()){
                    for(int j = 0 ;j<bomb.length(); j++){
                        ans.pop_back();
                    }
                }
            }
        }
    }

    if(ans.empty()){
        cout << "FRULA";
    }
    else{
        cout << ans;
    }
    return 0;
}
