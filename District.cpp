#include "District.h"
#include "City.h"

District::District() : district_id(0), district_name("") {}
District::District(int id, const std::string& name) : district_id(id), district_name(name) {}

int htDistricts::hashFunctionDistrict(int key) {
    return key % num_dis;
}

void htDistricts::insertDistrict(const District& district) {
    int index = hashFunctionDistrict(district.district_id);
    districts[index] = district;
}

District* htDistricts::getDistrict(int districtId) {
    int index = hashFunctionDistrict(districtId);
    return &districts[index];
}

void htDistricts::insertDistrict(int cityId, const District& district) {
    City* city = getCity(cityId); 
    if (city != nullptr) {
        city->city_disricts->insertDistrict(district);
    }
}
City* htDistricts::getCity(int cityId) {
    htCities cityHashTable; 
    City* city = cityHashTable.getCity(cityId); 
    return city;
}
