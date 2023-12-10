#include <iostream>
#include <string>
#include "Customer.h"
#include "calendar.cpp"
#include "bills.cpp"
using namespace std;

void setInfoOneMonth(Customers * BST, int ID, int month, int year, int Mconsumption, int Minjection)
{
    Customer *cust = BST->searchCustomer(ID);
    cust->setTotalInjection(Minjection);
    if(cust->totalInjection > BST->getmaxAmoutInjected())  BST->setInfoNewInjector(ID,Minjection);
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


void getOneMonthBill(Customers * BST, int ID, int month, int year){
    // cout << "Region: " << Region << "  City: " << City << "  District: " << District << endl;
    cout << "Bill of " << month
         << " / " << year << " : " << endl;
    Customer *cust = BST->searchCustomer(ID);
    cout << "Customer: " << cust->firstName << " " << cust->FamilyName << " , Electricity Account ID: " << cust->ElectricityAccountId << endl;
    if (cust != nullptr)
    {
        Year &y = cust->Customeryears->getYear(year);
        Bill &m = y.yearMonths->getbill(month);
        m.displayBill();
    }
    else
    {
        cout << "Customer not found." << endl;
    }
}



void Customer ::setTotalInjection(int value)
{
    totalInjection = totalInjection + value;
}

int Customer ::getCustomerId()
{
    return ElectricityAccountId;
}

Customer::Customer(string fname, string lname, int ElecId, int bankAccount, int numMemb, string region, string city, string district)
{

    setInfo(fname, lname, ElecId, bankAccount, numMemb, region, city, district);
}

void Customer::setInfo(string fname, string lname, int ElecId, int bankAccount, int numMemb, string region, string city, string district)
{
    firstName = fname;
    FamilyName = lname;
    ElectricityAccountId = ElecId;
    BankAccount = bankAccount;
    familyMembersNumber = numMemb;
    Region = region;
    City = city;
    District = district;

    haveInjectedBefore = false;
    left = nullptr;
    right = nullptr;
}

void Customers::insertNewCustomer(string fname, string lname, int ElecId, int bankAccount, int numMemb, string region, string city, string district)
{
    Customer *cus = new Customer(fname, lname, ElecId, bankAccount, numMemb, region, city, district);
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


void Customers ::setInfoNewInjector(int ID, int newValue)
{
    maxInjectorID = ID;
    maxAmountInjected = newValue;
}

int Customers ::getmaxInjectorID()
{
    return maxInjectorID;
}

 int Customers ::getmaxAmoutInjected()
{
    return maxAmountInjected;
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
