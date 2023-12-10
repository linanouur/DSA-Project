#include<iostream>
#include<fstream>
#include<iostream> 
#include<string>
#include<unordered_map> 

using namespace std ; 
// Customer class representing nodes in the BST
class Customer {
public:
     
    int IDname ; 
     

    Customer* left;
    Customer* right;

    Customer(int idname ) :IDname(idname), left(nullptr), right(nullptr) {}
};
 
// CustomerBST class implementing a Binary Search Tree for customers within each district
class CustomerBST {
private:
    Customer* root;
    int NumCustomers ; 
    Customer* insertCustomer(Customer* node, int IDname) {
        if (node == nullptr) {
            return new Customer(IDname );
        }

        if (IDname < node->IDname) {
            node->left = insertCustomer(root->left, IDname);
        } else if (IDname > node->IDname) {
            node->right = insertCustomer(node->right,IDname);
        }

        return node;
    }

    void displayCustomer(Customer* node) {
        if (node != nullptr) {
            displayCustomer(node->left);
            std::cout << node->IDname << " ";
            displayCustomer(node->right);
        }
    }

public:
    CustomerBST() : root(nullptr) {}

    void addCustomer(const  int & IDname) {
        root = insertCustomer(root, IDname);
    }

     CustomerBST &displayCustomers() {
        displayCustomer(root);
       
        return *this;
    }
};

// DistrictHashTable class storing a hash table for each district containing a CustomerBST
class DistrictHashTable {

 

public: 
    unordered_map<int, CustomerBST> districtMap;
    void addDistrict(int districtID) {
        districtMap[districtID] = CustomerBST();
    }

    void addCustomer(int districtID, const int & IDname) {
        districtMap[districtID].addCustomer(IDname);
    }

    void displayCustomers(int districtID) {
        std::cout << "Customers in District " << districtID << ": ";
        districtMap[districtID].displayCustomers();
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

    void addCustomerToDistrict(int cityID, int districtID, const int & IDname) {
        cityMap[cityID].addCustomer(districtID, IDname );
    }

    void displayCustomersInDistrict(int cityID, int districtID) {
        cityMap[cityID].displayCustomers(districtID);
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

    void addCustomerToDistrict(int regionID, int cityID, int districtID, const int & IDname) {
        regionMap[regionID].addCustomerToDistrict(cityID, districtID, IDname);
    }

    void displayCustomersInDistrict(int regionID, int cityID, int districtID) {
        regionMap[regionID].displayCustomersInDistrict(cityID, districtID);
    }  
    void displayCustomersInCity(int regionID, int cityID) {
        regionMap[regionID].displayCustomersInCity(cityID);
    } 
    
      
};

int main() {
    RegionHashTable hashTable;

    hashTable.addRegion(1); 
    hashTable.addRegion(2); 
    hashTable.addCity(1, 101); 
    hashTable.addCity(2,1);
    hashTable.addDistrictToCity(1,101,1001); 
    hashTable.addDistrictToCity(2,1,12);  
     hashTable.addDistrictToCity(2,1,13); 
    hashTable.addCustomerToDistrict(1, 101, 1001, 11011001); 
    hashTable.addCustomerToDistrict(2, 1, 12, 10000); 
    hashTable.addCustomerToDistrict(2, 1, 13, 1101131); 
    hashTable.addCustomerToDistrict(2, 1, 13, 1101132);
    hashTable.displayCustomersInDistrict(1, 101, 1001);   
    hashTable.displayCustomersInDistrict(2, 1, 12);  
    hashTable.displayCustomersInDistrict(2, 1, 13);   
    hashTable.displayCustomersInCity(2,1);  
   
    
   

    return 0;
}  

