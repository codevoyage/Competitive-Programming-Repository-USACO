/*
ID: shikha11
LANG: C++
TASK: sort3
*/
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

int N, input[1000], sorted[1000], min_swap=100000000 ;

map<int,int> maps[3];

void fill_positions(){
  for(int i=0; i < N; i++){
    if(input[i]!=sorted[i]){
      int wrong_number = input[i];
      maps[wrong_number-1][i] = 1;
    }
  }
}

void print_stuff( int arr[], int cur_pos, int swap_pos ){
  for(int i =0; i<N; i++){
    if(i==cur_pos || i== swap_pos)cout<<"->";
    cout<<arr[i]<<" ";
  }
  cout<<endl;
/*  map<int,int>::const_iterator it;
  for(int i =0;i<3;i++){
    cout<<"MAP "<<i+1<<endl;
    for(it = maps[i].begin(); it!=maps[i].end();it++)
      cout<<it->first<<endl;
  }
*/
}

void min_swaps( int f_input[], map<int,int> f_maps[], int start_position, int swaps){
//cout<<"Input Looks like"<<endl;


  if(start_position == N-1){
    cout<<"Enterered the base case, everything must be sorted by now"<<endl;

    min_swap = min(swaps, min_swap);
    return;
  }
  int local_input[1000];
  map<int, int> local_maps[3];

  int correct_number = sorted[start_position];

  if(f_input[start_position] != correct_number){

      for(map<int, int>::const_iterator it = f_maps[correct_number-1].begin(); it!= f_maps[correct_number-1].end(); it++){
cout<<"Swapping for position "<<start_position<<endl;
        //initiaize local input
        for(int k=0; k<N; k++) local_input[k] = f_input[k];
        //initialize the local maps
        for( int k =0; k<3; k++) local_maps[k].insert(f_maps[k].begin(), f_maps[k].end());


        int correct_number_current_position = it->first;
        //cout<<"Swapping {Position}->"<<correct_number_current_position<<endl;
        print_stuff(f_input, start_position, correct_number_current_position);
        cout<<"Swaps->"<<swaps<<endl;

        //swap the misplaced number with the position of the correct number in input
        int misplaced_number = local_input[start_position];
        local_input[start_position] = correct_number;
        local_input[correct_number_current_position] = misplaced_number;

        //delete the correct number from its wrong position
        local_maps[correct_number-1].erase(correct_number_current_position);

        //delete wrong number from start_position
        local_maps[misplaced_number-1].erase(start_position);

        //put the new position of the misplaced number in its map if the number is still misplaced.
        if( sorted[correct_number_current_position] != misplaced_number){
          local_maps[misplaced_number-1][correct_number_current_position] = 1;
          min_swaps( local_input, local_maps, start_position+1, swaps+1);
        }else{
          min_swaps( local_input, local_maps, start_position+1, swaps+1);
          break;
        }
          

      }
    }else{cout<<"No Swaps required"<<endl;
    min_swaps( f_input, f_maps, start_position+1, swaps);
  }

}



int main(){
  ifstream fin("sort3.in");
  ofstream fout("sort3.out");
  fin>>N;
  for(int i =0; i< N; i++){
    fin>> input[i];
    sorted[i] = input[i];
  }
  sort(sorted, sorted+N);
  fill_positions();
  min_swaps(input, maps, 0, 0);
  fout<<min_swap<<endl;

//  print_stuff();


}
