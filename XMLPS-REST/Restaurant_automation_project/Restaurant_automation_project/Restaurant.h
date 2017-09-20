// XMLPS-REST Restaurant System
//Restaurant.h

#ifndef __RES_H
#define __RES_H

#include <iostream> // std::cin, std::cout
#include <fstream> // std::ofstream
#include <cstdio> // stricmp()
#include <iomanip> // std::setw(), std::setfill()
#include <string> // std::string
#include <cctype> // isdigit()
#include <vector> // std::vector
#include <cstdlib> // system(), itoa(), rand(), srand()
#include <conio.h> // getchr()
#include <ctime> // time()
#include <sstream> // std::stringstream
#include <cstring> // stricmp()
#include <windows.h> // GetStdHandle(), SetConsoleTextAttribute()
#include <algorithm> // std::reverse()

using namespace std;

//function to set texts color
static std::ostream& setConsoleTextColor(int myColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, myColor);

	return cout;
}

// Some constants
const int TOTAL_ITEMS = 12;
const int ZERO_FOR_CAL = 0; // Zero for cal(calculation)
const int ONE_FOR_CAL = 1;
const int TWO_FOR_CAL = 2;
const int THREE_FOR_CAL = 3;
const int FOUR_FOR_CAL = 4;
const int MINUS_ONE_FOR_CAL = -1;
const double WA_RESTAURANT_TAX = 0.078;

// User-defined restaurant constants
const int RESTAURANT_APPETIZER_ITEMS = 3;
const int RESTAURANT_MAIN_DISHES_ITEMS = 3;
const int RESTAURANT_BEVERAGES_ITEMS = 3;
const int RESTAURANT_DESSERTS_ITEMS = 3;

// General item structure for all restaurants
struct Item_Raw
{
	char name[100];
	char description[500];
	double price;
};

// An item structure for an user-defined restaurant
class Food
{
private:
	std::string name;
	std::string description;
	double price;

public:
	void importItem(const Item_Raw &item);

	void setName(std::string _name);

	void setDescription(std::string _description);

	void setPrice(double _price);

	void setItem(std::string _name, std::string _description, double _price);

	std::string getName() const;

	std::string getDescription() const;

	double getPrice() const;
};


class Order
{
private:
	Food restaurantAppetizerItems[RESTAURANT_APPETIZER_ITEMS];
	Food restaurantMainDishesItems[RESTAURANT_MAIN_DISHES_ITEMS];
	Food restaurantBeveragesItems[RESTAURANT_BEVERAGES_ITEMS];
	Food restaurantDessertsItems[RESTAURANT_DESSERTS_ITEMS];

public:

	// The receipt structure for the user-defined Order
	struct Receipt
	{
		Receipt()
		{
			totalPrice = 0;
			taxPrice = 0;
			gratuity = 0;
		}

		vector<Food> itemsOrdered;

		double totalPrice;
		double taxPrice;
		double gratuity;
	};

	// Default constructor
	Order();

	// Default constructor will also call this function
	void initialize();

	// Show restaurant menu (If bHelp is toggled, the restaurant will show the customer how food items are ordered)
	void showMenu(bool bHelp = false);

	// Show restaurant help
	void showHelp();

	// Validate the customer's choice
	// Returns -1 if fails, 0 if no action should be taken, and 1 if successful
	int getInput(Food &theItem);

	// Formatting function
	static std::string printName(const std::string &s, int len = 0);

	// Generates a Html Receipt
	static std::string generateReceiptHtml(const Receipt &myReceipt);

	// A customer has entered the restaurant. Run the restaurant
	void runRestaurant();

private:

	// A helper function for Order::getInput()
	// Return 0 if successful, 1 to proceed to order, -1 if fails
	int getDescription(unsigned int category, unsigned int item_id);

	// A helper function for Order::getInput()
	// Return 1 if successful, -1 if fails
	int getPrice(unsigned int category, unsigned int item_id, Food &theItem);

	// A helper function for Order::getInput()
	// Return false (0) if no action should be taken, and return true (1) otherwise
	static int descriptionOrder(const Food &item);

	// A helper function for Order::getInput() and Order::getPrice()
	// This indicates that an order is completed. 
	static void completeOrder(const Food &item, Food &theItem);
};

enum
{
	Color_White = 7,
	Color_Yellow = 14,
	Color_Purple = 13,
	Color_Green = 10,
	Color_Bright_White = 15,
	Color_Light_Blue = 11,
	Color_Pink_Blue_Background = 23,
	Color_Red = 12
};

// User-defined restaurant items
enum RestaurantAppetizer
{
	Restaurant_Appetizer_1,
	Restaurant_Appetizer_2,
	Restaurant_Appetizer_3
};

enum RestaurantMainDishes
{
	Restaurant_Main_Dishes_1,
	Restaurant_Main_Dishes_2,
	Restaurant_Main_Dishes_3
};

enum RestaurantBeverages
{
	Restaurant_Beverages_1,
	Restaurant_Beverages_2,
	Restaurant_Beverages_3
};

enum RestaurantDesserts
{
	Restaurant_Desserts_1,
	Restaurant_Desserts_2,
	Restaurant_Desserts_3
};

// Global Order Appetizer Items
enum
{
	Item_Crispy_Crab_Wontons = 0,
	Item_Presunto_Pot_Stickers,
	Item_Crab_Cakes
};

// Global Order Main Dishes Items
enum
{
	Item_Presunto_And_Ricotta_Flatbread = Item_Crab_Cakes + 1,
	Item_Fresh_Kale_Salad,
	Item_Shrimp_Scampi,
};

// Global Order Beverages Items
enum
{
	Item_Fresh_Orange_Juice_Infused_With_Passion_Fruit_Seeds = Item_Shrimp_Scampi + 1,
	Item_Cold_Green_Ice_Tea,
	Item_Flavored_Lemonades
};

// Global Order Desserts Items
enum
{
	Item_Lemoncello_Cream_Torte = Item_Flavored_Lemonades + 1,
	Item_Chocolate_Tower_Truffle_Cake,
	Item_Warm_Apple_Crisp
};

#endif