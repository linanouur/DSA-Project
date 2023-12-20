#ifndef MENU_H
#define MENU_H

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"userFunctions.cpp"
#include"Regions.h"
using namespace std;
class menu
{
private:

    /* data */
public:
    menu(/* args */);
    void HomePage();
    void display();
    ~menu();
};

menu::menu(/* args */)
{
}

void menu::display()
{
    const int width = 60; // Total width for the message box
    conststd::string welcomeLine1 = "WELCOME TO OUR";
    conststd::string welcomeLine2 = "Electricity Network Management System";

    std::cout << "\n\n\n\n";

    // Top border of the square
    std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;

    // Empty line
    std::cout << "\t\t"
         << "^" << setfill(' ') << setw(width) << "^" << endl;

    // Centering the first line of the welcome message
    std::cout << "\t\t"
         << "^" << setw((width + welcomeLine1.length()) / 2) << welcomeLine1;
    std::cout << setw((width - welcomeLine1.length() + 1) / 2) << "^" << endl;

    // Centering the second line of the welcome message
    std::cout << "\t\t"
         << "^" << setw((width + welcomeLine2.length()) / 2) << welcomeLine2;
    std::cout << setw((width - welcomeLine2.length() + 1) / 2) << "^" << endl;

    // Empty line
    std::cout << "\t\t"
         << "^" << setfill(' ') << setw(width) << "^" << endl;

    // Bottom border of the square
    std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;

    std::cout << "\n\n\n";
    
    cout << "\t\t\t---------------------------------------------    " << endl;
    //(350);
    cout << "\t\t\t            Moving to Online Services            \n";
    //(350);
    cout << "\t\t\t---------------------------------------------    \n\n" << endl;
    //(1500);
}
// Function to read a single sentence from a CSV file
std::string getSentenceFromCSV(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string sentence;

    if (file.is_open() && std::getline(file, sentence)) {
        return sentence;
    }

    return ""; // Return emptystd::string if file can't be read
}



void menu::HomePage()
{
     
    
    htRegions Algeria;
    bool conn;
    const int width=60;
    int n;
   std::string password;
    do{
    // Role selection section
    
    std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Top border
    std::cout << "\t\t"
         << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
    std::cout << "\t\t"
         << "^" << setfill(' ') << setw(width - 25) << "Choose your role to continue" << setw(24) << "^" << endl;
    std::cout << "\t\t"
         << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
    std::cout << "\t\t"
         << "^" << setfill(' ') << setw(20) << "1_ Administrator" << setw(39) << "^" << endl;
    std::cout << "\t\t"
         << "^" << setfill(' ') << setw(15) << "2_ Customer" << setw(44) << "^" << endl;
    std::cout << "\t\t"
         << "^" << setfill(' ') << setw(15) << "3_ Quit...." << setw(44) << "^" << endl;
    std::cout << "\t\t"
         << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
         
    std::cout << "\t\t\t";
    std::cin >> n;
    std::cout << "\t\t"
         << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
    std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;   // Bottom border
    std::cout<< "\n\n\n";

    
   std::string password;
    switch (n)
    {
    case 1:

        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Top border
        std::cout << "\t\t"
             << "^" << setfill(' ') << setw(width - 10) << "Welcome admin please enter the password" << setw(9) << "^" << endl;
        std::cout << "\t\t\t";
        std::cin >> password;
        if (password == getSentenceFromCSV("password.csv")){conn=true;} else{conn=false; cout<<"incorrect password!"<<endl;}
        while(conn){   
            std::cout << "\t\t"
                 << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
            std::cout << "\t\t"
                 << "^" << setfill(' ') << setw(width - 15) << "Choose the operation you want to do" << setw(14) << "^" << endl;
            std::cout << "\t\t"
                 << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
            std::cout << "\t\t"
                 << "^" << setfill(' ') << setw(20) << "1_ Add customer" << setw(39) << "^" << endl;
            std::cout << "\t\t"
                 << "^" << setfill(' ') << setw(19) << "2_ Update bill" << setw(40) << "^" << endl;
            std::cout << "\t\t"
                 << "^" << setfill(' ') << setw(21) << "3_ display bills" << setw(38) << "^" << endl;
            std::cout << "\t\t"
                 << "^" << setfill(' ') << setw(23) << "4_ display weather" << setw(36) << "^" << endl;
            std::cout << "\t\t"
                 << "^" << setfill(' ') << setw(31) << "5_ listing of departements" << setw(28) << "^" << endl;
            std::cout << "\t\t"
                 << "^" << setfill(' ') << setw(18) << "6_ Log out..." << setw(41) << "^" << endl;
            int i;
            std::cout << "\t\t\t";
            std::cin >> i;
            std::cout << "\t\t"
                 << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
            std::cout << "\t\t"
                 << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
            std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;   // Bottom border
            std::cout << "\n\n\n";

            std::string reg, city, dist,fname,lname;
            int bnum,fnum,id_num,id_bill,m_bill,y_bill,mconsumption,minjection;
            
            switch (i)
            {
            case 1:
                std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Top border
                std::cout << "\t\t\t\t   Adding customer" << endl;

                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 30) << "Enter the region" << setw(29) << "^" << endl;
                std::cout << "\t\t\t\t";
                std::cin >> reg;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 32) << "Enter the city" << setw(31) << "^" << endl;
                std::cout << "\t\t\t\t";
                std::cin >> city;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 28) << "Enter the district" << setw(27) << "^" << endl;
                std::cout << "\t\t\t\t";
                std::cin >> dist;


                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 31) << "Enter Firstname" << setw(30) << "^" << endl;
                std::cout << "\t\t\t\t";
                std::cin >> fname;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 32) << "Enter Lastname" << setw(31) << "^" << endl;
                std::cout << "\t\t\t\t";
                std::cin >> lname;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 22) << "Enter Bankaccount number" << setw(21) << "^" << endl;
                std::cout << "\t\t\t\t";
                std::cin >> bnum;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 16) << "Enter number of family members" << setw(15) << "^" << endl;
                std::cout << "\t\t\t\t";
                std::cin >> fnum;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 38) << "Enter ID" << setw(37) << "^" << endl;
                std::cout << "\t\t\t\t";


                std::cin >> id_num;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                
                 
                cout<<"\t\t\t\t";
                insertNewCustomer(Algeria,fname,lname,bnum,fnum,reg,city,dist,id_num);
                std::cout << endl;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 20) << "Custumer added successfully" << setw(19) << "^" << endl;

                std::cout<<endl;
                std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Bottom border

                break;


                
            case 2:
                std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Top border
                std::cout << "\t\t\t\t   updating bill" << endl;

                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 20) << "Enter the ID of the customer" << setw(19) << "^" << endl;
                std::cout << "\t\t\t\t";
                std::cin >> id_bill;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 37) << "Enter month" << setw(36) << "^" << endl;
                std::cout << "\t\t\t\t";
                std::cin >> m_bill;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 38) << "Enter year" << setw(37) << "^" << endl;
                std::cout << "\t\t\t\t";
                std::cin >> y_bill;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 31) << "Enter consumption" << setw(30) << "^" << endl;
                std::cout << "\t\t\t\t";
                std::cin >> mconsumption;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 33) << "Enter injection" << setw(32) << "^" << endl;
                std::cout << "\t\t\t\t";
                std::cin >> minjection;
                

                setInfoOneMonth(Algeria,id_bill,m_bill,y_bill,mconsumption,minjection);

                std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Bottom border
                break;



            case 3:
                std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Top border
                std::cout << "\t\t\t\t   displaying bills" << endl;

                
