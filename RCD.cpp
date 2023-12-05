#include <iostream>
#include <string>

const int TABLE_SIZE = 100;

class District {
public:
    int district_id;
    std::string district_name;
    District() : district_id(0), district_name("") {}
    District(int id, const std::string& name) : district_id(id), district_name(name) {}
};

class City {
public:
    int city_id;
    std::string city_name;
    District districts[TABLE_SIZE];
    int numDistricts;

    City() : city_id(0), city_name(""), numDistricts(0) {}
    City(int id, const std::string& name) : city_id(id), city_name(name), numDistricts(0) {}

    // Function to initialize districts
    void initializeDistricts() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            districts[i] = District(0, ""); // Initialize each district
        }
    }
};

class Region {
public:
    int region_id;
    std::string region_name;
    City cities[TABLE_SIZE];
    int numCities;
    
    Region() : region_id(0), region_name(""), numCities(0) {}
    Region(int id, const std::string& name) : region_id(id), region_name(name), numCities(0) {}

    // Function to initialize cities
    void initializeCities() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cities[i] = City(0, ""); // Initialize each city
        }
    }
};

class HashTable {
private:
    Region regions[TABLE_SIZE];

    int hashFunctionRegion(int key) {
        return key % TABLE_SIZE;
    }

    int hashFunctionCity(int key, int regionId) {
        return (key + regionId) % TABLE_SIZE;
    }

    int hashFunctionDistrict(int key, int cityId) {
        return (key + cityId) % TABLE_SIZE;
    }

public:
    void insertRegion(const Region& region) {
        int index = hashFunctionRegion(region.region_id);
        regions[index] = region;
    }

    Region* searchRegion(int regionId) {
        int index = hashFunctionRegion(regionId);
        return &regions[index];
    }

    City* insertCity(Region& region, int cityId, const std::string& cityName) {
        if (region.numCities < TABLE_SIZE) {
            int index = hashFunctionCity(cityId, region.region_id);
            City& city = region.cities[index];
            city.city_id = cityId;
            city.city_name = cityName;
            return &city;
        }
        return nullptr;
    }

    District* insertDistrict(City& city, int districtId, const std::string& districtName) {
        if (city.numDistricts < TABLE_SIZE) {
            int index = hashFunctionDistrict(districtId, city.city_id);
            District& district = city.districts[index];
            district.district_id = districtId;
            district.district_name = districtName;
            return &district;
        }
        return nullptr;
    }
};

int main() {
    std::cout << "Program Start" << std::endl;

    HashTable hashTable;

    // Example usage:
    Region region1(1, "North Region");
    region1.initializeCities();
    hashTable.insertRegion(region1);

    Region* foundRegion = hashTable.searchRegion(1);
    if (foundRegion != nullptr) {
        City* city1 = hashTable.insertCity(*foundRegion, 101, "City A");
        city1->initializeDistricts();
        District* district1 = hashTable.insertDistrict(*city1, 1001, "District X");

        // Accessing data
        std::cout << foundRegion->region_name << " - " << city1->city_name << " - " << district1->district_name << std::endl;
    } else {
        std::cout << "Region not found" << std::endl;
    }

    std::cout << "Program End" << std::endl;

    return 0;
}

