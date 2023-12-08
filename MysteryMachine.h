/* Jason Lin 
 * 10/21/2023
 * Mystery Machine returns the day of the week as a string
 */ 
#ifndef MYSTERYMACHINE_H
#define MYSTERYMACHINE_H
#include "Date.h"
#include <string>
class MysteryMachine
{
    public:
        static string getDayOfWeek(Date inDate);
};
#endif
