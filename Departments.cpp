/* USING A SINGLE HEAP:
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;
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
    vector<Department> heap;

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parentIndex = (index - 1) / 2;
            if (heap[index].totalAmountPaid > heap[parentIndex].totalAmountPaid)
            {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int index)
    {
        int leftChild = 2*index + 1;
        int rightChild = 2*index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild].totalAmountPaid > heap[largest].totalAmountPaid)
        {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild].totalAmountPaid > heap[largest].totalAmountPaid)
        {
            largest = rightChild;
        }

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insertDepartment(const Department &department)
    {
        heap.push_back(department);
        heapifyUp(heap.size() - 1);
    }

    void updateBudget()
    {
        auto start = high_resolution_clock::now();

        sort(heap.begin(), heap.end(), [](const Department &a, const Department &b)
            { return a.totalAmountPaid > b.totalAmountPaid; });
        int numDepartments = heap.size();
        heap[0].budget *= 1.15;
        for (int i = 1; i < 10; ++i)
        {
            heap[i].budget *= 1.10;
        }
        heap[numDepartments - 1].budget *= 0.85;
        for (int i = numDepartments - 2; i >= numDepartments - 9; --i)
        {
            heap[i].budget *= 0.90;
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    }

    void printHeap() const
    {
        cout << "dep Name               Budget            Profit" << endl;
        for (const auto &department : heap)
        {
            cout << department.cityName << "       " << department.budget << " dzd           " << department.totalAmountPaid << " dzd\n";
        }
    }
};

int main()
{
    DepartmentHeap dh;

    Department d1("Algiers", 100000.00, 800000);
    Department d2("Setif", 100000.00, 900000);
    Department d3("Oran", 100000.00, 300000);
    Department d4("Batna", 100000.00, 40000);
    Department d5("Constantine", 100000.00, 500000);
    Department d6("Tipaza", 100000.00, 750000);
    Department d7("Medea", 100000.00, 200000);
    Department d8("Mascara", 100000.00, 100000);
    Department d9("Mostaganem", 100000.00, 450000);
    Department d10("Jijel", 100000.00, 250000);
    Department d11("Tizi", 100000.00, 660000);
    Department d12("Annaba", 100000.00, 770000);
    Department d13("Blida", 100000.00, 880000);
    Department d14("Bordj", 100000.00, 550000);
    Department d15("Bejaia", 100000.00, 123456);
    Department d16("Ilizi", 100000.00, 654321);
    Department d17("Skikda", 100000.00, 234567);
    Department d18("Djelfa", 100000.00, 456789);
    Department d19("Taref", 100000.00, 678909);
    Department d20("Boumerdes", 100000.00, 213212);
    dh.insertDepartment(d1);
    dh.insertDepartment(d2);
    dh.insertDepartment(d3);
    dh.insertDepartment(d4);
    dh.insertDepartment(d5);
    dh.insertDepartment(d6);
    dh.insertDepartment(d7);
    dh.insertDepartment(d8);
    dh.insertDepartment(d9);
    dh.insertDepartment(d10);
    dh.insertDepartment(d11);
    dh.insertDepartment(d12);
    dh.insertDepartment(d13);
    dh.insertDepartment(d14);
    dh.insertDepartment(d15);
    dh.insertDepartment(d16);
    dh.insertDepartment(d17);
    dh.insertDepartment(d18);
    dh.insertDepartment(d19);
    dh.insertDepartment(d20);

    cout << "**************Initial Heap:*****************\n";
    dh.printHeap();
    dh.updateBudget();
    cout << "\n***********Heap after modifications:***************\n";
    dh.printHeap();

    return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

class Department
{
public:
    string cityName;
    double budget;
    double totalAmountPaid;

    Department(const string &name = "", double budg = 100000.00, double amountPaid = 0.0) : cityName(name), budget(budg), totalAmountPaid(amountPaid) {}
};

/*class DepartmentHeap
{
private:
    vector<Department> maxHeap;
    vector<Department> minHeap;

    void maxHeapifyUp(int index)
    {
        while (index > 0)
        {
            int parentIndex = (index - 1) / 2;
            if (maxHeap[index].totalAmountPaid > maxHeap[parentIndex].totalAmountPaid)
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

    void maxHeapifyDown(int index)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < maxHeap.size() && maxHeap[leftChild].totalAmountPaid > maxHeap[largest].totalAmountPaid)
        {
            largest = leftChild;
        }

        if (rightChild < maxHeap.size() && maxHeap[rightChild].totalAmountPaid > maxHeap[largest].totalAmountPaid)
        {
            largest = rightChild;
        }

        if (largest != index)
        {
            swap(maxHeap[index], maxHeap[largest]);
            maxHeapifyDown(largest);
        }
    }

    void minHeapifyUp(int index)
    {
        while (index > 0)
        {
            int parentIndex = (index - 1) / 2;
            if (minHeap[index].totalAmountPaid < minHeap[parentIndex].totalAmountPaid)
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

    void minHeapifyDown(int index)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < minHeap.size() && minHeap[leftChild].totalAmountPaid < minHeap[smallest].totalAmountPaid)
        {
            smallest = leftChild;
        }

        if (rightChild < minHeap.size() && minHeap[rightChild].totalAmountPaid < minHeap[smallest].totalAmountPaid)
        {
            smallest = rightChild;
        }

        if (smallest != index)
        {
            swap(minHeap[index], minHeap[smallest]);
            minHeapifyDown(smallest);
        }
    }

public:
    void insertDepartment(const Department &department)
    {
        maxHeap.push_back(department);
        minHeap.push_back(department);

        maxHeapifyUp(maxHeap.size() - 1);
        minHeapifyUp(minHeap.size() - 1);
    }

    void updateBudget()
    {
        auto start = high_resolution_clock::now();
        int numDepartments = maxHeap.size();
        maxHeap[0].budget *=1.15;
        for (int i = 1; i < 10; ++i)
        {
            maxHeap[i].budget *= 1.10;
        }

        minHeap[0].budget *=0.85;
        for (int i = 0; i < 10; ++i)
        {
            minHeap[i].budget *= 0.90;
        }

        maxHeap[numDepartments-1].budget*=0.85;
        for (int i= numDepartments-2; i>numDepartments-10; --i)
        {
            maxHeap[i].budget*=0.90;
        }
        minHeap[numDepartments-1].budget*=1.15;
        for (int i= numDepartments-2; i>numDepartments-10; --i)
        {
            minHeap[i].budget*=1.10;
        }


        make_heap(maxHeap.begin(), maxHeap.end(), [](const Department &a, const Department &b) {
            return a.totalAmountPaid < b.totalAmountPaid;
        });

        make_heap(minHeap.begin(), minHeap.end(), [](const Department &a, const Department &b) {
            return a.totalAmountPaid > b.totalAmountPaid;
        });

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    }

    void printHeap(const vector<Department> &heap) const
    {
        cout << "Department\t" << "Budget\t" << "Profit" << endl;
        for (const auto &department : heap)
        {
            cout << department.cityName << "\t\t" << department.budget << " dzd\t" << department.totalAmountPaid << " dzd\n";
        }
    }

    void printBestDepartments()
    {
        printHeap(maxHeap);
    }

    void printWorstDepartments()
    {
        printHeap(minHeap);
    }
};*/
class DepartmentHeap
{
private:
    vector<Department> departments;
    vector<int> maxHeap;
    vector<int> minHeap;

