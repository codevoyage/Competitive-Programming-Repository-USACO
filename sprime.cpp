/*
ID: shikha11
LANG: C++
TASK: sprime
*/
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int N;
int start[] = {2,3,5,7};
int append[] = {1,3,7,9};
 ofstream fout("sprime.out");

bool isPrime(int seed){
  for(int i = 3; i<= sqrt(seed); i=i+2){
    if(seed%i == 0)
      return false;
  }
  return true;
}

void dfs(int n, int seed){
  if(!isPrime(seed)) return;

  if(n==0){
    fout<<seed<<endl;
    return;
  }
  for(int i=0;i<4;i++)
    dfs(n-1,seed*10+append[i]);
}

int main(){
  ifstream fin("sprime.in");
  fin>>N;

  for(int i=0;i<4;i++)
    dfs(N-1,start[i]);

  return 0;
}
