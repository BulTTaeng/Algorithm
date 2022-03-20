#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> v;

int solve(int s , int e , string str , int ans);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    cin >> N;
    string str;

    for(int i =0; i<N; i++){
        cin >> str;

        v.push_back(str);
    }

    int ans = 0;

    for(int i =0 ; i<v.size(); i++){
        str = v[i];
        int s = 0;
        int e = str.length()-1;
        
        ans = solve(s,e,str,0);
        cout << ans << "\n";
    }

    return 0;

}

int solve(int s , int e , string str , int ans){

    while(s<e){
        if(str[s] == str[e]){
            s++;
            e--;
        }
        else{
            if(ans == 1){
                return 2;
            }
            else{
                if(solve(s+1 , e , str , 1) == 0 || solve(s , e-1 , str , 1) == 0){
                    return 1;
                }
                else{
                    return 2;
                }
            }
        }
    }

    return 0;
}
