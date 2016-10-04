/*
ID: shikha11
LANG: C++
TASK: subset
*/
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int N;

int count[40][411];

int subset_sums( int target){
  count[0][0] = 1;

  for(int i=1; i<N; i++){
    for(int j=0; j<=target; j++){
      if( (j-i) < 0){
        count[i][j] = count[i-1][j];
      }else{
        count[i][j] = count[i-1][j-i] + count[i-1][j];
        if(count[i][j]==0) break;
      }
    }
  }

  return count[N-1][target];
}


int main(){
  ifstream fin("subset.in");
  ofstream fout("subset.out");

  fin>>N;

  if((N*(N+1)/2)%2) fout<<0<<endl;
  else{
    fout<<subset_sums(N*(N+1)/4-N)<<endl;
  }
  //for(int i =0;i<=N*(N+1)/4;i++) cout<<subset_count[i]<<endl;
  return 0;
}
