
/*
ID: shikha11
LANG: C++
TASK: prefix
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<map>
using namespace std;

/*
this is is dynamic programming algorithm for the prefix problem, in this soluion we will populate a
table that keeps a count of whether a prefix of a particular length is possible to make or not
*/
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

int prefix_len_table[200000];

string S;
int no_of_primitives = 0, S_length;

ifstream fin("prefix.in");
ofstream fout("prefix.out");

int read_input(){
  string prims;
  S = "";
  int p = 0; // number of primitives

  for(;;){ //read the primitives
    fin>>prims;
    if(prims.compare(".")==0)break;
    primitives[p++] = Primitives(prims);
  }

  string s;
  do{
    fin>>s;
    S=S+s;
    s="";
  }while(!fin.eof());

  S_length = (int)S.size();

  return p;
}

void populate(){

  for(int j =0; j<no_of_primitives; j++){ //initial
    if(S.compare(0, primitives[j].length, primitives[j].name)==0){
      prefix_len_table[primitives[j].length-1] = 1;
    }
  }

  for(int i=1; i<= S_length;i++){

    if(prefix_len_table[i-1]==0) continue;

    for(int j =0; j<no_of_primitives; j++){

      if(S.compare(i, primitives[j].length, primitives[j].name)==0){
        prefix_len_table[i+primitives[j].length-1] = 1;
      }

    }
  }
}


int main(){
  no_of_primitives = read_input();
  populate();
  bool zero = true;
  for(int i = S_length; i>=0; i--){
    if(prefix_len_table[i]==1){
      fout<<i+1<<endl;
      zero = false;
      break;
    }
  }
  if(zero){fout<<0<<endl;}


  return 0;
}
