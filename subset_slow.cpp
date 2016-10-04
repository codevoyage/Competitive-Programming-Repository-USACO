/*
ID: shikha11
LANG: C++
TASK: subset
*/
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int N, count=0;

void subset_sum( int sum_to_reach, int start_number){
  if(sum_to_reach == 0){
    count++;
    return;
  }

  if(sum_to_reach < 0) return;

  for(int i = start_number; i >0; i--){
    subset_sum(sum_to_reach-i, i-1);
  }
}


int main(){
  ifstream fin("subset.in");
  ofstream fout("subset.out");

  fin>>N;

  if((N*(N+1)/2)%2) fout<<0<<endl;
  else{
    int target_sum = N*(N+1)/4 -N;
    subset_sum(target_sum,N-1);
    fout<<count<<endl;
  }

  return 0;
}
