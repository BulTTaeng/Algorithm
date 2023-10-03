#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

string list[114] = { "h", "b", "c", "n", "o", "f", "p", "s", "k", "v", "y", "i","w", "u","ba", "ca" , 
"ga", "la", "na", "pa", "ra", "ta", "db", "nb", "pb", "rb", "sb", "tb", "yb", "ac",
"sc", "tc", "cd", "gd", "md", "nd", "pd", "be", "ce", "fe", "ge", "he", "ne", "re", "se", "te",
"xe", "cf", "hf", "rf", "ag", "hg", "mg", "rg", "sg", "bh", "rh", "th", "bi", "li", "ni", "si",
"ti", "bk", "al", "cl", "fl", "tl", "am", "cm", "fm", "pm", "sm", "tm", "cn", "in", "mn", "rn",
"sn", "zn", "co", "ho", "mo", "no", "po", "np", "ar", "br", "cr", "er", "fr", "ir", "kr", "lr",
"pr", "sr", "zr", "as", "cs", "ds", "es", "hs", "os", "at", "mt", "pt", "au", "cu", "eu", "lu",
"pu", "ru", "lv", "dy" };

vector<string> input;

bool visit[50001];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int t;
  cin >> t;

  string str;

  for(int i =0 ;i<t; i++){
    cin >> str;
    input.push_back(str);
  }

  int len;

  for(int i =0; i<t; i++){
    memset(visit, false, sizeof(visit));
    bool possible =false;

    len = input[i].size();
    queue<int> q;

    q.push(0);
    visit[0] = true;

    while(!q.empty()){

      int curr = q.front();
      q.pop();

      if(len == curr){
        possible = true;
        break;
      }

      string target1 ="";
      string target2 ="";
      
      target1 = target1 + input[i][curr];
      target2 = target2 + input[i][curr] + input[i][curr+1];

      for(int j = 0; j<114; j++){
        if(target1 == list[j] && visit[curr+1] == false){
          visit[curr+1] = true;
          q.push(curr+1);
        }

        if(target2 == list[j] && visit[curr+2] == false){
          visit[curr+2] = true;
          q.push(curr+2);
        }
      }

      
    } // end of while

    if(possible == true){
      cout << "YES" <<endl;
    }
    else{
      cout << "NO" << endl;
    }


  }
  return 0;



} 
