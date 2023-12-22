#include "consolebarchart.h"
#include <fstream>

using namespace aarsoftx;

int main(int argc, char **argv) {
    vector<ConsoleChartData> result;

    // Read data from file
    ifstream file("data.txt");
    if (file.is_open()) {
        string name;
        int value;
        while (file >> name >> value) {
            result.push_back({name, value});
        }
        file.close();
    } else {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Create and show the bar chart
    ConsoleBarChart *cbc = new ConsoleBarChart("Monthly Salary", 3, 500, result);
    cbc->show();

    return 0;
}
