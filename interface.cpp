#include<iostream>  
#include <fstream> 
#include <sstream>
using namespace std ; 
int main (){     
    int choice =1; 
    while (choice!= 6) 
    { 
     cout<<"\n ************************************** "<<endl; 
    cout<<"welcome to the Electricity Management Company "<<endl;  
     cout<<"\n ************************************** "<<endl; 
    cout <<"SYSTEM MENU :"<<endl;  

    cout<<"\n1.Add Customer  "<<endl;  
    cout <<"\n2.delete Customer "; 
    cout<<"\n3.Display Customer Bill"; 
    cout<<"\n4.Display All customer Bills in a district/city/region"; 
    cout<<"\n5.Display Performance of a Department ";  
    cout<<"\n6.exit";   
    cout<<"enter your choice"<<endl;  
    cin>>choice ; 
       switch(choice)
        {
          case 1:  
          cout<<"\nenter Customer ID "; 
          cin>>
                  break;
          case 2:
          
                  break;
          case 3:  
          cout<<"\nEnter Customer ID " <<endl; 
          cin>>ID; 
          cout<<"\nEnter Month , Year " << endl;  
          cin>> 

                  break;
          case 4:  
          cout<<"\nChoose one of the following  " ; 
          cout <<"\n1.Region \n2.City \n3.District" ; 
           
           cout<<"\nChoose one of the following Formats  " ;  
           cout <<"\n1.Month , Year "; 
            
           cout<<"\n3.Start Date " ; 
           cout<<"\n3.End Date " ; 
                  break; 
                  case 5: 
          case 6: break;
          default:{
          	   cout<<"\n\n  Invalid Choice...!";
          	   cout<<"\n\n Press any key to continue..";
          	  
	  }
        } 
    }



    return 0; 
}
