/*
ID:shikha11
LANG: C++
TASK: prefix
*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

class Primitives{
public:
 string name;
 int length;

 Primitives(string n){
     name = n;
     length = name.length();
   }
  Primitives(){}
};

Primitives primitives[200];

string S;
int no_of_primitives = 0, S_length;


ifstream fin("prefix.in");
ofstream fout("prefix.out");

int read_input(){
  string prims;
  S = "";
  int p = 0; // number of primitives

  for(;;){ //read the primtives
    fin>>prims;
    if(prims.compare(".")==0)break;
    primitives[p++] = Primitives(prims);
  }

  string s;
  //get the string
  do{
    fin>>s;
    S=S+s;
    s="";
  }while(!fin.eof());

  S_length = (int)S.size();

  return p;
}

int longest_prefix(int starting_position){
  int lp = 0;
  bool any_matching = false;

  if(starting_position >= S_length)return 0;

  for(int i=0; i<no_of_primitives; i++){

    if(starting_position+primitives[i].length>S_length)break;

    if(S.compare(starting_position, primitives[i].length, primitives[i].name)==0){
      any_matching = true;
      lp = max(lp, primitives[i].length + longest_prefix(starting_position + primitives[i].length));
    }
  }

  if(!any_matching)return 0;

  return lp;
}


int main(){
  no_of_primitives = read_input();

  fout<<longest_prefix(0)<<endl;

  return 0;


}
