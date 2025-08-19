/*
 * types.h
 *
 *  Created on: Aug 12, 2025
 *      Author: sgrujic
 */

#ifndef INCLUDE_TYPES_H_
#define INCLUDE_TYPES_H_


typedef enum { STANDARD, PREMIUM } AccountType;

typedef struct {
	int accountNumber;
	char pinHash[9];
	AccountType type;
	int balance;
} Account;


#endif /* INCLUDE_TYPES_H_ */
