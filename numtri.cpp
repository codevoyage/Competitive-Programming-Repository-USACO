/*
ID: shikha11
LANG: C++
TASK: numtri
*/
#include<iostream>
#include<fstream>
using namespace std;

int pyramid[1000][1000];
int dynamic_pyramid[1000][1000];
int R,MAX;

void find(int score, int level, int position){
  if(level==R-1){
    if(score>MAX)
      MAX = score;
    return;
  }
  find(score+pyramid[level+1][position],level+1,position);
  find(score+pyramid[level+1][position+1],level+1,position+1);
}
void build_dynamic_pyramid(){
  int above, above_left;
  for(int i=1; i<R;i++){
    for(int j=0;j<=i;j++){
      if(j-1<0){
        above_left = 0;
        above = dynamic_pyramid[i-1][j];
      }
      else if(pyramid[i-1][j]==-1){
        above = 0;
        above_left = dynamic_pyramid[i-1][j-1];
      }
      else{
        above = dynamic_pyramid[i-1][j];
        above_left = dynamic_pyramid[i-1][j-1];
      }
      dynamic_pyramid[i][j] = pyramid[i][j]+ max(above,above_left);
    }
  }
}

void find_max_value(){
  for(int i=0;i<R;i++)
    MAX = max(dynamic_pyramid[R-1][i],MAX);
}

int main(){
  ifstream fin("numtri.in");

  //initialize the tree
  for(int i=0;i<1000;i++)
    for(int j=0;j<1000;j++)
      pyramid[i][j]=-1;

  fin>>R;

  for(int i=0;i<R;i++)
    for(int j=0; j<= i;j++)
      fin>>pyramid[i][j];

 dynamic_pyramid[0][0]= pyramid[0][0];
//  find(pyramid[0][0],0,0);
  build_dynamic_pyramid();
  find_max_value();
  ofstream fout("numtri.out");
  fout<<MAX<<endl;
  return 0;
}
