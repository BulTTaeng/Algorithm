#include <iostream>
#include <string>

using namespace std;

string a , b;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> a;
    cin >> b;
    int mini = 987654321;
    int temp  = 0;
    for(int i =0; i<=b.length() - a.length(); i++){
        temp = 0;
        for(int j =0; j<a.length(); j++){
            if(a[j] != b[i+j]){
                temp++;
            }
        }

        mini = min(mini , temp);
    }

    cout << mini;
    return 0;
}
