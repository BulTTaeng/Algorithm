#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N , M ,B;
int num[257];

int time , h;

void solve(int mini , int maxi);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M >> B; 

    int temp;
    int mi = 987654;
    int ma = -1;
    memset(num , 0 , sizeof(num));

    for(int i =0; i<N ; i++){
        for(int j =0; j<M; j++){
            cin >> temp;
            num[temp]++;

            mi = min(temp, mi);
            ma = max(temp , ma);
        }
    }

    time = 987654321;
    h=-1;
    solve(mi ,ma);

    cout << time << " " << h;
    return 0;
}

void solve(int mini , int maxi){

    int block = B;
    int t = 0;
    
    for(int i =mini ; i <=maxi; i++){
        
        block = B;
        t = 0;

        for(int j = maxi ; j>=mini ; j--){
            if(num[j] != 0){

                if(j < i){
                    if(block >= num[j] * (i-j) ){
                        block -= num[j] * (i-j);
                        t += num[j] * (i-j);
                    }
                    else{
                        t = 987654321;
                        break;
                    }
                }

                else if (j > i){
                    block += (j-i)*num[j];
                    t += num[j]*2 * (j-i);
                }

            }
        }// end of j

        if(time == t){
            if(h < i){
                h = i;
            }
        }
        else if(t < time){
            time = t;
            h = i;
        }
    }

}
