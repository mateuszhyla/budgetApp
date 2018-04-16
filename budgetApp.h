#include <iostream>
#include <vector>
#include "usersHandler.h"
#include "recordsHandler.h"

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

	RecordsHandler recordsHandler;
	User loggedUser;
	char displayMainMenu();
	char displayBudgetMenu();
	char manageBudgetMenu();
	//char displaySearchMenu();
	void showConsoleTextInRed(string);

};
