#include <iostream>
#include <cstring>

using namespace std;

int num[10];
int main(){
    int x ,y ,z;

    cin >> x >> y >> z;

    long ans = x * y * z;
    int temp;

    memset(num , 0 , sizeof(num));

    while(!ans == 0 ){
        temp = ans % 10;
        num[temp]++;
        ans = ans /10;    
    }

    for(int i =0; i<10; i++){
        cout << num[i] << "\n";
    }
    return 0;
}
