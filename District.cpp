#include "District.h"
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


int main()
{
    htRegions regionHashTable;

    Region region1(1, "Region1");
    Region region2(2, "Region2");
    regionHashTable.insertRegion(region1);
    htDistricts districtHashTable;
    District district1(1, "District1");
    District district2(2, "District2");
    District district3(3, "District3");
    District district4(4, "District4"); 
    District district5(5, "District5");
    htCities cityHashTable;
    City city1(1, "City1");
    City city2(2, "City2");
    City city3(3, "City3");  
   
    districtHashTable.insertDistrictinCity(1, district1);
    districtHashTable.insertDistrictinCity(1, district2);
    districtHashTable.insertDistrictinCity(2, district3);
    districtHashTable.insertDistrictinCity(2, district4);
    districtHashTable.insertDistrictinCity(3, district5);
    regionHashTable.displaycities(1);


    return 0;
}


