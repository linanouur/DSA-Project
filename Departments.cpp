#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Department {
public:
    string cityName;
    double budget;
    double totalAmountPaid;

    Department(const string& name="",double budg= 100000.00, double amountPaid=0.0) : cityName(name),budget(budg), totalAmountPaid(amountPaid) {}
};

class DepartmentHeap {
private:
    vector<Department> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index].totalAmountPaid > heap[parentIndex].totalAmountPaid) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild].totalAmountPaid > heap[largest].totalAmountPaid) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild].totalAmountPaid > heap[largest].totalAmountPaid) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insertDepartment(const Department& department) {
        heap.push_back(department);
        heapifyUp(heap.size() - 1);
    }

    void updateBudget() {

        sort(heap.begin(), heap.end(), [](const Department& a, const Department& b) {
            return a.totalAmountPaid > b.totalAmountPaid;
        });
        int numDepartments = heap.size();
        heap[0].budget *= 1.15;
        for (int i = 1; i < 10; ++i) {
            heap[i].budget *= 1.10;
        }
        heap[numDepartments - 1].budget *= 0.85;
        for (int i = numDepartments - 2; i >= numDepartments - 9; --i) {
            heap[i].budget *= 0.90;
        }
    }

    void printHeap() const {
        cout << "dep Name               Budget            Profit" << endl;
        for (const auto& department : heap) {
            cout << department.cityName << "       " << department.budget << " dzd           "  << department.totalAmountPaid << " dzd\n";
        }
    }
};

int main() {
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
}

