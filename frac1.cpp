/*
ID: shikha11
LANG: C++
TASK: frac1
*/
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<sstream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}

string to_string(int val){
  stringstream convert; // stringstream used for the conversion
  convert << val;//add the value of Number to the characters in the stream
  return convert.str();//set Result to the content of the stream
}

 int main(){
  ifstream fin("frac1.in");
  ofstream fout("frac1.out");
  int N;
  fin>>N;
  map<double,string> frac_set;
  frac_set[0] = "0/1";
  frac_set[1] = "1/1";
  for(int i = 1; i<=N; i++){
    for(int j = i+1; j<=N;j++){
      double key = double(i)/double(j);
      //if(frac_set.find(key) == frac_set.end()){
        int gcd_num = gcd(j,i);
        string num =  to_string(i/gcd_num);
        string den = to_string(j/gcd_num);
        //cout<<num + "/" + den<<endl;
        frac_set[key] = num + "/" + den;
    //  }
    }
  }
  map<double, string>::const_iterator it;
  for(it = frac_set.begin(); it!=frac_set.end();it++)
    fout<<it->second<<endl;

 }
