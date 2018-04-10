#include <iostream>
#include <vector>
#include "usersHandler.h"
//#include "contactsHandler.h"

using namespace std;

class BudgetApp
{

public:
	void manageBudgetApp();

private:
    char mainMenuUserSelection;
	char budgetMenuUserSelection;
	//char searchMenuUserSelection;
	UsersHandler userHandler;
	//ContactsHandler contactHandler;
	User loggedUser;
	char displayMainMenu();
	char displayBudgetMenu();
	char manageBudgetMenu();
	//char displaySearchMenu();
	void showConsoleTextInRed(string);

};
