#ifndef DEPARTMENTS_CPP
#define DEPARTMENTS_CPP
#include <iostream>
#include <vector>
#include <algorithm>
#include "Departments.h"
#include "City.h"
#include "City.cpp"
#include <chrono>
using namespace std;
using namespace chrono;

void DepartmentHeap::maxHeapifyUp(int index)
{
    while (index>0) {
        int parentIndex = (index-1)/2;
        if (departments[maxHeap[index]].totalAmountPaid > departments[maxHeap[parentIndex]].totalAmountPaid) {
            swap(maxHeap[index], maxHeap[parentIndex]);
            index = parentIndex;
        }
        else {
            break;
        }
    }
}

void DepartmentHeap::maxHeapifyDown(int index)
{
    int leftChild = 2*index +1;
    int rightChild = 2*index +2;
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

void DepartmentHeap::minHeapifyUp(int index)
{
    while (index>0)
    {
        int parentIndex = (index-1)/2;
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

void DepartmentHeap::minHeapifyDown(int index)
{
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;
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

void DepartmentHeap::insertDepartment(const Department &department)
{
    departments.push_back(department);
    maxHeap.push_back(departments.size()-1);
    minHeap.push_back(departments.size()-1);
    maxHeapifyUp(maxHeap.size()-1);
    minHeapifyUp(minHeap.size()-1);
    maxHeapifyDown(maxHeap.size()-1);
    minHeapifyDown(minHeap.size()-1);
}

void DepartmentHeap::updateBudget()
{
    auto start = high_resolution_clock::now();

    departments[maxHeap[0]].budget *=1.15;
    for (int i=1; i<10; i++)
    {
        departments[maxHeap[i]].budget *=1.10;
    }

    departments[minHeap[0]].budget *= 0.85;
    for (int i=1; i<10; i++)
    {
        departments[minHeap[i]].budget *=0.90;
    }

    make_heap(maxHeap.begin(), maxHeap.end(), [&](const int &a, const int &b)
        { return departments[a].totalAmountPaid < departments[b].totalAmountPaid; });

    make_heap(minHeap.begin(), minHeap.end(), [&](const int &a, const int &b)
        { return departments[a].totalAmountPaid > departments[b].totalAmountPaid; });

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "\n\tTime taken by function: " << duration.count() << " microseconds" << endl;
}

void DepartmentHeap::printHeap(const vector<int>&heap) const
{
    cout << "Department\t"
         << "Budget\t"
         << "Profit" << endl;
    for (const auto &departmentIndex: heap)
    {
        const auto &department = departments[departmentIndex];
        cout << department.city_id << "\t\t" << department.budget << " dzd\t" << department.totalAmountPaid << " dzd\n";
    }
}

void DepartmentHeap::printBestDepartments()
{
    printHeap(maxHeap);
}

void DepartmentHeap::printWorstDepartments()
{
    printHeap(minHeap);
}
void DepartmentHeap:: getBest10() const
{
    cout << "Best 10 Departments of this year: " << endl;
    for (int i=0; i<10; i++)
    {
        cout << i+1 << ". " <<departments[maxHeap[i]].city_id << endl;
    }
}
void DepartmentHeap:: getWorst10() const
{
    cout << "Worst 10 Departments of this year: " << endl;
    for (int i=0; i<10; i++)
    {
        cout << i+1 << ". " <<departments[minHeap[i]].city_id << endl;
    }
}

void Department:: setBudget(double budg)
{
    this->budget = budg;
}
void Department:: setTotalAmountPaid(double tap)
{
    this->totalAmountPaid = tap;
}
double Department:: getBudget() const
{
    return this->budget;
}
double Department:: getTotalAmountPaid() const
{
    return this->totalAmountPaid;
}

/*int main()
{
    /*DepartmentHeap dh;
    Department d1(1, 100000.00, 111);
    Department d2(2, 100000.00, 222);
    Department d3(3, 100000.00, 333);
    Department d4(4, 100000.00, 444);
    Department d5(5, 100000.00, 555);
    Department d6(6, 100000.00, 666);
    Department d7(7, 100000.00, 777);
    Department d8(8, 100000.00, 888);
    Department d9(9, 100000.00, 999);
    Department d10(10, 100000.00, 1111);
    Department d11(11, 100000.00, 2222);
    Department d12(12, 100000.00, 3333);
    Department d13(13, 100000.00, 4444);
    Department d14(14, 100000.00, 5555);
    Department d15(15, 100000.00, 6666);
    Department d16(16, 100000.00, 7777);
    Department d17(17, 100000.00, 8888);
    Department d18(18, 100000.00, 9999);
    Department d19(19, 100000.00, 11111);
    Department d20(20, 100000.00, 22222);
    Department d21(21, 100000.00, 33333);
    Department d22(22, 100000.00, 44444);
    Department d23(23, 100000.00, 55555);
    Department d24(24, 100000.00, 66666);

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
    cout << "-----------------BEST-----------------------" << endl;
    dh.printBestDepartments();
    cout << "-----------------WORST-----------------------" << endl;
    dh.printWorstDepartments();
    dh.updateBudget();
    cout << "\n***********After Updating:***************\n";
    cout << "-----------------  BEST  -----------------------" << endl;
    dh.printBestDepartments();
    cout << "-----------------  WORST -----------------------" << endl;
    dh.printWorstDepartments();

    dh.getBest10();
    dh.getWorst10();
    return 0;
}*/
#endif
