
#include "GameAlgorithms.h"

using namespace std;

int getUserInt()
{
	int x = 0;
	while (!(cin >> x)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}
	cin.clear();
	return x;

}