    void maxHeapifyUp(int index)
    {
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

    void maxHeapifyDown(int index)
    {
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

    void minHeapifyUp(int index)
    {
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

    void minHeapifyDown(int index)
    {
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

public:
    void insertDepartment(const Department &department)
    {
        departments.push_back(department);
        maxHeap.push_back(departments.size() - 1);
        minHeap.push_back(departments.size() - 1);
        maxHeapifyUp(maxHeap.size() - 1);
        minHeapifyUp(minHeap.size() - 1);
        maxHeapifyDown(maxHeap.size() - 1);
        minHeapifyDown(minHeap.size() - 1);
        
    }

    void updateBudget()
    {
        auto start = high_resolution_clock::now();

        departments[maxHeap[0]].budget *= 1.15;
        for (int i = 1; i < 10; ++i)
        {
            departments[maxHeap[i]].budget *= 1.10;
        }

        departments[minHeap[0]].budget *= 0.85;
        for (int i = 1; i < 10; ++i)
        {
            departments[minHeap[i]].budget *= 0.90;
        }

        make_heap(maxHeap.begin(), maxHeap.end(), [&](const int &a, const int &b)
                  { return departments[a].totalAmountPaid < departments[b].totalAmountPaid; });

        make_heap(minHeap.begin(), minHeap.end(), [&](const int &a, const int &b)
                  { return departments[a].totalAmountPaid > departments[b].totalAmountPaid; });

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\n\tTime taken by function: " << duration.count() << " microseconds" << endl;
    }

    void printHeap(const vector<int> &heap) const
    {
        cout << "Department\t" << "Budget\t" << "Profit" << endl;
        for (const auto &departmentIndex : heap)
        {
            const auto &department = departments[departmentIndex];
            cout << department.cityName << "\t\t" << department.budget << " dzd\t" << department.totalAmountPaid << " dzd\n";
        }
    }

    void printBestDepartments()
    {
        printHeap(maxHeap);
    }

    void printWorstDepartments()
    {
        printHeap(minHeap);
    }
};

int main()
{
    DepartmentHeap dh;

    Department d1("Alger", 100000.00, 111);
    Department d2("Setif", 100000.00, 222);
    Department d3("Oran", 100000.00, 333);
    Department d4("Batna", 100000.00, 444);
    Department d5("Const", 100000.00, 555);
    Department d6("Tipaza", 100000.00, 666);
    Department d7("Medea", 100000.00, 777);
    Department d8("Mascara", 100000.00, 888);
    Department d9("Mosta", 100000.00, 999);
    Department d10("Jijel", 100000.00, 1111);
    Department d11("Tizi", 100000.00, 2222);
    Department d12("Annaba", 100000.00, 3333);
    Department d13("Blida", 100000.00, 4444);
    Department d14("Bordj", 100000.00, 5555);
    Department d15("Bejaia", 100000.00, 6666);
    Department d16("Ilizi", 100000.00, 7777);
    Department d17("Skikda", 100000.00, 8888);
    Department d18("Djelfa", 100000.00, 9999);
    Department d19("Taref", 100000.00, 11111);
    Department d20("Boumerd", 100000.00, 22222);
    Department d21("Oued", 100000.00, 33333);
    Department d22("Bayd", 100000.00, 44444);
    Department d23("Defla", 100000.00, 55555);
    Department d24("Tbessa", 100000.00, 66666);

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
    return 0;
}
