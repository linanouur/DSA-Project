#include"City.h"
#include "District.h"
#include "Regions.h"

 /*int main()
{
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

    citiesTable.insertCity(cityA);
    citiesTable.insertCity(cityB);
    citiesTable.insertCity(cityC);

    regionsTable.insertCity(1, cityA);
    regionsTable.insertCity(2, cityB);
    regionsTable.insertCity(3, cityC);

    // Create and insert districts
    District districtX(1001, "District X");
    District districtY(1002, "District Y");
    District districtZ(1003, "District Z");

    districtsTable.insertDistrict(cityA.CityID, districtX);
    districtsTable.insertDistrict(cityB.CityID, districtY);
    districtsTable.insertDistrict(cityC.CityID, districtZ);

    // Accessing data
    Region *foundRegion = regionsTable.getRegion(1);
    if (foundRegion != nullptr)
    {
        City *foundCity = citiesTable.getCity(101);
        if (foundCity != nullptr)
        {
            District *foundDistrict = districtsTable.getDistrict(1001);

            // Displaying information
            std::cout << "Region: " << foundRegion->RegionName << std::endl;
            std::cout << "City: " << foundCity->CityName << std::endl;
            std::cout << "District: " << foundDistrict->DistrictName << std::endl;
        }
        else
        {
            std::cout << "City not found." << std::endl;
        }
    }
    else
    {
        std::cout << "Region not found." << std::endl;
    }

    return 0;
} 
*/