std::cout << "\t\t"
          << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
std::cout << "\t\t"
          << "^" << setfill(' ') << setw(width - 15) << "You want to display the bill for:" << setw(14) << "^" << endl;
std::cout << "\t\t"
          << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
std::cout << "\t\t"
          << "^" << setfill(' ') << setw(20) << "1_ single customer" << setw(39) << "^" << endl;
std::cout << "\t\t"
          << "^" << setfill(' ') << setw(24) << "2_ many customers" << setw(35) << "^" << endl;
int y;
std::cout << "\t\t\t\t   ";
std::cin >> y;
switch (y)
{
    int S_id;
case 1:
    std::cout << "\t\t\t enter the customer ID please:";
    std::cin >> S_id;
    std::cout << "\t\t\t you want the customer's bill in: "<<endl;
    std::cout << "\t\t"
              << "^" << setfill(' ') << setw(20) << "1_ month" << setw(39) << "^" << endl;
    std::cout << "\t\t"
              << "^" << setfill(' ') << setw(24) << "2_ year" << setw(35) << "^" << endl;
    std::cout << "\t\t"
              << "^" << setfill(' ') << setw(20) << "3_ periode of time" << setw(39) << "^" << endl;
    int t;
    std::cout << "\t\t\t";
    std::cin >> t;
    switch (t)
    {
    case 1:
        std::cout << "\t\t\t enter the month" << endl;
        int tm;
        std::cout << "\t\t\t";
        std::cin >> tm;
        std::cout << "\t\t\t enter the year" << endl;
        int ty;
        std::cout << "\t\t\t";
        std::cin >> ty;
        // getOnemonthBill(Algeria, S_id, tm, ty);
        break;
    case 2:
        std::cout << "\t\t\t enter the year" << endl;
        int ty2;
        std::cout << "\t\t\t";
        std::cin >> ty2;
        // getOneYearBill(Algeria, S_id, ty); 
        break;

    case 3:
        std::cout << "\t\t\t enter the start month" << endl;
        int sm;
        std::cout << "\t\t\t";
        std::cin >> sm;
        std::cout << "\t\t\t enter the start year" << endl;
        int sy;
        std::cout << "\t\t\t";
        std::cin >> sy;
        std::cout << "\t\t\t enter the end month" << endl;
        int em;
        std::cout << "\t\t\t";
        std::cin >> em;
        std::cout << "\t\t\t enter the end year" << endl;
        int ey;
        std::cout << "\t\t\t";
        std::cin >> ey;
        // getPeriodBill(Algeria,S_id, sm, em, sy, ey);
        break;

    default:
        break;
    }

    break;




case 2:

                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 15) << "you want customers' bills of: " << setw(14) << "^" << endl;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(24) << "1_ Region" << setw(35) << "^" << endl;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(22) << "2_ City" << setw(37) << "^" << endl;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(26) << "3_ District" << setw(33) << "^" << endl;
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(25) << "4_ Country" << setw(34) << "^" << endl;
                int x;
                std::cout << "\t\t\t\t   ";
                std::cin >> x;
                switch (x)
                {
                case 1:
                    
        std::cout << "\t\t\t enter district" << endl;
       std::string dist1;
        std::cout << "\t\t\t";
        std::cin >> dist1;
        std::cout << "\t\t\t enter city" << endl;
       std::string ct1;
        std::cout << "\t\t\t";
        std::cin >> ct1;
        std::cout << "\t\t\t enter region" << endl;
        int rg1;
        std::cout << "\t\t\t";
        std::cin >>rg1;
        // displayByDistrict(Algeria,rg, ct, dist);
                    break;
                case 2:
                    std::cout << "\t\t\t enter city" << endl;
       std::string ct2;
        std::cout << "\t\t\t";
        std::cin >> ct2;
        std::cout << "\t\t\t enter region" << endl;
        int rg2;
        std::cout << "\t\t\t";
        std::cin >>rg2;
        // displayByCity(Algeria,rg, ct);
                    break;
                case 3:
                    std::cout << "\t\t\t enter region" << endl;
        int rg3;
        std::cout << "\t\t\t";
        std::cin >>rg3;
        // displayByRegion(Algeria,rg);
                    break;
                case 4:
                    // displayByRegion(Algeria);
                    break;
                

                default:
                    break;
                }

