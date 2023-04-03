#include <iostream>

using namespace std;

bool leap_year(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 != 0)
		{
			return true;
		}
		else if (year % 400 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}
int main() 
{
	int year;
	cout << "Welcome to the leap year calculator!\nPlease enter year, and I'll tell you whether it is a leap year or not." << endl;
	cin >> year;
	
	if (leap_year(year))
	{
		cout << "The year " << year << " is a leap year!" << endl;
	}
	else
	{
		cout << "The year " << year << " is not a leap year." << endl;
	}

	return 0;
}