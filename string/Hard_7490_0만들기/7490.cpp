#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N , num;

void recur(int n , int temp , int sum , string opt , int prev);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    
    for(int i =0; i<N; i++){
        cin >> num;
        recur(2 , 1, 0 , "1" , 1);
        cout << "\n";
    }

}

void recur(int n , int temp , int sum , string opt , int prev){
    
        //cout << n << " " << sum+(temp*prev) << " " << opt <<"\n";
    
    if(n == num+1){
        if(sum+(temp*prev) == 0){
            cout << opt <<"\n";
            return;
        }
    }
    else{
        recur(n+1 , temp * 10 + n , sum, opt + " " + (char)(n + 48) , prev);
        recur(n+1 , n, sum + temp*prev, opt + "+"+ (char)(n + 48) , 1);
        recur(n+1 ,n,  sum + temp*prev, opt + "-" + (char)(n + 48) , -1);
    }
}
