#include <iostream>  
#include <chrono>  
using namespace std;  
int main()  
{  
  int num;  
  char choice;  
  int score1 = 0;  
  int score2 = 0;  
  string playerName;  
  cout << "\t========WELCOME TO THE GAMING WORLD========\n";  
  cout << "\nWhat's your Name: ";   
  getline(cin,playerName);  
  start:  
  do  
  {  
    cout << "\n\t ========WELCOME TO THE GAMING WORLD"<<playerName<<"!=======\n";  
    cout << "\t Choose which time limited game you want to play:\n";  
    cout << "\t ○ Enter 1 for Betting Game\n";   
    cout << "\t ○ Enter 2 for Hangman Game\n";   
    cout << "\t ○ Enter 3 to exit game\n";   
    cout<<"\nRemember!The number entered should be from 1 to 3!\n";  
    cin>>num;  
  }while(num!=1&&num!=2&&num!=3);  
  if(num==1)  
  {  
    int balance;   
    int bettingAmount;   
    int guess;   
    int dice;  
    const int BETTING_TIME_LIMIT = 120;  
    cout << "\n\n\t========WELCOME TO THE BETTING GAME!=======\n";  
    cout << "\t\t======RULES!======\n";  
    cout << "\tThe following are the rules to this amazing game:\n";   
    cout << "\t○ Choose a number between 1 to 10.\n";   
    cout << "\t○ Winner gets 10 times the betted amount.\n";   
    cout << "\t○ Wrong bet and you lose the betted amount.\n";  
    cout << "\t○ Five points are added to score in case of a win.\n";  
    cout << "\t○ Remember the time limit for this game is 120 sec!\n\n";
    game:
    cout << "\n\nHey there "<< playerName<<"! Enter the starting balance to play game : Rs ";   
    cin >> balance;   
    do  
    {   
      cout << "\nYour current balance is Rs. " << balance << "\n";  
      do   
      {   
        cout <<"Enter the amount you want to bet : Rs.";   
        cin >> bettingAmount;   
        if(bettingAmount > balance)   
        cout << "\n○ Your betting balance can't be more than the current balance!\n"<<"\nKindly re-enter the betting balance\n ";   
      }  
      while(bettingAmount > balance);  
      chrono::steady_clock::time_point start_time = chrono::steady_clock::now();  
      do   
      {  
        cout << "Guess any betting number between 1 & 10 :";   
        cin >> guess;   
        if(guess <= 0 || guess > 10)   
        cout << "\n○ Number should be between 1 to 10\n" <<"○ Re-enter number:\n ";   
      }while(guess <= 0 || guess > 10);   
      srand((time(0)));  
      dice = rand()%10 + 1;   
      chrono::steady_clock::time_point end_time = chrono::steady_clock::now();  
      chrono::duration<double> elapsed_seconds = end_time - start_time;  
      if (elapsed_seconds.count() >= BETTING_TIME_LIMIT)  
      {  
        cout << "\n\tTime's up! GAME OVER\n";  
        goto jumpp;  
      }  
      if(dice == guess)   
      {   
        cout << "\n\nYou are in luck! You have won Rs." << bettingAmount * 10;  
        balance = balance + bettingAmount * 10;   
        score1 =score1+5;  
      }   
      else   
      {  
        cout << "\nOops! Better luck next time! You lost Rs. "<< bettingAmount <<"\n";   
        balance = balance - bettingAmount;   
      }   
      cout << "\nThe winning number was  " << dice <<"\n";  
      if (balance <= 0)  
      {  
        cout << "\nGAME OVER! You have run out of money!\n";  
        goto jumpp;  
      }  
      cout << "\n"<<playerName<<"!You have balance of Rs. " << balance << "\n";   
      cout<<"Your total score is " <<score1 << "\n";  
      cout << "\n\n○ Do you want to continue playing this game? (y/n)?";   
      cin >> choice;   
    }while(choice =='Y'|| choice=='y');   
    jumpp:  
    cout << "\n\n"<<playerName<<"!"<<"Thanks for playing the game.\nYour total balance is Rs. " << balance <<endl;  
    cout<<"Youre final score is "<<score1<<endl;  
    cout<<"\n○ Would you like to play this game again(y/n)";  
    cin>>choice;  
    if(choice =='Y'|| choice=='y')  
    {  
      goto game;  
    }  
    cout<<"\n○ Would you like to the menu option?(y/n)";  
    cin>>choice;  
    if(choice =='Y'|| choice=='y')  
    {  
      goto start;  
    }  
    else  
    {  
      goto end;  
    }  
  }  
  else if(num==2) 
  {  
    const int BETTING_TIME_LIMIT = 120;  
    cout << "\n\n\t===========WELCOME TO THE HANGMAN GAME!==========\n";  
    cout << "\t\t======RULES!======\n";  
    cout << "\tThe rules of this game are simply as pie!\n";  
    cout << "\t○ The category is 'EXOTIC FRUITS'.\n";  
    cout << "\t○ You simply have to guess the given word.\n";  
    cout << "\t○ A total of 7 chances are given at the start of each game.\n";  
    cout << "\t○ Two points are added to score in case of a win.\n";  
    cout << "\t○ In case of loss no change is observed.\n"; 
    cout << "\t○ If you fail to guess then you will be simply hanged and be named the hangman!\n";  
    cout << "\t○ Remember the time limit for this game is 120 sec!\n\n";  
    const int Total_Chances = 7;  // maximum number of incorrect guesses allowed    // Possible words to be guessed
    hangman:  
    const string words[] =  
    {  
      "KIWI",  
      "GUAVA",  
      "PERSIMMON",  
      "DURIAN",  
      "AVACADO",  
      "DRAGONFRUIT",  
      "PAPAYA",  
      "LYCHEE"  
    };  
  srand((time(0)));  
  int randomword = rand() % 8;  
  string wordToGuess = words[randomword];  // word to be guessed  
  int length = wordToGuess.length();  
  string soFar(length, '-');  // word guessed so far  
  string used = "";  // letters already guessed  
  int wrong = 0;  // number of incorrect guesses  
  // Record start time  
  chrono::steady_clock::time_point start_time = chrono::steady_clock::now();  
  while (wrong < Total_Chances && soFar != wordToGuess)  
  {  
    cout << "\n\nYou have " << (Total_Chances - wrong) << " guesses left.\n";  
    cout << "\nYou've used the following letters:\n" << used << endl;  
    cout << "\nSo far, the word is:\n" << soFar << endl;  
    char guess;  
    cout << "Your score is " << score2 << endl;  
    cout << "\n\nEnter your guess: ";  
    cin >> guess;  
    guess = toupper(guess);  // make uppercase since word is in uppercase  
    // Record end time  
    chrono::steady_clock::time_point end_time = chrono::steady_clock::now();  
    chrono::duration<double> elapsed_seconds = end_time - start_time;  
    if (elapsed_seconds.count() >= BETTING_TIME_LIMIT)
    {  
      cout << "Time's up! GAME OVER!\n";  
      goto jump;  
    }  
    while (used.find(guess) != -1)  
    {  
      cout << "\nYou've already guessed " << guess << endl;  
      cout << "Enter your guess: ";  
      cin >> guess;  
      guess = toupper(guess);  
    } 
    used += guess;  
    if (wordToGuess.find(guess) != -1)  
    {  
        cout << "That's right! " << guess << " is in the word.\n";   
        score2=score2+2;  
        for (int i = 0; i < length; ++i)  
        {  
          if (wordToGuess[i] == guess)  
          {  
            soFar[i] = guess;  
          }  
        }  
    }  
    else  
    {  
      cout << "Sorry, " << guess << " isn't in the word.\n";  
      ++wrong;  
      cout<<"Total number of wrong guesses "<<wrong;  
    }  
  }// game is over, print result  
  if (wrong ==Total_Chances)  
  {  
    cout << "\n\nYou've been hanged!";  
  }  
  else  
  {  
    cout << "\n\nCongratulations! You guessed the word!";  
  }  
  cout << "\nThe word was " << wordToGuess << endl;  
  jump:  
  cout << playerName<<"!"<<"Your total score is " << score2 << endl;  
  cout<<"\n○ Would you like to play again?(y/n)";  
  cin>>choice;  
  if(choice =='Y'|| choice=='y')  
  {  
    goto hangman;  
  }  
  cout<<"\n\n○ Would you like to go to the menu option?(y/n)";  
  cin>>choice;  
  if(choice =='Y'|| choice=='y')  
  {  
    goto start;  
  }  
  else  
  {  
    goto end;  
  }  
}  
else if(num==3)  
{  
  end:  
  int totalscore=0;  
  totalscore=score1+score2;  
  cout<<"\n\n\t================GAME OVER================";  
  cout<<"\n\tThank you for playing our games "<<playerName<<"!\n\tYour final score is "<<totalscore<<"."<<endl;  
  cout<<"\n\t\tGOOD BYE AND COME AGAIN!\t";  
}  
return 0;  
} 
