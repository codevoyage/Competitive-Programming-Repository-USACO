/*
ID: shikha11
LANG: C++
TASK: sort3
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

int ranges[3][2], input[1000], N, count_numbers[3], sorted[1000];
vector<int> positions[3];

void fill_positions(){
  for(int i=0; i < N; i++){

    count_numbers[input[i]-1] = count_numbers[input[i]-1]+1;

    if( input[i]!=sorted[i] ){
      int wrong_number = input[i];
      positions[wrong_number-1].push_back(i);
    }
  }

//Set the ranges for the numbers
    ranges[0][0] = 0;
    ranges[0][1] =count_numbers[0]-1;
    ranges[1][0] =  ranges[0][1]+1;
    ranges[1][1] = ranges[1][0] + count_numbers[1]-1;
    ranges[2][0] =  ranges[1][1]+1;
    ranges[2][1] = N-1;
}

int count_swaps(int swaps){
  for(int i=0;i<N;i++){
    if(input[i]!=sorted[i]){
      int wrong_number = input[i];
      int correct_number = sorted[i];

      //Check if the correct number can be swapped from a nice position
      bool nice_position_found = false;
      for (std::vector<int>::iterator it = positions[correct_number-1].begin(); it != positions[correct_number-1].end(); ++it){
        if( *it >= ranges[wrong_number-1][0] && *it <= ranges[wrong_number-1][1]){
          nice_position_found = true;
          //SWAP!!
          input[*it] = wrong_number; //change the input
          input[i] = correct_number;
          // now change the position vectors
          positions[correct_number-1].erase(it);
          positions[wrong_number-1].erase(find(positions[wrong_number-1].begin(), positions[wrong_number-1].end(), i));
          break;
        }
      }
      if(!nice_position_found){
        // swap from the last position: due to ease of implementation
        int pos = positions[correct_number-1].back();
        positions[correct_number-1].pop_back();
        int swapping_with = input[pos];
        //change the input
        input[i] = correct_number;
        input[pos] = wrong_number;

        /*
        * Erase the correct number at the wrong position: done above
        * Erase the wrong number from the current position
        * Add the wrong number to its new position
        */
        positions[wrong_number-1].erase(find(positions[wrong_number-1].begin(), positions[wrong_number-1].end(), i));
        positions[wrong_number-1].push_back(pos);
      }
      swaps++; //increment swaps
    }
  }
  return swaps;
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
  fout<<count_swaps(0)<<endl;
}
