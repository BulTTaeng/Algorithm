#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int N , K;
string str;
int ans = 0;
bool eat[20001];

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> K;

    cin >> str;

    memset(eat , false ,sizeof(eat));

    bool s = false;

    for(int i =0; i<str.length() ; i++){
        if(str[i] == 'P'){
            s = false;
            for(int j =K ; j>=1; j--){
                if(i-j>= 0 ){
                    if(!eat[i-j] && str[i-j] == 'H'){
                        eat[i-j] = true;
                        ans++;
                        s= true;
                        break;
                    }
                }
            }

            if(!s){
                for(int j =1; j<=K; j++){
                    if(i+j < str.length()){
                        if(!eat[i+j] && str[i+j] == 'H'){
                            eat[i+j] = true;
                            ans++;
                            break;

                        }
                    }
                }
            }

        }
    }

    cout << ans;
    return 0;
}
