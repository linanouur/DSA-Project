#include <iostream>
#include"menu.h"


using namespace std;


int main (){
    try{ menu m;
     m.display();
     m.HomePage();
    
     }catch (...) {
        // Catch-all handler for any other exceptions
        std::cerr << "Unknown exception caught" << std::endl;
    } 
     return 0; 
}



