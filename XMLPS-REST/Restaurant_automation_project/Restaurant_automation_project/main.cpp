// XMLPS-REST Restaurant System
//main.cpp

#include "Restaurant.h"

using namespace std;

//stricmp function to compare strings
int stricmp(const char * pStr1, const char *pStr2)
{
	char c1, c2;
	int  v;

	do {
		c1 = *pStr1++;
		c2 = *pStr2++;
		/* The casts are necessary when pStr1 is shorter & char is signed */
		v = (unsigned int)tolower(c1) - (unsigned int)tolower(c2);
	} while ((v == 0) && (c1 != '\0') && (c2 != '\0'));

	return v;
}

//itoa function converts integer into null-terminated string 
char *itoa(int i, char *buffer, int n = 10)
{
	std::string str;
	do
	{
		str += (char)('0' + (i % 10)); i /= 10;
	} while (i != 0);

	std::reverse(str.begin(), str.end());

	strcpy(buffer, str.c_str());
	return buffer;
}

//Run the main restaurant Menu
int main()
{
	string choice;

	Order myRestaurant;

	while (true)
	{
		// A customer has entered the restaurant! Begin serving now
		myRestaurant.runRestaurant();

		cout << "Do you want to order again? (";
		setConsoleTextColor(Color_Yellow) << "Y";
		setConsoleTextColor(Color_White) << " to continue) : ";

		setConsoleTextColor(Color_Yellow);
		cin >> choice;
		setConsoleTextColor(Color_White);

		if (stricmp(choice.c_str(), "y") == 0 || stricmp(choice.c_str(), "Yes") == 0)
		{
			// Do nothing
		}
		else
		{
			break;
		}
	}

	system("pause");

	return 0;
}