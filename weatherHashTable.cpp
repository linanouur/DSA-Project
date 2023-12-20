#include"weatherHashTable.h"

weatherHashTable::weatherHashTable(){
    startYear=2022;
    addYear(2022+1);
}
weatherHashTable::weatherHashTable(int sy,int ny){
    startYear=sy;
    addYear(sy+ny);//resizing the table according to number of years

}
void  weatherHashTable::addYear(int year) {
        int yearIndex = year - startYear;
        if (yearIndex >= years.size()) { //we check if the added year is included
            // Resize the vector so that the added year will be included
            years.resize(yearIndex + 1);
        }
    }

weather& weatherHashTable::getWeather(int year, int month, int day) {
        int yearIndex = year - startYear;
        return years[yearIndex].getMonth(month).getDay(day).w;
    }

void weatherHashTable::insertWeather(int year, int month, int day, const weather& weather) {
        addYear(year); // Ensure the year exists
        int yearIndex = year - startYear;
        years[yearIndex].getMonth(month).getDay(day).w = weather;
        cout << "Weather inserted for " << year << "/" << month << "/" << day << endl;
    }

    
