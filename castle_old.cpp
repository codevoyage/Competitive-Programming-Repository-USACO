/*
ID: shikha11
LANG: C++
TASK: castle
*/
#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;

int castle[50][50], M ,N, graph[1024][1024];
int modules = M*N;
int room_number = 1, seen[2500], room[2500];

// M -> columns, N -> rows
/*
void print_graph(){
  for(int i =0; i < M*N; i++){
    for(int j =0; j < M*N; j++){
      fout<<graph[i][j]<<" ";
    }
    fout<<endl;
  }
}
*/

void initialize_neighbours(int i, int j){
  if(j){
    graph[M*i+j][M*i+j-1] = 1;
    graph[M*i+j-1][M*i+j] = 1;
  }
  if(i){
    graph[M*i+j][M*(i-1)+j] = 1;
    graph[M*(i-1)+j][M*i+j] = 1;
  }

  if(j!= M-1){
    graph[M*i+j][M*i+j+1] = 1;
    graph[M*i+j+1][M*i+j] = 1;
  }

  if(i!=N-1){
    graph[M*i+j][M*(i+1)+j] = 1;
    graph[M*(i+1)+j][M*i+j] = 1;
  }
}

void make_graph(){
  for(int i =0;i<M*N;i++) graph[i][i] = 1; //initialize all diagonal elements to 1

  int walls, power, wall;
  for(int i =0;i<N;i++){
    for(int j =0; j<M;j++){
      walls = castle[i][j];
      initialize_neighbours(i,j); // initialize the neighbours to 1
      while(walls){
        power = (log(walls)/ log(2));
        wall = pow(2,power);
        walls-=wall;
        //make changes in the graph representation
        switch(wall){
          case 1:
          if(j){
            graph[M*i+j][M*i+j-1] = 0;
            graph[M*i+j-1][M*i+j] = 0;
          } break;

          case 2:
          if(i){
            graph[M*i+j][M*(i-1)+j] = 0;
            graph[M*(i-1)+j][M*i+j] = 0;
          } break;

          case 4:
          if(j!=M-1){
            graph[M*i+j][M*i+j+1] = 0;
            graph[M*i+j+1][M*i+j] = 0;
          } break;

          case 8:
          if(i!=N-1){
            graph[M*i+j][M*(i+1)+j] = 0;
            graph[M*(i+1)+j][M*i+j] = 0;
          } break;
        }
      }
    }
  }
}

void dfs(int i){
    seen[i] = 1;
    room[i] = room_number;
    for(int k = 0; k < M*N ; k++){
      if(graph[i][k] && !seen[k] && (k!=i))
        dfs(k);
    }
}

int count_rooms(){
  for(int i = 0; i < M*N; i++){
    if(!seen[i]){
      dfs(i);
      room_number++;
    }
  }
  return room_number-1;
}

int largest_room(){
  sort(room, room + M*N);

  int max_size = 1, local = 1;

  for(int i = 0; i < M*N-1; i++){
    if( room[i] == room[i+1]){
      local++;
      max_size = max(local,max_size);
    }
    else
      local = 1;
  }
  return max_size;
}

 void initialize_rooms(){
   room_number = 1;
   for(int i=0;i<M*N;i++){
     seen[i]=0;
     room[i]=0;
   }
 }


//remove the walls between neigbours one at a  time and then recalculate the largest room every time
int max_size = 0, row, column; char side;
int break_walls(){
  for(int x = M-1; x >= 0; x--){
    for(int y =0; y < N; y++){
      int i = y*M + x;
        if((i+1)%M){ //remove right wall
          if(graph[i][i+1]==0){
            graph[i][i+1] = 1;
            graph[i+1][i] = 1;
            initialize_rooms();
            count_rooms();
            int lr = largest_room();
            if(lr >= max_size){
              column = x;
              row = y;
              side = 'E';
              max_size = lr;
            }
            graph[i][i+1] = 0;
            graph[i+1][i] = 0;
          }
        }
          if(i-M>0){ //remove top wall
            if(graph[i][i-M]==0){
              graph[i][i-M] = 1;
              graph[i-M][i] = 1;
              initialize_rooms();
              count_rooms();
              int lr = largest_room();
              if(lr>=max_size){
                column = x;
                row = y;
                side = 'N';
                max_size = lr;
              }
              graph[i][i-M] = 0;
              graph[i-M][i] = 0;
            }
          }
    }
  }

  return max_size;

}

int main(){
  ifstream fin("castle.in");
  ofstream fout("castle.out");

  fin>>M>>N;

  for(int i =0;i < N;i++){
    for(int j =0; j < M;j++){
      fin>>castle[i][j];
    }
  }

  make_graph();
  fout<<count_rooms()<<endl;
  fout<<largest_room()<<endl;
  fout<<break_walls()<<endl;
  fout<<row+1<<" "<<column+1<<" "<<side<<endl;

  /*
  print_graph();
  print_room_seen();
  */

  return 0;
}
