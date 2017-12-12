#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct ticket {
char confirmationNumber[7];
char passenger_name[25];
char flight_number[7];
char departure_airport[4];
char arrival_airport[4];
char dateOfDeparture[11]; // mm/dd/yyyy  + '\0' = 10 + 1 = 11
char departure_time[6]; // hh:mm + '\0' = 5 + 1 = 6
char arrival_time[6]; // hh:mm + '\0' = 5 + 1 = 6
char dateOfArrival[11]; // mm/dd/yyyy + '\0' = 10 + 1 = 11
};


int getKeyValue(char *confNumber) ;
