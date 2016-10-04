/*
ID: shikha11
LANG: C++
TASK: milk3
*/
#include <iostream>
#include <fstream>
using namespace std;

int milk[21][21][21];
int possible_milk[21];
int A,B,C;

void pour_until_you_die(int a , int b, int c){
  if(a == 0){
    possible_milk[c] = 1;
  }

  if(milk[a][b][c]){
    return;
  }
  else{
    milk[a][b][c] = 1;
  }

  // C -> B
  if( b<B && c>0){
    pour_until_you_die(a, min(B, b+c), max(0, c-(B-b)));
  }
  // B -> C
  if( c<C && b>0){
    pour_until_you_die(a,max(0, b-(C-c)), min(C, c+b));
  }
  // B -> A
  if( a<A && b>0){
    pour_until_you_die(min(A, a+b),max(0, b-(A-a)),c);
  }
  //A -> B
  if(a>0 && b<B){
    pour_until_you_die(max(0, a-(B-b)),min(B, b+a),c);
  }
  // A -> C
  if( c<C && a>0){
    pour_until_you_die(max(0, a-(C-c)), b, min(C , a+c));
  }
  //C -> A
  if( a<A && c>0){
    pour_until_you_die(min(A, a+c),b, max(0, c-(A-a)));
  }
}


int main(){
  ifstream fin("milk3.in");
  fin>>A>>B>>C;
  pour_until_you_die(0,0,C);
  ofstream fout("milk3.out");

  for(int i=0; i<21;i++ ){
    if(possible_milk[i]){
      if(i==C)
        fout<<i<<endl;
      else
        fout<<i<<" ";
    }

  }

  return 0;
}
