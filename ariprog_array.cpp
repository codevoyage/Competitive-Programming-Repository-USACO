/*
ID: shikha11
LANG: C++
TASK: ariprog
*/
#include <iostream>
#include <fstream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
/*
will do it in 2 parts, in the first part will generate all the numbers.
*/
int MAX_DIFF;
int MAX;
int bisquares[MAX+1]={-1};
int M,N;

void generate_bisquares(){
  int k = 0;
  for( int i=0 ; i <= M; i++ ){
    for( int j = 0; j <= M; j++){
      bisquares[i*i + j*j]= i*i + j*j;
    }
  }
  MAX_DIFF = M*M;
}
void print_bisquares(){
  for( int = 0; i< MAX; i++){
    cout<<bisquares[i]<<endl;
  }
}
bool is_seq_begin(int first_term, int diff){
  int t = first_term;
  for(int i=0; i < N-1; i++){
    if(bisquares[i]==-1)return false;
    else{
      t+=diff;
    }
  }
  return true;
}
void find_progressions(){
  ofstream fout("ariprog.out");
  int is_none = 1;
  for(int diff = 1 ; diff <= MAX_DIFF; diff++){
    for(int i= 0; i<= MAX; i++){
      if(is_seq_begin(i, diff)){
        fout<<i<<" "<<diff<<endl;
        is_none = 0;
      }
    }
  }
  if(is_none)fout<<"NONE"<<endl;
}
int main(){

  ifstream fin("ariprog.in");
  fin>>N>>M;
  MAX = 2*M*M;
  generate_bisquares();
  //print_bisquares();
  find_progressions();
  return 0;
}
