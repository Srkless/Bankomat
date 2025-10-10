/*
 * utls.c
 *
 *  Created on: Aug 12, 2025
 *      Author: sgrujic
 */
#include <stdio.h>
#include "../include/utils.h"
#include <stdlib.h>

// Vraca limit za korisnicni nalog
int getAccountLimit(AccountType type){
	switch(type){
	case STANDARD:
		return 1000;
	case PREMIUM:
		return 5000;
	default:
		return -1;
	}
}

Status updateAccountInFile(Account *account) {
    Status result = {0};

    if (account == NULL) {
        result.code = STATUS_ACCOUNT_NOT_EXISTS;
        strcpy(result.message, "Account ne postoji\n");
        return result;
    }

    FILE *fp = fopen(USERS_FILE, "r");
    if (!fp) {
        result.code = STATUS_FILE_ERROR;
        strcpy(result.message, "Greska pri citanju iz fajla.\n");
        return result;
    }

    char **lines = NULL;
    int count = 0;
    char buffer[256];
    int oldBalance = -1;
    int balanceUpdated = 0;

    char accNumStr[20];
    sprintf(accNumStr, "%d", account->accountNumber);

    while (fgets(buffer, sizeof(buffer), fp)) {
        buffer[strcspn(buffer, "\n")] = 0;

        char temp[256];
        strcpy(temp, buffer);

        char *number = strtok(temp, "|");

        if (strcmp(number, accNumStr) == 0) {
            snprintf(buffer, sizeof(buffer), "%d|%s|%d|%d", account->accountNumber,
                     account->pinHash,
                     account->type,
                     account->balance);

            balanceUpdated = 1;
        }

        char **tmp = realloc(lines, sizeof(char *) * (count + 1));
        if (!tmp) {
            result.code = STATUS_ERROR;
            strcpy(result.message, "Greska u realokaciji\n");
            return result;
        }

        lines = tmp;

        lines[count] = strdup(buffer);
        if (!lines[count]) {
            result.code = STATUS_ERROR;
            strcpy(result.message, "Greska kod sadrzaja u fajlu\n");
            return result;
        }

        count++;
    }

    fclose(fp);

    fp = fopen(USERS_FILE, "w");
	if (!fp) {
		result.code = STATUS_FILE_ERROR;
		strcpy(result.message, "Greska pri otvaranju fajla za pisanje\n");
		return result;
	}

	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s\n", lines[i]);
		free(lines[i]);
	}
	free(lines);
	fclose(fp);

    if (!balanceUpdated) {
        result.code = STATUS_ACCOUNT_NOT_EXISTS;
        strcpy(result.message, "Nalog nije pronadjen u fajlu\n");
        return result;
    } else {
        result.code = STATUS_OK;
        strcpy(result.message, "Uspjesan update i balance promijenjen\n");
    }

    return result;
}

