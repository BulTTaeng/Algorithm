#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N , q;
vector<int> v[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int x , y;

    for(int i =1 ; i<N ; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    cin >> q;

    int opt , n;

    for(int i =0; i <q; i++){
        cin >> opt >> n;

        if(opt == 1){
            if(v[n].size() > 1){
                cout << "yes" <<"\n";
            }
            else{
                cout << "no" <<"\n";
            }
        }

        else if(opt == 2){
            cout << "yes" << "\n";
        }
    }

}
