/*
 * security.c
 *
 *  Created on: Aug 12, 2025
 *      Author: sgrujic
 */
#include <string.h>
#include "../include/security.h"

Status validatePin(char* pinBuffer, char temp[10]) {
	Status result = {0};
	if (strlen(temp) != 4) {
		result.code = STATUS_PIN_INVALID;
		strcpy(result.message, "PIN mora imati tacno 4 cifre.\n");
		return result;
	}

	int sve_cifre = 1;
	for (int i = 0; i < 4; i++) {
		if (!isdigit(temp[i])) {
			sve_cifre = 0;
			break;
		}
	}

	if (!sve_cifre) {
		result.code = STATUS_PIN_INVALID;
		strcpy(result.message, "PIN smije sadrzavati samo cifre.\n");
		return result;
	}

	strcpy(pinBuffer, temp);
	result.code = STATUS_OK;
	strcpy(result.message, "Validacija pina uspjesna.\n");
	return result;
}

void hashPin(const char *pin, char *output) {
    unsigned int hash = 2166136261u;
    unsigned int prime = 16777619;

    for (int i = 0; pin[i] != '\0'; i++) {
        hash ^= (unsigned int)(pin[i]);
        hash *= prime;
        hash = (hash << 1) | (hash >> 31);
    }

    sprintf(output, "%08X", hash);
}


