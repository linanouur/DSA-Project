#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "userFunctions.cpp"
#include "Regions.h"
using namespace std;

void insertCustomersFromFile(htRegions &Reg)
{

    ifstream file("Customer.csv");

    if (file.is_open())
    {

        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string fname, lname, reg, city, dist, bnum, fnum, fage, id;
            int age, bankNum;
            int *ages;
            int regID, cityID, distID;

            getline(ss, fname, ',');
            getline(ss, lname, ',');
            getline(ss, reg, ',');
            getline(ss, city, ',');
            getline(ss, dist, ',');
            getline(ss, bnum, ',');
            bankNum = stoi(bnum);
                getline(ss, fnum, ',');
            int famNum = stoi(fnum);
            ages = new int[famNum];
            for (int i = 0; i < famNum; i++)
            {
                getline(ss, fage, ',');
                age = stoi(fage);
                ages[i] = age;
            }
            getline(ss, id, ',');
            long long ID = stoll(id);
            insertNewCustomer(Reg, fname, lname,bankNum,famNum,ages,reg,city,dist, ID);
        }

        file.close();
    }
    else
    {
        std::cout << "Unable to open file." << endl;
    }
}