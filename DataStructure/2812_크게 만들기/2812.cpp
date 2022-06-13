#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N , K;
stack<int> s;
vector<int> inp;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> K;\
    int k = K;
    char temp;

    for(int i =0; i<N; i++){
        cin >> temp;
        inp.push_back(temp-'0');
    }

    for(int i =0; i<N; i++){
        
        while(!s.empty() && s.top() < inp[i] && K){
            s.pop();
            K--;
        }
        s.push(inp[i]);
    
    }

    while(K--){
        s.pop();
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    for(int i = ans.size()-1 ; i>=0 ; i--){
        cout << ans[i];
    }

    return 0;
}
