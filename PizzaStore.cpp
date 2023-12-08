// File defines functions from PizzaStore.h
#include "PizzaStore.h" 

// * constructors //
PizzaStore::PizzaStore(){}
PizzaStore::PizzaStore(string name, int maxPizzas, double productionPerTick, double successRate) : name(name), maxPizzas(maxPizzas), productionPerTick(productionPerTick), successRate(successRate)
{
    pizzasProduced = 0; 
    totalSlices = maxPizzas * slicesPerPizza; // total slices we start off with (full slots)
    vectorPizza.resize(maxPizzas); // sizes vector to maxPizzas size
    for (int i = 0; i < maxPizzas; i++) { vectorPizza[i] = 8; } // populates array
}

// * accessors * //
string PizzaStore::getName() { return name; }
int PizzaStore::getTotalSlicesLeft() { return totalSlices; }
int PizzaStore::getAdd() { return pizzasProduced; }
void PizzaStore::clearVector() { vectorPizza.clear(); }

// * random generators * //
int PizzaStore::genRandNum() { 
    return rand() % 100 + 1; // returns a 1 <= number <= 100
}

// * slices consumes * //
// function does two things, update the slots of PizzaStore and returns true if PizzaStore stays in the fight and false if they lose the fight
bool PizzaStore::consumeSlices(int slices) { 
    if (totalSlices >= slices) { 
        for (int i = 0; i < maxPizzas; i++) { // checks each pizza slot
            if (slices > 0) { // remember it goes through all slots, so if there is no more pizza to consume, it skips the consuming process
                if (vectorPizza[i] > 0) { // if that slot as pizza
                    while (vectorPizza[i] > 0 && slices > 0) { // will run until that slot runs out of pizza or slices consumed goes to zero
                        vectorPizza[i]--;
                        slices--; 
		    	totalSlices--;}    
                }
            }
        } 
    return true; } else { 
        for(int i = 0; i < maxPizzas; i++) { // since supply != demand, set all slots to zero
            vectorPizza[i] = 0; }
       	totalSlices = 0;
        return false; } 
}

// * slices add * //
// function does two things, return the number of pizza remainding + added pizza and updates the slots 
int PizzaStore::tickUpdate() { 
    pizzasProduced = 0; // how many pizzas are produced 
    int newPizzas = static_cast<int>(productionPerTick); // (2 for core and 1 for shilletter)
    for (int i = 0; i < newPizzas; i++) {
        if (genRandNum() <= successRate * 100) { // pizzaProduced will increment is the randomly generated number is <= the success rate
            pizzasProduced++; } 
    } 
    int slicesProduced = slicesPerPizza * pizzasProduced; // number of slices added to store
    for (int i = 0; i < maxPizzas; i++) { // adding the number of slices starting with the first slot 
        if (slicesProduced > 0) {
            while (vectorPizza[i] < 8 && slicesProduced > 0) {
                slicesProduced--;
                vectorPizza[i]++;
		totalSlices++;
            }
        }
    }
   usleep(50000); // allows algorithum to smoothly execute
   return pizzasProduced;
}

// * prints the board * //
void PizzaStore::showStatus() {
	cout << setw(20) << right << name << ": ";
	for (int i = 0; i < maxPizzas; i++) {
		cout << vectorPizza[i] << " ";
	}
	cout << "" << endl;
	
}

