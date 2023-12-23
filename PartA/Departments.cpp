#ifndef DEPARTMENTS_CPP
#define DEPARTMENTS_CPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "Departments.h"
#include "City.h"
#include "City.cpp"
#include "District.h"
#include "District.cpp"
#include <iomanip>
#include <chrono>

using namespace std;
using namespace chrono;

// Definition of maxHeapifyUp function
void DepartmentHeap::maxHeapifyUp(int index)
{
    // Move the element up in the max heap until the heap property is satisfied
    while (index > 0)
    {
        int parentIndex = (index - 1) / 2;
        if (departments[maxHeap[index]].totalAmountPaid > departments[maxHeap[parentIndex]].totalAmountPaid)
        {
            swap(maxHeap[index], maxHeap[parentIndex]);
            index = parentIndex;
        }
        else
        {
            break;
        }
    }
}

// Definition of maxHeapifyDown function
void DepartmentHeap::maxHeapifyDown(int index)
{
    // Move the element down in the max heap until the heap property is satisfied
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < maxHeap.size() && departments[maxHeap[leftChild]].totalAmountPaid > departments[maxHeap[largest]].totalAmountPaid)
    {
        largest = leftChild;
    }

    if (rightChild < maxHeap.size() && departments[maxHeap[rightChild]].totalAmountPaid > departments[maxHeap[largest]].totalAmountPaid)
    {
        largest = rightChild;
    }

    if (largest != index)
    {
        swap(maxHeap[index], maxHeap[largest]);
        maxHeapifyDown(largest);
    }
}

// Definition of minHeapifyUp function
void DepartmentHeap::minHeapifyUp(int index)
{
    // Move the element up in the min heap until the heap property is satisfied
    while (index > 0)
    {
        int parentIndex = (index - 1) / 2;
        if (departments[minHeap[index]].totalAmountPaid < departments[minHeap[parentIndex]].totalAmountPaid)
        {
            swap(minHeap[index], minHeap[parentIndex]);
            index = parentIndex;
        }
        else
        {
            break;
        }
    }
}

// Definition of minHeapifyDown function
void DepartmentHeap::minHeapifyDown(int index)
{
    // Move the element down in the min heap until the heap property is satisfied
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < minHeap.size() && departments[minHeap[leftChild]].totalAmountPaid < departments[minHeap[smallest]].totalAmountPaid)
    {
        smallest = leftChild;
    }

    if (rightChild < minHeap.size() && departments[minHeap[rightChild]].totalAmountPaid < departments[minHeap[smallest]].totalAmountPaid)
    {
        smallest = rightChild;
    }

    if (smallest != index)
    {
        swap(minHeap[index], minHeap[smallest]);
        minHeapifyDown(smallest);
    }
}

// Definition of insertDepartment function
void DepartmentHeap::insertDepartment(const Department &department)
{
    // Adding the department to the vector
    departments.push_back(department);

    // Adding the indices to both max and min heaps
    maxHeap.push_back(departments.size() - 1);
    minHeap.push_back(departments.size() - 1);

    // Maintaining heap properties
    maxHeapifyUp(maxHeap.size() - 1);
    minHeapifyUp(minHeap.size() - 1);
    maxHeapifyDown(maxHeap.size() - 1);
    minHeapifyDown(minHeap.size() - 1);
}

// Definition of updateBudget function
void DepartmentHeap::updateBudget()
{
    // Recording the start time
    auto start = high_resolution_clock::now();

    // Updating budgets based on performance
    departments[maxHeap[0]].budget *= 1.15;
    for (int i = 1; i < 10; i++)
    {
        departments[maxHeap[i]].budget *= 1.10;
    }

    departments[minHeap[0]].budget *= 0.85;
    for (int i = 1; i < 10; i++)
    {
        departments[minHeap[i]].budget *= 0.90;
    }

    // Rebuilding max and min heaps
    make_heap(maxHeap.begin(), maxHeap.end(), [&](const int &a, const int &b)
              { return departments[a].totalAmountPaid < departments[b].totalAmountPaid; });

    make_heap(minHeap.begin(), minHeap.end(), [&](const int &a, const int &b)
              { return departments[a].totalAmountPaid > departments[b].totalAmountPaid; });

    // Calculating and displaying the time taken
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n\tTime taken by function: " << duration.count() << " microseconds" << endl;
}

