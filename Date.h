/* Jason Lin 
 * 10/21/2023
 * Object Date consist of month, day, and year and can be manipulated by its member functions
 */
#ifndef DATE_H
#define DATE_H
// - - - - - - - 
#include <string>
#include <iostream>
using namespace std;

// * * * * * * * * * * * * * //
// * (!) DO NOT MODIFY (!) * //
// * * * * * * * * * * * * * //


class Date 
{
public:
    Date();
    Date(int month, int day, int year);

    int getMonth();
    int getDay();
    int getYear();

    void setMonth(int month); 
    void setDay(int day);
    void setYear(int year);

    Date operator+(int days);
    Date operator-(int days);
    Date operator++(void); // 	*prefix*
    Date operator++(int); //	*postfix*
    Date operator--(void); // 	*prefix*
    Date operator--(int); // 	*postfix*

    string getDayOfWeek(); 
    string toString(); 

    int month, day, year;
};

#endif //DATE_H
