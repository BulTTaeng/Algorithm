#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int N;
int ans[1000001];
stack<pair<int , int>> s;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int temp;
    memset(ans , -1 , sizeof(ans));
    
    for(int i =0; i<N; i++){
        cin >> temp;

        if(s.empty()){
            s.push({temp , i });
        }
        else{
            while(!s.empty() && temp > s.top().first){
                ans[s.top().second] = temp;
                s.pop();
            }
            s.push({temp, i});
        }
    }

    for(int i =0; i<N; i++){
        cout << ans[i] << " ";
    }
    return 0;


}
