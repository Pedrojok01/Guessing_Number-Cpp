#include <iostream>
#include <limits>
#include <termios.h>
#include <unistd.h>

using namespace std;

void SetStdinEcho(bool enable = true)
{
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if( !enable )
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;

    (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}


//Get player1 hidden number as integer:
int getHiddenPlayerOneNumber(){
    char input[5];
    int i;
    int num;

    for (i = 0; i < 4; i++){
        SetStdinEcho(false);
        cin>>input[i];
        SetStdinEcho(true);
        if(isdigit(input[i]) == true){
            cout<<"*";
        }
        else{
            cout<<"";
            i--;
        }
    }
    input[i] = '\0';
    num = atoi(input);
    return num;
}


//Get player2 number as integer:
int getPlayerTwoNumber(){
    int i;
    while (true){
        cout << "Enter your guess:" << endl;
        cin >> i;
        if (!cin){
            cout << "Enter an int you moron! " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    else break;
  }
  return i;
}


//While loop until right guess & Counter count:
void playerTwoGuess(int num1, int num2){
    int attemptCounter = {1};
    while (num2 != num1){
            if (num2 > num1){
                cout << num2 << " is greater than player 1 number! Try again: "<<endl;
                attemptCounter++;
                num2 = getPlayerTwoNumber();
            }
            else{
                cout << num2 << " is lower than player 1 number! Try again: "<<endl;
                attemptCounter++;
                num2 = getPlayerTwoNumber();
            }
    }
        cout <<endl<<endl<< "CONGRATULATION PLAYER 2, YOU'VE FOUND PLAYER 1 NUMBER IN " << attemptCounter << " ATTEMPTS!!!"<<endl<<endl<<endl;
}



int main(){

    cout << "Welcome To GUESSING NUMBER Game!!!"<<endl;
    cout << "=================================="<<endl<<endl;

    bool play = true;
    while (play = true){

        //Player 1 input number:
        cout << "Player 1: it's your turn to play!" << endl;
        cout << "Enter the number you want player 2 to guess (4 characters required! i.e. 50 = 0050): " << endl;
        int numPlayer1 = getHiddenPlayerOneNumber();
        cout<<endl<<endl;

        // Player 2 guess player 1 number:
        cout << "Player 2, it's your turn to play. Try to find player one's number in as few attempts as possible!!!" << endl;
        int numPlayer2 = getPlayerTwoNumber();
        playerTwoGuess(numPlayer1,numPlayer2);
        play = false;


        //Play again or quit?
        cout<<"Do you want to play again?"<<endl;
        cout<<"Press 'Y' to play again, or any other key to quit"<<endl;

        string answer;
        cin >> answer;
        cout<<endl<<endl;

        if (toupper(answer[0]) == 'Y'){
            play = true;
        }
        else{
            break;
        }
    }
    return 0;
}
