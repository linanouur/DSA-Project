#ifndef DEPARTMENTS_H
#define DEPARTMENTS_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Month {
    public:
    string monthName;
    int monthNumber;
    int TotalSpentAmount = 0;
    
    Month(){}
    Month(string name, int num)
    {
        monthName = name;
        monthNumber = num;
    }
    void setMonth(string name, int num)
    {
        monthName = name;
        monthNumber = num;
    }

    void setMonthInfo(int TotalSpent)
    {
      
        TotalSpentAmount = TotalSpentAmount+TotalSpent;
       
    }

};



class MonthsDepartment

{
public:
    Month months[13];
    MonthsDepartment() {
        const string monthNames[] = {
            "January", "February", "March", "April",
            "May", "June", "July", "August",
            "September", "October", "November", "December"};

        for (int i = 1; i <= 12; ++i)
        {
            months[i].setMonth(monthNames[i - 1], i);
        }
    }

    Month *getmonth(int month)
    {
        return &months[month];
    }
};

class YearDepartment
{ 
    public: 
     int payment = 0;
     MonthsDepartment *YMonths;
    int year;
    YearDepartment() { 
        YMonths = new MonthsDepartment();
    }
    YearDepartment(int num)
    {
        YMonths = new MonthsDepartment();
        year = num;
      
    }
};


class YearsDepartment
{ 
       public:   
   
      YearsDepartment() { }
  
     YearDepartment years[50];
    int hash(int numYear)
    {
        return numYear % 50;
    }

    void insertYear(int numYear)
    {
        years[hash(numYear)] = YearDepartment(numYear);
    }

    YearDepartment * getYear(int year)
    {
        return &years[hash(year)];
    }
}; 
// Definition of the Department class
class Department
{
public: 
    YearsDepartment *Departmentyears;
    int city_id; 
    string city_name;
    double budget;
    double totalAmountPaid;

    // Constructor with default values for parameters
    Department(int id = 0,string name="", double budg = 100000.00, double amountPaid = 0.0 )
        : city_id(id),city_name(name), budget(budg), totalAmountPaid(amountPaid) { Departmentyears = new YearsDepartment();
        for(int i=2022;i<2072;i++)
        {
            Departmentyears->insertYear(i);}
        }

    // Member functions for setting and getting budget and total amount paid
    void setBudget(double);
    double getBudget() const;
    void setTotalAmountPaid(int);
    double getTotalAmountPaid() const;
    void setInfo(int , int , int , int);
    // Custom swap function for the Department class
    friend void swap(Department& first, Department& second) noexcept {
        using std::swap;
        swap(first.city_id, second.city_id);
        swap(first.totalAmountPaid, second.totalAmountPaid);
        // Add other members if necessary
    }
};


// Definition of the DepartmentHeap class
class DepartmentHeap
{
private:
    // Vector to store Department objects
    vector<Department> departments;
    // Vectors to represent max and min heaps
    vector<int> maxHeap;
    vector<int> minHeap;

    // Private functions for heap maintenance
    void maxHeapifyUp(int index);
    void maxHeapifyDown(int index);
    void minHeapifyUp(int index);
    void minHeapifyDown(int index);

public:
    // Public member functions for various operations
    void insertDepartment(const Department &department);
    void updateBudget();
    void printHeap(const vector<int> &heap, int );
    void printDepartments(int);
    //void printWorstDepartments(int);
    void getBest10(int);
    void getWorst10(int);
}; 






#endif
