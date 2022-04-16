#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
vector<string>v;
vector<char> c;
int alpha[27];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    string str;

    for(int i =0; i<27 ; i++){
        alpha[i] = 0;
    }

    for(int i =0; i<N; i++){
        cin>> str;
        v.push_back(str);
    }

    int pow =1;

    for(int i =0; i<v.size(); i++){
        pow = 1;        
        for(int j =v[i].size()-1; j>=0; j--){
            alpha[(int)(v[i][j] - 'A') ] += pow;
            pow = pow*10;
        }
    }

    vector<int> vi;

    for(int i =0; i<27 ; i++){
        if(alpha[i] != 0){
            vi.push_back(alpha[i]);
        }
    }

    sort(vi.begin() , vi.end() , greater<int>());
    
    int ans = 0;
    int num = 9;
    for(int i =0; i<vi.size(); i++){
        ans = ans + num*vi[i];
        num--;
    }

    cout << ans;
    return 0;
}
