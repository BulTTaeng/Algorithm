#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string num;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> num;

    long long sum = 0;
    bool have_zero = false;

    for(int i =0; i<num.length() ; i++){
        sum += (num[i]-'0');
        ans.push_back(num[i]-'0');

        if(num[i] == '0'){
            have_zero = true;
        }
    }

    if(!have_zero || sum%3 != 0){
        cout << -1;
        return 0;
    }

    sort(ans.begin() , ans.end() , greater<>());

    for(int i =0; i<ans.size() ; i++){
        cout << ans[i];
    }

    return 0;
}
