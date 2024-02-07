#include <iostream>
#include <stdlib.h>
#include "singly_linked_list.h"
#include <string>
#include "Queue_Array.h"
#include <cstdio>
#include <ctime>

using namespace std;

string UserName;
string Password;
int command;
node<User>* currentNode;
singly_linked_list<User> userlist; // store all user
singly_linked_list<Book> Booklist; // store all books
singly_linked_list<Magazine> Magazinelist; // store all magazines
int posOfCurrent;
Queue_Array queueDownloads(15); // download queue

void signUP();
void mainMenu();
void showDownloads();
void loginPage();
void searchPage();
void viewAll();
void addPage();

string fName, lName;

//home screen for the application
void homeScreen() //Home screen
{
    system("CLS");
    cout << "\n\t\t\t*************************************************" << endl;
    cout << "\t\t\t------Online Library Application Version 01------\n" << endl;
    cout << "\t\t\t*************************************************" << endl;
    cout << "\t\t\t\tWelcome to the online library !!!\n\n" << endl;
    cout << "\t\t\t\t  Log in\t\tPress 1" << endl;
    cout << "\t\t\t\t  New sign up\t\tPress 2" << endl;
    cout << "\t\t\t\t  Exit\t\t\tPress 3" << endl;

    //moveCursorFunc(12, 5);
    cout << "\n\t\t\tEnter the command : ";
    cin >> command;
    cin.ignore();

    switch (command)
    {
    case 1:
        loginPage();
        break;
    case 2:
        signUP();
        break;
    case 3:
        cout << "\n\t\t\t\t      ****Program closed****" << endl;
        cout << "\n\t\t\t------------------------------------------------\n" << endl;
        break;
    default:
        cout << "\n\t\t\t\t      ****wrong command****" << endl;
        homeScreen();
    }

}

//user login page
void loginPage() //Login page
{
    system("CLS");
    cout << "\n\t\t\t*************************************************" << endl;
    cout << "\t\t\t------Online Library Application Version 01------\n" << endl;
    cout << "\t\t\t*************************************************" << endl;
    cout << "\t\t\t\t      -----Login Page-----\n" << endl;
    cout << "\t\t\t\tUser Name\t: ";
    cin >> UserName;
    cout << "\n\t\t\t\tPassword\t: ";
    cin >> Password;

    cout << "\t\t1. Enter" << endl;
    cout << "\t\t2. Back" << endl;

    cout << "\n\t\t\tEnter the command : ";
    cin >> command;

    switch (command)
    {
    case 1:
    {
        verify userVerify = userlist.searchUser2(UserName,currentNode); // check whether user is present on the list

        if (userVerify.isThere)
        {
            if (userVerify.pass == Password)
            {
                cout << "\n\t\t\t--------------------------------------------" << endl;
                cout << "\t\t\t /////Welcome " + UserName + " ! to the library/////"<< endl;
                cout << "\t\t\t--------------------------------------------" << endl;
                posOfCurrent = userlist.posUserNode(UserName);
                Sleep(2000);
                mainMenu();
            }
            else
            {
                cout << "\n\t\t\t\t  ****User Password is wrong****" << endl;
                Sleep(2000);
                homeScreen();
            }
        }
        else
        {
            cout << "\n\t\t\t\t      ****No user found****" << endl;
            Sleep(2000);
            homeScreen();
        }
        break;
    }
    case 2:
        homeScreen();
        break;
    default:
        cout << "\n\t\t\t\t      ****wrong command****" << endl;
        Sleep(2000);
        loginPage();
    }

}

