#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "budgetApp.h"
//#include "contact.h"



using namespace std;


void BudgetApp::manageBudgetApp()
{
mainMenuWindow:

    mainMenuUserSelection = displayMainMenu();

    switch (mainMenuUserSelection)
    {

    case '1':
        userHandler.registerNewUser();
        goto mainMenuWindow;
        break;

    case '2':

        loggedUser = userHandler.logIn();
        if (loggedUser.getId() != 0)
        {
            budgetMenuUserSelection = manageBudgetMenu();
        }
        goto mainMenuWindow;
        break;

    case '0':
        exit(0);
    }
}

char BudgetApp::displayMainMenu()
{
    char userSelection;

    system("cls");

    showConsoleTextInRed(".:Budget application:.");
    cout << endl << endl;
    cout << "1. Register" << endl;
    cout << "2. Log in" << endl;
    cout << "0. Close application" << endl << endl;
    cout << "Select a number to start an action..." << endl;

    do
    {
        userSelection = _getch();
    }
    while ((userSelection != '1') && (userSelection != '2') && (userSelection != '0'));

    return userSelection;
}

char BudgetApp::manageBudgetMenu()
{

    //int contactId;

budgetsWindow:
    //contactId = readContactsDataFromFile(currentUserInfo.id, allContacts);
    budgetMenuUserSelection = displayBudgetMenu();

    switch (budgetMenuUserSelection)
    {

    case '1':
        recordsHandler.addRecord(loggedUser.getId(), "income");
        goto budgetsWindow;
        break;

    case '2':
        recordsHandler.addRecord(loggedUser.getId(), "expenditure");
        goto budgetsWindow;
        break;

    case '3':
        recordsHandler.displaySummary("current", loggedUser.getId());
        goto budgetsWindow;
        break;

    case '4':
        recordsHandler.displaySummary("previous", loggedUser.getId());
        goto budgetsWindow;
        break;

    case '5':
        recordsHandler.displaySummary("custom", loggedUser.getId());
        goto budgetsWindow;
        break;

    case '6':
        userHandler.changePassword(loggedUser);
        goto budgetsWindow;

    case '0':
        return budgetMenuUserSelection;
    }
}

char BudgetApp::displayBudgetMenu()
{
    char userSelection;
    system("cls");

    showConsoleTextInRed(".:Manage budget:.");
    cout << "  User: " << loggedUser.getLogin();
    cout << endl << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expenditure" << endl;
    cout << "3. Show current month summary" << endl;
    cout << "4. Show previous month summary" << endl;
    cout << "5. Show custom range summary" << endl;
    cout << "6. Change password" << endl;
    cout << "0. Log off" << endl << endl;

    cout << "Select a number to start an action..." << endl;

    do
    {
        userSelection = getch();
    }
    while ((userSelection != '0') && (userSelection != '1') && (userSelection != '2') && (userSelection != '3')&& (userSelection != '4') && (userSelection != '5') && (userSelection != '6'));

    return userSelection;
}
/*
char ContactsBook::displaySearchMenu()
{
	char userSelection;

	system("cls");
	showConsoleTextInRed(".:Search contact:.");
	cout << endl << endl;
	cout << "1. By name..." << endl;
	cout << "2. By surname..." << endl;
	cout << "0. Back" << endl << endl;
	cout << "Select a number to start an action..." << endl;

	do
	{
		userSelection = getch();
	} while ((userSelection != '1') && (userSelection != '2') && (userSelection != '0'));

	return userSelection;
}
*/
void BudgetApp::showConsoleTextInRed(string header)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 12);
    cout << header;
    SetConsoleTextAttribute(console, 15);

}
