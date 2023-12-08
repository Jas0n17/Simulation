/* Jason Lin 
 * 10/21/2023
 * File defines functions for Date object
 */ 
#include "MysteryMachine.h"
#include "Date.h"
// - - - - - - - -
// prototype //
int daysInMonth(int);
// constructors //
Date::Date() : month(1), day(1), year(2000){} // default day for default contructor
Date::Date(int month, int day, int year) : month(month), day(day), year(year){}

// accessors //
int Date::getMonth() {return month;}
int Date::getDay() {return day;}
int Date::getYear() {return year;}

// mutators //
void Date::setMonth(int month) {this->month = month;}
void Date::setDay(int day) {this->day = day;}
void Date::setYear(int year) {this->year = year;}

// function calls function getDayOfWeek from MysteryMachine, returns the day of week based on the Date object passed in 
string Date::getDayOfWeek() {
    return MysteryMachine::getDayOfWeek(*this); }
// fucntion ouputs the Date's date in mm/dd/yyyy format   
string Date::toString() {
    string output = to_string(month) + "/" + to_string(day) + "/" + to_string(year); return output; }

// (!) Operators (!) //
// Function adds to Date object by days, accounts for month and year overflow
Date Date::operator+(int n) {
	Date result(month, day + n, year);
	while(result.day > daysInMonth(result.month)) {	// checks for days in month overflow
		result.day -= daysInMonth(result.month);
		result.month++; 
		if (result.month > 12) 
		{	result.month = 1; 
			result.year++;	}   // checks for months in year overflow
	}
return result; }
// Function subtracts to Date object by days, accounts for month and year underflow
Date Date::operator-(int n) {
	Date result(month, day - n, year); 
	while (result.day <= 0) {	// check for days in month underflow
		result.month--;			
		if (result.month == 0) 	// check for months in year underflow
		{	result.month = 12;
			result.year--;	}
		result.day += daysInMonth(result.month);
	}
	return result; }
// Function prefix increments the Date object account for year/month overflow
Date Date::operator++(void){ 
	day++;
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			if (day > 31) {
				month++;
				day = 1;} break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30) {
				month++;
				day = 1;} break;
		case 2:
			if (day > 28) {
				month++;
				day = 1;} break;
		case 12:
			if (day > 31) {
				month = 1;
				day = 1;
				year++;} break;
		default: break;
	}
	return *this;
}
// Function postfix increments the Date object accounts for year/month overflow
Date Date::operator++(int){
	Date oldDate = *this; // this will be returned as the new Date is incremented
	day++;
	switch(month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			if (day > 31) {
				month++;
				day = 1;} break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30) {
				month++;
				day = 1;} break;
		case 2:
			if (day > 28) {
				month++;
				day = 1;} break;
		case 12:
			if (day > 31) {
				month = 1;
				day = 1;
				year++;} break;
		default: break;
	}
	return oldDate;}
// Function prefix decrements Date by one day, accounts for month/year underflow
Date Date::operator--(void){
	day--;
	switch (month) {
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
			if (day == 0) {
				month--;
				day = daysInMonth(month);} break;
		case 1:
			if (day ==0) {
				month = 12;
				day = daysInMonth(month);
				year--;} break;
		default: break;
	}
	return *this;}
// Function postfix decrements Date by one day, accounts for month/year underflow
Date Date::operator--(int){
	Date oldDate = *this; // old Date will be return as new Date is decremented
	day--;
	switch (month) {
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
			if (day == 0) {
				month--;
				day = daysInMonth(month);} break;
		case 1:
			if (day ==0) {
				month = 12;
				day = daysInMonth(month);
				year--;} break;
		default: break;
	}
	return oldDate;}
// * helper function * //
// Function returns the number of days in a month 
int daysInMonth(int m) {
	switch(m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			return 28;
	} return -1; }