//page for signup new users
void signUP() //Signup page
{
    system("CLS");
    cout << "\n\t\t\t**************************************************" << endl;
    cout << "\t\t\t-----Online Library Application Version 01-----\n" << endl;
    cout << "\t\t\t**************************************************" << endl;
    cout << "\t\t\t-----New sign up-----\n" << endl;
    cout << "\t\t\tEnter first name\t\t: ";//not necc
    cin >> fName;
    cout << "\t\t\tEnter last name\t\t\t: ";//not necc
    cin >> lName;
    cout << "\t\t\tEnter user name\t\t\t: ";
    cin >> UserName;
    cout << "\t\t\tEnter new password\t\t: ";
    cin >> Password;

    cout << "\t\t1. Create" << endl;
    cout << "\t\t2. Back" << endl;


    cout << "\n\t\t\tEnter the command : ";
    cin >> command;

    switch (command)
    {
    case 1:
        //need to search the all user names and check whether have a user with same name
        //if there is       - print user name already taken
        //if there is not   - create a user and add password

    {
        bool isNode = userlist.searchUser(UserName);
        if (isNode == true)
        {
            cout << "\n\t\t\t\t    ****User name already taken****" << endl;
            Sleep(2000);
        }
        else
        {
            User USname(UserName, Password);
            
            userlist.insertLast(USname);

            cout << "\n\t\t\t\t      ****User created****" << endl;
            Sleep(2000);
        }
    }
        loginPage();
        break;
    case 2:
        homeScreen();
        break;
    case 3:
        cout << "\n\t\t\t\t      ****Program closed****" << endl;
        break;
    default:
        cout << "\n\t\t\t\t      ****Wrong command****" << endl;
    }
}

//page with main fucntion of the library
void mainMenu()
{
    system("CLS");
    cout << "\n\t\t\t**************************************************" << endl;
    cout << "\t\t\t-------Online Library Application Version 01------\n" << endl;
    cout << "\t\t\t**************************************************" << endl;
    cout << "\n\t\t\t\t      -----Main Menu-----\n" << endl;
    cout << "\t\t\t\t\t1. Search" << endl;
    cout << "\t\t\t\t\t2. View" << endl;
    cout << "\t\t\t\t\t3. Add" << endl;
    cout << "\t\t\t\t\t4. Downloads" << endl;
    cout << "\t\t\t\t\t5. Log out" << endl;

    cout << "\n\t\t\tEnter the command : ";
    cin >> command;

    switch (command)
    {
    case 1:
        searchPage();
        break;
    case 2:
        viewAll();
        break;
    case 3:
        addPage();
        break;
    case 4:
        showDownloads();
        break;
    case 5:
        homeScreen();
        break;
    default:
        cout << "\n\t\t\t\t      ****wrong command****" << endl;
        mainMenu();
    }
}

