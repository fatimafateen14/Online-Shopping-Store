#include <iostream>   // libraries 
#include <fstream>
#include <string>
#include <cstdlib> // For system("cls")
#include <windows.h>
using namespace std;

//colours declaration
const string RED = "\033[31m";
const string YELLOW = "\033[33m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string RESET = "\033[0m";
//for loading bar
char bar = 219;

//calculating item with their quantites
double calculateTotal(int quantity, double price)
{
    return quantity * price;
}
//============================================Base Class Mystore============================================
class Mystore {
protected:
    //member variables
    string fullname;
    string contact;
    string address;
    string username;
    string password;
    ofstream myfile;
    string user, pass;

public:
    //constructor
    Mystore() {
        myfile.open("cart.txt");
    }

    //--------------------------------Main page------------------------------------
    void displayMainPage() {
    mainpage:
        cout << CYAN << "\n\n\n\t\t\t          * * * MAIN PAGE * * *" << RESET << endl;
        cout << "\n\n\n\t\t\t[1] Register \t\t\t[2] Login" << endl;
        cout << "\n\n\n\t\t\t[Any Key] Exit" << endl;
        cout << "\n\n\n\t\t\tEnter Your Choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            registerAccount();
            break;
        case 2:
            login();
            break;
        default:
            exit(0);
        }
    }

    //-------------------functions for exceptional handling--------------------------------
    bool Alphabet(const string& str) {
        for (char c : str) {
            if (!isalpha(c) && c != ' ') return false;
        }
        return true;
    }

    bool Numeric(const string& str) {
        for (char c : str) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    //----------------------------registration page-----------------------------------
    void registerAccount() {
        system("cls");
        cout << CYAN << "\n\n\n\t\t\t==============================================" << RESET << endl;
        cout << CYAN << "\t\t\t          * * * REGISTRATION * * *" << RESET << endl;
        cout << CYAN << "\t\t\t==============================================" << RESET << endl;
        while (true) {
            cout << "\n\n\n\t\t\tName   :   ";
            cin.ignore();
            getline(cin, fullname);
            if (Alphabet(fullname)) break;
            cout << RED << "\n\n\n\t\t\t Invalid! Name must not contain numeric value" << RESET << endl;
        }
        while (true) {
            cout << "\t\t\tContact Number   :   ";
            getline(cin, contact);
            if (Numeric(contact)) break;
            cout << RED << "\n\n\n\t\t\t Invalid! contact number must be numeric" << RESET << endl;
        }
        cout << "\t\t\tAddress   :   ";
        getline(cin, address);

        cout << "\n\n\n\t\t\tUsername   :   ";
        getline(cin, username);

        cout << "\t\t\tPassword   :   ";
        getline(cin, password);

        Sleep(500);
        cout << "\n\n\n\t\t\tCreating Account...." << endl;
        cout << "\n\t\t\t";
        //this loop is displaying a loading bar
        for (int j = 0; j < 30; j++) {
            Sleep(200);
            cout << YELLOW << (char)219 << RESET;
        }

        cout << "\n\n\n\t\t\tAccount Registered! " << endl;
        displayMainPage(); //compiler goes to the main page again
    }
    //--------------------------login page----------------------------------------------
    void login() {
        system("cls");
        cout << CYAN << "\n\n\n\t\t\t==============================================" << RESET << endl;
        cout << CYAN << "\t\t\t          * * * LOGIN * * * " << RESET << endl;
        cout << CYAN << "\t\t\t==============================================" << RESET << endl;
        cout << "\n\n\n\t\t\tUsername   :   ";
        cin.ignore();
        getline(cin, user);
        cout << "\n\t\t\tPassword   :   ";
        getline(cin, pass);

        if (user == username && pass == password) {
            cout << "\n\n\n\t\t\tLogging In " << endl;
            cout << "\n\t\t\t";
            //loop for loading  bar
            for (int j = 0; j < 27; j++) {
                Sleep(200);
                cout << YELLOW << (char)219 << RESET;
            }
            cout << "\n\t\t\tYou Have Logged In Your Account" << endl;
            Sleep(500);
        }
        else {
            cout << RED << "\n\n\n\t\t\tInvalid username or password!" << RESET << endl;
            displayMainPage();
        }
    }

    //--------------------------------product category page-----------------------------------------
    void displayProducts() {
        system("cls");
        cout << CYAN << "\n\n\n\t\t\t=======================================" << RESET << endl;
        cout << CYAN << "\t\t\t     WELCOME DEAR " << RESET << YELLOW << username << "!" << RESET << endl;
        cout << CYAN << "\t\t\t=======================================" << RESET << endl;
        Sleep(1000);

        cout << "\n\n\n\t\t\tSHOP BY CATEGORY:" << endl;
        cout << "\n\t\t\t[1] CLOTHES" << endl;
        cout << "\n\t\t\t[2] FOOTWEAR" << endl;
        cout << "\n\t\t\t[3] MAKEUP" << endl;
        cout << "\n\n\t\t\tEnter Category: ";
    }

    //--------------------------address details page ---------------------------------
    void addressdetails() {
        system("cls");
        cout << CYAN << "\n\n\n\t\t\t           * * * * CHECKOUT * * * *" << RESET << endl;
        cout << CYAN << "\n\n\n\t\t\t==============================================" << RESET << endl;
        cout << CYAN << "\t\t\t         * * * * Delivery Address * * * *" << RESET << endl;
        cout << CYAN << "\t\t\t==============================================" << RESET << endl;
        cout << "\n\t\t\tNAME     :   " << fullname << endl;
        cout << "\n\t\t\tCONTACT  :   " << contact << endl;
        cout << "\n\t\t\tADDRESS  :   " << address << endl;
    }

    //-------------------------- pure virtual functions ----------------------------------
    virtual void displayProductPage() = 0;
    virtual void displayBillingPage() = 0;
    virtual void displayCheckoutPage() = 0;
    virtual void displayPaymentPage() = 0;
    virtual int calculateGrandTotal() = 0;
};

//========================================== Clothes Class =========================================
class Myclothes : public Mystore {
private:
    // default member initializer
    int id = 0;
    int i = 0;
    int pay = 0;
    int otp = 0;
    string idnum[50] = {};
    string cardnum = "";
    string product[10] = {};
    int total[10] = {};
    int qty[10] = {};
    int limit = 0;
    int price[10] = {};

public:
    // Constructor
    Myclothes() {}

    // Parameterized constructor
    Myclothes(int ID, int I, int PAY, int OTP1, const string& CARDNUM, int LIMIT) {
        id = ID;
        i = I;
        pay = PAY;
        otp = OTP1;
        cardnum = CARDNUM;
        limit = LIMIT;
    }
    //----------------------------- display product page-------------------------------------------
    void displayProductPage() override {
        system("cls");
    clothes:
        cout << endl;
        cout << CYAN << "\n\n\n\t\t\t=============================================================" << RESET << endl;
        cout << CYAN << "\t\t\t      * * * * * * * * * * * C L O T H E S * * * * * * * * * *" << RESET << endl;
        cout << CYAN << "\t\t\t=============================================================" << RESET << endl;
        Sleep(1000);
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\t|                        WOMEN                            |" << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\t| ID |                  NAME                    | price   |" << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\t| 1  | Stitched                                 | Rs 8000 |" << endl;
        cout << "\t\t\t| 2  | UnStitched                               | Rs 5000 |" << endl;
        cout << "\t\t\t| 3  | Denim Jacket                             | Rs 9000 |" << endl;
        cout << "\t\t\t| 4  | Denim Pants                              | Rs 7000 |" << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\t|                         MEN                             |" << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\t| ID |                  NAME                    | price   |" << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\t| 5  | Hoodies                                  | Rs 8000 |" << endl;
        cout << "\t\t\t| 6  | shirt                                    | Rs 5000 |" << endl;
        cout << "\t\t\t| 7  | Jacket                                   | Rs 9000 |" << endl;
        cout << "\t\t\t| 8  | Jeans                                    | Rs 7000 |" << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\tEnter ID Number   :   ";
        cin >> id;

        switch (id)
        {
        case 1:
            idnum[i] = "1";
            product[i] = "Stitched";
            price[i] = 8000;
            break;
        case 2:
            idnum[i] = "2";
            product[i] = "UnStitched";
            price[i] = 5000;
            break;
        case 3:
            idnum[i] = "3";
            product[i] = "denim jacket";
            price[i] = 9000;
            break;
        case 4:
            idnum[i] = "4";
            product[i] = "denim pants";
            price[i] = 7000;
            break;
        case 5:
            idnum[i] = "5";
            product[i] = "hoodies";
            price[i] = 8000;
            break;
        case 6:
            idnum[i] = "6";
            product[i] = "Shirt";
            price[i] = 5000;
            break;
        case 7:
            idnum[i] = "7";
            product[i] = "jacket";
            price[i] = 9000;
            break;
        case 8:
            idnum[i] = "8";
            product[i] = "jeans";
            price[i] = 7000;
            break;
        default:
            cout << RED << "\n\t\t\t\t\t\tInvalid ID number! " << RESET << endl;
            goto clothes;
        }
    }
    //--------------------------------------billing page---------------------------------------------
    void displayBillingPage() override {
        cout << "\n\t\t\tEnter Quantity   :   ";
        cin >> qty[i];

        total[i] = calculateTotal(qty[i], price[i]);
        cout << "\n\t\t\tYour Total Payment is    :" << total[i] << endl;

        Sleep(2000);
        int f;
        cout << "\n\n\n\t\t\tProduct Added To Cart!" << endl;
        cout << "\n\n\n\t\t\tWant to Remove The Product From The Cart?" << endl;
        cout << "\t\t\t [1]YES               [2]NO" << endl;
        cin >> f;
        if (f == 1) {
            cout << RED << "\n\n\n\t\t\tYour Product " << product[i] << "  Is Removed From Cart" << RESET << endl;
        }
        else
            cout << "\n\n\n\t\t\t Billing In Process" << endl;
    }

    //-----------------------------checkout page--------------------------------------------------
    void displayCheckoutPage() override {
    checkout:
        system("cls");
        Sleep(2000);
        cout << "\n\n\n\t\t\t  CHECKING OUT....." << endl;
        cout << "\t\t\t ";
        for (int j = 0; j < 30; j++)
        {
            Sleep(200);
            cout << YELLOW << bar << RESET;
        }

        Sleep(2000);
        system("cls");
        cout << CYAN << "\n\n\n\t\t\t==============================================" << RESET << endl;
        cout << CYAN << "\t\t\t      * * * * Order Details * * * *" << RESET << endl;
        cout << CYAN << "\t\t\t==============================================" << RESET << endl;
        for (int k = 0; k < i; k++) {
            cout << "\n\n\n\t\t\t_" << endl;
            cout << "\n\t\t\t" << product[k] << " PRODUCT NAME ";
            myfile << "\n\t\t\t" << product[k] << " PRODUCT NAME ";
            cout << "\n\t\t\t" << qty[k] << " Qty";
            myfile << "\n\t\t\t" << qty[k] << " Qty";
            cout << "\n\t\t\t" << price[k] << " Price ";
            myfile << "\n\t\t\t" << price[k] << " Price ";
            cout << "\n\t\t\t" << total[k] << " amount ";
            myfile << "\n\t\t\t" << total[k] << " amount ";
            cout << "\n\n\n\t\t\t_" << endl;
        }

        cout << "\n\n\n\t\t\t  Billing In Process" << calculateGrandTotal() << endl;
        Sleep(2000);
    }

    //------------------------------------payment page--------------------------------
    void displayPaymentPage() override {
        Sleep(1000);
    payment:
        system("cls");
        cout << CYAN << "\n\n\n\t\t\t        * * * * Payment Method * * * *" << RESET << endl;
        cout << "\n\n\t\t\t [1] CASH ON DELIVERY \t\t\t [2] CARD PAYMENT" << endl;
        cout << "\n\n\t\t\tEnter Payment Method   :   ";
        cin >> pay;

        switch (pay)
        {
            //---------------------cash on delivery -----------------------------------
        case 1:
            cout << "\n\n\n\t\t\tPLACING ORDER......." << endl;
            cout << "\t\t\t ";
            for (int j = 0; j < 30; j++)
            {
                Sleep(200);
                cout << YELLOW << bar << RESET;
            }
            cout << "\n\n\n\t\t\tYour Order Is Placed Successfully!" << endl;
            Sleep(1000);
            cout << "\n\n\n\t\t\tParcel will be delivered within 3-5 days" << endl;
            Sleep(2000);
            cout << "\n\n\n\t\t\t THANK YOU FOR SHOPPING!!!" << endl;
            exit(0);

            //------------------------------ card payment--------------------------------------
        case 2:
            cout << CYAN << "\n\n\n\t\t\t==============================================" << RESET << endl;
            cout << CYAN << "\t\t\t   * * * CARD PAYMENT * * *" << RESET << endl;
            cout << CYAN << "\t\t\t==============================================" << RESET << endl;
        cardnum:
            cout << "\n\t\t\tEnter your 15 Digit card number  :  ";
            cin >> cardnum;
            if ((cardnum.length() == 15) || (cardnum.length() == 14))
            {
                goto OTP;
            }
            else
            {
                cout << "\n\t\t\tInvalid Card Number, try again!" << endl;
                goto cardnum;
            }

        OTP:
            system("cls");
            cout << "\n\n\n\t\t\tNote:	Enter OTP (ONE TIME PASSWORD) sent to your registered mobile number." << endl;
            Sleep(3000);
            cout << "\n\t\t\tYour OTP is 22189" << endl;
            cout << "\n\t\t\t(Don't share the OTP with anyone.)" << endl;

        otpn:
            cout << "\n\n\n\t\t\tEnter OTP: "; 							//input same otp
            cin >> otp;

            if (otp == 22189)
            { 				//------------check if input otp is valid/same-----------------------
                Sleep(3000);
                cout << "\n\n\n\t\t\tPROCESSING PAYMENT....." << endl;
                cout << "\t\t\t";
                for (int j = 0; j < 30; j++)
                {
                    Sleep(200);
                    cout << YELLOW << bar << RESET;
                }
                system("cls");
                cout << "\n\n\n\t\t\tPAYMENT SUCCESSFULL!" << endl;
                Sleep(3000);
                cout << "\n\n\t\t\tYour order will be delivered within 3-5 days" << endl;
                Sleep(2000);
                cout << MAGENTA << "\n\n\n\t\t\t        THANK YOU FOR SHOPPING!!!\n\n\n\n" << RESET << endl;
                exit(0);
            }
            else
            {
                cout << RED << "\n\t\t\t\t\t\t\tInvalid OTP! Try again." << RESET << endl;
                Sleep(3000);
                goto otpn;
            }
        default:
            cout << RED << "\n\t\t\t\t\t\t\tInvalid OTP! Choice." << RESET << endl;
            goto payment;
        }
    }
    //-----------------------calculating final of this category----------------------------- 
    int calculateGrandTotal() override {
        int  grand_total = 0;
        for (int i = 0; i <= limit; i++) {
            grand_total += total[i];
            cout << "\n\t\t\tGrand total   :   " << grand_total << endl;
            myfile << "\n\t\t\tGrand total   :   " << grand_total << endl;

        }
        return grand_total;
    }
    //destructor
    ~Myclothes() {}
};

//========================================== Footwear Class =========================================
class Myfootwear : public Mystore {
private:
    // defualt member initializer
    int id = 0;
    int i = 0;
    int pay = 0;
    int otp = 0;
    string idnum[50] = {};
    string cardnum = "";
    string product[10] = {};
    int total[10] = {};
    int qty[10] = {};
    int limit = 0;
    int price[10] = {};

public:

    // Constructor
    Myfootwear() {}

    // Parameterized constructor
    Myfootwear(int ID, int I, int PAY, int OTP1, const string& CARDNUM, int LIMIT)
    {
        id = ID;
        i = I;
        pay = PAY;
        otp = OTP1;
        cardnum = CARDNUM;
        limit = LIMIT;
    }

    void displayProductPage() override {
        system("cls");
    footwear:
        cout << CYAN << "\n\n\n\t\t\t=================================================================" << RESET << endl;
        cout << CYAN << "\t\t\t      * * * * * * * * * * * F O O T W E A R * * * * * * * * * *" << RESET << endl;
        cout << CYAN << "\t\t\t=================================================================" << RESET << endl;
        Sleep(1000);
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\t| ID |                  NAME                    | price   |" << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\t| 9   | High Heels                              | Rs 8999 |" << endl;
        cout << "\t\t\t| 10  | Ladies Flates                           | Rs 5900 |" << endl;
        cout << "\t\t\t| 11  | Ladies Sneakers                         | Rs 9990 |" << endl;
        cout << "\t\t\t| 12  | Loaffers                                | Rs 7500 |" << endl;
        cout << "\t\t\t| 13  | Gentes Sneakers                         | Rs 8700 |" << endl;
        cout << "\t\t\t| 14  | Joggers                                 | Rs 5500 |" << endl;
        cout << "\t\t\t| 15  | FancyWear                               | Rs 9999 |" << endl;
        cout << "\t\t\t| 16  | Pumps                                   | Rs 7990 |" << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\n\t\t\tEnter item ID   :   ";
        cin >> id;

        switch (id)
        {
        case 9:
            idnum[i] = "9";
            product[i] = "High Heels";
            price[i] = 8999;
            break;
        case 10:
            idnum[i] = "10";
            product[i] = "Ladies Flates";
            price[i] = 5900;
            break;
        case 11:
            idnum[i] = "11";
            product[i] = "Ladies Sneakers";
            price[i] = 9990;
            break;
        case 12:
            idnum[i] = "12";
            product[i] = "Loaffers";
            price[i] = 7500;
            break;
        case 13:
            idnum[i] = "13";
            product[i] = "Gentes sneakers";
            price[i] = 8700;
            break;
        case 14:
            idnum[i] = "14";
            product[i] = "Joggers";
            price[i] = 5500;
            break;
        case 15:
            idnum[i] = "15";
            product[i] = "Fancywear";
            price[i] = 9999;
            break;
        case 16:
            idnum[i] = "16";
            product[i] = "Pumps";
            price[i] = 7990;
            break;
        default:
            cout << RED << "\n\t\t\t\t\t\tInvalid ID number! " << RESET << endl;
            goto footwear;
        }
    }

    //billing page
    void displayBillingPage() override {
        cout << "\n\t\t\tEnter Quantity   :   ";
        cin >> qty[i];

        total[i] = calculateTotal(qty[i], price[i]);
        cout << "\n\t\t\tYour Total Payment is    :" << total[i] << endl;

        Sleep(2000);
        int f;
        cout << "\n\n\n\t\t\tProduct Added To Cart!" << endl;
        cout << "\n\n\n\t\t\tWant to Remove The Product From The Cart?" << endl;
        cout << "\t\t\t [1]YES               [2]NO" << endl;
        cin >> f;
        if (f == 1) {
            cout << RED << "\n\n\n\t\t\tYour Product " << product[i] << "  Is Removed From Cart" << RESET << endl;
        }
        else
            cout << "\n\n\n\t\t\t  Billing In Process" << endl;
    }


    //checkout page
    void displayCheckoutPage() override {
    checkout:

        Sleep(2000);
        cout << "\n\n\n\t\t\t  CHECKING OUT....." << endl;
        cout << "\t\t\t ";
        for (int j = 0; j < 30; j++)
        {
            Sleep(200);
            cout << YELLOW << bar << RESET;
        }

        Sleep(2000);
        cout << CYAN << "\n\n\n\t\t\t==============================================" << RESET << endl;
        cout << CYAN << "\t\t\t     * * * * Order Details * * * *" << RESET << endl;
        cout << CYAN << "\t\t\t==============================================" << RESET << endl;
        cout << "\n\n\n\t\t\t_" << endl;
        cout << "\n\t\t\t" << product[i] << " PRODUCT NAME ";
        myfile << "\n\t\t\t" << product[i] << " PRODUCT NAME ";
        cout << "\n\t\t\t" << qty[i] << " Qty";
        myfile << "\n\t\t\t" << qty[i] << " Qty";
        cout << "\n\t\t\t" << price[i] << " Price ";
        myfile << "\n\t\t\t" << price[i] << " Price ";
        cout << "\n\t\t\t" << total[i] << " amount ";
        myfile << "\n\t\t\t" << total[i] << " amount ";
        cout << "\n\n\n\t\t\t_" << endl;

        cout << "\n\n\n\t\t\t  Billing In Process" << calculateGrandTotal() << endl;
        Sleep(2000);
        ;
    }

    //-----------------------calculating final of this category----------------------------- 
    int calculateGrandTotal() override {
        int  grand_total = 0;
        for (int i = 0; i <= limit; i++) {
            grand_total += total[i];
            cout << "\n\t\t\tGrand total   :   " << grand_total << endl;
            myfile << "\n\t\t\tGrand total   :   " << grand_total << endl;

        }
        return grand_total;
    }

    void displayPaymentPage() {}
    //destructor
    ~Myfootwear() {}
};

//========================================== Makeup Class =========================================
class Mymakeup : public Mystore {
private:
    // defualt member initializer
    int id = 0;
    int i = 0;
    int pay = 0;
    int otp = 0;
    string idnum[50] = {};
    string cardnum = "";
    string product[10] = {};
    int total[10] = {};
    int qty[10] = {};
    int limit = 0;
    int price[10] = {};

public:
    // Constructor
    Mymakeup() {}

    // Parameterized constructor 
    Mymakeup(int ID, int I, int PAY, int OTP1, const string& CARDNUM, int LIMIT) {
        id = ID;
        i = I;
        pay = PAY;
        otp = OTP1;
        cardnum = CARDNUM;
        limit = LIMIT;
    }

    void displayProductPage() override {
        system("cls");
    makeup:
        cout << CYAN << "\n\n\n\t\t\t===============================================================" << RESET << endl;
        cout << CYAN << "\t\t\t      * * * * * * * * * * * M A K E U P * * * * * * * * * *" << RESET << endl;
        cout << CYAN << "\t\t\t===============================================================" << RESET << endl;
        Sleep(1000);
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\t| ID |                  NAME                    | price   |" << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\t| 17  | Foundation                              | Rs 8999 |" << endl;
        cout << "\t\t\t| 18  | Lipstickes                              | Rs 5900 |" << endl;
        cout << "\t\t\t| 19  | Eye shadow platte                       | Rs 9990 |" << endl;
        cout << "\t\t\t| 20  | Primer                                  | Rs 7500 |" << endl;
        cout << "\t\t\t| 21  | Tints                                   | Rs 8700 |" << endl;
        cout << "\t\t\t| 22  | Mascarra                                | Rs 5500 |" << endl;
        cout << "\t\t\t| 23  | Eye liner                               | Rs 9999 |" << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\n\t\t\tEnter item ID   :   ";
        cin >> id;

        switch (id)
        {
        case 17:
            idnum[i] = "17";
            product[i] = "foundation";
            price[i] = 8999;
            break;
        case 18:
            idnum[i] = "18";
            product[i] = "Lipstickes";
            price[i] = 5900;
            break;
        case 19:
            idnum[i] = "19";
            product[i] = "Eye shadow platte";
            price[i] = 9990;
            break;
        case 20:
            idnum[i] = "20";
            product[i] = "Primer";
            price[i] = 7500;
            break;
        case 21:
            idnum[i] = "21";
            product[i] = "Tints";
            price[i] = 8700;
            break;
        case 22:
            idnum[i] = "22";
            product[i] = "Mascarra";
            price[i] = 5500;
            break;
        case 23:
            idnum[i] = "23";
            product[i] = "Eye liner";
            price[i] = 9999;
            break;
        default:
            cout << RED << "\n\t\t\t\t\t\tInvalid ID number! " << RESET << endl;
            goto makeup;
        }
    }

    void displayBillingPage() override {
        cout << "\n\t\t\tEnter Quantity   :   ";
        cin >> qty[i];
        total[i] = calculateTotal(qty[i], price[i]);
        cout << "\n\t\t\tYour Total Payment is    :" << total[i] << endl;

        Sleep(2000);
        int f;
        cout << "\n\n\n\t\t\tProduct Added To Cart!" << endl;
        cout << "\n\n\n\t\t\tWant to Remove The Product From The Cart?" << endl;
        cout << "\t\t\t [1]YES               [2]NO" << endl;
        cin >> f;
        if (f == 1) {
            cout << RED << "\n\n\n\t\t\tYour Product " << product[i] << "  Is Removed From Cart" << RESET << endl;
        }
        else
            cout << "\n\n\n\t\t\t  Billing In Process" << endl;
    }

    void displayCheckoutPage() override {
    checkout:

        Sleep(2000);
        cout << "\n\n\n\t\t\t  CHECKING OUT....." << endl;
        cout << "\t\t\t ";
        for (int j = 0; j < 30; j++)
        {
            Sleep(200);
            cout << YELLOW << bar << RESET;
        }

        Sleep(2000);
        cout << CYAN << "\n\n\n\t\t\t==============================================" << RESET << endl;
        cout << CYAN << "\t\t\t     * * * * Order Details * * * *" << RESET << endl;
        cout << CYAN << "\t\t\t==============================================" << RESET << endl;
        cout << "\n\n\n\t\t\t_" << endl;
        cout << "\n\t\t\t" << product[i] << " PRODUCT NAME ";
        myfile << "\n\t\t\t" << product[i] << " PRODUCT NAME ";
        cout << "\n\t\t\t" << qty[i] << " Qty";
        myfile << "\n\t\t\t" << qty[i] << " Qty";
        cout << "\n\t\t\t" << price[i] << " Price ";
        myfile << "\n\t\t\t" << price[i] << " Price ";
        cout << "\n\t\t\t" << total[i] << " amount ";
        myfile << "\n\t\t\t" << total[i] << " amount ";
        cout << "\n\n\n\t\t\t_" << endl;

        cout << "\n\n\n\t\t\t  Billing In Process" << calculateGrandTotal() << endl;
        Sleep(2000);
    }


    //-----------------------calculating final of this category----------------------------- 
    int calculateGrandTotal() override {
        int  grand_total = 0;
        for (int i = 0; i <= limit; i++) {
            grand_total += total[i];
            cout << "\n\t\t\tGrand total   :   " << grand_total << endl;
            myfile << "\n\t\t\tGrand total   :   " << grand_total << endl;

        }
        return grand_total;
    }

    void displayPaymentPage() {}
    //destructor
    ~Mymakeup() {}
};



int main()
{
    cout << "\n\n\n\t\t\t";
    char a[] = { '*','*','*',' ','F','.','S','H','O','P','P','I','N','G',' ','S','T','O','R','E',' ','*','*','*' };
    cout << "\t\t\t";
    for (int j = 0; j < 24; j++)
    {
        Sleep(300);
        cout << CYAN << a[j] << RESET;
    }
    cout << CYAN << "\n\n\n\t\t\t==============================================" << RESET << endl;
    cout << CYAN << "\t\t\t          Welcome To Our Store" << RESET << endl;
    cout << CYAN << "\t\t\t==============================================" << RESET << endl;

    Sleep(400);

    int cont, category, choice, option;

    //--------------------------------classes objects----------------------------------
    Myclothes clothesStore;
    Myfootwear footwearStore;
    Mymakeup makeupStore;

    clothesStore.displayMainPage();  //calling mainpage

    do {
    ask:
        clothesStore.displayProducts();  //calling product category page
        cin >> category;
        if (category == 1) {
            clothesStore.displayProductPage();  //displaying products
            clothesStore.displayBillingPage();  //displaying billing
        }
        else if (category == 2) {
            footwearStore.displayProductPage();  //displaying products
            footwearStore.displayBillingPage();  //displaying billing
        }
        else if (category == 3) {
            makeupStore.displayProductPage();  //displaying products
            makeupStore.displayBillingPage();  //displaying billing
        }
        else
        {
            cout << "\n\n\t\t\tInvalid choice! Try again!\n";		//invalid choice
            goto ask;
            break;
        }
    conti:
        cout << "\n\n\n\t\t\tDo you want to continue shopping?" << endl;
        cout << "\t\t\t [1]YES               [2]NO" << endl;
        cout << "\n\t\t\tEnter Your Choice   :   ";
        cin >> cont;

    } while (cont == 1);

    //checking validity of option
    if (cont != 2)
    {
        cout << RED << "\n\t\t\tInvalid Choice! Try again " << RESET << endl;
        Sleep(2000);
        goto conti;

    }
    clothesStore.addressdetails();
    //checkout calls
    do {
    checkout:
        cout << "\n\n\n\t\t\t CHECKOUT Option: ";
        cout << "\n\n\t\t\t [1].Clothes   [2].Footwear  [3].Makeup" << endl;
        cout << "\n\t\t\tEnter Your Choice   :   ";
        cin >> choice;
        switch (choice) {
        case 1:
            clothesStore.displayCheckoutPage();
            break;
        case 2:
            footwearStore.displayCheckoutPage();
            break;
        case 3:
            makeupStore.displayCheckoutPage();
        case 4:
            break;
        default:
            goto checkout;
        }
    proc:
        cout << "\n\t\t\tDo you have other Checkout Option? " << endl;
        cout << "\t\t\t [1]YES               [2]NO" << endl;
        cout << "\t\t\t [3]Cancel Order" << endl;
        cout << "\n\t\t\tEnter Your Choice   :   ";
        cin >> option;
        if (option == 3) {
            cout << RED << "\n\t\t\tYour order is cancelled! " << RESET << endl;
            exit(0);
        }
    } while (option == 1);
    if (option != 1 && option != 2 && option != 3) {
        cout << RED << "\n\t\t\tInvalid Choice! Try again " << RESET << endl;
        goto proc;
    }
    Sleep(3000);
    // Calculate total amount
    double amount_1 = clothesStore.calculateGrandTotal();
    double amount_2 = footwearStore.calculateGrandTotal();
    double amount_3 = makeupStore.calculateGrandTotal();

    cout << "Clothes Store Total: " << amount_1 << endl;
    cout << "Footwear Store Total: " << amount_2 << endl;
    cout << "Makeup Store Total: " << amount_3 << endl;
    Sleep(3000);
    double TotalAmount = amount_1 + amount_2 + amount_3;
    cout << "\n\n\n\t YOUR Total PAYMENT IS : " << TotalAmount << endl;

    //payment page display showing payment methodes
    clothesStore.displayPaymentPage();

    return 0;

}