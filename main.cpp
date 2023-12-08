#include"City.h"
#include"District.h"
#include"Regions.h"

int main() {
    // Create hash tables
    htRegions regionsTable;
    htCities citiesTable;
    htDistricts districtsTable;

    // Create and insert regions
    Region region1(1, "North Region");
    Region region2(2, "South Region");
    Region region3(3, "East Region");

    regionsTable.insertRegion(region1);
    regionsTable.insertRegion(region2);
    regionsTable.insertRegion(region3);

    // Create and insert cities
    City cityA(101, "City A");
    City cityB(102, "City B");
    City cityC(103, "City C");

    citiesTable.insertCity(cityA, region1.region_id);
    citiesTable.insertCity(cityB, region2.region_id);
    citiesTable.insertCity(cityC, region3.region_id);

    // Create and insert districts
    District districtX(1001, "District X");
    District districtY(1002, "District Y");
    District districtZ(1003, "District Z");

    districtsTable.insertDistrict(cityA.city_id, districtX);
    districtsTable.insertDistrict(cityB.city_id, districtY);
    districtsTable.insertDistrict(cityC.city_id, districtZ);

    // Accessing data
    Region* foundRegion = regionsTable.getRegion(1);
    if (foundRegion != nullptr) {
        City* foundCity = citiesTable.getCity(101);
        if (foundCity != nullptr) {
            District* foundDistrict = districtsTable.getDistrict(1001);

            // Displaying information
            std::cout << "Region: " << foundRegion->region_name << std::endl;
            std::cout << "City: " << foundCity->city_name << std::endl;
            std::cout << "District: " << foundDistrict->district_name << std::endl;
        } else {
            std::cout << "City not found." << std::endl;
        }
    } else {
        std::cout << "Region not found." << std::endl;
    }

    return 0;
}