//page to search book materials
void searchPage()
{
    system("CLS");
    cout << "\n\t\t\t**************************************************" << endl;
    cout << "\t\t\t-----Online Library Application Version 1-----\n" << endl;
    cout << "\t\t\t**************************************************" << endl;
    cout << "\t\t\t\t      -----Search Page-----\n" << endl;
    cout << "\t\t\t\t\t1. Search books" << endl;
    cout << "\t\t\t\t\t2. Search magazines" << endl;
    cout << "\t\t\t\t\t3. Back" << endl;

    int command;
    cout << "\n\t\t\tEnter the command : ";
    cin >> command;
    cin.ignore();

    switch (command)
    {
    case 1://search books
    {
        system("CLS");
        cout << "\n\t\t\t**************************************************" << endl;
        cout << "\t\t\t-----Online Library Application Version 1-----\n" << endl;
        cout << "\t\t\t**************************************************" << endl;
        cout << "\t\t\t\t      -----Search Page-----\n" << endl;
        cout << "\t\t\t\t\t1. Search by Name" << endl;
        cout << "\t\t\t\t\t2. Search by author" << endl;
        cout << "\t\t\t\t\t3. Back" << endl;

        cout << "\n\t\t\tEnter the command : ";
        int command1;
        cin >> command1;
        cin.ignore();

        switch (command1)
        {
        case 1:
        {
            string bookName;
            cout << "\n\t\t\t\t      ----:Search by name:----" << endl;
            cout << "\n\t\t\t\tEnter the book name: ";
            getline(cin, bookName);

            bool bookFound = Booklist.searchBooks(bookName);

            int command2;
            if (bookFound==true)
            {

                cout << "\n\t Download the book \t- press 1" << endl;
                cout << "\n\t Back \t\t\t- press 2" << endl;

                cout << "\n\tEnter the command : ";
                cin >> command2;
                cin.ignore();
            }
            else
            {
                cout << "\n\t\t\t\t      ****Book not found****" << endl;
                Sleep(2000);
                command2 = 2;
            }
            downMat bookDown;
            string dateDown;

            switch (command2)
            {
            case 1:
                //int result = userlist.searchDownloadedBooks(posOfCurrent);
                queueDownloads.enQueue(bookName);

                cout << "\n\t\t\t      *Book added to the downloading queue*" << endl;

                cout << "\n\t\t\t\t_________Book downloaded_________" << endl;
                Sleep(2000);

                //current date return
                time_t rawtime;
                tm timeinfo;
                char buffer[80];

                time(&rawtime);
                localtime_s(&timeinfo, &rawtime);

                strftime(buffer, 80, "%Y/%m/%d", &timeinfo);
                dateDown = buffer;

                //setting structure
                bookDown.date = dateDown;
                bookDown.name = bookName;
                userlist.addBooksUser(bookDown, posOfCurrent);
                searchPage();
                break;

            case 2:
                searchPage();
                break;

            default:
                cout << "\n\t\t\t\t      ****wrong command****" << endl;
                Sleep(2000);
                mainMenu();
            }
            break;
        }
        case 2:
        {
            string authorName;
            string bookName;
            cout << "\n\t\t\t\t      ----:Search by author:----" << endl;
            cout << "\n\t\t\t\tEnter the author name: ";
            getline(cin, authorName);

            cout << "\n\t\t\tBooks written: \n" << endl;

            bool bookFound=Booklist.searchBooksAuthor(authorName);

            int command3;
            if (bookFound==true)
            {
                cout << "\n\n\t\tEnter the book name : ";
                getline(cin, bookName);

                Booklist.searchBooks(bookName);

                cout << "\n\t Download the book \t- press 1" << endl;
                cout << "\n\t Back \t\t\t- press 2" << endl;

                cout << "\n\tEnter the command : ";
                cin >> command3;
                cin.ignore();
            }
            else
            {
                cout << "\n\t\t\t\t      ****Book not found****" << endl;
                Sleep(2000);
                command3 = 2;
            }
            string dateDown;
            downMat bookDown;

            switch (command3)
            {
            case 1:
                //int result = userlist.searchDownloadedBooks(posOfCurrent);
                queueDownloads.enQueue(bookName);

                cout << "\n\t\t\t      *Book added to the downloading queue" << endl;

                cout << "\n\t\t\t\t_________Book downloaded_________" << endl;
                Sleep(2000);

                //current date return
                time_t rawtime;
                tm timeinfo;
                char buffer[80];

                time(&rawtime);
                localtime_s(&timeinfo, &rawtime);

                strftime(buffer, 80, "%Y/%m/%d", &timeinfo);
                dateDown = buffer;

                //setting structure
                bookDown.date = dateDown;
                bookDown.name = bookName;
                userlist.addBooksUser(bookDown, posOfCurrent);
                searchPage();
                break;

            case 2:
                searchPage();
                break;

            default:
                cout << "\n\t\t\t\t      ****wrong command****" << endl;
                Sleep(2000);
                mainMenu();
            }
            break;
        }
        case 3:
            mainMenu();
            break;

        default:
            cout << "\n\t\t\t\t      ****wrong command****" << endl;
            Sleep(2000);
            searchPage();
        }
        break;
    }

    case 2://search magazines
    {
        system("CLS");
        cout << "\n\t\t\t**************************************************" << endl;
        cout << "\t\t\t-----Online Library Application Version 1-----\n" << endl;
        cout << "\t\t\t**************************************************" << endl;
        cout << "\t\t\t\t      -----Search Page-----\n" << endl;
        string magName;
        cout << "\n\t\t\t\tEnter the magazine name: ";
        getline(cin, magName);

        bool magFound = Magazinelist.searchMagazines(magName);

        int command4;
        if (magFound)
        {
            cout << "\n\t Download the Magazine \t- press 1" << endl;
            cout << "\n\t Back \t\t\t- press 2" << endl;

            cout << "\n\tEnter the command : ";
            cin >> command4;
            cin.ignore();
        }
        else
        {
            cout << "\n\t\t\t\t      ****Magazine not found****" << endl;
            Sleep(2000);
            command4 = 2;
        }
        string dateDown;
        downMat magDown;

        switch (command4)
        {
        case 1:
            //int result = userlist.searchDownloadedBooks(posOfCurrent);
            queueDownloads.enQueue(magName);

            cout << "\n\t\t\t      *Magazine added to the downloading queue*" << endl;

            cout << "\n\t\t\t\t_________Magazine downloaded_________" << endl;
            Sleep(2000);

            //return date
            time_t rawtime;
            tm timeinfo;
            char buffer[80];

            time(&rawtime);
            localtime_s(&timeinfo, &rawtime);

            strftime(buffer, 80, "%Y/%m/%d", &timeinfo);
            dateDown = buffer;

            //setting structure
            magDown.date = dateDown;
            magDown.name = magName;
            userlist.addMagazineUser(magDown, posOfCurrent);
            searchPage();
            break;

        case 2:
            searchPage();
            break;

        default:
            cout << "\n\t\t\t\t      ****wrong command****" << endl;
            Sleep(2000);
            mainMenu();
        }
        break;
    }

    case 3:
        mainMenu();
        break;

    default:
        cout << "\n\t\t\t\t      ****wrong command****" << endl;
        Sleep(2000);
        mainMenu();
    }

}

