#include <iostream>
using namespace std;

/* This whole game is made on concept of functional prgramming so there is no use of classes here*/

void DisplayBoard() // this function is just to display the board structure 
{
    cout <<  "  \t\t| 1  | 2  | 3  |" << endl;
    cout <<  "  \t\t-------------" << endl;
    cout <<  "  \t\t| 4  | 5  | 6  |" << endl;
    cout <<  "  \t\t-------------" << endl;
    cout <<  "  \t\t| 7  | 8  | 9  |" << endl;
}

char Winner(char board[3][3])
{
    char winner;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == 'X')
        winner = 'X';
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == 'O')
        winner = 'O';

    // Diagonal check (top-right to bottom-left)
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == 'O')
        winner = 'O';
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == 'X')
        winner = 'X';

    // Row 1 (top row) check
    else if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == 'X')
        winner = 'X';
    else if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == 'O')
        winner = 'O';

    // Row 2 check (middle row)
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == 'X')
        winner = 'X';
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == 'O')
        winner = 'O';

    // Row 3 check (bottom row)
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == 'X')
        winner = 'X';
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == 'O')
        winner = 'O';

    // Column 1 check (left column)
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == 'X')
        winner = 'X';
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == 'O')
        winner = 'O';

    // Column 2 check (middle column)
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == 'X')
        winner = 'X';
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == 'O')
        winner = 'O';

    // Column 3 check (right column)
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == 'X')
        winner = 'X';
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == 'O')
        winner = 'O';
    return winner;
}

void userInput(char (&arr)[3][3],int input,char sign)
{
    if(input <= 3) arr[0][input-1] = sign;
    else if(input < 6 && input >=3) arr[1][input % 3-1] = sign;
    else if(input < 9 && input>6) arr[2][input % 3-1] = sign;
    else if(input == 3) arr[0][2] = sign;
    else if(input == 6) arr[1][2] = sign;
    else if(input == 9) arr[2][2] = sign;
}

bool filled_boxes(int user_input,int (&arr)[9])
{
    bool is_find = false;
    for(int i = 0 ;i < 9;i++){
        if(user_input == arr[i]) {
            arr[i] = 0;
            is_find = true;
        }
    }
    return is_find;
}

void Botstrategy(int &randomNumber)
{
    // if(user_choice){
        randomNumber = rand() % 9 + 1;
// }
}

void Game_running() // this the function is whih both the player will play his/her strategy
{      
    // 2d array of characters where real data of players strategy is stored 
    char BoardArray[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}, i = 1;
    int user_input;
    int arr[9] = {1,2,3,4,5,6,7,8,9},randomNumber = 0;
    char mod_choice;
    cout<<"------------------------------------------"<<endl;
    cout<<"Do you wanna play with you friend or bot"<<endl;
    cout<<"Enter F to play with a friend or B to play with bot";
    cin>>mod_choice;
    cout<<endl<<endl;
    while (i <= 9)
    {   
        if(i % 2 != 0){ // for every odd iteration player x will play
            cout<<"Player's turn(X):"<<endl;
            cout<<"Enter your input : ";
            cin>>user_input;


            if(filled_boxes(user_input,arr) == false) {cout<<"Invalid input!"<<endl; continue;}

            userInput(BoardArray,user_input,'X');
            cout << endl;}
        else{ // for every even iteration player o will play

            if(mod_choice == 'B' || mod_choice=='b'){

                cout<<"Bot's turn:"<<endl;
                
                Botstrategy(randomNumber);
                user_input = randomNumber;


                if(filled_boxes(user_input,arr) == false) { continue;}

                userInput(BoardArray,user_input,'O');
                cout<<endl;
            }
            else{
                cout<<"Friend turn(O):"<<endl;
                cout<<"Enter your input : ";
                cin>>user_input;
                if(filled_boxes(user_input,arr) == false) {cout<<"Invalid input!"<<endl; continue;}

                 userInput(BoardArray,user_input,'O');
                cout << endl;
            }
        
            }

        for (int i = 0; i < 3; i++) // just to show the updated data of player_strategy array
        {
            cout<<" | ";
            for (int j = 0; j < 3; j++)
            {
                cout << BoardArray[i][j] << " | ";
            }
            cout<<"\n -------------";
            cout << endl;
        }

        if(Winner(BoardArray)){
            cout<< "--------------------------------"<< Winner(BoardArray)<<" is winner---------------------------\n\n";
            break;    
                }
        
        i++;
    
}

    if(i == 10){
        cout<<"----------------------The game is draw!------------------\n"<<endl;
    }
}
int main()
{
    cout<<"\t\t***************Welcome to tic tac toe game**********************\n\n";
    char user_choice;
    bool is_running = true;
    while(is_running){
        cout<<"To Start game please enter y:";
        cin>>user_choice;
        if(user_choice == 'Y' || user_choice == 'y'){
            DisplayBoard();
            Game_running();
        }
        else{   
            is_running = false;
            continue;}

    }
}