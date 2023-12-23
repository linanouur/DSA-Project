#ifndef DISTRICT_H
#define DISTRICT_H

#include <iostream>
#include <string>
#include "customers.h"
#include "customers.h"
using namespace std;

const int num_dis = 100;
// class City;

class District
{
public:
    int DistrictID;
    string DistrictName;
    Customers BST;
    District();
    District(int id, const std::string &name);
    void getOneMonthBillinDistrict(int month, int year);
    void getPeriodBillinDistrict(int StartMonth, int StartYear, int EndMonth, int EnDYear);
    void getOneYearBillinDistrict(int year);
};

class htDistricts
{
public:
    District districts[num_dis];
    int hashFunctionDistrict(int key);
    void insertDistrict(const District &district);
    void insertDistrictinCity(int cityId, const District &district);
    District getDistrict(int districtId);
    District *getDistrictptr(int districtId);
    Customers *getBST(int districtID);
    void insertCustomerIntoDistrict(District &obj, Customer *node);
    void setInfoInDistrict(District &obj, int ID, int month, int year, Bill &b);
    void displayAllDistricts();

};

#endif
