#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "weatherHashTable.h"
#include "customers.h"
// #include "userFunctions.cpp"
// #include "Regions.h"
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
     const std::string welcomeLine1 = "WELCOME TO OUR";
     const std::string welcomeLine2 = "Electricity Network Management System";

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
     cout << "\t\t\t---------------------------------------------    \n\n"
          << endl;
     //(1500);
}
// Function to read a single sentence from a CSV file
std::string getSentenceFromCSV(const std::string &filePath)
{
     std::ifstream file(filePath);
     std::string sentence;

     if (file.is_open() && std::getline(file, sentence))
     {
          return sentence;
     }

     return ""; // Return emptystd::string if file can't be read
}

void menu::HomePage()
{

     Customers BST;
     // htRegions Algeria;
     weatherHashTable wht;
     bool conn;
     const int width = 60;
     int n;
     std::string password;
     do
     {
          // Role selection section

          std::cout << "\n";
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
          std::cout << "\n\n\n";

          std::string password;
          switch (n)
          {
          case 1:

               std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Top border
               std::cout << "\t\t"
                         << "^" << setfill(' ') << setw(width - 10) << "Welcome admin please enter the password" << setw(9) << "^" << endl;
               std::cout << "\t\t\t\t";
               std::cin >> password;
               if (password == getSentenceFromCSV("password.csv"))
               {
                    conn = true;
               }
               else
               {
                    conn = false;
                    cout << "\t\t\t\t incorrect password!\n"
                         << endl;
                    std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                    cout << "\n\n";
               }
               while (conn)
               {
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
                              << "^" << setfill(' ') << setw(34) << "5_ Best customer of the month" << setw(25) << "^" << endl;
                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(31) << "6_ listing of departements" << setw(28) << "^" << endl;
                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(28) << "7_ Best 10 edpartements" << setw(31) << "^" << endl;
                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(29) << "8_ Worst 10 departements" << setw(30) << "^" << endl;
                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(18) << "9_ Log out..." << setw(41) << "^" << endl;
                    int i;
                    std::cout << "\t\t\t";
                    std::cin >> i;
                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                    std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;   // Bottom border
                    std::cout << "\n\n\n";

                    std::string reg, city, dist, fname, lname;
                    int bnum, fnum, id_num, m_bill, y_bill, mconsumption, minjection;
                    long int id_bill;

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
                         if (std::cin.fail())
                         {
                              throw std::runtime_error("Input was not an integer.");
                         }
                         if (bnum < 0)
                         {
                              std::cout << "\t\t\t Invalid bank account number entered!!\n\n";
                              std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                              break;
                         }
                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 16) << "Enter number of family members" << setw(15) << "^" << endl;
                         std::cout << "\t\t\t\t";
                         std::cin >> fnum;
                         if (std::cin.fail())
                         {
                              throw std::runtime_error("Input was not an integer.");
                         }
                         if (fnum < 0)
                         {
                              std::cout << "\t\t\t Invalid family members number entered!!\n\n";
                              std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                              break;
                         }
                         // std::cout << "\t\t"
                         //   << "^" << setfill(' ') << setw(width - 38) << "Enter ID" << setw(37) << "^" << endl;
                         // std::cout << "\t\t\t\t";

                         // std::cin >> id_num;
                         // if (id_num > 9999 || id_num < 0)
                         //{
                         //  std::cout << "\t\t\t Invalid ID entered!!\n\n";
                         //  std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                         //  break;
                         //}
                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line

                         cout << "\t\t\t\t";
                         // insertNewCustomer(Algeria, fname, lname, bnum, fnum, reg, city, dist, id_num);
                         std::cout << endl;
                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 20) << "Custumer added successfully" << setw(19) << "^" << endl;

                         std::cout << endl;
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
                         if (id_bill > 99999999999 || id_bill < 0)
                         {
                              std::cout << "\t\t\t Invalid ID entered!!\n\n";
                              std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                              break;
                         }
                         if (std::cin.fail())
                         {
                              throw std::runtime_error("Input was not an integer.");
                         }
                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 37) << "Enter month" << setw(36) << "^" << endl;
                         std::cout << "\t\t\t\t";
                         std::cin >> m_bill;
                         if (m_bill < 0 || m_bill > 12)
                         {
                              std::cout << "\t\t\t Invalid month entered!!\n\n";
                              std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                              break;
                         }
                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 38) << "Enter year" << setw(37) << "^" << endl;
                         std::cout << "\t\t\t\t";
                         std::cin >> y_bill;
                         if (y_bill > 2072 || y_bill < 2022)
                         {
                              std::cout << "\t\t\t Invalid year entered!!\n\n";
                              std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                              break;
                         }

                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 31) << "Enter consumption" << setw(30) << "^" << endl;
                         std::cout << "\t\t\t\t";
                         std::cin >> mconsumption;
                         if (mconsumption < 0)
                         {
                              std::cout << "\t\t\t Invalid consumption entered!!\n\n";
                              std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                              break;
                         }
                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 33) << "Enter injection" << setw(32) << "^" << endl;
                         std::cout << "\t\t\t\t";
                         std::cin >> minjection;
                         if (minjection < 0)
                         {
                              std::cout << "\t\t\t Invalid injection entered!!\n\n";
                              std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                              break;
                         }

                         // setInfoOneMonth(Algeria, id_bill, m_bill, y_bill, mconsumption, minjection);

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
                                   << "^" << setfill(' ') << setw(25) << "1_ single customer" << setw(34) << "^" << endl;
                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(24) << "2_ many customers" << setw(35) << "^" << endl;
                         int y;
                         std::cout << "\t\t\t\t   ";
                         std::cin >> y;
                         switch (y)
                         {
                              long int S_id;
                         case 1:
                              std::cout << "\t\t\t enter the customer ID please:\n";
                              std::cout << "\t\t\t\t   ";
                              std::cin >> S_id;
                              if (S_id > 99999999999 || id_bill < 0)
                              {
                                   std::cout << "\t\t\t Invalid ID entered!!\n\n";
                                   std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                   break;
                              }

                              if (std::cin.fail())
                              {
                                   throw std::runtime_error("Input was not an integer.");
                              }
                              std::cout << "\n\n";
                              std::cout << "\t\t\t you want the customer's bill in: \n"
                                        << endl;
                              std::cout << "\t\t"
                                        << "^" << setfill(' ') << setw(20) << "1_ month" << setw(39) << "^" << endl;
                              std::cout << "\t\t"
                                        << "^" << setfill(' ') << setw(19) << "2_ year" << setw(40) << "^" << endl;
                              std::cout << "\t\t"
                                        << "^" << setfill(' ') << setw(30) << "3_ periode of time" << setw(29) << "^" << endl;
                              int t;
                              std::cout << "\t\t\t\t";
                              std::cin >> t;
                              switch (t)
                              {
                              case 1:
                                   std::cout << "\t\t\t enter the month" << endl;
                                   int tm;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> tm;
                                   if (tm > 12 || tm < 0)
                                   {
                                        std::cout << "\t\t\t Invalid month entered!!\n\n";
                                        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                        break;
                                   }
                                   std::cout << "\t\t\t enter the year" << endl;
                                   int ty;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> ty;
                                   if (ty > 2072 || ty < 2022)
                                   {
                                        std::cout << "\t\t\t Invalid year entered!!\n\n";
                                        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                        break;
                                   }
                                   // getOnemonthBill(Algeria, S_id, tm, ty);
                                   break;
                              case 2:
                                   std::cout << "\t\t\t enter the year" << endl;
                                   int ty2;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> ty2;
                                   if (ty2 > 2072 || ty2 < 2022)
                                   {
                                        std::cout << "\t\t\t Invalid year entered!!\n\n";
                                        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                        break;
                                   }
                                   // getOneYearBill(Algeria, S_id, ty);
                                   break;

                              case 3:
                                   std::cout << "\t\t\t enter the start month" << endl;
                                   int sm;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> sm;
                                   if (sm < 0 || sm > 12)
                                   {
                                        std::cout << "\t\t\t Invalid month entered!!\n\n";
                                        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                        break;
                                   }

                                   std::cout << "\t\t\t enter the start year" << endl;
                                   int sy;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> sy;
                                   if (sy > 2052 || sy < 2022)
                                   {
                                        std::cout << "\t\t\t Invalid year entered!!\n\n";
                                        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                        break;
                                   }

                                   std::cout << "\t\t\t enter the end month" << endl;
                                   int em;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> em;
                                   if (em < 0 || em > 12)
                                   {
                                        std::cout << "\t\t\t Invalid month entered!!\n\n";
                                        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                        break;
                                   }
                                   std::cout << "\t\t\t enter the end year" << endl;
                                   int ey;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> ey;
                                   if (ey > 2052 || ey < 2022)
                                   {
                                        std::cout << "\t\t\t Invalid year entered!!\n\n";
                                        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                        break;
                                   }
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
                                        << "^" << setfill(' ') << setw(width - 15) << "Display bills according to: " << setw(14) << "^" << endl;
                              std::cout << "\t\t"
                                        << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                              std::cout << "\t\t"
                                        << "^" << setfill(' ') << setw(24) << "1_ District" << setw(35) << "^" << endl;
                              std::cout << "\t\t"
                                        << "^" << setfill(' ') << setw(20) << "2_ City" << setw(39) << "^" << endl;
                              std::cout << "\t\t"
                                        << "^" << setfill(' ') << setw(22) << "3_ Region" << setw(37) << "^" << endl;
                              std::cout << "\t\t"
                                        << "^" << setfill(' ') << setw(23) << "4_ Country" << setw(36) << "^" << endl;
                              int x;
                              std::cout << "\t\t\t\t   ";
                              std::cin >> x;

                              std::string dist1, ct1, rg1, rg2, ct2, rg3;
                              switch (x)
                              {
                              case 1:

                                   std::cout << "\t\t\t enter district" << endl;

                                   std::cout << "\t\t\t\t";
                                   std::cin >> dist1;
                                   std::cout << "\t\t\t enter city" << endl;

                                   std::cout << "\t\t\t\t";
                                   std::cin >> ct1;
                                   std::cout << "\t\t\t enter region" << endl;

                                   std::cout << "\t\t\t\t";
                                   std::cin >> rg1;

                                   std::cout << "\n\n";
                                   std::cout << "\t\t\t you want the bills of: \n"
                                             << endl;
                                   std::cout << "\t\t"
                                             << "^" << setfill(' ') << setw(20) << "1_ month" << setw(39) << "^" << endl;
                                   std::cout << "\t\t"
                                             << "^" << setfill(' ') << setw(19) << "2_ year" << setw(40) << "^" << endl;
                                   std::cout << "\t\t"
                                             << "^" << setfill(' ') << setw(30) << "3_ periode of time" << setw(29) << "^" << endl;
                                   int tz;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> tz;
                                   switch (tz)
                                   {
                                   case 1:
                                        std::cout << "\t\t\t enter the month" << endl;
                                        int tm;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> tm;
                                        if (tm > 12 || tm < 0)
                                        {
                                             std::cout << "\t\t\t Invalid month entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        std::cout << "\t\t\t enter the year" << endl;
                                        int ty;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> ty;
                                        if (ty > 2072 || ty < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        // getOneMonthBillDistrict(Algeria, rg1,ct1, dist1, tm, ty)
                                        break;
                                   case 2:
                                        std::cout << "\t\t\t enter the year" << endl;
                                        int ty2;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> ty2;
                                        if (ty2 > 2072 || ty2 < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }

                                        // getOneYearBillDistrict(Algeria, rg1, ct1,dist1,ty2);
                                        break;

                                   case 3:
                                        std::cout << "\t\t\t enter the start month" << endl;
                                        int sm;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> sm;
                                        if (sm < 0 || sm > 12)
                                        {
                                             std::cout << "\t\t\t Invalid month entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }

                                        std::cout << "\t\t\t enter the start year" << endl;
                                        int sy;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> sy;
                                        if (sy > 2052 || sy < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }

                                        std::cout << "\t\t\t enter the end month" << endl;
                                        int em;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> em;
                                        if (em < 0 || em > 12)
                                        {
                                             std::cout << "\t\t\t Invalid month entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        std::cout << "\t\t\t enter the end year" << endl;
                                        int ey;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> ey;
                                        if (ey > 2052 || ey < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        // getOnePeriodBillDistrict(Algeria, rg1,ct1,dist1,sm, em, sy, ey);
                                        break;

                                   default:
                                        break;
                                   }

                                   break;
                              case 2:
                                   std::cout << "\t\t\t enter city" << endl;

                                   std::cout << "\t\t\t\t";
                                   std::cin >> ct2;
                                   std::cout << "\t\t\t enter region" << endl;

                                   std::cout << "\t\t\t\t";
                                   std::cin >> rg2;

                                   std::cout << "\n\n";
                                   std::cout << "\t\t\t you want the bills in: \n"
                                             << endl;
                                   std::cout << "\t\t"
                                             << "^" << setfill(' ') << setw(20) << "1_ month" << setw(39) << "^" << endl;
                                   std::cout << "\t\t"
                                             << "^" << setfill(' ') << setw(19) << "2_ year" << setw(40) << "^" << endl;
                                   std::cout << "\t\t"
                                             << "^" << setfill(' ') << setw(30) << "3_ periode of time" << setw(29) << "^" << endl;
                                   int tzz;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> tzz;
                                   switch (tzz)
                                   {
                                   case 1:
                                        std::cout << "\t\t\t enter the month" << endl;
                                        int tm;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> tm;
                                        if (tm > 12 || tm < 0)
                                        {
                                             std::cout << "\t\t\t Invalid month entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        std::cout << "\t\t\t enter the year" << endl;
                                        int ty;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> ty;
                                        if (ty > 2072 || ty < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        // getOneMonthBillCity(Algeria, rg2,ct2, tm, ty)
                                        break;
                                   case 2:
                                        std::cout << "\t\t\t enter the year" << endl;
                                        int ty2;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> ty2;
                                        if (ty2 > 2072 || ty2 < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }

                                        // getOneYearBillCity(Algeria, rg2, ct2,ty2);
                                        break;

                                   case 3:
                                        std::cout << "\t\t\t enter the start month" << endl;
                                        int sm;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> sm;
                                        if (sm < 0 || sm > 12)
                                        {
                                             std::cout << "\t\t\t Invalid month entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }

                                        std::cout << "\t\t\t enter the start year" << endl;
                                        int sy;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> sy;
                                        if (sy > 2052 || sy < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }

                                        std::cout << "\t\t\t enter the end month" << endl;
                                        int em;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> em;
                                        if (em < 0 || em > 12)
                                        {
                                             std::cout << "\t\t\t Invalid month entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        std::cout << "\t\t\t enter the end year" << endl;
                                        int ey;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> ey;
                                        if (ey > 2052 || ey < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        // getOnePeriodBillCity(Algeria, rg2,ct2,sm, em, sy, ey);
                                        break;
                                   default:
                                        break;
                                   }

                                   break;
                              case 3:
                                   std::cout << "\t\t\t enter region" << endl;

                                   std::cout << "\t\t\t\t";
                                   std::cin >> rg3;
                                   std::cout << "\n\n";
                                   std::cout << "\t\t\t you want the bills in: \n"
                                             << endl;
                                   std::cout << "\t\t"
                                             << "^" << setfill(' ') << setw(20) << "1_ month" << setw(39) << "^" << endl;
                                   std::cout << "\t\t"
                                             << "^" << setfill(' ') << setw(19) << "2_ year" << setw(40) << "^" << endl;
                                   std::cout << "\t\t"
                                             << "^" << setfill(' ') << setw(30) << "3_ periode of time" << setw(29) << "^" << endl;
                                   int tzzz;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> tzzz;
                                   switch (tzzz)
                                   {
                                   case 1:
                                        std::cout << "\t\t\t enter the month" << endl;
                                        int tm;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> tm;
                                        if (tm > 12 || tm < 0)
                                        {
                                             std::cout << "\t\t\t Invalid month entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        std::cout << "\t\t\t enter the year" << endl;
                                        int ty;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> ty;
                                        if (ty > 2072 || ty < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        // getOneMonthBillRegion(Algeria, rg3, tm, ty)
                                        break;
                                   case 2:
                                        std::cout << "\t\t\t enter the year" << endl;
                                        int ty2;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> ty2;
                                        if (ty2 > 2072 || ty2 < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }

                                        // getOneYearBillRegion(Algeria, rg3,ty2);
                                        break;

                                   case 3:
                                        std::cout << "\t\t\t enter the start month" << endl;
                                        int sm;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> sm;
                                        if (sm < 0 || sm > 12)
                                        {
                                             std::cout << "\t\t\t Invalid month entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }

                                        std::cout << "\t\t\t enter the start year" << endl;
                                        int sy;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> sy;
                                        if (sy > 2052 || sy < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }

                                        std::cout << "\t\t\t enter the end month" << endl;
                                        int em;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> em;
                                        if (em < 0 || em > 12)
                                        {
                                             std::cout << "\t\t\t Invalid month entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        std::cout << "\t\t\t enter the end year" << endl;
                                        int ey;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> ey;
                                        if (ey > 2052 || ey < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        // getOnePeriodBillRegion(Algeria, rg3,sm, em, sy, ey);
                                        break;
                                   default:
                                        break;
                                   }

                                   break;
                              case 4:
                                   std::cout << "\n\n";
                                   std::cout << "\t\t\t you want the bills in: \n"
                                             << endl;
                                   std::cout << "\t\t"
                                             << "^" << setfill(' ') << setw(20) << "1_ month" << setw(39) << "^" << endl;
                                   std::cout << "\t\t"
                                             << "^" << setfill(' ') << setw(19) << "2_ year" << setw(40) << "^" << endl;
                                   std::cout << "\t\t"
                                             << "^" << setfill(' ') << setw(30) << "3_ periode of time" << setw(29) << "^" << endl;
                                   int ttz;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> ttz;
                                   switch (ttz)
                                   {
                                   case 1:
                                        std::cout << "\t\t\t enter the month" << endl;
                                        int tm;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> tm;
                                        if (tm > 12 || tm < 0)
                                        {
                                             std::cout << "\t\t\t Invalid month entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        std::cout << "\t\t\t enter the year" << endl;
                                        int ty;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> ty;
                                        if (ty > 2072 || ty < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        // getOneMonthBillCountry(Algeria, tm, ty)
                                        break;
                                   case 2:
                                        std::cout << "\t\t\t enter the year" << endl;
                                        int ty2;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> ty2;
                                        if (ty2 > 2072 || ty2 < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }

                                        // getOneYearBillCountry(Algeria,ty2);
                                        break;

                                   case 3:
                                        std::cout << "\t\t\t enter the start month" << endl;
                                        int sm;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> sm;
                                        if (sm < 0 || sm > 12)
                                        {
                                             std::cout << "\t\t\t Invalid month entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }

                                        std::cout << "\t\t\t enter the start year" << endl;
                                        int sy;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> sy;
                                        if (sy > 2052 || sy < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }

                                        std::cout << "\t\t\t enter the end month" << endl;
                                        int em;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> em;
                                        if (em < 0 || em > 12)
                                        {
                                             std::cout << "\t\t\t Invalid month entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        std::cout << "\t\t\t enter the end year" << endl;
                                        int ey;
                                        std::cout << "\t\t\t\t";
                                        std::cin >> ey;
                                        if (ey > 2052 || ey < 2022)
                                        {
                                             std::cout << "\t\t\t Invalid year entered!!\n\n";
                                             std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                             break;
                                        }
                                        // getOnePeriodBillCountry(Algeria,sm, em, sy, ey);
                                        break;
                                   default:
                                        break;
                                   }
                                   break;

                              default:
                                   break;
                              }

                              break;
                         }

                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Bottom border
                         break;

                    case 4:
                         int dw, mw, yw;
                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Top border
                         std::cout << "\t\t\t\t   displaying weather" << endl;

                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 30) << "Enter the date" << setw(29) << "^" << endl;
                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 43) << "day" << setw(42) << "^" << endl;
                         std::cout << "\t\t\t\t";
                         std::cin >> dw;
                         if (dw < 0 || dw > 31)
                         {
                              std::cout << "\t\t\t Invalid day entered!!\n";
                              std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                              break;
                         }

                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 41) << "month" << setw(40) << "^" << endl;
                         std::cout << "\t\t\t\t";
                         std::cin >> mw;
                         if (mw > 12 || mw < 0)
                         {
                              std::cout << "\t\t\t Invalid month entered!!\n";
                              std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                              break;
                         }

                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 42) << "year" << setw(41) << "^" << endl;
                         std::cout << "\t\t\t\t";
                         std::cin >> yw;
                         if (yw > 2052 || yw < 2022)
                         {
                              std::cout << "\t\t\t Invalid year entered!!\n";
                              std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                              break;
                         }
                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Bottom border

                         wht.printWeatherInfo(yw, mw, dw);

                         break;
                    case 5:

                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Top border
                         std::cout << "\t\t\t\t   Best customer " << endl;

                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                         // BST.displayWinner();
                         cout << "\t\t\t BST.displayWinner();" << endl;

                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Bottom border

                         break;

                    case 6:

                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Top border
                         std::cout << "\t\t\t\t   listing of departements " << endl;

                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                         // printBestDepartments();
                         cout << "\t\t\t printBestDepartments();" << endl;

                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Bottom border

                         break;
                    case 7:

                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Top border
                         std::cout << "\t\t\t\t   Top 10 departements: " << endl;

                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                         // getBest10();
                         cout << "\t\t\t getBest10();" << endl;

                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Bottom border

                         break;
                    case 8:

                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Top border
                         std::cout << "\t\t\t\t   Worst 10departements: " << endl;

                         std::cout << "\t\t"
                                   << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                         // getWorst10();
                         cout << "\t\t\t getWorst10();" << endl;

                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl; // Bottom border

                         break;

                    case 9:
                         conn = false;
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
               long int ID;
               std::cout << "\t\t\t\t\t";
               std::cin >> ID;
               if (std::cin.fail())
               {
                    throw std::runtime_error("Input was not an integer.");
               }
               else if (ID > 99999999999 || ID < 0)
               {
                    std::cout << "\t\t\t Invalid ID entered!!\n";
                    std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                    break;
               }

               // if id exists
               std::cout << "\t\t"
                         << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
               std::cout << "\t\t"
                         << "^" << setfill(' ') << setw(width - 15) << "How would you like to display the bill?" << setw(14) << "^" << endl;
               std::cout << "\t\t"
                         << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
               std::cout << "\t\t"
                         << "^" << setfill(' ') << setw(39) << "1. For a specific month in a year" << setw(20) << "^" << endl;
               std::cout << "\t\t"
                         << "^" << setfill(' ') << setw(28) << "2. For a specific year" << setw(31) << "^" << endl;
               std::cout << "\t\t"
                         << "^" << setfill(' ') << setw(29) << "3. For a period of time" << setw(30) << "^" << endl;
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

                    std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(width - 1) << "^" << endl; // Empty line
                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(width - 30) << "Enter the month:" << setw(29) << "^" << endl;
                    int cm;
                    std::cout << "\t\t\t\t\t";
                    std::cin >> cm;
                    if (cm < 0 || cm > 12)
                    {
                         std::cout << "\t\t\t Invalid month entered!!\n";
                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                         break;
                    }

                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(width - 31) << "Enter the year:" << setw(30) << "^" << endl;
                    int cy;
                    std::cout << "\t\t\t\t\t";
                    std::cin >> cy;
                    if (cy < 2022 || cy > 2072)
                    {
                         std::cout << "\t\t\t Invalid year entered!!\n";
                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                         break;
                    }

                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(width - 1) << "^" << endl;
                    std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                    std::cout << "\n\n";
                    // getOnemonthBill(Algeria, ID, cm, cy)
                    break;
               case 2:
                    std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(width - 30) << "Enter the year:" << setw(29) << "^" << endl;
                    int cy2;
                    std::cout << "\t\t\t\t\t";
                    std::cin >> cy2;
                    if (cy2 < 2022 || cy2 > 2072)
                    {
                         std::cout << "\t\t\t Invalid year entered!!\n";
                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                         break;
                    }

                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(width - 1) << "^" << endl;
                    // getOneYearBill(Algeria, ID, cy2)
                    std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                    std::cout << "\n\n";
                    break;
               case 3:
                    std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;

                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(width - 20) << "Enter the start month:" << setw(19) << "^" << endl;
                    int sm2;
                    std::cout << "\t\t\t\t\t";
                    std::cin >> sm2;
                    if (sm2 < 0 || sm2 > 12)
                    {
                         std::cout << "\t\t\t Invalid month entered!!\n";
                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                         break;
                    }

                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(width - 21) << "Enter the start year:" << setw(20) << "^" << endl;
                    int sy2;
                    std::cout << "\t\t\t\t\t";
                    std::cin >> sy2;
                    if (sy2 < 2022 || sy2 > 2072)
                    {
                         std::cout << "\t\t\t Invalid year entered!!\n";
                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                         break;
                    }

                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(width - 22) << "Enter the end month:" << setw(21) << "^" << endl;
                    int em2;
                    std::cout << "\t\t\t\t\t";
                    std::cin >> em2;
                    if (em2 < 0 || em2 > 12)
                    {
                         std::cout << "\t\t\t Invalid month entered!!\n";
                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                         break;
                    }

                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(width - 23) << "Enter the end year:" << setw(22) << "^" << endl;
                    int ey2;
                    std::cout << "\t\t\t\t\t";
                    std::cin >> ey2;
                    if (ey2 < 2022 || ey2 > 2072)
                    {
                         std::cout << "\t\t\t Invalid year entered!!\n";
                         std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                         break;
                    }
                    std::cout << "\t\t"
                              << "^" << setfill(' ') << setw(width - 1) << "^" << endl;
                    // getPeriodBill(Algeria, ID, sm2, em2, sy2, ey2);
                    std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                    std::cout << "\n\n";
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
               std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
               std::cout << "\n\n";
               break;
          }
     } while (n != '1' && n != '2');
}

menu::~menu() {}
#endif