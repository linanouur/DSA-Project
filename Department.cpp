#include<iostream> 
#include<queue>
#include<string>
#include<vector>
using namespace std;
// Department node
class Department
{
public:
    
    double YearlyConsumption;
    Department *left;
    Department *right;

    Department(double =0);
};

Department ::Department( double yearlyConsumption)
{
    YearlyConsumption=yearlyConsumption>0 ?yearlyConsumption :0 ; 
   // Budget = budget > 0 ? budget : 0;
    left = nullptr;
    right = nullptr;
}
// Department BST
class DepartmentBst
{
private:
    Department *root;

    Department *insertRecursive(Department *root, double yearlyconsump)
    {
        if (root == nullptr)
        {
            return new Department(yearlyconsump);
        }

        if (yearlyconsump < root->YearlyConsumption)
        {
            root->left = insertRecursive(root->left, yearlyconsump);
        }
        else if (yearlyconsump > root->YearlyConsumption)
        {
            root->right = insertRecursive(root->right, yearlyconsump);
        }

        return root;
    }

    void inOrderTraversalRecursive(Department *root, std::vector<double> &elements)
    {
        if (root != nullptr)
        {
            inOrderTraversalRecursive(root->right, elements);
            elements.push_back(root->YearlyConsumption);
            inOrderTraversalRecursive(root->left, elements);
        }
    }

public:
    DepartmentBst()
    {

        root = nullptr;
    }

    void insert(double yearlyconsump)
    {
        root = insertRecursive(root, yearlyconsump);
    }

    void getWorst10()
    {
        vector<double> elements;
        inOrderTraversalRecursive(root, elements);
        std::cout << " 10  worst departements: ";
        for (int i = elements.size() - 1; i >= elements.size() - 10; --i)
        {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }

    void getBest10()
    {
        vector<double> elements;
        inOrderTraversalRecursive(root, elements);
        std::cout << "10 best Departements: ";
        for (int i = 0; i < 10; ++i)
        {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
}; 
int main(){ 
    DepartmentBst D; 

    D.insert(50.3);
    D.insert(30.1);
    D.insert(20.6);
    D.insert(40.8);
    D.insert(70.9);
    D.insert(60.9);
    D.insert(80.9);
    D.insert(283.4);
    D.insert(34.5);
    D.insert(28.09);
    D.insert(93.7);
    D.insert(23.5);
    D.insert(12.4);
    D.insert(8.5);
    D.getBest10();
    D.getWorst10();

    return 0;
}