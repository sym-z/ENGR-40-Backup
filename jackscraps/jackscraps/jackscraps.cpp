#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
bool play_craps();
int rand_int(int a, int b);

int main()
{
    double wins = 0;
    double losses = 0;
    double winPercentage;
    int aboveFifty = 0;
    double maxChance = 0;
    double minChance = 100;
    srand(time(0));
    for (int j = 0; j < 100; j++)
    {
        wins = 0;
        losses = 0;
        for (int i = 0; i < 10000; i++)
        {
            if (play_craps())
            {
                wins++;
            }
            else
            {
                losses++;
            }
        }
        winPercentage = (wins / 10000.0) * 100.0;
        if (winPercentage >= 50.0)
        {
            aboveFifty++;
        }
        if (winPercentage > maxChance) {
            maxChance = winPercentage;
        }
        if (winPercentage < minChance)
        {
            minChance = winPercentage;
        }
        cout << winPercentage << endl;
    }
    cout << "Amount of win percentages over 50%: " << aboveFifty << endl;
    cout << "Out of 100 runs of 10,000 games of craps, your highest odds of winning are: " << maxChance << "%" << endl;
    cout << "and your lowest chance of winning is " << minChance << "%" << endl;
    return 0;
}

bool play_craps()
{
    int rolls = 0;
    int die1;
    int die2;
    int total;
    int scoreToWin;

    die1 = rand_int(1, 6);
    die2 = rand_int(1, 6);
    total = die1 + die2;

    if (total == 7 || total == 11)
    {
        return true;
    }
    else if (total == 2 || total == 3 || total == 12)
    {
        return false;
    }
    else
    {
        scoreToWin = total;

        die1 = rand_int(1, 6);
        die2 = rand_int(1, 6);
        total = die1 + die2;

        while (total != 7 && total != scoreToWin)
        {
            die1 = rand_int(1, 6);
            die2 = rand_int(1, 6);
            total = die1 + die2;
        }
        if (total == scoreToWin)
        {
            return true;
        }
        else
        {
            return false;
        }

    }


}

int rand_int(int a, int b)
{
    return rand() % (b - a + 1) + a;
}