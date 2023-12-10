#include <iostream>
#include <string>
#include "Customer.h"
#include "calendar.cpp"
#include "bills.cpp"
using namespace std;


int getRegionId(int CustomerID) { 
    string CustomerIDString = to_string(CustomerID);
    string regionID = CustomerIDString.substr(0, 2);
   return stoi (regionID) ;
} 
int getCityId(int CustomerID) {
    string CustomerIDString = to_string(CustomerID);
    string cityID = CustomerIDString.substr(2, 2);
    return stoi(cityID);
}
int getDistrictId(int CustomerID) {
    string CustomerIDString = to_string(CustomerID);
    string districtID = CustomerIDString.substr(4, 2);
   return stoi (districtID) ;
}   
int getCustomerID(int CustomerID) {
    string CustomerIDString = to_string(CustomerID);
    string customerID = CustomerIDString.substr(6, CustomerIDString.length()-6);
    return stoi(customerID);
}

void setInfoOneMonth(Customers * BST, int ID, int month, int year, int Mconsumption, int Minjection)
{
    Customer *cust = BST->searchCustomer(ID);
    cust->setTotalInjection(Minjection);
    if(cust->totalInjection > BST->getmaxAmoutInjected())  BST->setInfoNewInjector(ID,cust->totalInjection,cust->Region,cust->City,cust->District);
    if (cust != nullptr)
    {
        Year &y = cust->Customeryears->getYear(year);
        y.setYearlyTotal(Mconsumption*5);
        y.setYearlyCredit(Minjection*3);
        Bill &m = y.yearMonths->getbill(month);
        m.setBillInfo(Mconsumption,Minjection);
    }
    else
    {
        cout << "Customer not found." << endl;
    }
}


// void getOneMonthBill(Customers * BST, int ID, int month, int year){
//     // cout << "Region: " << Region << "  City: " << City << "  District: " << District << endl;
//     cout << "Bill of " << month
//          << " / " << year << " : " << endl;
//     Customer *cust = BST->searchCustomer(ID);
//     cout << "Customer: " << cust->firstName << " " << cust->FamilyName << " , Electricity Account ID: " << cust->ElectricityAccountId << endl;
//     if (cust != nullptr)
//     {
//         Year &y = cust->Customeryears->getYear(year);
//         Bill &m = y.yearMonths->getbill(month);
//         m.displayBill();
//     }
//     else
//     {
//         cout << "Customer not found." << endl;
//     }
// }


// void getPeriodBill(Customers * BST, int ID, int monthStart , int monthEnd, int yearStart , int yearEnd){
//     // cout << "Region: " << Region << "  City: " << City << "  District: " << District << endl;
//     cout << "Bill of " << monthStart <<
//          << " / " << yearStart << " : " << endl;
//     Customer *cust = BST->searchCustomer(ID);
//     cout << "Customer: " << cust->firstName << " " << cust->FamilyName << " , Electricity Account ID: " << cust->ElectricityAccountId << endl;
    // if (cust != nullptr)
    // {
    //     Year &y = cust->Customeryears->getYear(year);
    //     Bill &m = y.yearMonths->getbill(month);
    //     m.displayBill();
    // }
    // else
    // {
    //     cout << "Customer not found." << endl;
    // }
// }

// void getOneYearBill(Customers * BST, int ID, int year){
//     // cout << "Region: " << Region << "  City: " << City << "  District: " << District << endl;
//     cout << "Bill of " << year << " : " << endl;
//     Customer *cust = BST->searchCustomer(ID);
//     cout << "Customer: " << cust->firstName << " " << cust->FamilyName << " , Electricity Account ID: " << cust->ElectricityAccountId << endl;
//     if (cust != nullptr)
//     {
//         Year &y = cust->Customeryears->getYear(year);
//         Bill &m = y.yearMonths->getbill(month);
//         m.displayBill();
//     }
//     else
//     {
//         cout << "Customer not found." << endl;
//     }
// }

void Customer ::setTotalInjection(int value)
{
    totalInjection = totalInjection + value;
}

int Customer ::getCustomerId()
{
    return ElectricityAccountId;
}

Customer::Customer (string fname, string lname, int bankAccount,  int numMemb, string region, string city, string district)
{

    setInfo(fname, lname, bankAccount, numMemb, region, city, district);  
    ElectricityAccountId = generateCustomerID();
    
}




