#include <iostream> 
#include <cmath> 
#include <string>
using namespace std;

char rowD[] = {'-', '1', '2', '3', '4', '-'};
char rowC[] = {'-', '1', '2', '3', '4', '-'};
char rowB[] = {'-', '1', '2', '3', '4', '-'};
char rowA[] = {'-', '1', '2', '3', '4', '-'};

char *mainBoard[5]; 

void board();
void display();
int charToNum(char row);
bool checkmate(char player, int row, int num);
bool checkPoints(int points);
bool tieGame(int iter);

int main()
{
  board(); 
  display();

  char player1 = 'X'; 
  char player2 = 'O'; 
  char playerTurns;
  char row;
  int num;
  bool game = false;


  int turn = rand()%2;
  int iter = 0;
  do{     
    if(turn)
      playerTurns = player1; 
    else
      playerTurns = player2; 
    
    cout << "PLAYER " << turn+1 << " TURNS" << endl;
    cout << "Row + Number: ";
    
    int letter = 0;
    bool move = true;
    while(move){
      cin >> row;    
      cin >> num; 
      letter = charToNum(row);
      char n = (char)num%48 + 48;

      if(mainBoard[letter][num] == n){
	      mainBoard[letter][num] = playerTurns;
	      move = false; 
      }else
	      cout << "The selected spot has been taken. Please pick a different spot " << endl;
     }

    game = checkmate(playerTurns, letter, num);
    display();

    turn = (turn+1)%2;
    iter++;
    
  }while(!game && !tieGame(iter));

  if(tieGame(iter))
    cout << "TIE GAME!" << endl;
  else{
    cout << "THE GAME IS OVER" << endl;
    cout << "PLAYER " << (turn+1) << " WINS!" << endl;
  }
    
  return 0;
}

bool tieGame(int iter){
  //there are only 16 positions
  if(iter == 16)
    return true;
  else 
    return false;
}

bool checkmate(char player, int row, int num){
  //need four points to win
  int points = 0;

  for(int i=1; i<=4; i++){
    if(mainBoard[row][i] == player)
      points++;
    else{ 
      points = 0;
      break;
    }      
  }
  if(checkPoints(points))
    return true;

  for(int i=1; i<=4; i++){
    if(mainBoard[i][num] == player)
      points++;
    else{ 
      points = 0;
      break;
    }
  }
  if(checkPoints(points))
    return true;

  for(int i=1; i<=4; i++){
    if(mainBoard[i][i] == player)
      points++;
    else{
      points = 0;
      break; 
    }
  }
  if(checkPoints(points))
    return true;

  for(int i=1; i<=4; i++){
    if(mainBoard[5-i][i] == player)
      points++;
    else{
      points = 0; 
      break;
    }
  }
  return checkPoints(points);
}

bool checkPoints(int points){
  //a row of 4 same pieces results a win
  if (points == 4)
    return true;
  return false; 
}

int charToNum(char row){
  //convert row into a number
  if (row == 'D' || row == 'd')
    return 4;
  else if (row == 'C' || row == 'c')
    return 3;
  else if (row == 'B' || row == 'b')
    return 2;
  else if (row == 'A' || row == 'a')
    return 1;
  else{
    cout << "Invalid move. Please try again" << endl;
    return 0;
  }
}

void display(){
  //draw the board display
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
  //set the main board
  mainBoard[0] = NULL;
  mainBoard[1] = rowA; 
  mainBoard[2] = rowB; 
  mainBoard[3] = rowC;
  mainBoard[4] = rowD; 
}
