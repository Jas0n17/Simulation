/* Jason Lin 
 * 10/21/2023
 * Pizza Store is what the algorithum will test. Pizza Store will against another Pizza Store. 
 */ 
#ifndef PIZZASTORE_H
#define PIZZASTORE_H

#include <iostream>
#include <string>
#include <unistd.h>
#include <random>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

class PizzaStore {
    public:
        PizzaStore();
        PizzaStore(string name, int maxPizzas, double productionPerTick, double successRate);
        int tickUpdate(); 
        bool consumeSlices(int slices);
        void showStatus(); 
        string getName();
        int getTotalSlicesLeft(); 
        int getAdd(); 
        void clearVector();
        int genRandNum();        
    private:
        string name; 
        int maxPizzas; 
        int totalSlices; 
        static const int slicesPerPizza = 8; 
        int pizzasProduced; 
        double productionPerTick; 
        double successRate; 
        vector<int> vectorPizza; 

};

#endif //PIZZASTORE_H
