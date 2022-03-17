#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N;
map<string , int> m;
vector<int> v;


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    string str;

    for(int i =0; i<N ; i++){
        cin >> str;
        m[str] = i; 
    }

    int ans = 0;

    for(int i =0; i<N ; i++){
        cin >> str;
        v.push_back(m[str]);
    }

    for(int i =0; i<N ; i++){
        for(int j =i+1; j<N; j++){
            if(v[i] > v[j]){
                ans++;
                break;
            }
        }
    }

    cout << ans;
    return 0;
}
