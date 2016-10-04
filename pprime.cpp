/*
ID: shikha11
LANG: C++
TASK: pprime
*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;

int a, b, a_len, b_len, k=0;
int result[500000];
ifstream fin("pprime.in");
ofstream fout("pprime.out");


int find_len(int x){
  int k=0, t=x;
  while(t){
    t/=10;
    k++;
  }
  return k;
}

bool is_prime(int seed){
  if(seed%2==0) return false;

  for(int i = 3; i<= sqrt(seed); i=i+2){
    if(seed%i == 0)
      return false;
  }
  return true;
}

void palindrome( int seed, int seed_len){
  if( seed_len > b_len || seed>b) return;

  if(a<=seed && seed<=b && is_prime(seed)){
      //cout<<seed<<endl;
      result[k++] = seed;
  }

  for(int i=0;i<=9;i++){
    //cout<<pow(10.0,seed_len+1)*i + seed*10 + i<<endl;
    palindrome(pow(10,seed_len+1)*i + seed*10 + i, seed_len+2);
  }
}

void print_result(){
  sort(result,result+k);
  for (int i = 0; i < k; i++)
        fout << result[i] << endl;
}

int main(){


  fin>>a>>b;

  a_len = find_len(a);
  b_len = find_len(b);

  for(int i=0;i<=9;i++){
    palindrome(i,1);
  }
  for(int i=1;i<=9;i++){
    palindrome(i*11,2);
  }
  print_result();
  return 0;
}
