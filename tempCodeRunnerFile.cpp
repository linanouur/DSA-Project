  ifstream file("RegionCityDistrict.csv");  

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string regionID, regionName, cityID, cityName, districtID, districtName;

            getline(ss, regionID, ',');
            getline(ss, regionName, ',');
            getline(ss, cityID, ',');
            getline(ss, cityName, ',');
            getline(ss, districtID, ',');
            getline(ss, districtName, ',');
            int RegionID, CityID, DistrictID;
            RegionID = stoi(regionID);
            CityID = stoi(cityID);
            DistrictID = stoi(districtID);
            regionHashTable.insertRegion(Region(RegionID, regionName));
            regionHashTable.insertCity(RegionID, City(CityID, cityName));
            regionHashTable.insertDistrict(RegionID, CityID, District(DistrictID, districtName));
        }

        file.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }