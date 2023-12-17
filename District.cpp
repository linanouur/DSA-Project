#include "District.h"
#include "City.h"
#include "Regions.h"
#include <iostream>
using namespace std;
#include <string>
District::District() : DistrictID(0), DistrictName("")
{
    BST = new Customers();
}
District::District(int id, const std::string &name) : DistrictID(id), DistrictName(name) {}

int htDistricts::hashFunctionDistrict(int key)
{
    return key % num_dis;
}

void htDistricts::insertDistrict(const District &district)
{
    int index = hashFunctionDistrict(district.DistrictID);
    districts[index] = district;
}

District *htDistricts::getDistrict(int districtId)
{
    int index = hashFunctionDistrict(districtId);
    return &districts[index];
}





