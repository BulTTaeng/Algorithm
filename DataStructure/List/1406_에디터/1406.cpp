#include <iostream>
#include <list>

using namespace std;

string str;
int N;
list<char> l;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> str;

    for(int i =0; i<str.length() ; i++){
        l.push_back(str[i]);
    }

    cin >> N;
    char temp;
    char c;
    auto iter = l.end();

    for(int i =0; i<N; i++){
        cin >> temp;

        if(temp == 'L'){
            if(iter != l.begin()){
                iter--;
            }
        }
        else if(temp == 'D'){
            if(iter != l.end()){
                iter++;
            }
        }
        else if(temp == 'B'){
            if(iter != l.begin()){
                iter--;
                iter = l.erase(iter);
            }
        }
        else{
            cin >> c;
            l.insert(iter , c);
        }
    }

    for(auto i = l.begin(); i!=l.end() ; i++){
        cout << *i;
    }

    return 0;
}
