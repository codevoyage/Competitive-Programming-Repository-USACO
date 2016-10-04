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

set<int> bisquares;

void generate_bisquares(int M){
  int k = 0;
  for( int i=0 ; i <= M; i++ ){
    for( int j = 0; j <= M; j++){
      bisquares.insert(i*i + j*j);
    }
  }
  MAX_DIFF = M*M;
}
void print_bisquares(){
  //std::set<int>::iterator it = numbers.begin();
  set<int>::iterator iter;
  for( iter = bisquares.begin(); iter != bisquares.end(); ++iter){
    cout<<*iter<<endl;
  }
}
bool is_seq_begin(int first_term, int diff,int N){
  int t = first_term;
  for(int i=0; i < N-1; i++){
    if(!bisquares.count(t+diff))return false;
    else{
      t+=diff;
    }
  }
  return true;
}
void find_progressions(int N){
  ofstream fout("ariprog.out");
  int is_none = 1;
  set<int>::iterator iter;
  for(int diff = 1 ; diff <= MAX_DIFF; diff++){
    for(iter = bisquares.begin(); iter != bisquares.end(); ++iter){
      if(is_seq_begin(*iter, diff,N)){
        fout<<*iter<<" "<<diff<<endl;
        is_none = 0;
      }
    }
  }
  if(is_none)fout<<"NONE"<<endl;
}
int main(){
  int M,N;
  ifstream fin("ariprog.in");
  fin>>N>>M;
  generate_bisquares(M);
  //print_bisquares();
  find_progressions(N);
  return 0;
}
