#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;

bool is_prime(int n);
bool is_p(string st);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    if(N == 1){
        cout << 2;
        return 0;
    }

    int num = N;
    string str = to_string(N);

    while(true){

        if(is_prime(num)){
            if(is_p(str)){
                cout << num;
                break;
            }
        }

        num++;
        str = to_string(num);
    }
    
    return 0;
}

bool is_prime(int n){
    int nn = sqrt(n);

    for(int i =2; i<=nn; i++){
        if(n %i == 0){
            return false;
        }
    }

    return true;
}

bool is_p(string st){

    int l = st.length();
    
    for(int i =0; i<l/2; i++){
        if(st[i]  != st[l-i-1]){
            return false;
        }
    }

    return true;
}
