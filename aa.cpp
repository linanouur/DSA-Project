                                   std::cout << "\t\t\t enter district" << endl;

                                   std::cout << "\t\t\t\t";
                                   std::cin >> dist1;
                                   std::cout << "\t\t\t enter city" << endl;

                                   std::cout << "\t\t\t\t";
                                   std::cin >> ct1;
                                   std::cout << "\t\t\t enter region" << endl;

                                   std::cout << "\t\t\t\t";
                                   std::cin >> rg1;
                                   // displayByDistrict(Algeria,rg, ct, dist);
                                   break;




                                   
                              std::cout << "\n\n";
                              std::cout << "\t\t\t you want the bill in: \n"
                                        << endl;
                              std::cout << "\t\t"
                                        << "^" << setfill(' ') << setw(20) << "1_ month" << setw(39) << "^" << endl;
                              std::cout << "\t\t"
                                        << "^" << setfill(' ') << setw(19) << "2_ year" << setw(40) << "^" << endl;
                              std::cout << "\t\t"
                                        << "^" << setfill(' ') << setw(30) << "3_ periode of time" << setw(29) << "^" << endl;
                              int t;
                              std::cout << "\t\t\t\t";
                              std::cin >> t;
                              switch (t)
                              {
                              case 1:
                                   std::cout << "\t\t\t enter the month" << endl;
                                   int tm;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> tm;
                                   if (tm > 12 || tm < 0)
                                   {
                                        std::cout << "\t\t\t Invalid month entered!!\n\n";
                                        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                        break;
                                   }
                                   std::cout << "\t\t\t enter the year" << endl;
                                   int ty;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> ty;
                                   if (ty > 2072 || ty < 2022)
                                   {
                                        std::cout << "\t\t\t Invalid year entered!!\n\n";
                                        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                        break;
                                   }
                                   // getOnemonthBill(Algeria, S_id, tm, ty);
                                   break;
                              case 2:
                                   std::cout << "\t\t\t enter the year" << endl;
                                   int ty2;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> ty2;
                                   if (ty2 > 2072 || ty2 < 2022)
                                   {
                                        std::cout << "\t\t\t Invalid year entered!!\n\n";
                                        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                        break;
                                   }
                                   // getOneYearBill(Algeria, S_id, ty);
                                   break;

                              case 3:
                                   std::cout << "\t\t\t enter the start month" << endl;
                                   int sm;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> sm;
                                   if (sm < 0 || sm > 12)
                                   {
                                        std::cout << "\t\t\t Invalid month entered!!\n\n";
                                        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                        break;
                                   }

                                   std::cout << "\t\t\t enter the start year" << endl;
                                   int sy;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> sy;
                                   if (sy > 2052 || sy < 2022)
                                   {
                                        std::cout << "\t\t\t Invalid year entered!!\n\n";
                                        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                        break;
                                   }

                                   std::cout << "\t\t\t enter the end month" << endl;
                                   int em;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> em;
                                   if (em < 0 || em > 12)
                                   {
                                        std::cout << "\t\t\t Invalid month entered!!\n\n";
                                        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                        break;
                                   }
                                   std::cout << "\t\t\t enter the end year" << endl;
                                   int ey;
                                   std::cout << "\t\t\t\t";
                                   std::cin >> ey;
                                   if (ey > 2052 || ey < 2022)
                                   {
                                        std::cout << "\t\t\t Invalid year entered!!\n\n";
                                        std::cout << "\t\t" << setfill('^') << setw(width) << "" << endl;
                                        break;
                                   }
                                   // getPeriodBill(Algeria,S_id, sm, em, sy, ey);
                                   break;

                              default:
                                   break;
                              }

                              break;