//page to add book materials to library
void addPage()
{
    system("CLS");
    cout << "\n\t\t\t**************************************************" << endl;
    cout << "\t\t\t-----Online Library Application Version 1-----\n" << endl;
    cout << "\t\t\t**************************************************" << endl;
    cout << "\n\t\t\t\t      ------Add Page------\n" << endl;
    cout << "\t\t\t\t      Type of material" << endl;
    cout << "\n\t\t\t\t\t1. Book" << endl;
    cout << "\t\t\t\t\t2. Magazines" << endl;
    cout << "\t\t\t\t\t3. videos" << endl;
    cout << "\t\t\t\t\t4. Audio books" << endl;
    cout << "\t\t\t\t\t5. Back" << endl;

    cout << "\n\t\t\t\tEnter the command : ";
    cin >> command;
    cin.ignore();
    cout << "\n";

    string title, author, authors, date, frcyofpb, publishedYear, type;
    int pages;

    switch (command)
    {
    case 1:
        cout << "\tEnter the book details: " << endl;
        cout << "\n\t     Title           : ";
        getline(cin, title);

        cout << "\t     Author          : ";
        getline(cin, author);

        cout << "\t     Published year  : ";
        cin >> publishedYear;
        cin.ignore();
        
        cout << "\t     Type            : ";
        getline(cin, type);

        cout << "\t     Pages           : ";
        cin >> pages;

        cout << "\n\t\t1. Confirm";
        cout << "\n\t\t2. Cancel";
        int command2;
        cout << "\n\tEnter the comand : ";
        cin >> command2;

        switch (command2)
        {
        case 1:
        {
            Book newBook(title, author, publishedYear, pages, type);
            Booklist.insertLast(newBook);
            addPage();
            break;
        }
        case 2:
            mainMenu();
            break;

        default:
            mainMenu();
        }
        break;

    case 2:
        cout << "\tEnter the magazine details: " << endl;
        cout << "\n     Title                   : ";
        getline(cin, title);

        cout << "\n     Type                    : ";
        getline(cin, type);

        cout << "\n     Authors                 : ";
        getline(cin, author);

        cout << "\n     Frequancy of Publication: ";
        getline(cin, frcyofpb);

        cout << "\n     Date                    : ";
        cin >> date;
        cin.ignore();

        cout << "\n\t1. Confirm";
        cout << "\n\t2. Cancel";
        int command3;
        cout << "\nEnter the comand : ";
        cin >> command3;

        switch (command3)
        {
        case 1:
        {
            Magazine newMagazine(title, author, date, frcyofpb, type);
            Magazinelist.insertLast(newMagazine);
            addPage();
            break;
        }
        case 2:
            mainMenu();
            break;

        default:
            mainMenu();
        }


        break;

    case 3:
        cout << "Name: ";
        cout << "Creator: ";
        cout << "Year: ";
        cout << "Month: ";
        cout << "Day: ";
        break;

    case 5:
        mainMenu();
        break;

    default:
        "\t\t\t\t      ****Wrong command****";
        Sleep(2000);
        mainMenu();//
    }
}

