#include"year.h"
using namespace std;


class weatherHashTable {
private:
    std::vector<year> years;
    int startYear; 

public:
    weatherHashTable(int startYear,int numberOfYears );

    void addYear(int year);

    weather& getWeather(int year, int month, int day);

    void insertWeather(int year, int month, int day, const weather& weather) ;
    
    int getsize(){return years.size();}
};