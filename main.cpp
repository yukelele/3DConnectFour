#include <iostream> 
#include <cmath> 
using namespace std;

char rowD[] = {'-', '1', '2', '3', '4', '-'};
char rowC[] = {'-', '1', '2', '3', '4', '-'};
char rowB[] = {'-', '1', '2', '3', '4', '-'};
char rowA[] = {'-', '1', '2', '3', '4', '-'};

char *mainBoard[5]; 


void board();
void display();
int charToNum(char row);

int main()
{
  board(); 

  char player1 = 'X'; 
  char player2 = 'O'; 
  char playerTurns;
  char row;
  int num;

  int turn = 1;
  
  do{
  display();

  


  if(turn%2)
    playerTurns = player1; 
  else
    playerTurns = player2; 

  cout << "Row: ";
  cin >> row;
  cout << "Num: ";
  cin >> num; 

  mainBoard[charToNum(row)][num] = playerTurns;
  
  turn++;
  }while(true);


  return 0;
}

int charToNum(char row){
  if (row == 'D' || row == 'd')
    return 4;
  else if (row == 'C' || row == 'c')
    return 3;
  else if (row == 'B' || row == 'b')
    return 2;
  else if (row == 'A' || row == 'a')
    return 1;
  else{
    cout << "Invalid move\n Please try again";
    ////////////// fixing: retry player's turn
    return -1;
  }
}

void display(){
  cout << endl;
  cout << endl;

  cout << "---|---|---|---|---" << endl;
  cout << " D | " << rowD[1] << " | " << rowD[2] << " | " << rowD[3] << " | " << rowD[4] << " " << endl;
  cout << "---|---|---|---|---" << endl;
  cout << " C | " << rowC[1] << " | " << rowC[2] << " | " << rowC[3] << " | " << rowC[4] << " " << endl;
  cout << "---|---|---|---|---" << endl;
  cout << " B | " << rowB[1] << " | " << rowB[2] << " | " << rowB[3] << " | " << rowB[4] << " " << endl;
  cout << "---|---|---|---|---" << endl;
  cout << " A | " << rowA[1] << " | " << rowA[2] << " | " << rowA[3] << " | " << rowA[4] << " " << endl;
  cout << "---|---|---|---|---" << endl;

  cout << endl;
  cout << endl;

}

void board(){
  mainBoard[0] = NULL;
  mainBoard[1] = rowA; 
  mainBoard[2] = rowB; 
  mainBoard[3] = rowC;
  mainBoard[4] = rowD; 
}