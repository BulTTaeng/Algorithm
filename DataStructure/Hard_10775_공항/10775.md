#include <iostream>
#include <cstring>

using namespace std;

int G , P;
int ans = 0;
int root[100001];

int Find(int x);
void Union(int x, int y);

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> G;
    cin >> P;
    int air;
    bool stop = false;
    int p;

    memset(root , 0 ,sizeof(root));

    for(int i =0; i<=G; i++){
        root[i] = i;
    }

    for(int i =1; i<=P; i++){
        cin >> air;

        if(stop){
            continue;
        }
        p = Find(air);
        if(p == 0){
            stop = true;
        }
        else{
            ans++;
            Union(p , p-1);
        }
    }

    cout << ans;
    return 0;

}


int Find(int x){
    if(root[x] == x) return x;
    else{
        return root[x] = Find(root[x]);
    }
}

void Union(int x , int y){
    x = Find(x);
    y = Find(y);

    root[x] = y;
}
