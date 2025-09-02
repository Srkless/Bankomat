
/*
 * transaction.c
 *
 *  Created on: Aug 6, 2025
 *      Author: sgrujic
 */

#include "../include/transaction.h"
Status deposit(Account *account, int money) {
	Status result = {0};
	if(account == NULL){
		result.code = STATUS_ACCOUNT_NOT_EXISTS;
		strcpy(result.message, "Account nije pronadjen\n");
		return result;
	}

	int moneyLimit = getAccountLimit(account->type);

	if(moneyLimit == -1){
		result.code = STATUS_ACCOUNT_TYPE_INVALID;
		strcpy(result.message, "Account type nije pronadjen\n");
		return result;
	}

	if(money < 10){
		result.code = STATUS_WRONG_VALUE;
		strcpy(result.message, "Minimalan unos je 10.\n");
		return result;
	}
	else if(money % 10 != 0){
		result.code = STATUS_WRONG_VALUE;
		strcpy(result.message, "Pogresna vrijednost (mora biti djeljiva sa 10)\n");
		return result;
	}
	else if(money + account->balance > moneyLimit){
		result.code = STATUS_LIMIT_EXCEEDING;
		strcpy(result.message, "Prekoracenje limita\n");
		return result;
	}
	else{
		account->balance += money;
		result.code = STATUS_OK;
		Status a = updateAccountInFile(account);
		strcpy(result.message, "Uplata na racun uspjesna\n");
		return result;
	}

}

Status withdraw(Account *account, int money) {
	Status result = {0};
	if(account == NULL){
		result.code = STATUS_ACCOUNT_NOT_EXISTS;
		strcpy(result.message, "Account nije pronadjen\n");
		return result;
	}

	int moneyLimit = getAccountLimit(account->type);

	if(moneyLimit == -1){
		result.code = STATUS_ACCOUNT_TYPE_INVALID;
		strcpy(result.message, "Account type nije pronadjen\n");
		return result;
	}

	if(money < 10){
		result.code = STATUS_WRONG_VALUE;
		strcpy(result.message, "Minimalan unos je 10.\n");
		return result;
	}
	else if(money % 10 != 0){
		result.code = STATUS_WRONG_VALUE;
		strcpy(result.message, "Pogresna vrijednost (mora biti djeljiva sa 10)\n");
		return result;
	}
	else if(account->balance - money < 0){
		result.code = STATUS_INSUFFICIENT_MONEY;
		strcpy(result.message, "Nemate dodovljno novca.\n");
		return result;
	}
	else{
		account->balance -= money;
		result.code = STATUS_OK;
		updateAccountInFile(account);
		strcpy(result.message, "Isplata sa racuna uspjesna\n");
		return result;
	}

}

