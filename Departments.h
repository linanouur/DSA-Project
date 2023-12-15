#ifndef DEPARTMENTS_H
#define DEPARTMENTS_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Department
{
public:
    string cityName;
    double budget;
    double totalAmountPaid;
    Department(const string &name = "", double budg = 100000.00, double amountPaid = 0.0) : cityName(name), budget(budg), totalAmountPaid(amountPaid) {}
};

class DepartmentHeap
{
private:
    vector<Department> departments;
    vector<int> maxHeap;
    vector<int> minHeap;

    void maxHeapifyUp(int index);
    void maxHeapifyDown(int index);
    void minHeapifyUp(int index);
    void minHeapifyDown(int index);

public:
    void insertDepartment(const Department &department);
    void updateBudget();
    void printHeap(const vector<int> &heap) const;
    void printBestDepartments();
    void printWorstDepartments();
};
#endif
