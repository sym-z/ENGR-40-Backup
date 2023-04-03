#include <iostream>
#include <cstdlib>
#include <ctime>//header files

using namespace std;
void play_craps();
int rand_int(int a, int b);//function declarations
int main()
{
    char answer;
    
    do
    {
        srand(time(0));//seeds the randomizer with the time function
        cout << endl << endl << endl;
        cout << "Would you like to play a game of craps \? Type y for yes"
            << " or n for no:";
        
        answer = cin.get();
        cin.ignore();
       
        if (answer == 'y' || answer == 'Y')
            play_craps();
    } while (answer == 'y' || answer == 'Y');//Given menuing system
   
    system("PAUSE");
    
    return 0;
}

void play_craps()
{
    int die1;
    int die2;//the dice that will be used for the rolls
    int total;//the variable that hold the total roll
    int scoreToWin;//the value used to hold the first roll in the event the player must keep rolling

    cout << "Time to roll the dice. Good luck!" << endl;
    cout << "Rolling..." << endl;//outputs messages to the player

    die1 = rand_int(1, 6);
    die2 = rand_int(1, 6);//calculates the first roll
    total = die1 + die2;

    if (total == 7 || total == 11)//if first roll is a 7 or an 11, automatic win
    {
        cout << "Your total roll was " << total << "!" << endl;
        cout << "INSTANT WIN, LUCK IS ON YOUR SIDE TODAY!!!" << endl;//outputs instant win to the player
        return;//exits the function
    }
    else if (total == 2 || total == 3 || total == 12)//if first roll is a 2, 3 or 12, automatic loss
    {
        cout << "Your total roll was " << total << "..." << endl;
        cout << "Unlucky day, oh no! Instant loss!" << endl;//outputs instant loss to the player
        return;//exits the function
    }
    else//multiple roll scenario
    {
        cout << "Your total roll on your first roll was " << total << " time to see if luck is on your side today." << endl;//prompts the player that they will be rolling again.
        
        scoreToWin = total;//sets the first roll to be the score needed to win
        
        die1 = rand_int(1, 6);
        die2 = rand_int(1, 6);//recalculates a new total
        total = die1 + die2;

        while (total != 7 && total != scoreToWin)//while loop to run until the score is either a 7 or equal to the first roll
        {
            cout << "You just rolled: " << total << "..." << endl;
            cout << "Time to keep going..." << endl;//if they need to roll again (not their first score or a 7
            die1 = rand_int(1, 6);
            die2 = rand_int(1, 6);//rolls the dice continuously
            total = die1 + die2;
        }
        if (total == scoreToWin)//if the first roll score is rolled
        {
            cout << "You rolled: " << total << endl;
            cout << "Congradulations! You beat the odds!! YOU WIN!!" << endl;//outputs win to the player
            return;//exits function
        }
        else//if a 7 is rolled
        {
            cout << "Ouch, you rolled a " << total << ", sorry! YOU LOSE!" << endl;//outputs a loss to the player
            return;//exits funtion
        }

    }


}

int rand_int(int a, int b)//given random number generator from lecture
{
    return rand() % (b - a + 1) + a;
}

/*OUTPUT:

RUN 1: (INSTANT LOSS CASE)
Would you like to play a game of craps ? Type y for yes or n for no:Y
Time to roll the dice. Good luck!
Rolling...
Your total roll was 2...
Unlucky day, oh no! Instant loss!

RUN 2:(MULTIPLE ROLL WIN CASE)
Would you like to play a game of craps ? Type y for yes or n for no:Y
Time to roll the dice. Good luck!
Rolling...
Your total roll on your first roll was 10 time to see if luck is on your side today.
You just rolled: 5...
Time to keep going...
You just rolled: 5...
Time to keep going...
You just rolled: 9...
Time to keep going...
You just rolled: 9...
Time to keep going...
You just rolled: 9...
Time to keep going...
You just rolled: 4...
Time to keep going...
You just rolled: 9...
Time to keep going...
You just rolled: 4...
Time to keep going...
You just rolled: 6...
Time to keep going...
You rolled: 10
Congradulations! You beat the odds!! YOU WIN!!

RUN 3:(MULTIPLE ROLL LOSS CASE)
Would you like to play a game of craps ? Type y for yes or n for no:Y
Time to roll the dice. Good luck!
Rolling...
Your total roll on your first roll was 10 time to see if luck is on your side today.
You just rolled: 5...
Time to keep going...
You just rolled: 8...
Time to keep going...
You just rolled: 8...
Time to keep going...
You just rolled: 8...
Time to keep going...
You just rolled: 6...
Time to keep going...
Ouch, you rolled a 7, sorry! YOU LOSE!

RUN 4:(INSTANT WIN CASE)
Would you like to play a game of craps ? Type y for yes or n for no:Y
Time to roll the dice. Good luck!
Rolling...
Your total roll was 7!
INSTANT WIN, LUCK IS ON YOUR SIDE TODAY!!!
*/