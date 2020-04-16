#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
char plates[8] = {'W','B','W','B','W','B','W','B'};
char plates2[8] = {'W','B','W','B','W','B','W','B'};
for(int i = 0; i < 8; i++){
  cout << plates[i] << ' ';
}
cout << "\n\n";

//left to right algorithm
//WBWBWBWB
//WWBBWBWB
//WWBWBBWB
//WWBWBBWB
//WWBWBWBB  WBWBWBWB

for(int i = 0; i < 4; i++){ // 8/2
  for(int j = 0; j < 8-1; j++){
      if(plates2[j] == 'B'){
        if(plates2[j+1] == 'W'){
          swap(plates2[j], plates2[j+1]);
        }
      }
  }
          //TEST PRINT
          for(int i = 0; i < 8; i++){
            cout << plates2[i] << ' ';
          }
          cout << "\n\n";
}

cout << "LAWN MOWER \n\n";

//Lawnmower algorithm

for(int i = 0; i < (4/2); i++){ // 8/2
      for(int j = 0; j < (8-1); j++){
          if(plates[j] == 'B'){
            if(plates[j+1] == 'W'){
              swap(plates[j], plates[j+1]);
            }
          }
      }
      //TEST PRINT
      for(int i = 0; i < 8; i++){
        cout << plates[i] << ' ';
      }
      cout << "\n\n";

      for(int j = (8-1); j > 0; j--){
          if(plates[j] == 'W'){
            if(plates[j-1] == 'B'){
              char temp = plates[j];
              swap(plates[j], plates[j-1]);
            }
          }
      }
      //TEST PRINT
      for(int i = 0; i < 8; i++){
        cout << plates[i] << ' ';
      }
      cout << "\n\n";

}




  return 0;
}
