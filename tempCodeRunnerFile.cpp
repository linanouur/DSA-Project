//void setInfoOneMonth(htRegions Alg, int ID, int month, int year, int Mconsumption, int Minjection)
// {
//     Bill bill;
//     bill.setBillInfo(Mconsumption, Minjection);
//     int R = getRegionId(ID);
//     int C = getCityId(ID);
//     int D = getDistrictId(ID);
//     Region *Rptr = Alg.getRegion(R);
//     City *Cptr = Rptr->Cities->getCity(C);
//     District Dis=Cptr->Districts->getDistrict(D);
   
//     // District *Dptr = Cptr->Districts->getDistrict(D);
//     // Dptr->BST.setInfoCustomerOneMonthBST(ID, month, year, bill);
// }


// void getOnemonthBill(htRegions Alg, int ID, int month, int year)
// {
//     int R = getRegionId(ID);
//     int C = getCityId(ID);
//     int D = getDistrictId(ID);
//     Region *Rptr = Alg.getRegion(R);
//     City *Cptr = Rptr->Cities->getCity(C);
//      District Dis=Cptr->Districts->getDistrict(D);
//     Dis.BST.getOneMonthBillBST(ID,month,year);
//     // District *Dptr = Cptr->Districts->getDistrict(D);
//     // Dptr->BST.getOneMonthBillBST(ID, month, year);
// }

// void getOneYearBill(htRegions Alg, int ID, int year)
// {
//     int R = getRegionId(ID);
//     int C = getCityId(ID);
//     int D = getDistrictId(ID);
//     Region *Rptr = Alg.getRegion(R);
//     City *Cptr = Rptr->Cities->getCity(C);
//      District Dis=Cptr->Districts->getDistrict(D);
//     Dis.BST.getOneYearBillBST(ID,year);
//     // District *Dptr = Cptr->Districts->getDistrict(D);
//     // Dptr->BST.getOneYearBillBST(ID, year);
// }

// void getPeriodBill(htRegions &Alg, int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
// {
//     int R = getRegionId(ID);
//     int C = getCityId(ID);
//     int D = getDistrictId(ID);
//     Region *Rptr = Alg.getRegion(R);
//     City *Cptr = Rptr->Cities->getCity(C);
//      District Dis=Cptr->Districts->getDistrict(D);
//     Dis.BST.getPeriodBillBST(ID,monthStart,monthEnd,yearStart,yearEnd);
//     // District *Dptr = Cptr->Districts->getDistrict(D);
//     // Dptr->BST.getPeriodBillBST(ID, monthStart, monthEnd, yearStart, yearEnd);
// }
