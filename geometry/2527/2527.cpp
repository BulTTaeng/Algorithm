#include <iostream>

using namespace std;

int x1 , y1 , px1 , py1;
int x2 , y2 , px2, py2;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    for(int i =0; i<4; i++){
        cin >> x1 >> y1 >> px1 >> py1;
        cin >> x2 >> y2 >> px2 >> py2;

        if(px1 < x2 || px2 < x1 || py1 < y2 || py2 < y1){
            cout << "d" << "\n";
        }

        else if(px1 == x2 ){
            if(py1 == y2 || y1 == py2){
                cout << "c" << "\n";
            }
            else{
                cout << "b" << "\n";
            }
        }

        else if(px2 == x1){
            if(y2 == py1 || py2 == y1){
                cout << "c" << "\n";
            }
            else{
                cout << "b" << "\n";
            }
        }

        else if(y1 ==py2){
            if(x1 == px2 || px1 == x2){
                cout << "c" << "\n";
            }
            else{
                cout << "b" << "\n";
            }
        }

        else if(py1 == y2){
            if(px2 == x1 || x2 == px1){
                cout << "c" << "\n";
            }
            else{
                cout << "b" << "\n";
            }
        }
        else{
            cout << "a" << "\n";
        }
        
    }


    return 0;
}
