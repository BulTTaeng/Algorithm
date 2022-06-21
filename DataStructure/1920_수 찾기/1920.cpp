#include <iostream>
#include <map>

using namespace std;

map<long long , int> m;
int N , M;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    long long temp;

    for(int i =0;i <N; i++){
        cin >> temp;
        m[temp] = 1;
    }

    cin >> M;

    for(int i= 0;i<M; i++){
        cin >> temp;
        if(m[temp] == 1){
            cout <<1 << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
}
