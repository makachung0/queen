#include <iostream>
#include <string>

using namespace std;
const int N = 18;

//function prototyope
void initializeBoard(char board[][N]);
void printBoard(char board[][N], int &numQueens, int &numEmpty);
int updateBoard(int col, int row, char board[][N], int &numQueens, int &numEmpty);

int main () {
   char board[N][N];
   int row;
   char col;
   int numQueens=0;
   int numEmpty=N*N;
   initializeBoard(board);
   printBoard(board, numQueens, numEmpty);
   while (numEmpty !=0){
      cout << "Please Make your move: ";
      cin >> col >> row;
      // cout << col << " " << row;
      if(updateBoard(col, row, board, numQueens, numEmpty)){
         printBoard(board, numQueens, numEmpty);
      }
   }
   cout << "Game End";
   return 0;
};

void initializeBoard(char board[][N]){
   for (int i=0; i<N; i++){
      for (int j=0; j<N; j++){
         board[i][j] = '.';
      }
   }
};

void printBoard(char board[][N], int &numQueens, int &numEmpty){

   int colName = 'A';
   cout << "   ";
   for (int k=0; k<N; k++){
      cout << (char)colName << " ";
      colName++;
   }
   cout << endl;

   for (int i=0; i<N; i++){
      (i<10) ? cout << i << "  " : cout << i << " ";
      for (int j=0; j<N; j++){
         cout << board[i][j] << " ";
      }
      cout << endl;
   }

   cout << "Number of Queens: " << numQueens << "\n";
   cout << "Number of Empty: " << numEmpty << "\n";


};

int updateBoard(int col, int row, char board[][N], int &numQueens, int &numEmpty){
   col -= 65;
   int flag = 0;
   //updateQ()
   if(board[row][col]=='.'){
      board[row][col] = 'Q';
      numEmpty--;
      numQueens++;
      flag = 1;
   }
   //updateRow()
   for(int i=0; i<N; i++){
      if(board[row][i]=='.'){
         board[row][i] = '=';
         numEmpty--;
         flag = 1;
      }
   }
   //updateCol()
   for(int j=0; j<N; j++){
      if(board[j][col]=='.'){
         board[j][col] = '=';
         numEmpty--;
         flag = 1;
      }
   }
   //updateDiagonal()
   for (int p=0; p<N; p++){
      for (int q=0; q<N; q++){
         if((abs(col-q)==abs(row-p))&&board[p][q]=='.'){
            board[p][q] = '=';
            numEmpty--;
            flag = 1;
         }
      }
   }

   
   return flag;
};
