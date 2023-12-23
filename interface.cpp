#include <iostream>
#include "menu.h"
#include "userFunctions.cpp"

using namespace std;

int main()
{
    cout << "Electricity Management system loading.." << endl;
    htRegions Alg;
    DepartmentHeap AlgHeap;
    FillHashTablesRCD(Alg, AlgHeap);
    SetCustomersFromFile(Alg);
    FillHashTablesRCD(Alg, AlgHeap);
    try
    {
        menu m(Alg, AlgHeap);
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


















