void Customer::setInfo(string fname, string lname, int bankAccount, int numMemb, string region, string city, string district)
{
    firstName = fname;
    FamilyName = lname;
    
    BankAccount = bankAccount;
    familyMembersNumber = numMemb;
    Region = region;
    City = city;
    District = district;

    haveInjectedBefore = false;
    left = nullptr;
    right = nullptr; 
    vector<string> IDs = getIDs(Region,City,District);  
    
  
} 
 vector<string> Customer ::getIDs( string region, string city,  string district)
{
   ifstream file("RegionCityDistrict.csv");
    string line;
    string IDorName;
    vector<string> IDSorNames;

    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return vector<string>(3, ""); 
    }

    while (getline(file, line)) {
        istringstream lineStream(line);
        IDSorNames.clear();

        while (getline(lineStream, IDorName, ',')) {
            IDSorNames.push_back(IDorName);
        }

        if (IDSorNames.size() >= 6 && 
            IDSorNames[1] == region && 
            IDSorNames[3] == city && 
            IDSorNames[5] == district) {
            return vector<string> {IDSorNames[0], IDSorNames[2], IDSorNames[4]}; 
        }
    }

    return vector<string>(3, ""); 

} 
 string  Customer ::  getConcatenatedIDs(string region, string city, string district)
{
    vector<string> IDs = getIDs(region,city,district);
    string concatenatedIDs = "";

    
        concatenatedIDs = IDs[0] + IDs[1] + IDs[2];
     
          
    return concatenatedIDs;

    
}  
int Customer ::  generateCustomerID() {
    static  int CustomerIDS =1; 
    string concatenatedIDs = getConcatenatedIDs(Region,City,District); 
    string CustomerID = concatenatedIDs + to_string(CustomerIDS);
    CustomerIDS++;
    

    return stoi(CustomerID);
}


void Customers::insertNewCustomer(string fname, string lname, int bankAccount, int numMemb, string region, string city, string district)
{
    Customer *cus = new Customer(fname, lname,bankAccount, numMemb, region, city, district);
    rootCus = insert(rootCus, cus);
}

Customer *Customers::insert(Customer *root, Customer *node)
{
    if (root == nullptr)
    {
        return node;
    }
    else if (node->ElectricityAccountId <= root->ElectricityAccountId)
    {
        root->left = insert(root->left, node);
    }
    else
    {
        root->right = insert(root->right, node);
    }
    return root;
}

Customer *Customers::searchCustomer(int ID, Customer *r)
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

Customer *Customers::searchCustomer(int ID)
{
    return searchCustomer(ID, rootCus);
}


    void Customers::printInorder(Customer *ptr)
{
    if (ptr == NULL)
        return;

    printInorder(ptr->left);

   cout.width(10);
   cout << ptr->firstName;
   cout.width(20);
    cout<<ptr->FamilyName;
    cout.width(10);
    cout<<ptr->ElectricityAccountId << endl;

    printInorder(ptr->right);
}


void Customers::print()
{
    printInorder(rootCus);
}


void Customers ::setInfoNewInjector(int ID, int newValue , string RW, string CW, string DW)
{
    maxInjectorID = ID;
    maxAmountInjected = newValue;
    regionWinner = RW;
    cityWinner = CW;
    districtWinner = DW;
}

int Customers ::getmaxInjectorID()
{
    return maxInjectorID;
}

 int Customers ::getmaxAmoutInjected()
{
    return maxAmountInjected;
}

void Customers :: displayWinner(){
cout << "The winner of this month is: "<<endl;
cout << "ID Winner: "<< maxInjectorID << endl;
cout << "From: "<< regionWinner <<"  "<<cityWinner << "  " << districtWinner<<endl;
cout << "with an injection Amount : " << maxAmountInjected  <<endl;
}


int main()
{
    Customers BST;
    BST.insertNewCustomer("John", "Doe", 12345, 54321, 3, "North", "Mahelma", "Bouira");
    BST.insertNewCustomer("Jane", "Doe", 67890, 21345, 1, "South", "Algiers", "Bab El Oued");
    BST.insertNewCustomer("Michael", "Smith", 45678, 87654, 4, "East", "Constantine", "Salah Bey");
    BST.insertNewCustomer("Emma", "Brown", 23456, 12345, 2, "West", "Oran", "Es Senia");
    BST.insertNewCustomer("David", "Miller", 89012, 98765, 5, "North", "Skikda", "El Harrouch");
    BST.insertNewCustomer("Aisha", "Boudjemaa", 76543, 89012, 2, "South", "Tlemcen", "Nedroma");
    BST.insertNewCustomer("Karim", "Belkacem", 34567, 56789, 4, "East", "Batna", "Merouana");
    BST.insertNewCustomer("Fatima", "Zohra", 12345, 34567, 1, "West", "Annaba", "El Bouni");
    BST.print(); // Outputs the ElectricityAccountId values of the customers
    cout << endl;

    cout<<"enter customer id"<<endl; 
    int id ;
    cin>>id;
    cout<<getRegionId(id)<<endl;
    cout<<getCityId(id)<<endl;
    cout<<getDistrictId(id)<<endl;
    cout<<getCustomerID(id)<<endl;


   Customer *cust = BST.searchCustomer(67890);
    if (cust != nullptr)
    {
        cust->Customeryears->insertYear(1950);
        Year &y = cust->Customeryears->getYear(1950);
        Bill &m = y.yearMonths->getbill(3);
        cout << "Month number: " << m.numberMonth << endl;
    }
    else
    {
        cout << "Customer not found." << endl;
    }  
    return 0;
}


int getPrize(Customers *BST){
    cout<<"The winner ID: ";
    return BST->getmaxInjectorID();
}
