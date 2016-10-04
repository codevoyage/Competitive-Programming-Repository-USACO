/*
ID: shikha11
LANG: C++
TASK: lamps
*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

// Basic Even Odd 3K+1
int n_even_possibilties[8][4] = {{0,0,0,0},{0,0,1,1}, {0,1,0,1}, {1,0,0,1}, {0,1,1,0}, {1,0,1,0}, {1,1,0,0}, {1,1,1,1}};

int n_1_possibilties[4][4] = {{0,0,0,1}, {0,0,1,0}, {0,1,0,0}, {1,0,0,0}};

int n_odd_possibilties[3][4] ={ {1,0,1,1}, {1,1,0,1}, {0,1,1,1}};


int lamps[100];

int N, C;

int ON[100], OFF[100];
string result[16];
int a = 0, on =0, off =0, r = 0;




void apply(int possibility[]){

  //initialize
  for(int i =0;i<N;i++) lamps[i] = 1;


  if(possibility[0]==1){ //Basic Toggle
    for(int i =0; i<N; i++){
      if(lamps[i]==1) lamps[i] = 0;
      else if( lamps[i]==0) lamps[i] = 1;
    }
  }
  if(possibility[1]==1){ //Even
    for(int i = 1; i<N; i=i+2){
      if(lamps[i]==1) lamps[i] = 0;
      else if( lamps[i]==0) lamps[i] = 1;
    }
  }
  if(possibility[2]==1){ //Odd
    for(int i = 0; i < N; i=i+2){
      if(lamps[i]==1) lamps[i] = 0;
      else if( lamps[i]==0) lamps[i] = 1;
    }
  }
  if(possibility[3]==1){ //3K+1
    for(int i = 0 ; i < N; i=i+3){
      if(lamps[i]==1) lamps[i] = 0;
      else if( lamps[i]==0) lamps[i] = 1;
    }
  }
}

bool conforms(int state[]){

  for(int i=0; i< on;i++){
    if(ON[i]==-1) break;
    if(state[ON[i]-1]!=1) return false;
  }

  for(int i=0; i< off; i++){
    if(state[OFF[i]-1]!=0) return false;
  }

  return true;

}

string to_string(){
  string l;
  int i;
  for(i=0;i<N;i++){
    l+=lamps[i]+48;
  }
  //cout<<"IN to_string"<<endl;
  //cout<<l<<endl;
  return l;
}

int main(){
  ifstream fin("lamps.in");
  ofstream fout("lamps.out");

  fin>>N>>C;

  do{
    fin>>a;
    ON[on++] = a;
  }while(a!=-1);


  do{
    fin>>a;
    OFF[off++] = a;
  }while(a!=-1);

  for(int i =0;i<N;i++) lamps[i] = 1;



  if(C==1){ //ONE
    for(int i=0;i<4; i++){
      apply(n_1_possibilties[i]);
      if(conforms(lamps)){
        //cout<<to_string()<<endl;;
        result[r++] = to_string();
      }
    }
  }else if(C==0){
    int p[4]= {0,0,0,0};
    apply(p);
    if(conforms(lamps))result[r++] = to_string();
  }else if(C%2==0){ //EVEN
    for(int i=0; i<8; i++){
      if(C==2 && i==7) break;
      apply(n_even_possibilties[i]);
      if(conforms(lamps)){
        result[r++] = to_string();
        /*for(int i =0; i<N;i++) fout<<lamps[i];
        fout<<endl;
        */
      }
    }
  }else{ //odd
    for(int i=0;i<4; i++){
      apply(n_1_possibilties[i]);
      if(conforms(lamps)){
        result[r++] = to_string();
        /*for(int i =0; i<N;i++) fout<<lamps[i];
        fout<<endl;*/
      }
    }
    for(int i=0;i<3; i++){
      apply(n_odd_possibilties[i]);
      if(conforms(lamps)){
        result[r++] = to_string();
      }
    }

  }
  if(r==0)fout<<"IMPOSSIBLE"<<endl;
  else{
    sort(result, result+r);
    for(int i=0;i<r;i++){
      fout<<result[i]<<endl;
    }
  }
  return 0;
}
