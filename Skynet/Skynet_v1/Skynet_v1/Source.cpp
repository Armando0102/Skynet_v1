#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void main()
{
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand();
	int enemyLocation = ((randomNumber % 8) + 1) * 8;
	int ping = 1;
	int searchHighNum = 64;
	int searchLowNum = 0;
	int targetPrediction = ((searchHighNum - searchLowNum) / 2) + searchLowNum;
	bool found = false;

	cout << "Generate Random enemy location on 8x8 grid.....\nThe enemy is located at location #" << enemyLocation << " on grid\nInitializing Skynet HK-Aerial software....." << endl;
	while (found == false)
	{
		cout << "----------------------------------------------------\nSkynet HK-Aerial Radar sending out ping #" << ping << endl;
		if (targetPrediction < enemyLocation)
		{
			searchLowNum = targetPrediction + 1;
			ping++;
			cout << "The target location prediction of " << targetPrediction << " was lower than enemy location of " << enemyLocation << endl;
			targetPrediction = ((searchHighNum - searchLowNum) / 2) + searchLowNum;
		}
		else if (targetPrediction > enemyLocation)
		{
			searchLowNum = targetPrediction - 1;
			ping++;
			cout << "The target location prediction of " << targetPrediction << " was higher than enemy location of " << enemyLocation << endl;
			targetPrediction = ((searchHighNum + searchLowNum) / 2) - searchLowNum;
		}
		else if (targetPrediction == enemyLocation)
		{
			cout << "The enemy was hiding at location #" << enemyLocation << "\nTarget was found at location #" << targetPrediction << "\nSkynet HK-Aerial Software took " << ping << " predictions to find enemy" << endl;
			system("pause");
			found = true;
		}
	}
}