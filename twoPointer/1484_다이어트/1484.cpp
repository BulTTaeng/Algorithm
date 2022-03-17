#include <iostream>
#include <set>

using namespace std;

int G;

set<int> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> G;

    int start =1;
    int end =2;
    int diff = 0 ;

    while(start < end){
        diff = (end*end) - (start * start);

        if(diff == G){
            ans.insert(end);
            end++;
        }
        else if(diff < G){
            end++;
        }
        else{
            start++;
        }
    }

    if(ans.size() == 0){
        cout << -1;
    }
    else{
        set<int> :: iterator iter;
        for(iter = ans.begin() ; iter != ans.end() ; iter++){
            cout << *iter << "\n";
        }
    }
    return 0;
}
