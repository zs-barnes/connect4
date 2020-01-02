#include    <stdio.h>
#include    <stdlib.h>

char board[8][8];   //2D array to store board state

void printBoard();
void redMove();
void blueMove();
void win();
void checkWin();

int main() {
	//initialize board to all spaces ("empty")
	for(int i=0; i < 8; i++)
			for(int j=0; j < 8; j++)
				board[i][j] = ' ';
                
    int count = 0;
    while(count < 64){
    printBoard();
    redMove();
    printBoard();
    checkWin();
    blueMove();
    printBoard();
    checkWin();
    printf("--------\n");
    count += 2;
    }

}

void printBoard(){
    //print the board
	for(int j=7; j >= 0; j--) {
		for(int i=0; i < 8; i++)
			printf("%c", board[i][j]);
		printf("\n");
	}
}

//drop a red char 
void redMove(){
    int x;
    printf("Red enter a number 0-7: ");
    scanf("%d", &x);

    for (int i = 0; i<= 7; i++){
        if(board[x][i] == ' '){
            board[x][i] = 'R';
            break;
        }
    }
    printf("--------\n");
}

//drop a blue char
void blueMove(){
    int y;
    printf("Blue enter a number 0-7: ");
    scanf("%d", &y);
    for (int i = 0; i<= 7; i++){
        if(board[y][i] == ' '){
            board[y][i] = 'B';
            break;
        }
    }
    printf("--------\n");
}

void checkWin(){
    // check for horizontal line win
    for (int j = 0; j < 8; j ++){
        for (int i = 0; i < 8; i++){
            if((board[i][j] != ' ')
            && (board[i+1][j] != ' ')
            && (board[i+2][j] != ' ')
            && (board[i+3][j] != ' ')
            && ((board[i][j] == board[i+1][j])
            && (board[i+1][j] == board[i+2][j])
            && (board[i+2][j] == board[i+3][j]))){
            char winner = board[i][j];
            printf(" %c won! \n", winner);
            exit(0);
            }
        }
    }

    // check for vertical line win
    for (int i = 0; i < 8; i ++){
        for (int j = 0; j < 8; j++){
            if((board[i][j] != ' ')
            && (board[i][j+1] != ' ')
            && (board[i][j+2] != ' ')
            && (board[i][j+3] != ' ')
            && ((board[i][j] == board[i][j+1])
            && (board[i][j+1] == board[i][j+2])
            && (board[i][j+2] == board[i][j+3]))){
            char winner = board[i][j];
            printf(" %c won! \n", winner);
            exit(0);
            }
        }
    }

    // check for left-right diagonal win
    for (int i = 0; i < 8; i ++){
        for (int j = 0; j < 8; j++){
            if((board[i][j] != ' ')
            && (board[i+1][j+1] != ' ')
            && (board[i+2][j+2] != ' ')
            && (board[i+3][j+3] != ' ')
            && ((board[i][j] == board[i+1][j+1])
            && (board[i+1][j+1] == board[i+2][j+2])
            && (board[i+2][j+2] == board[i+3][j+3]))){
            char winner = board[i][j];
            printf(" %c won! \n", winner);
            exit(0);
            }
        }
    }

    // check for right-left diagonal win
    for (int i = 7; i >= 0; i--){
        for (int j = 0; j < 8; j++){
            if((board[i][j] != ' ')
            && (board[i-1][j+1] != ' ')
            && (board[i-2][j+2] != ' ')
            && (board[i-3][j+3] != ' ')
            && ((board[i][j] == board[i-1][j+1])
            && (board[i-1][j+1] == board[i-2][j+2])
            && (board[i-2][j+2] == board[i-3][j+3]))){
            char winner = board[i][j];
            printf(" %c won! \n", winner);
            exit(0);
            }
        }
    }

}