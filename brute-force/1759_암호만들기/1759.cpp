#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L , C;
vector<char> v;

void dfs(string ans , int idx);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> L >> C;
    char t;

    for(int i =0; i<C; i++){
        cin>> t;
        v.push_back(t);
    }

    sort(v.begin() , v.end());

    dfs("" , -1);

    return 0;
}

void dfs(string ans ,int idx){
    if(ans.length() == L){
        
        int c =0;
        int mc = 0;
        for(int i =0; i<L; i++){
            if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u'){
                c++;
            }
            else{
                mc++;
            }
        }

        if(c >=1 && mc>=2 ){
            cout << ans << "\n";
        }
        
        return;
    }
    
    for(int i =idx+1;i<C; i++){
        dfs(ans+v[i] , i);
    }

}
