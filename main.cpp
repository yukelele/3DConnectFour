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
char mark(char player);

int main()
{
  board();
  display();

  char player1 = 'X'; 
  char player2 = 'O'; 
  char playerTurns;
  
  int turn = 1; 

  if(turn%2)
    playerTurns = player1; 
  else
    playerTurns = player2; 

  mark(playerTurns);


  return 0;
}

char mark(char player){

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