// printHeap function to display the heap elements with their attributes
void DepartmentHeap::printHeap(const vector<int> &heap, int year)
{
    for (int i = 0; i < departments.size(); i++)
    {
        departments[maxHeap[i]].setTotalAmountPaid(year);
    }
     for (int i = 0; i < departments.size(); i++)
    {
        departments[minHeap[i]].setTotalAmountPaid(year);
    }
    make_heap(maxHeap.begin(), maxHeap.end(), [&](const int &a, const int &b)
              { return departments[a].totalAmountPaid < departments[b].totalAmountPaid; });
    make_heap(minHeap.begin(), minHeap.end(), [&](const int &a, const int &b)
              { return departments[a].totalAmountPaid > departments[b].totalAmountPaid; });

     cout << left << setw(15) << "Department ID"
         << setw(25) << "Department name"
         << setw(15) << "Budget"
         << setw(15) << "Profit" << endl;

    for (const auto &departmentIndex : heap) {
        const auto &department = departments[departmentIndex];
        cout << setw(15) << department.city_id
             << setw(25) << department.city_name
             << setw(15) << fixed << setprecision(2) << department.budget 
             << setw(15) << fixed << setprecision(2) << department.totalAmountPaid << " dzd" << endl;
    }
}

void Department ::setInfo(int month, int year, int CustomerPayment, int Minjection)
{
    YearDepartment *Year = Departmentyears->getYear(year);
    Year->payment += CustomerPayment;
    Month *m = Year->YMonths->getmonth(month);
    int value = 3 * Minjection;
    m->setMonthInfo(value);
}

// printWorstDepartments function to print the departments from the best to the worst
void DepartmentHeap::printDepartments(int year)
{
    printHeap(maxHeap, year);
}

/* printWorstDepartments function to print the departments from the worst to best NOT NEEDED
void DepartmentHeap::printWorstDepartments(int year)
{
    printHeap(minHeap, year);
}*/

// getBest10 function to display the best 10 departments of the year
void DepartmentHeap::getBest10(int year) 
{
    for (auto dep : departments)
    {
        dep.setTotalAmountPaid(year);
    }
    make_heap(maxHeap.begin(), maxHeap.end(), [&](const int &a, const int &b)
              { return departments[a].totalAmountPaid < departments[b].totalAmountPaid; });
    make_heap(minHeap.begin(), minHeap.end(), [&](const int &a, const int &b)
              { return departments[a].totalAmountPaid > departments[b].totalAmountPaid; });
    cout << "Best 10 Departments of year " << year << " :" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (departments[maxHeap[i]].getTotalAmountPaid()< departments[maxHeap[i+1]].getTotalAmountPaid()) {
            swap(departments[maxHeap[i]], departments[maxHeap[i + 1]]);
        }
        cout << i + 1 << ". " << departments[maxHeap[i]].city_id << " ~ " << departments[minHeap[i]].city_name << endl;
    }
}

