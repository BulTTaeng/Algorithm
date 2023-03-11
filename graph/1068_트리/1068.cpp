#include <iostream>
#include <cstring>

using namespace std;

int N , root ,er;
bool is_p[52];
int parent[52];

void recur(int num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    int leaf = 0;

    memset(is_p, false , sizeof(is_p));

    for(int i =0 ; i<N ; i++){
        cin >> parent[i];

        if(parent[i] == -1){
            root = i;
        }
        else{
            is_p[parent[i]] = true;
        }
    }

    cin >> er;
    bool only = true;

    for(int i =0; i<N; i++){
        if(parent[i] == parent[er] && i != er){
            only = false;
            break;
        }
    }

    if(only){
        is_p[parent[er]] = false;
    }

    recur(er);
    

    for(int i =0; i<N ; i++){
        if(!is_p[i]){
            leaf++;
        }
    }

    

    cout << leaf;
    return 0;

}

void recur(int num){

    is_p[num] = true;

    for(int i =0; i<N; i++){
        if(parent[i] == num){
            recur(i);
        }
    }
    
}
