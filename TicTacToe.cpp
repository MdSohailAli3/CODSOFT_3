#include<iostream>
#include<string.h>
using namespace std;
char board[10]={'0','1','2','3','4','5','6','7','8','9'};
void draw_board(){
cout<<"\n\t\t\t      |       |       ";
cout<<"\n\t\t\t  "<<board[1]<<"   |   "<<board[2]<<"   |   "<<board[3];
cout<<"\n\t\t\t______|_______|_______";
cout<<"\n\t\t\t      |       |       ";
cout<<"\n\t\t\t  "<<board[4]<<"   |   "<<board[5]<<"   |   "<<board[6];
cout<<"\n\t\t\t______|_______|_______";
cout<<"\n\t\t\t      |       |       ";
cout<<"\n\t\t\t  "<<board[7]<<"   |   "<<board[8]<<"   |   "<<board[9];
cout<<"\n\t\t\t      |       |       \n";
}
int check_win(){
  for (int i = 1; i <=9; i){
    if (board[i]==board[i+1]&&board[i+1]==board[i+2]){
        return 1;
    }
    i+=3;
  }
   for (int i = 1; i <=3; i++){
    if (board[i]==board[i+3]&&board[i+3]==board[i+6]){
        return 1;
    }
  } 
    if (board[1]==board[5]&&board[5]==board[9]){
        return 1;
    }
    else if (board[3]==board[5]&&board[5]==board[7]){
        return 1;  //for win
    }
    else if(board[1]!='1'&&board[2]!='2'&&board[3]!='3'&&board[4]!='4'&&board[5]!='5'&&
            board[6]!='6'&&board[7]!='7'&&board[8]!='8'&&board[9]!='9'){
         return 0; //for draw
    }
    else {
      return 7;
    }
}
int reserved(int choice){
    if (board[choice]=='X'||board[choice]=='O'){
      return 2;
    }
}
int marking(char mark,int choice,int player){
   if (choice>=1 && choice<=9){
      board[choice]=mark;
    }
  else{
    return 1;
    }  
}   
void reset_board(){
  for (int i = 0; i < 10; i++){
    board[i]='0' + i;
  }
}
int play_again(int player){
  while(true){
    int choice;
    char mark,again[10];
    player=(player%2)?1:2;
    mark=(player%2)?'X':'O';
    cout<<"Player "<<player<<" enter your choice: ";
    cin>>choice;
    reserved(choice);
    if (reserved(choice)==2){
      cout<<"\nSPACE ALREADY OCCUPIED!\n"<<endl;
      cout<<"Player "<<player<<" enter your choice: ";  
      cin>>choice;
    }
    marking(mark,choice,player);
    if (marking(mark,choice,player)==1){
      cout<<"\nINVALID MOVE!"<<endl;
      player=3-player;
    }
    draw_board();
if (check_win()==1){ 
  cout<<"\nPLAYER "<<player<<" WINS!"<<endl;  
}
else if (check_win()==0){
    cout<<"\nGAME DRAW!"<<endl;
     }
if (check_win()==1||check_win()==0){
    table:
    cout<<"DO YOU WANT TO PLAY AGAIN(y/n):- ";
    cin>>again;
    if(tolower(again[0])=='y'){
    reset_board();
    draw_board();
    play_again(player);
    }
    else if (tolower(again[0])=='n'){
      exit(0);
    } 
    else{
      cout<<"\nWRONG CHOICE ENTERED-\n"<<endl;
      goto table;//certain part repeating function in notebook
      }
    }
    player=3-player;
    }
}
int main(int argc, char const *argv[]){
cout<<"\n\t\t^^^^^^^^^^TIC-TAC-TOE-GAME^^^^^^^^^^\n\t\t\t\tFOR 2 PLAYERS\n\n\n";
   int player=1;
   draw_board();
   cout<<"Player 1 will mark- X.\t\t\t\tPlayer 2 will mark- O.\n\n\t\t\tPlayer 1 will play first-\n\n";
   play_again(player);
    return 0;
}