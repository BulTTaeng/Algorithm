#include <iostream>
#include <map>
#include <math.h>

using namespace std;

map<string , int> m;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string str;
    int num = 0;

    while(getline(cin , str)){
        num++;

        if(m.find(str) != m.end()){
            m[str] += 1;
        }
        else{
            m[str] = 1;
        }
    }

    cout << fixed;
    cout.precision(4);

    for(auto iter = m.begin() ; iter != m.end() ; iter++){
        cout << iter->first << " " << round((double(iter->second) / double(num))*1000000) /10000 << "\n";
    }

    return 0;
}
