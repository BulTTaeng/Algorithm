#include <iostream>
#include <string>
#include <list>

using namespace std;

int N;
string str ,ans;
list<char> l;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;
    while(N--){
        str = "";
        l.clear();
        auto iter = l.begin();
        cin >> str;

        for(int i =0; i<str.length(); i++){

            if(str[i] == '<'){
                if(iter != l.begin()){
                    iter--;
                }
            }
            else if(str[i] == '>'){
                if(iter != l.end()){
                    iter++;
                }
            }
            else if(str[i] == '-'){
                if(iter != l.begin()){
                    iter--;
                    iter = l.erase(iter);
                }
            }
            else{
                l.insert(iter , str[i]);
            }
            
        }

        for(auto i = l.begin(); i!=l.end(); i++){
            cout << *i;
        }

        cout << "\n";
    }
    return 0;
}
