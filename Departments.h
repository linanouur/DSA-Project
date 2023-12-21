#ifndef DEPARTMENTS_H
#define DEPARTMENTS_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition of the Department class
class Department
{
public:
    int city_id;
    double budget;
    double totalAmountPaid;

    // Constructor with default values for parameters
    Department(int id = 0, double budg = 100000.00, double amountPaid = 0.0)
        : city_id(id), budget(budg), totalAmountPaid(amountPaid) {}

    // Member functions for setting and getting budget and total amount paid
    void setBudget(double);
    double getBudget() const;
    void setTotalAmountPaid(double);
    double getTotalAmountPaid() const;
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
    void printHeap(const vector<int> &heap) const;
    void printBestDepartments();
    void printWorstDepartments();
    void getBest10() const;
    void getWorst10() const;
};


#endif
