#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int K , N;
int inp[501];
double ans = 987654321.321;

int main(){
    cout.tie(0);
    cin.tie(0);

    cin >> N >> K;

    for(int i =0; i<N; i++){
        cin>> inp[i];
    }

    double avg = 0;
    double std = 0;

    while(K<=N){
        for(int i =0; i<=N-K; i++){
            avg = 0;
            std = 0;

            for(int j=i; j<i+K; j++){
            avg+= inp[j]; 
            }

            avg = avg/K;

            for(int j=i; j<i+K; j++){
                std += (inp[j]-avg) *(inp[j]-avg);
            }
            
            std = std/K;
            std = sqrt(std);

            ans = min(ans , std);
        }

        K++;
    }
    printf("%.6lf", ans);
    
    return 0;
}
