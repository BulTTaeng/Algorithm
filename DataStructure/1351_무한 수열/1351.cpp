#include <iostream>
#include <map>

using namespace std;

long long N , P , Q;
map<long long , long long> m;

long long recur(long long num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> P >> Q;
    
    m.insert({0,1});
    cout << recur(N);

    return 0;
}

long long recur(long long num){

    if(num == 0){
        return 1;
    }
    if(m[num] != 0){
        return m[num];
    }
    else{
        return m[num] = recur(num/P) + recur(num/Q);
    }

}
