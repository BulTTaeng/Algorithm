#include <iostream>
#include <stack>
#include <cstring>
#include <vector>

using namespace std;

int N;
stack<int> s;
int f[1000001];
int ans[1000001];
vector<int> inp;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int temp;

    memset(f ,0 ,sizeof(f));
    memset(ans , -1 , sizeof(ans));

    for(int i =0; i<N; i++){
        cin >> temp;
        inp.push_back(temp);
        f[temp]++;
    }

    for(int i =0; i<N; i++){
       
        while(!s.empty() && f[inp[s.top()]] < f[inp[i]] ){
            if(ans[s.top()] == -1){
                ans[s.top()] = inp[i];
            }
            s.pop();
        }

        s.push(i);
        
    }

    for(int i =0; i<N; i++){
        cout << ans[i] << " ";
    }

    return 0;
}
