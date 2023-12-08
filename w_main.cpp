#include"weatherHashTable.h"
using namespace std; 

int main (){
    int arr[3]={1,1,2023}; //create date

    weather w1(arr,20,10,12,"sunny"); //create weather
  
   
   weatherHashTable wh(2023,2);//create the hashtable


   
   wh.insertWeather(2023,1,1,w1);
   cout<<wh.getWeather(2023,1,1).getMaxTemperature()<<endl;
   

cout<<wh.getsize();
   
}