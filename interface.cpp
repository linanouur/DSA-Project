#include <iostream>
#include "menu.h"
#include "userFunctions.cpp"

using namespace std;

int main()
{
    cout << "Loading.." << endl;
    htRegions Alg;
    DepartmentHeap AlgHeap;
    FillHashTablesRCD(Alg,AlgHeap);
   // SetCustomersFromFile(Alg);
    FillHashTablesRCD(Alg,AlgHeap);
    try
    {
        cout << "Electricity network management system loading..." << endl;
        menu m;
        m.display();
        m.HomePage();
        return 0;
    }
    catch (...)
    {
        // Catch-all handler for any other exceptions
        std::cerr << "Unknown exception caught" << std::endl;
    }
}


















































