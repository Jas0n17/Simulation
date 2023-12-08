/* Jason Lin 
 * 10/21/2023
 * Pizza Wars runs the algorithum applys Date, PizzaStore, and MysteryMachine
 */ 
#ifndef PIZZAWARS_H
#define PIZZAWARS_H
#include "MysteryMachine.h"
#include "Date.h"
#include "PizzaStore.h"
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

class PizzaWars 
{
public:
    PizzaWars();
    static void runSimulation();
    Date dateArray[7];
protected:
    static Date * allocateWeekOfDates(Date date);
    static void runSeriesSimulation(Date * dates, int length);  
    static string runDaySimulation(Date *datePtr, PizzaStore*, PizzaStore*); // *pointers to the store obj* remember that shit 
    static void marchToSunday(Date *datePtr);
    static void writeToFile(Date *datePtr, PizzaStore *winner);
};



#endif //PIZZAWARS_H
