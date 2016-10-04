/*
ID: shikha11
LANG: C++
TASK: holstein
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

const int no_of_vitamins = 25;
const int no_of_feeds = 15;

int min_requirement[no_of_vitamins], feeds[no_of_feeds][no_of_vitamins],
vitamins, feed_types, min_scoops = 20, min_feed_taken[no_of_feeds];

bool sufficient_vitamins( int feed_taken[]){
  int requirements[no_of_vitamins];

  for(int i=0;i<no_of_vitamins;i++) requirements[i]=0;

  for(int i=0; i<feed_types; i++){
    if(feed_taken[i]==1){
      for(int j=0; j< vitamins; j++){
        requirements[j]+= feeds[i][j];
      }
    }
  }

  //compare the requirements to min requirements:
  for(int i=0; i<vitamins; i++){
    if(requirements[i]<min_requirement[i]) return false;
  }
  return true;
}

void find_min_scoop( int feed_taken[], int scoops, int start_pos ){

  if(scoops==min_scoops) return;

  if(sufficient_vitamins(feed_taken)){ // base case
    if(scoops < min_scoops){
      min_scoops = scoops;
      for(int f=0;f<feed_types;f++) min_feed_taken[f] = feed_taken[f];
    }
    return;
  }

  for(int i=start_pos; i<feed_types;i++){
    if(feed_taken[i]==0){
      feed_taken[i] = 1;
      find_min_scoop( feed_taken, scoops+1, i+1);
      feed_taken[i] = 0;
    }
  }
}

int main(){
  ifstream fin("holstein.in");
  ofstream fout("holstein.out");

  fin>>vitamins; // number of vitamins

  for(int i =0;i<vitamins;i++) fin>>min_requirement[i]; // minimum requirement for each vitamin

  fin>>feed_types; ///number of feed types.

  for(int i=0;i<feed_types;i++){
    for(int j =0;j<vitamins;j++){ // amount of vitamins in every feed.
      fin>>feeds[i][j];
    }
  }

  int feed_taken[no_of_feeds];
  for(int i=0; i<feed_types;i++) feed_taken[i] = 0;

  find_min_scoop( feed_taken, 0,0);

  fout<<min_scoops;

  for(int i =0; i<feed_types; i++){
    if(min_feed_taken[i]){
      fout<<" "<<i+1;
    }
  }

  fout<<endl;

  return 0;
}
