#ifndef DEPARTMENTS_H
#define DEPARTMENTS_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Department
{
public:
    int city_id;
    double budget;
    double totalAmountPaid;
    Department(int id = 0, double budg = 100000.00, double amountPaid = 0.0) : city_id(id), budget(budg), totalAmountPaid(amountPaid) {}
    void setBudget(double);
    double getBudget() const;
    void setTotalAmountPaid(double);
    double getTotalAmountPaid() const;
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
    void insert(int);
    void insertDepartment(const Department &department);
    void updateBudget();
    void printHeap(const vector<int> &heap) const;
    void printBestDepartments();
    void printWorstDepartments();
    void getBest10() const;
    void getWorst10() const;
};
#endif