//page to print all book materials
void viewAll()
{
    system("CLS");
    cout << "\n\t\t\t**************************************************" << endl;
    cout << "\t\t\t-----Online Library Application Version 1-----\n" << endl;
    cout << "\t\t\t**************************************************" << endl;
    cout << "\t\t\t\t      -----View Page------" << endl;
    cout << "\n\t\t\t\t\t1. Books" << endl;
    cout << "\t\t\t\t\t2. Magazines" << endl;
    cout << "\t\t\t\t\t3. Videos" << endl;
    cout << "\t\t\t\t\t4. Audio Books" << endl;
    cout << "\t\t\t\t\t5. Back" << endl;

    cout << "\n\t\t\tEnter the command : ";
    cin >> command;
    cout << "\n";

    switch (command)
    {
    case 1:
    {
        cout << "\n\t\tAll available books : \n" << endl;
        Booklist.sortingBooks();

        cout << "\n\n\t1.Back" << endl;

        int command2;
        cout << "\tEnter the command : ";
        cin >> command2;
        cout << "\n";

        switch (command2)
        {
        case 1:
            viewAll();
            break;
        default:
            cout << "\t\t\t\t****Wrong command...Back to main menu****" << endl;
            Sleep(2000);
            mainMenu();
        }
        break;
    case 2:

        cout << "\n\t\tAll available magazines : \n" << endl;
        Magazinelist.sortingMagazines();

        cout << "\n\n\t1.Back" << endl;

        int command3;
        cout << "\tEnter the command : ";
        cin >> command3;
        cout << "\n";

        switch (command3)
        {
        case 1:
            system("CLS");
            viewAll();
            break;
        default:
            cout << "\t\t\t\t****Wrong command...Back to main menu****" << endl;
            Sleep(2000);
            system("CLS");
            mainMenu();
        }
        break;
    }
    case 3:
        cout << "\t\tAll available Videos : \n" << endl;
        cout << "\n\t1.Back" << endl;

        int command4;
        cout << "\tEnter the command : ";
        cin >> command4;
        cout << "\n";

        switch (command4)
        {
        case 1:
            viewAll();
            break;
        default:
            cout << "\t\t\t\t****Wrong command...Back to main menu****" << endl;
            Sleep(2000);
            mainMenu();
        }
        break;
    case 4:
        cout << "\t\tAll available Audio Books : \n" << endl;
        cout << "\n\t1.Back" << endl;

        int command5;
        cout << "\tEnter the command : ";
        cin >> command5;
        cout << "\n";

        switch (command5)
        {
        case 1:
            viewAll();
            break;
        default:
            cout << "\t\t\t\t****Wrong command...Back to main menu****" << endl;
            Sleep(2000);
            mainMenu();
        }
        break;
    case 5:
        mainMenu();
        break;
    default:
        "\t\t\t\t      ****Wrong command****";
        Sleep(2000);
        viewAll();
        break;
    }

}

//page to print all downloads done by a user
void showDownloads()
{
    system("CLS");
    cout << "\n\t\t\t**************************************************" << endl;
    cout << "\t\t\t-----Online Library Application Version 1-----\n" << endl;
    cout << "\t\t\t**************************************************" << endl;
    cout << "\n\t\t\tList of the material download history\n" << endl;

    userlist.showDownloadUser(posOfCurrent);

    cout << "\n\t\t\t1. Back to main menu" << endl;

    cout << "\n\t\t\tEnter the command : ";
    cin >> command;
    cout << "\n";

    switch (command)
    {
    case 1:
        system("CLS");
        mainMenu();
        break;

    default:
        system("CLS");
        mainMenu();
    }
    
}

int main()
{
    //adding default users
    User DefaultUser("Masha", "230");
    userlist.insertFirst(DefaultUser);
    User DefaultUser2("Rush", "429");
    userlist.insertFirst(DefaultUser2);

    //adding default books
    Book DefaultBook1("Data Structures", "M.T.Goodrich", "2009", 738, "Educational");
    Booklist.insertLast(DefaultBook1);
    Book DefaultBook2("The ring", "C.H.Riley", "2018", 68, "Adventure");
    Booklist.insertLast(DefaultBook2);
    Book DefaultBook3("Love and war", "D.C.Carely", "2011", 1023, "Novel");
    Booklist.insertLast(DefaultBook3);

    //adding default magazines
    Magazine DefaultMagazine1("My Vehicle", "Jerry", "12/10/2015", "Annually", "Technolagy");
    Magazinelist.insertLast(DefaultMagazine1);
    Magazine DefaultMagazine2("Lifestyle", "Ann", "14/12/2020", "Monthly", "Fashion");
    Magazinelist.insertLast(DefaultMagazine2);

    homeScreen();
    
    return 0;
}


