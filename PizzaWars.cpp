// Defines functions from PizzaWars.h 
// Disclaimer "Core" and "Schilleter" are the names of the pizza store battling against each other
#include "PizzaWars.h"
int genRandConsume(); // contructor of helper function

// * constructor * //
PizzaWars::PizzaWars() {
	runSimulation(); 
};

// * runs the simulation * //
// function essentially runs the entire simulation literating throughout a week starting on Sunday and ending on Saturday. Writes to a file with seven possible outputs core wins, schilletter wins, or a tie
void PizzaWars::runSimulation(){
	srand(time(0)); // seed created
	cout << "Welcome to Pizza Wars!\n"; // Introduction 
        cout << "This program simulates an epic battle between Core and Schilletter and their ability to keep up with the demand for pizza!\n\n";
        cout << "Please enter the date you'd like to start the simulation in MM DD YYYY format: ";
	int month, day, year; cin >> month >> day >> year; // starting day entered
	Date startDate(month, day, year); // make date object
       	if (startDate->getDayOfWeek() != "Sunday") {
		cout << "That day is not a Sunday, so we're moving to the nearest future Sunday to start\n";

	} 
	cout << "Starting on " << datePtr->toString() << endl;	
	marchToSunday(&startDate); // pass date object into marchToSunday 
	Date * datePTR = allocateWeekOfDates(startDate); // make a date pointer to the date that is a Sunday 

	runSeriesSimulation(datePTR, 7); // run the simulation
	delete datePTR;
}
// function dynamically allocates seven different Date in a Date[] array
Date * PizzaWars::allocateWeekOfDates(Date date) { 
	Date * datePtr = nullptr;
       	datePtr = new Date[7]; //datePtr points seven resevered spaces of Date type. Allowing an each slot to be its unique Date object.
	for (int i = 0; i < 7; i++) {
		datePtr[i] = date; // Sunday = datePtr[0] ... Saturday = datePtr[6]
		date++;
	} return datePtr; // returns the Date on Sunday (algorithum starts on Sunday)
}
// function calls runsDaySimulation seven times, essentially running the algorithum
void PizzaWars::runSeriesSimulation(Date *dates, int length) {
	
        for (int i = 0; i < length; i++) { 
		PizzaStore * nowinner = NULL; // pointer set to NUll to be used in case of tie
		PizzaStore core("Core", 3, 2.0, 0.9); PizzaStore schilletter("Schilletter", 6, 1.0, 0.8); // creates PizzaStore objects

		string winner = runDaySimulation(dates + i, &core, &schilletter); 
		if (winner == "Core") // Core wins the day
		{ cout << "Core wins!\n\n"; writeToFile(dates + i, &core); }
		else if (winner ==  "Schilletter") // Schilletter wins the day  
		{ cout << "Schilletter wins!\n\n"; writeToFile(dates + i, &schilletter); }
		else // tie
 	       	{ cout << "TIE!\n\n"; writeToFile(dates + i, nowinner); }
		core.clearVector(); schilletter.clearVector();
		delete nowinner; core.clearVector(); schilletter.clearVector();
	}

}
// function takes in a Date pointer and will return Date on the nearest future Sunday, will return the Date as is if already Sunday
void PizzaWars::marchToSunday(Date * datePtr) { // marchToSunday(&dateobj)
	string dateName = (*datePtr).getDayOfWeek();
	while (dateName != "Sunday") { // increments until Sunday
		(*datePtr)++;
		dateName = (*datePtr).getDayOfWeek();
	}
}
// functions runs an individual day, keeps track of time and win conditions
string PizzaWars::runDaySimulation(Date * dateptr, PizzaStore * corePtr, PizzaStore * schilletterPtr){
	string time[] = {"11:00", "11:30", "12:00", "12:30", "1:00", "1:30", "2:00", "2:30", "3:00", "3:30", "4:00", "4:30", "5:00", "5:30", "6:00", "6:30", "7:00", "7:30", "8:00", "8:30", "9:00", "9:30"}; // array of time, stores close at 9:00 during weekdays and 8:00 weekends
	cout << "Running simulation for " << dateptr->getDayOfWeek() << " " << dateptr->toString() << "\n\n"; 
	
	int i = 0; bool coreWin = true; bool schiWin = true; string toClose; // coreWin and schiWin keeps track of win conditions, toClose keeps track of closing times

	if (dateptr->getDayOfWeek() == "Saturday" || dateptr->getDayOfWeek() == "Sunday") 
	{ toClose = "8:00"; }
       	else { toClose = "9:00"; } 

	while(coreWin && schiWin && time[i] != toClose) { // * loops runs one day* //
		cout <<  time[i] << endl; i++; 

		int consumeC = genRandConsume(); int consumeS = genRandConsume(); // random 5 <= number <= 20 of pizzas are demanded from each store 
		cout << consumeC << " slice(s) are consumed at Core" << endl;
                cout << consumeS << " slice(s) are consumed at Schilletter" << endl;
		coreWin = (*corePtr).consumeSlices(consumeC); // false if core lose
                schiWin = (*schilletterPtr).consumeSlices(consumeS); // false if sch lose
		
		corePtr->showStatus(); schilletterPtr->showStatus(); // prints the display board (consumption will always be left -> right)

		if (coreWin && schiWin) { // if a win condition is met, this will not execute and the day will end with the winner displayed
			corePtr->tickUpdate(); schilletterPtr->tickUpdate();
			cout << corePtr->getAdd() << " pizza(s) were added at Core\n";
			cout << schilletterPtr->getAdd() << " pizza(s) were added at Schilletter\n";

			corePtr->showStatus(); schilletterPtr->showStatus(); cout << endl; // display board
		}
	}
	// @ this point of the code, either coreWin == false || schiWin == false || time[i] == toClose
	if (coreWin && schiWin) { return "";  } // tie!
	else if (coreWin && !schiWin) { return corePtr->getName(); } // core wins 
	else if (schiWin && !coreWin) { return schilletterPtr->getName(); } // schilletter wins
	else { return ""; } // (!) this should not execute (!) //
}
// * helper function * //
// generates a random number between 5 and 20 //
int genRandConsume() { // rand num 5 - 20
    return (rand() % 16) + 5;
}
// function writes to a file in <dayOfWeek> <date> <winner> format (see log.txt) 
void PizzaWars::writeToFile(Date * dateptr, PizzaStore * winner) {
	ofstream fileOut; fileOut.open("log.txt", ios::app);	
	fileOut << setw(10) << left << dateptr->getDayOfWeek();
	fileOut << setw(9) << left << dateptr->toString();
	if (winner != NULL) {
		fileOut << " " << winner->getName() << " won with " << winner->getTotalSlicesLeft() << " slices left!\n";
	} else { fileOut << " Tie!" << endl; } 
	fileOut.close();
}

