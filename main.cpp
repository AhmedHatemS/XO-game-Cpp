#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char index[3][3]; //indexes of box.
int number; //get the tempValue of index to play.
char sign; // X or O
int flag = 0; //board elements full?

void temp_shape(); //contains the numbers' arrangement on the board.
void player1(); // contains the first player's question and sign.
void player2(); // contains the second player's question and sign.
void cases(); // switch the player's choice to play.
void realValue(); //get the choices into the array.
void shape(); //shows the game board.
void check1(); // check who wins or end --- direct to player2.
void check2(); // check who wins or end --- direct to player1.

int main()
{
   temp_shape();
   player1();
   return 0;
}

void player1()
{
    puts("Player 1 : X");
    cout<< "Where to put X?" <<endl;
    cin>> number;
    sign = 'X';
    cases();
    realValue();
    flag++;
    check1();
}

void player2()
{
    puts("Player 2 : O");
    cout<< "Where to put O?" <<endl;
    cin>> number;
    sign = 'O';
    cases();
    realValue();
    flag++;
    check2();
}

void cases()
{
    if (number>0 && number<=3)
        index[0][number-1] = sign;
    else if (number>3 && number<=6)
        index[1][number-4] = sign;
    else if (number>6 && number<=9)
        index[2][number-7] = sign;
    else
        puts("Number you entered is unavailable");
}

void realValue()
{
    char value; // Real value in square
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (index[i][j] == 'X' || index[i][j] == 'O')
                value = index[i][j];
            else
                value = ' ';
            index[i][j] = value;
        }
    }
    shape();
}

void temp_shape()
{
    printf("\n\t\t\t\t\t\t\t Temp board:");
    cout<< "\n\t\t\t\t\t\t\t ___ ___ ___\n" <<endl;
    cout<< "\t\t\t\t\t\t\t| " << "1" << " | " << "2" << " | " << "3" << " |" <<endl;
    cout<< "\t\t\t\t\t\t\t ___ ___ ___\n" <<endl;
    cout<< "\t\t\t\t\t\t\t| " << "4" << " | " << "5" << " | " << "6" << " |" <<endl;
    cout<< "\t\t\t\t\t\t\t ___ ___ ___\n" <<endl;
    cout<< "\t\t\t\t\t\t\t| " << "7" << " | " << "8" << " | " << "9" << " |" <<endl;
    cout<< "\t\t\t\t\t\t\t ___ ___ ___\n" <<endl;
}

void shape()
{
    printf("\t\t\t\t\t\t\t Your board:");
    cout<< "\n\t\t\t\t\t\t\t ___ ___ ___\n" <<endl;
    cout<< "\t\t\t\t\t\t\t| " << index[0][0] << " | " << index[0][1] << " | " << index[0][2] << " |" <<endl;
    cout<< "\t\t\t\t\t\t\t ___ ___ ___\n" <<endl;
    cout<< "\t\t\t\t\t\t\t| " << index[1][0] << " | " << index[1][1] << " | " << index[1][2] << " |" <<endl;
    cout<< "\t\t\t\t\t\t\t ___ ___ ___\n" <<endl;
    cout<< "\t\t\t\t\t\t\t| " << index[2][0] << " | " << index[2][1] << " | " << index[2][2] << " |" <<endl;
    cout<< "\t\t\t\t\t\t\t ___ ___ ___\n" <<endl;
}

void check1()
{
    if ( //Horizontal
        (index[0][0] == 'X' && index[0][1] == 'X' && index[0][2] == 'X') ||
        (index[1][0] == 'X' && index[1][1] == 'X' && index[1][2] == 'X') ||
        (index[2][0] == 'X' && index[2][1] == 'X' && index[2][2] == 'X') ||
        //Vertical
        (index[0][0] == 'X' && index[1][0] == 'X' && index[2][0] == 'X') ||
        (index[0][1] == 'X' && index[1][1] == 'X' && index[2][1] == 'X') ||
        (index[2][0] == 'X' && index[2][1] == 'X' && index[2][2] == 'X') ||
        //Cross
        (index[0][0] == 'X' && index[1][1] == 'X' && index[2][2] == 'X') ||
        (index[0][2] == 'X' && index[1][1] == 'X' && index[2][0] == 'X')
        )
            {
                puts("Player 1 won!");
                exit(1);
            }
    else if (flag == 9)
        puts("No one won, play again.");
    else
    {
        system("cls");
        temp_shape();
        shape();
        player2();
    }
}

void check2()
{
    if ( //Horizontal
        (index[0][0] == 'O' && index[0][1] == 'O' && index[0][2] == 'O') ||
        (index[1][0] == 'O' && index[1][1] == 'O' && index[1][2] == 'O') ||
        (index[2][0] == 'O' && index[2][1] == 'O' && index[2][2] == 'O') ||
        //Vertical
        (index[0][0] == 'O' && index[1][0] == 'O' && index[2][0] == 'O') ||
        (index[0][1] == 'O' && index[1][1] == 'O' && index[2][1] == 'O') ||
        (index[2][0] == 'O' && index[2][1] == 'O' && index[2][2] == 'O') ||
        //Cross
        (index[0][0] == 'O' && index[1][1] == 'O' && index[2][2] == 'O') ||
        (index[0][2] == 'O' && index[1][1] == 'O' && index[2][0] == 'O')
        )
            {
                puts("Player 2 won!");
                exit(1);
            }
    else if (flag == 9)
        puts("No one won, play again.");
    else
    {
        system("cls");
        temp_shape();
        shape();
        player1();
    }
}
