#include <iostream>
#include <fstream>

using namespace std;//header files

int main() //main function
{
	ifstream pFile;//two file streams, one for the sentinel file sFile, one for the prenum file pFile
	ifstream sFile;

	int choice, prenumChecks, prenumCheckNum = 0, prenumDesired, sentinelDesired,sentinelCheckNum=0; //variables for the choice made in the switch statements, current check numbers being read, and the check numbers we want to find as well as prenum checks, the quantity of checks read in the prenum case
	double  prenumCheckAmount,sentinelCheckAmount=0.0; //two double variables for the the check amounts in the sentinel file and the prenum file

	pFile.open("C:\\Users\\Housefly\\source\\repos\\prenum.txt");//ifstreams open the respective .txt files
	sFile.open("C:\\Users\\Housefly\\source\\repos\\sentinel.txt");

	cout << "Please make a choice of what you would like to do:\n1.\tUse the \"prenum\" file.\n2.\tUse the \"sentinel\" file." << endl;//prompts the user to choose whether they want to use the prenum .txt file or the sentinel .txt file

	cin >> choice;//takes user choice

	switch (choice)//uses the choice to run the respective code for either choice, handles bad input
	{

	case 1:
	{
		pFile >> prenumChecks;
		cout << "You chose to use the prenum file." << endl;
		cout << "Please enter the number of the check you wish to find." << endl;
		cin >> prenumDesired;

		for (int i = 0; i < prenumChecks; i++)
		{
			pFile >> prenumCheckNum >> prenumCheckAmount;

			if (prenumCheckNum == prenumDesired)
			{
				cout << "Check found!\nCheck number:\t" << prenumCheckNum << "\nCheck dollar amount:\t" << prenumCheckAmount << endl;
				break;//breaks out of for loop
			}
		}

		if (prenumCheckNum != prenumDesired)
		{
			cout << "Check not found..." << endl;
			break;//breaks switch statement if check not found
		}
		break;//breaks switch statement if check found
	}

	case 2:
	{
		cout << "You chose to use the sentinel file." << endl;
		cout << "Please enter the number of the check you wish to find." << endl;
		cin >> sentinelDesired;
		while (sentinelCheckNum != -9999 && sentinelCheckAmount != -9999)
		{
			sFile >> sentinelCheckNum >> sentinelCheckAmount;

			if (sentinelCheckNum == sentinelDesired)
			{
				cout << "Check found!\nCheck number:\t" << sentinelCheckNum << "\nCheck dollar amount:\t" << sentinelCheckAmount << endl;
				break;
			}

			if (sentinelCheckNum == -9999 && sentinelCheckAmount == -9999)
			{
				cout << "Check not found..." << endl;
				break;
			}
		}
		break;
	}

	default:
	{
		cout << "Invalid choice entered. Please try again.";
		break;
	}
	
	}

	return 0;
}