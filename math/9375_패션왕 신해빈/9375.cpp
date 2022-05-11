#include <iostream>
#include <map>

using namespace std;

int T , N;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    cin >> T;
    
    string n , t;
    int ans = 1;

    while(T--){
        cin >> N;
        ans = 1;
        map<string , int>   m;
        
        for(int i =0; i<N; i++){
            cin >> n >> t;
            if (m.find(t) != m.end()) {
                m[t]++; 
            } 
            else {
                m.insert({t, 1});
            }
        }

    
        for(auto iter = m.begin(); iter != m.end() ; iter++){
            ans = ans * (iter->second+1);
        }
        ans--;

        cout << ans << "\n";
    }

    return 0;

}
