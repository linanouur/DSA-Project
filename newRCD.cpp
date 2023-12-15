#include<iostream>
#include<fstream> 
#include<sstream>
#include<string>
#include<unordered_map> 
#include <iomanip> 

using namespace std ;


// Customer class representing nodes in the BST
class Customer1 {
public:
     
    int ElectricityAccountId ; 
     

    Customer1* left;
    Customer1* right;

    Customer1(int idname ) :ElectricityAccountId(idname), left(nullptr), right(nullptr) {}
};
 
// CustomerBST class implementing a Binary Search Tree for customers within each district
class CustomerBST {
private:
    Customer1* root;
    int NumCustomers ; 
    Customer1* insertCustomer(Customer1* node, int ElectricityAccountId) {
        if (node == nullptr) {
            return new Customer1(ElectricityAccountId );
        }

        if (ElectricityAccountId < node->ElectricityAccountId) {
            node->left = insertCustomer(root->left, ElectricityAccountId);
        } else if (ElectricityAccountId > node->ElectricityAccountId) {
            node->right = insertCustomer(node->right,ElectricityAccountId);
        }

        return node;
    }

    void displayCustomer(Customer1* node) {
        if (node != nullptr) {
            displayCustomer(node->left);
            std::cout << node->ElectricityAccountId << " ";
            displayCustomer(node->right);
        }
    }  
    Customer1 *CustomerBST::searchCustomer(int ID, Customer1 *r)
{
    if (r == nullptr)
    {
        return nullptr;
    }
    else if (ID == r->ElectricityAccountId)
    {
        return r;
    }
    else if (ID < r->ElectricityAccountId)
    {
        return searchCustomer(ID, r->left);
    }
    else
    {
        return searchCustomer(ID, r->right);
    }
}

    
public:
    CustomerBST() : root(nullptr) {}

    void addCustomer(const  int & ElectricityAccountId) {
        root = insertCustomer(root, ElectricityAccountId);
    }

     CustomerBST &displayCustomers() {
        displayCustomer(root);
       
        return *this;
    } 
    CustomerBST & searchCustomers() {
        
       return *this ;
    } 
    Customer1 *CustomerBST::searchCustomer(int ID)
{
    return searchCustomer(ID, );
}
};

// DistrictHashTable class storing a hash table for each district containing a CustomerBST
class DistrictHashTable {

 

public: 
    unordered_map<int, CustomerBST> districtMap;
    void addDistrict(int districtID) {
        districtMap[districtID] = CustomerBST();
    }

    void addCustomer(int districtID, const int & ElectricityAccountId) {
        districtMap[districtID].addCustomer(ElectricityAccountId);
    }

    void displayCustomers(int districtID) {
        std::cout << "Customers in District " << districtID << ": ";
        districtMap[districtID].displayCustomers();
    }  
    void searchCustomerinDistrict(int districtID) {
        districtMap[districtID].searchCustomers();
    }

};

// CityHashTable class storing a hash table for each city containing a DistrictHashTable
class CityHashTable {

   
public: 

    unordered_map<int, DistrictHashTable> cityMap;
    void addCity(int cityID) {
        cityMap[cityID] = DistrictHashTable();
    }

    void addDistrict(int cityID, int districtID) {
        cityMap[cityID].addDistrict(districtID);
    }

    void addCustomerToDistrict(int cityID, int districtID, const int & ElectricityAccountId) {
        cityMap[cityID].addCustomer(districtID, ElectricityAccountId );
    }

    void displayCustomersInDistrict(int cityID, int districtID) {
        cityMap[cityID].displayCustomers(districtID);
    }    
    void searchCustomerinCity(int cityID, int districtID) {
        cityMap[cityID].searchCustomerinDistrict(districtID);
    }
    void displayCustomersInCity(int cityID) {
    cout << "Customers in City " << cityID << ":" << endl;
    for (auto& [districtID, district] : cityMap[cityID].districtMap) {
        district.displayCustomers(); // Assuming CustomerBST has a displayCustomers() method
    }
}
 
    
};

// RegionHashTable class storing a hash table for each region containing a CityHashTable
class RegionHashTable {

   

public:  
    unordered_map<int, CityHashTable> regionMap;
    void addRegion(int regionID) {
        regionMap[regionID] = CityHashTable();
    }

    void addCity(int regionID, int cityID) {
        regionMap[regionID].addCity(cityID);
    }

    void addDistrictToCity(int regionID, int cityID, int districtID) {
        regionMap[regionID].addDistrict(cityID, districtID);
    }

    void addCustomerToDistrict(int regionID, int cityID, int districtID, const int & ElectricityAccountId) {
        regionMap[regionID].addCustomerToDistrict(cityID, districtID, ElectricityAccountId);
    }

    void displayCustomersInDistrict(int regionID, int cityID, int districtID) {
        regionMap[regionID].displayCustomersInDistrict(cityID, districtID);
    }  
    void displayCustomersInCity(int regionID, int cityID) {
        regionMap[regionID].displayCustomersInCity(cityID);
    }  
    void searchCustomerInRegion(int regionID, int cityID, int districtID) {
        regionMap[regionID].searchCustomerinCity(cityID, districtID); }
    
     
      
};
/*
int main() {
    RegionHashTable hashTable;
    ifstream file("RegionCityDistrict.csv"); // Update the file path accordingly

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string regionID, regionName, cityID, cityName, districtID, districtName;

            getline(ss, regionID, ',');
            getline(ss, regionName, ',');
            getline(ss, cityID, ',');
            getline(ss, cityName, ',');
            getline(ss, districtID, ',');
            getline(ss, districtName, ',');
            int RegionID, CityID, DistrictID;
            RegionID=stoi(regionID); 
            CityID=stoi(cityID);
            DistrictID=stoi(districtID); 
            hashTable.addRegion(RegionID);
            hashTable.addCity(RegionID, CityID);
            hashTable.addDistrictToCity(RegionID, CityID, DistrictID); 
        
          
            
       

        }  

        file.close(); 
      
    } else {
        cout << "Unable to open file." << endl;
    }
 int number=12222; 
    std::cout << "Number with leading zero: " <<setw(5)<< setfill('0') << number << std::endl;
    return 0;
} 
*/