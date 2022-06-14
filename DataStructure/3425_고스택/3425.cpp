#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int N;
string str; 
bool check = false;
vector<pair<string , int>> operation;
stack<long long> s;

#define ERR 1000000001
#define MAX 1000000000

long long simulation();
bool swap();
bool add();
bool sub();
bool mul();
bool div();
bool mod();

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int temp;
    long long next;
    long long ans;

    while(true){
        check = false;
        operation.clear();


        while(true){
            cin >> str;

            if(str == "QUIT"){
                return 0;
            }
            else if(str == "END"){
                break;
            }
            else if(str == "NUM"){
                cin >> temp;
            }

            operation.push_back({str , temp});
        }

        cin >> N;

        for(int i =0; i<N; i++){
            cin >> next;
            s.push(next);
            ans = simulation();

            if(ans == ERR){
                cout << "ERROR" << "\n";
            }
            else{
                cout << ans << "\n";
            }

            while(!s.empty()){
                s.pop();
            }
        }
        cout << "\n";
    }

    return 0;
}

long long simulation(){

    long long  tt;

    for(int i =0; i<operation.size(); i++){

        if(operation[i].first == "NUM"){
            s.push(operation[i].second);
        }
        else if(operation[i].first == "POP"){
            if(s.empty()){
                return ERR;
            }
            else{
                s.pop();
            }
        }
        else if(operation[i].first == "INV"){
            if(s.empty()){
                return ERR;
            }
            else{
                tt = s.top();
                s.pop();
                s.push(-tt);
            }
        }
        else if(operation[i].first == "DUP"){
            if(s.empty()){
                return ERR;
            }
            else{
                s.push(s.top());
            }
        }
        else if(operation[i].first == "SWP"){
            if(!swap()){
                return ERR;
            }
        }
        else if(operation[i].first == "ADD"){
            if(!add()){
                return ERR;
            }
        }
        else if(operation[i].first == "SUB"){
            if(!sub()){
                return ERR;
            }
        }
        else if(operation[i].first == "MUL"){
            if(!mul()){
                return ERR;
            }
        }
        else if(operation[i].first == "DIV"){
            if(!div()){
                return ERR;
            }
        }
        else if(operation[i].first == "MOD"){
            if(!mod()){
                return ERR;
            }
        }
        
    }

    
    if(s.empty() || s.size() >1){
        return ERR;
    }
    else{
        return s.top();
    }
}

bool swap(){

    long long n1 , n2;

    if(s.size() <2){
        return false;
    }
    else {
        n1 = s.top();
        s.pop();
        n2 = s.top();
        s.pop();
        s.push(n1);
        s.push(n2);
    }

    return true;
}

bool add(){

    long long n1 , n2;

    if(s.size() <2){
        return false;
    }
    else {
        n1 = s.top();
        s.pop();
        n2 = s.top();
        s.pop();

        if(abs(n1+n2) > MAX ){
            return false;
        }

        s.push(n1 + n2);
    }

    return true;
}

bool sub(){

    long long n1 , n2;

    if(s.size() <2){
        return false;
    }
    else {
        n1 = s.top();
        s.pop();
        n2 = s.top();
        s.pop();

        if(abs(n2-n1) > MAX ){
            return false;
        }

        s.push(n2 - n1);
    }

    return true;
}


bool mul(){

    long long n1 , n2;

	if (s.size() < 2) {
		return false;
	}
    else{
        n1 = s.top();
        s.pop();
        n2 = s.top();
        s.pop();

        if(abs(n2*n1) > MAX ){
            return false;
        }

        s.push(n2 * n1);
    }

	return true;
}
 
bool div(){

    long long n1 , n2;
    bool is_negative = false;

	if (s.size() < 2) {
		return false;
	}
    else{
        n1 = s.top();
        s.pop();
        n2 = s.top();
        s.pop();

        if(n1 == 0){
            return false;
        }

        if(n1 < 0 ){
            is_negative = !is_negative;
        }

        if(n2 < 0){
            is_negative = !is_negative;
        }

        if(is_negative){
            s.push(-(abs(n2/n1)));
        }
        else{
            s.push(abs(n2/n1));
        }
    }
    
    return true;
}
 
bool mod(){
	long long n1 , n2;
    bool is_negative = false;

	if (s.size() < 2) {
		return false;
	}
    else{
        n1 = s.top();
        s.pop();
        n2 = s.top();
        s.pop();

        if(n1 == 0){
            return false;
        }

        if(n2 < 0){
            is_negative = true;
        }
        
        if(is_negative){
            s.push(-(abs(n2%n1)));
        }
        else{
            s.push(abs(n2%n1));
        }
    }
    
    return true;
}