// getWorst10 function to display the worst 10 departments of the year
void DepartmentHeap::getWorst10(int year) 
{
        for (auto dep : departments)
    {
        dep.setTotalAmountPaid(year);
    }
    make_heap(maxHeap.begin(), maxHeap.end(), [&](const int &a, const int &b)
              { return departments[a].totalAmountPaid < departments[b].totalAmountPaid; });
    make_heap(minHeap.begin(), minHeap.end(), [&](const int &a, const int &b)
              { return departments[a].totalAmountPaid > departments[b].totalAmountPaid; });
    cout << "Worst 10 Departments of this year: " << endl;
    for (int i = 0; i < 10; i++)
    {
        if (departments[maxHeap[i]].getTotalAmountPaid()> departments[maxHeap[i+1]].getTotalAmountPaid()) {
            swap(departments[maxHeap[i]], departments[maxHeap[i + 1]]);
        }
        cout << i + 1 << ". " << departments[minHeap[i]].city_id << " ~ " << departments[minHeap[i]].city_name << endl;
    }
}

// setBudget function in the Department class for setting the budget for the department
void Department::setBudget(double budg)
{
    this->budget = budg;
}

// setTotalAmountPaid function in the Department class for setting the total amount paid for the department
void Department::setTotalAmountPaid(int year)
{
    YearDepartment *Y = Departmentyears->getYear(year);
    totalAmountPaid = Y->payment;
}

// getBudget function in the Department class for getting the budget of the department
double Department::getBudget() const
{
    return this->budget;
}

// getTotalAmountPaid function in the Department class for getting the total amount paid for the department
double Department::getTotalAmountPaid() const
{
    return this->totalAmountPaid;
}

/*int main()
{
    DepartmentHeap dh;
    Department d1(1, "A", 100000.00, 111);
    Department d2(2, "B", 100000.00, 222);
    Department d3(3, "C", 100000.00, 333);
    Department d4(4, "D", 100000.00, 444);
    Department d5(5, "E", 100000.00, 555);
    Department d6(6, "F", 100000.00, 666);
    Department d7(7, "G", 100000.00, 777);
    Department d8(8, "H", 100000.00, 888);
    Department d9(9, "I", 100000.00, 999);
    Department d10(10, "J", 100000.00, 1111);
    Department d11(11, "K", 100000.00, 2222);
    Department d12(12, "L", 100000.00, 3333);
    Department d13(13, "M", 100000.00, 4444);
    Department d14(14, "N", 100000.00, 5555);
    Department d15(15, "O", 100000.00, 6666);
    Department d16(16, "P", 100000.00, 7777);
    Department d17(17, "Q", 100000.00, 8888);
    Department d18(18, "R", 100000.00, 9999);
    Department d19(19, "S", 100000.00, 11111);
    Department d20(20, "T", 100000.00, 22222);
    Department d21(21, "U", 100000.00, 33333);
    Department d22(22, "V", 100000.00, 44444);
    Department d23(23, "W", 100000.00, 55555);
    Department d24(24, "X", 100000.00, 66666);

    dh.insertDepartment(d1);
    dh.insertDepartment(d2);
    dh.insertDepartment(d3);
    dh.insertDepartment(d4);
    dh.insertDepartment(d5);
    dh.insertDepartment(d6);
    dh.insertDepartment(d7);
    dh.insertDepartment(d8);
    dh.insertDepartment(d9);
    dh.insertDepartment(d11);
    dh.insertDepartment(d10);
    dh.insertDepartment(d12);
    dh.insertDepartment(d13);
    dh.insertDepartment(d14);
    dh.insertDepartment(d15);
    dh.insertDepartment(d16);
    dh.insertDepartment(d17);
    dh.insertDepartment(d18);
    dh.insertDepartment(d19);
    dh.insertDepartment(d20);
    dh.insertDepartment(d21);
    dh.insertDepartment(d22);
    dh.insertDepartment(d23);
    dh.insertDepartment(d24);

    cout << "**************Initial Heap:*****************\n";
    dh.printDepartments(2022);
    dh.updateBudget();
    cout << "\n***********After Updating:***************\n";
    dh.printDepartments(2022);

    
    cout << "-----------------  BEST 10 -----------------------" << endl;
    dh.getBest10(2022);
    cout << "-----------------  WORST 10-----------------------" << endl;
    dh.getWorst10(2022);
    return 0;
}*/
#endif
