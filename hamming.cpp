/*
ID: shikha11
LANG: C++
TASK: hamming
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<math.h>
using namespace std;

const int MAX = 256;
int N, B, D, result[MAX];

bool check_hamming_distance(int a, int b){
  int x, hd = 0;

  x = a^b;

  while(x){
    hd+=(x%2);
    x/=2;
  }
  return (hd>=D);
}

bool check(int number){
  for(int i = 0; i<number; i++){
    if(result[i] && !check_hamming_distance(i,number)){
      return false;
    }
  }
  return true;
}

void find_numbers(){
  int total, count;
  total = pow(2,B);

  for(int i = 0; i< total; i++){

    count = 1;
    for(int k = 0; k< total; k++)result[k] = 0;
    result[i] = 1;

    for(int j = i+1; j<=total; j++){
      if(count>=N){
        return;
      }
      if(check(j)){
        count++;
        //cout<<i<<" "<<j<<" "<<count<<endl;
        result[j] = 1;
      }
    }
  }
}

int main(){
  ifstream fin("hamming.in");
  ofstream fout("hamming.out");
  fin>>N>>B>>D;
  find_numbers();
  int count = 0;
  for(int k = 0; k< MAX; k++){
    if(result[k]){
      count++;
      fout<<k;
      if(count!=N){
        if(count%10==0)fout<<endl;
        else fout<<" ";
      }else fout<<endl;

    }

  }
  return 0;
}
