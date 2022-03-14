#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

set<string> s;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string st;

    cin >> st;

    for(int i =0; i <st.length()-2; i++){
        for(int j =i+1; j<st.length()-1; j++){
                string s1 , s2 , s3;

                for(int k =0; k<=i ; k++){
                    s1+= st[k];
                }
                for(int k =i+1; k<=j ; k++){
                    s2+= st[k];
                }
                for(int k =j+1; k<st.length() ; k++){
                    s3+= st[k];
                }


                reverse(s1.begin() , s1.end());
                reverse(s2.begin() , s2.end());
                reverse(s3.begin() , s3.end());

                s.insert(s1+s2+s3);
            
        }
    }

    set<string>::iterator iter;

    cout << * s.begin();
    return 0;
}
