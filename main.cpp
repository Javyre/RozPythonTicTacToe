#include <iostream>

using namespace std;

void displayBoard(int[]);
char trans(int);
unsigned int checkForWin(int[]);

int main()
{
    int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int board2d[3][3] = {
                            {0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0}
                        };
    int movesmade = 0;
    bool moveOK;
    unsigned int pmove;

    //while (true) {
        for (int i=0;; i++){
            displayBoard(board);
            moveOK = true;
            while(moveOK){
                cout << (i%2 == 0 ? "X" : "O") << " Turn! Pick #s 0-8." << e ;
                cin >> pmove;
                if (board[pmove])
                    cout << "cheat!" << endl;
                else {
                    board[pmove]=(i%2==0)+1;
                    moveOK = false;
                    movesmade++;
                }

            }
            if (checkForWin(board) == (i%2==0)+1){
                displayBoard(board);
                cout << (i%2 == 0 ? "X" : "O") << " Win!" << endl;
                break;
            }
            if (movesmade >= 9) {
                displayBoard(board);
                cout << "Cats!" << endl;
                break;
            }
        }



    return 0;
}

void displayBoard(int board[]) {
   cout << trans(board[0]) << " | " << trans(board[1]) << " | " << trans(board[2]) << endl;
   cout << "==========" << endl;
   cout << trans(board[3]) << " | " << trans(board[4]) << " | " << trans(board[5]) << endl;
   cout << "==========" << endl;
   cout << trans(board[6]) << " | " << trans(board[7]) << " | " << trans(board[8]) << endl;
}

char trans(int bob){
   if (bob==1)
      return'X';
   else if (bob==2)
      return'O';
   else
      return' ';
}

unsigned int checkForWin(int board[]){
    for (int i=1; i<3; i++){
        if ((board[0]==i && board[1]==i && board[2]==i) || // _
            (board[3]==i && board[4]==i && board[5]==i) || // _
            (board[6]==i && board[7]==i && board[8]==i) || // _

            (board[0]==i && board[3]==i && board[6]==i) ||
            (board[1]==i && board[4]==i && board[7]==i) || // | | |
            (board[2]==i && board[5]==i && board[8]==i) ||

            (board[0]==i && board[4]==i && board[8]==i) || // X
            (board[2]==i && board[4]==i && board[6]==i)) {
            return i;
        }
    }
    return 0;
}
