#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    int i = 666;
    int c = 0;
    string str;

    while(true)
    {
        str = to_string(i);
        for(int j = 0; j < str.length()-2; j++)
            if(str[j] == '6' && str[j+1] == '6' && str[j+2] == '6')
            {
                c++;
                if(c == N){
                    cout << i;
                    return 0;
                }
                break;
            }
        i++;
    }

    return 0;
}
