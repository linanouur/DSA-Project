<<<<<<< Updated upstream
#include "City.h"
#include "District.h"
#include "Regions.h"

int main() {
    // Create hash tables
    htRegions regionsTable;
    htCities citiesTable;
    htDistricts districtsTable;

    // Create and insert regions
    Region region1(1, "North Region");
    Region region2(2, "South Region");
    Region region3(3, "East Region");

    regionsTable.insertRegion(region1);
    regionsTable.insertRegion(region2);
    regionsTable.insertRegion(region3);

    // Create and insert cities
    City cityA(101, "City A");
    City cityB(102, "City B");
    City cityC(103, "City C");

    citiesTable.insertCity(cityA, region1.region_id);
    citiesTable.insertCity(cityB, region2.region_id);
    citiesTable.insertCity(cityC, region3.region_id);

    // Create and insert districts
    District districtX(1001, "District X");
    District districtY(1002, "District Y");
    District districtZ(1003, "District Z");

    districtsTable.insertDistrict(cityA.city_id, districtX);
    districtsTable.insertDistrict(cityB.city_id, districtY);
    districtsTable.insertDistrict(cityC.city_id, districtZ);

    // Accessing data
    Region* foundRegion = regionsTable.getRegion(1);
    if (foundRegion != nullptr) {
        City* foundCity = citiesTable.getCity(101);
        if (foundCity != nullptr) {
            District* foundDistrict = districtsTable.getDistrict(1001);

            // Displaying information
            std::cout << "Region: " << foundRegion->region_name << std::endl;
            std::cout << "City: " << foundCity->city_name << std::endl;
            std::cout << "District: " << foundDistrict->district_name << std::endl;
        } else {
            std::cout << "City not found." << std::endl;
        }
    } else {
        std::cout << "Region not found." << std::endl;
    }

    return 0;
=======
#include<iostream>  
#include<fstream> 
#include<sstream> 
#include<string>
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
          AddCustomer(); 
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
 void AddCustomer() {  
   string firstname , lastname, distrcit, city , regioin ;  
   int electID , bankAccount , numMem ; 
   vector<int> ages ;  
        cout<<"\nEnter Customer Electricity Account ID" ;  
        cin>>electID ; 
        cout<<"\nEnter customer first Name"; 
        cin>>fname;  
        cout<<"\nEnter Customer last name " ; 
        cin>>lastname;  
        cout<<"\nEnter Customer District " ;  
        cin>>district ; 
        cout<<"\nEnter Customer city" ;  
        cin>>city ;  
        cout<<"\nEnter Customer region" ;  
        cin>>region ;     
        cout<<"\nEnter Customer Family Members " ;  
        cin>>numMem;  
         cout<<"\nEnter Customer family Numbers ages  " ;   
         int age 
        for(int i=0;i<numMem; i++)  
        {  
             cin>>age ;
        if (age <0 ) {
            break;
        }
        ages.push_back(age);
        }



       


        Customer ()
 }



    return 0; 
>>>>>>> Stashed changes
}
