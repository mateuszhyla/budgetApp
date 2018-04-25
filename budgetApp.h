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
	char displayMainMenu();
	char displayBudgetMenu();
	char manageBudgetMenu();

	UsersHandler userHandler;
	RecordsHandler recordsHandler;
	User loggedUser;
	void showConsoleTextInRed(string);
};
