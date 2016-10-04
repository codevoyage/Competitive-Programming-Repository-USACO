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

string primitives[200];
string S;
int no_of_primitives = 0;
ifstream fin("prefix.in");
ofstream fout("prefix.out");

int read_input(){
  string prims;
  S = "";
  int p = 0;
  for(;;){
    fin>>prims;
    if(prims.compare(".")==0)break;
    primitives[p++] = prims;
  }
  string s;
  do{
    fin>>s;
    S=S+s;
    s="";
  }while(!fin.eof());
  return p;
}

int longest_prefix(int starting_position){
  int lp = 0;
  bool any_matching = false;

  if(starting_position>=(int)S.size())return 0;

  for(int i=0; i<no_of_primitives; i++){
    if(S.compare(starting_position, (int)primitives[i].size(),primitives[i])==0){
      any_matching = true;
      lp = max(lp, (int)primitives[i].size()+longest_prefix(starting_position+(int)primitives[i].size()));
    }
  }

  if(!any_matching)return 0;

  return lp;
}


int main(){
  no_of_primitives = read_input();
  //cout<<"NO OF PRIMTIVES "<<no_of_primitives<<endl;
  //sort(primitives, primitives+no_of_primitives);

  fout<<longest_prefix(0)<<endl;

  return 0;
}
