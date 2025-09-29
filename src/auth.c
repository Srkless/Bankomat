/*
 * auth.c
 *
 *  Created on: Aug 6, 2025
 *      Author: sgrujic
 */
#include "../include/auth.h"
#include "stdio.h"

Status registration(int number, char pin[5], int accountTypeOption) {
	Status result = {0};
    FILE *fp = fopen(USERS_FILE, "a");
    if (fp == NULL) {
    	result.code = STATUS_FILE_ERROR;
		strcpy(result.message, "Greska pri citanju iz fajla.\n");
		return result;
    }
    Account newAccount;
    newAccount.accountNumber = number;

	char hash[65];

    hashPin(pin, hash);
    strcpy(newAccount.pinHash, hash);

    newAccount.type = (accountTypeOption == 1) ? STANDARD : PREMIUM;

    newAccount.balance = 0.0;

    fprintf(fp, "%d|%s|%d|%.2lf\n",
    		newAccount.accountNumber,
			newAccount.pinHash,
        newAccount.type,
		newAccount.balance);
    fclose(fp);

    result.code = STATUS_OK;
	strcpy(result.message, "Uspjesna registracija korisnika!\n");
	return result;

}

Account* login(int accountNumber, const char pinCode[5]) {
    char computed[65];
    hashPin(pinCode, computed);

    FILE* fp = fopen(USERS_FILE, "r");
    if (!fp) return NULL;

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), fp)) {
        int number;
        char pinField[9];
        int accountType;
        int bal;

        if (sscanf(line, "%d|%8[^|]|%d|%d", &number, pinField, &accountType, &bal) != 4) continue;

        if (number == accountNumber) {
            Account* acc = malloc(sizeof(*acc));
            if (!acc) { fclose(fp); return NULL; }

            acc->accountNumber = number;
            strcpy(acc->pinHash,pinField);
            acc->type   = accountType;
            acc->balance = bal;

            fclose(fp);
            return acc;
        }
    }

    fclose(fp);
    return NULL;
}

