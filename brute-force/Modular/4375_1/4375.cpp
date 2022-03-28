#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long N;

int len = 0;

bool check1(long long num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int temp = 1;
    int num =1;

    while(cin >> N){       
        num =1;
        temp =1;
        while(true){
            if(temp % N == 0){
                cout << num << "\n";
                break;
            }
            temp = (temp*10 + 1) %N;
            num++;
        }
    }

    return 0;
}
