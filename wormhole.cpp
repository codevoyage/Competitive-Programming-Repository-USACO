/*
ID: shikha11
LANG: C++
TASK: wormhole
*/
#include<iostream>
#include<fstream>
using namespace std;

#define MAX 12

int N, pic[MAX+1], X[MAX+1], Y[MAX+1], count=0, next[MAX+1];

void initialize_pos(){
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(X[j]>X[i] && (X[next[i]] > X[j] || next[i]==0)&& Y[i]==Y[j]){
          next[i]=j;
      }
    }
  }
}

int does_cycle_exist(){
  for(int start = 1; start <= N; start++){
    int pos = start;
    for(int i =0; i<=N; i++){
      pos = next[pic[pos]];
    }
    if(pos!=0){
      return 1;//if loop
    }
  }
  return 0; // if no loop
}


int do_it(){
  int i, count =0;
  for(i = 1; i <= N; i++){
    if(pic[i]==0){
      break;
    }
  }
  //if all are paired

  if( i > N){  //check for cycle
    return does_cycle_exist();
  }
  for(int j = i+1; j <= N; j++){
    if( pic[j] == 0){
      pic[i]=j;
      pic[j]=i;
      count+= do_it();
      pic[i]=0;
      pic[j]=0;
    }
  }
  return count;
}


int main(){
  ifstream fin("wormhole.in");
  fin>>N;
  for(int i =1; i<=N;i++){
    fin>>X[i]>>Y[i];
  }
  initialize_pos();
  ofstream fout("wormhole.out");
  fout<<do_it()<<endl;
  return 0;
}
