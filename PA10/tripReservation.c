/*
* @author Namir Hassan
* @date 12/12/17
* @name Programming Assignment 10
*/

#include "tripReservation.h"

#define HASH_SIZE 2000
#define PRIME 997  // some of the prime to test double hashing 149, 151, 499, 997, 1459, 1999
#define CONF_NUMBER_SIZE 6
#define TOTALALPHABETS 26  // 'Z' - 'A' + 1 = (90 - 65) + 1 = 26, 'z' - 'a' + 1 = 122 - 97 + 1 = 26

struct ticket *reservation[HASH_SIZE]; // This is the hash table.

/*
 * This function returns the hash key for a confirmation number.
 */
int findHashKey(char confNumber[]) {
	int confNumberValue = 0;
	int key;

	confNumberValue = getKeyValue(confNumber);

	key = confNumberValue % HASH_SIZE;

	if(reservation[key] != NULL && strcmp(reservation[key]->confirmationNumber, confNumber) != 0){
		key = PRIME - (key % PRIME);
	}

	return key;
}
/*
 * This function generate the confirmation number.
 */
char* generateConfNumber() {
	char *confNumber = (char *) malloc(( CONF_NUMBER_SIZE + 1) * sizeof(char)); // confNumber + '\0' => CONF_NUMBER_SIZE + 1
	int j;
	if (confNumber == NULL) {
		printf("Too bad!, can not allocate memory\n");
		exit(1);
	}
	do{
		for (j = 0; j < CONF_NUMBER_SIZE; j++)
			confNumber[j] = 'A' + rand() / (RAND_MAX / TOTALALPHABETS + 1); // Randomly generate alphabet from 'A' - 'Z'
		confNumber[j] = '\0';
	// Check whether confirmation number exists in the hash table or not.
	//If exists, it will loop and generate another confNumber Until new unique confirmation number is generated.
	} while(reservation[findHashKey(confNumber)] != NULL && strcmp(reservation[findHashKey(confNumber)]->confirmationNumber, confNumber) == 0);// .

	return confNumber;
}
/*
 * This function make sure that all characters in confNumber are upper case letter;
 */
char *toUpper(char *confNumber) {
	for (int i = 0; i < CONF_NUMBER_SIZE; i++) {
		if (confNumber[i] >= 97 && confNumber[i] <= 122) {
			confNumber[i] = 'A' + confNumber[i] - 'a'; // Converts lower to upper
		} else if (confNumber[i] < 65 || confNumber[i] > 90) {
			printf("Illegal character in confNumber, Something wrong!!!\n");
			exit(1);
		}
	}
	return (confNumber);
}
/*
 * This function sums confNumber's array of characters using Ascii value. 'A' => 65 ...
 */
int getKeyValue(char *confNumber) {
	int keyValue = 0;
	for (int i = 0; i < CONF_NUMBER_SIZE; i++)
		keyValue += confNumber[i];
	return keyValue;
}

/*
 * This function inserts a new record in the hash table corresponding to the
 * newly purchased ticket.
 * confNumber: confirmation number of the purchased ticket
 * ticket: flight information with purchaser's name.
 */
void insertTicket(char confNumber[], struct ticket tkt) {
	int hashKey = 0;

	char *validedConfNuber = toUpper(confNumber);

	if (validedConfNuber) {
		hashKey = findHashKey(confNumber);

		//printf("confNumber=%s converted to hash key=%d\n",confNumber, hashKey);
		struct ticket *tmp = (struct ticket *) malloc(sizeof(struct ticket));
		*tmp = tkt;
		reservation[hashKey] = tmp;

	}

}
struct ticket *lookupTicket(char confNumber[]) {
	int hashKey = findHashKey(confNumber);
	if(reservation[hashKey] != NULL && strcmp(reservation[findHashKey(confNumber)]->confirmationNumber, confNumber) == 0)
		return reservation[hashKey];
	return NULL;
}
void deleteTicket(char confNumber[]){
	struct ticket *tmp ;//= lookupTicket(confNumber);
	int hashKey = findHashKey(confNumber);
	if(reservation[hashKey] != NULL && strcmp(reservation[findHashKey(confNumber)]->confirmationNumber, confNumber) == 0){
		tmp = reservation[hashKey] ;
		reservation[hashKey] = NULL;
		free(tmp);
	} else {
		printf("Confirmation Number: %s not found.\n", confNumber);
	}
}
void printTicket(char confNumber[]){
	int hashKey = findHashKey(confNumber);
	if(reservation[hashKey] != NULL){
		printf("\n");
		printf("Flight Number: %s\n", reservation[hashKey]->flight_number);
		printf("Passenger Name: %s\n", reservation[hashKey]->passenger_name);
		printf("Departure Airport: %s\n", reservation[hashKey]->departure_airport);
		printf("Arrival Airport: %s\n", reservation[hashKey]->arrival_airport);
		printf("Date Of Departure: %s\n", reservation[hashKey]->dateOfDeparture);
		printf("Date Of Arrival: %s\n", reservation[hashKey]->dateOfArrival);
		printf("Departure Time: %s\n", reservation[hashKey]->departure_time);
		printf("Arrival TIme: %s\n", reservation[hashKey]->arrival_time);
		printf("Confirmation Number: %s\n", reservation[hashKey]->confirmationNumber);
		printf("\n");
	} else {
		printf("No ticket found for confirmation number: %s reservation system\n", confNumber);
	}
}

// Main commented before submission
// For Testing ONLY.
/*
int main() {

	int count = 0;

	struct ticket aTicket;

	strcpy(aTicket.flight_number, "");
	strcpy(aTicket.passenger_name, "");
	strcpy(aTicket.departure_airport, "");
	strcpy(aTicket.arrival_airport, "");
	strcpy(aTicket.dateOfDeparture, "");
	strcpy(aTicket.dateOfArrival, "");
	strcpy(aTicket.departure_time, "");
	strcpy(aTicket.arrival_time, "");
	char *confNumber = generateConfNumber();
	strcpy(aTicket.confirmationNumber, confNumber);

	insertTicket(confNumber, aTicket);


	if(lookupTicket(confNumber) != NULL)
		printf("Yes!, we found it.\n");
	else
		printf("Nothing there\n");

//	deleteTicket(confNumber);
//	if(lookupTicket(confNumber) != NULL)
//			printf("Yes!, we found it.\n");
//		else
//			printf("Nothing there\n");

	printTicket(confNumber);
	return 0;
}
*/