break;
}


                std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Bottom border
                break;

                case 4:
                int dw,mw,yw;
                std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Top border
                std::cout << "\t\t\t\t   displaying weather" << endl;

                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 30) << "Enter the date" << setw(29) << "^" << endl;
                 std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width -43) << "day" << setw(42) << "^" << endl;
                     std::cout << "\t\t\t\t";
                     std::cin >> dw;
                     std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 41) << "month" << setw(40) << "^" << endl;
                     std::cout << "\t\t\t\t";
                     std::cin >> mw;
                     std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 42) << "year" << setw(41) << "^" << endl;  
                     std::cout << "\t\t\t\t";
                     std::cin >> yw;  
                    // std::cout << "\t\t"
                    // << "^" << setfill(' ') << setw(width - 20) << printWeather(dw,mw,yw) << setw(39) << "^" << endl;  
                     
                     
                     std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Bottom border

                break;




            
                case 5:
                
                std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Top border
                std::cout << "\t\t\t\t   listing of departements " << endl;

                std::cout << "\t\t"
                     << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                     // listingOfDepartements();
                     
                     std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Bottom border

                break;

                case 6:
                   conn=false;
                break;



            default:
                std::cout << "\t\t\t\t Invalid operation selected." << endl;
                break;
            }
        }
        break;















        /**********************************customer******************************************/

    case 2:
        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Top border
        std::cout << "\t\t"
             << "^" << setfill(' ') << setw(width - 10) << "Welcome customer please enter your ID" << setw(9) << "^" << endl;
        int ID;
        std::cout << "\t\t\t\t\t";
        std::cin >> ID;
        // if id exists
        std::cout << "\t\t"
             << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
        std::cout << "\t\t"
             << "^" << setfill(' ') << setw(width - 15) << "Choose the operation you want to do" << setw(14) << "^" << endl;
        std::cout << "\t\t"
             << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
        std::cout << "\t\t"
             << "^" << setfill(' ') << setw(20) << "1_ See bill by month" << setw(39) << "^" << endl;
        std::cout << "\t\t"
             << "^" << setfill(' ') << setw(20) << "1_ See bill by year" << setw(39) << "^" << endl;
        


       int c;
        std::cout << "\t\t\t\t\t";
        std::cin >> c;
        std::cout << "\t\t"
             << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;   // Bottom border
        std::cout << "\n\n\n";

        switch (c)
        {
        case 1:
            std::cout << "\t\t\t\t Seeing bills" << endl;
            break;
        case 2:
            std::cout << "\t\t\t\t Others" << endl;
            break;
        default:
            std::cout << "\t\t\t\t Invalid operation selected." << endl;
            break;
        }
        break;

     case 3:
     exit(0);
     

    default:
        std::cout << "\t\t\t\t Invalid role selected." << endl;
        break;
    }
}while (n != '1' && n != '2' );
}


menu::~menu()
{
}
#endif