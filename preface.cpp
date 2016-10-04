/*
ID: shikha11
LANG: C++
TASK: preface
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<map>
using namespace std;

const int one = 0;
const int five = 1;
const int ten = 2;
const int fifty = 3;
const int hundred = 4;
const int five_hundred = 5;
const int thousand = 6;


class digits{
public:
  int letter_count[7];

};

map<int,digits> basic_table;
digits cumulative_count[3501];
int N;

void make_table(){
  basic_table[0] = digits();

  for(int i=1;i<=9;i++){ //units
    digits obj = digits();

    if(i<4){
      obj.letter_count[one] = i;
    }
    else if(i==4){
      obj.letter_count[one] = 1;
      obj.letter_count[five] = 1;
    }
    else if(i==5){
      obj.letter_count[five] = 1;
    }
    else if(i==9){
      obj.letter_count[one] = 1;
      obj.letter_count[ten] = 1;
    }
    else{
      obj.letter_count[five] = 1;
      obj.letter_count[one] =  i-5;
    }
    basic_table[i] = obj;
  }

  for(int i = 10; i <= 90; i = i+10){ //tens
    digits obj = digits();

    if(i<40){
      obj.letter_count[ten] = i/10;

    }
    else if(i==40){
      obj.letter_count[ten] = 1;
      obj.letter_count[fifty] = 1;

    }
    else if(i==50){
      obj.letter_count[fifty] = 1;
      basic_table[i] = obj;
    }
    else if(i==90){
      obj.letter_count[ten] = 1;
      obj.letter_count[hundred] = 1;
    }
    else{
      obj.letter_count[fifty] = 1;
      obj.letter_count[ten] = (i-50)/10;
    }
    basic_table[i] = obj;
  }
  for(int i = 100; i <= 900; i = i+100){ //hundreds
    digits obj = digits();

    if(i<400){
      obj.letter_count[hundred] = i/100;

    }
    else if(i==400){
      obj.letter_count[hundred] = 1;
      obj.letter_count[five_hundred] = 1;

    }
    else if(i==500){
      obj.letter_count[five_hundred] = 1;

    }
    else if(i==900){
      obj.letter_count[hundred] = 1;
      obj.letter_count[thousand] = 1;

    }
    else{
      obj.letter_count[five_hundred] = 1;
      obj.letter_count[hundred] = (i-500)/100;
    }
    basic_table[i] = obj;
  }
  for(int i = 1000; i <= 3000; i = i+1000){ //thousands
    digits obj = digits();
    obj.letter_count[thousand] = i/1000;
    basic_table[i] = obj;
  }
}

digits count_cur(int num){
  int thous = (num/1000);
  num%=1000;
  int hun = (num/100);
  num%=100;
  int t = (num/10);
  num%=10;
  int o = num;

  //cout<<thous<<" "<<hun<<" "<<t<<" "<<o<<endl;
  //for(int i =0; i<7;i++) cout<<basic_table[t*10].letter_count[i]<<endl;

  digits result = digits();
  for(int i=0;i<7;i++){
    result.letter_count[i] = basic_table[thous*1000].letter_count[i] + basic_table[hun*100].letter_count[i] +
     basic_table[t*10].letter_count[i] + basic_table[o].letter_count[i];
  }
  return result;
}

digits count_characters(){
  cumulative_count[1].letter_count[one] = 1;
  //fout<<"Good in count character"<<endl;
  for( int i = 2; i <= N; i++ ){
    digits current = count_cur(i);
    for( int j = 0; j < 7; j++ ){
      cumulative_count[i].letter_count[j] = cumulative_count[i-1].letter_count[j] + current.letter_count[j];
    }
  }
  return cumulative_count[N];
}



int main(){
  ifstream fin("preface.in");
  ofstream fout("preface.out");


  fin>>N;
  make_table();
  digits result = count_characters();
  //digits result = count_cur(2965);

  //fout<<basic_table[5].letter_count[five]<<endl;

  for(int i=0;i<7;i++){
    if(result.letter_count[i] == 0 ) break;
    if(i==one){
      fout<<"I ";
    }
    else if(i==five){
      fout<<"V ";
    }
    else if(i==ten){
      fout<<"X ";
    }
    else if(i==fifty){
      fout<<"L ";
    }
    else if(i==hundred){
      fout<<"C ";
    }
    else if(i==five_hundred) fout<<"D ";
    else fout<<"M ";

    fout<<result.letter_count[i]<<endl;
  }

  return 0;
}
