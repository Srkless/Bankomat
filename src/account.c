/*
 * account.c
 *
 *  Created on: Aug 6, 2025
 *      Author: sgrujic
 */


#include <stdio.h>
#include <string.h>
#include "../include/account.h"
int MAX_ATTEMPTS = 10;

Status isAccountExists(int accountNumber) {
	Status result = {0};
    FILE *fp = fopen(USERS_FILE, "r");
    if (!fp){
    	result.code = STATUS_FILE_ERROR;
    	strcpy(result.message, "Greska pri citanju iz fajla.\n");
    	return result;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        int readNumber;
        sscanf(line, "%d", &readNumber);
        if (readNumber == accountNumber) {
            fclose(fp);
            result.code = STATUS_OK;
			strcpy(result.message, "Broj racuna uspjesno pronadjen.\n");
			return result;
        }
    }
    fclose(fp);
    result.code = STATUS_ACCOUNT_NOT_EXISTS;
	strcpy(result.message, "Broj racuna ne postoji.\n");
	return result;
}


Status generateAccountNumber() {
	Status result = {0};
    srand(time(NULL));
    int attempts = 0;
    int newNumber;

    do {
    	newNumber = (rand() % 90000000) + 10000000;
        attempts++;
    } while (isAccountExists(newNumber).code == STATUS_OK && attempts < MAX_ATTEMPTS);


    if (attempts == MAX_ATTEMPTS) {
    	result.code = STATUS_MAX_ATTEMPTS_REACHED;
		strcpy(result.message, "Nemoguce kreirati novi racun.\n");
		return result;
    }

    result.code = STATUS_OK;
    snprintf(result.message, sizeof(result.message), "Uspjesno kreiran broj racuna: %d.\n", newNumber);

	return result;
}


