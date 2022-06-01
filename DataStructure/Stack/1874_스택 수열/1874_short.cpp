#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<int> s;
vector<int> v;
string ans ="";

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    cin>> N;
    int temp;

    for(int i =0; i<N; i++){
        cin >> temp;
        v.push_back(temp);
    }

    int iter=0;

    for(int i =0; i<N; i++){
        s.push(i+1);
        ans+='+';

        while(!s.empty() && s.top() == v[iter]){
            ans+='-';
            s.pop();
            iter++;
        }
    }

    if(iter == N){
        for(int i =0; i<ans.length() ; i++){
            cout << ans[i] << "\n";
        }
    }
    else{
        cout << "NO";
    }

    return 0;
}
