/*
 * main.c
 *
 *  Created on: Aug 6, 2025
 *      Author: sgrujic
 */

#include <stdio.h>
#include "../include/account.h"
#include "../include/types.h"
#include "../include/status.h"
#include "../include/security.h"
#include "../include/transaction.h"
#include "../include/auth.h"
#define MAX_ACCOUNTS 100

Account accounts[MAX_ACCOUNTS];
int n_accounts = 0;
int main(){
	int option = 0;
	int pinCode = 0;
	int type = 0;

	do{
			printf("1) Registracija na sistem\n");
			printf("2) Prijava na sistem\n");
			printf("0) Otkazi\n");
			printf("Odaberite opciju: ");
			fflush(stdout);
			scanf("%d", &option);

			switch(option){
			case 1:{
				Status validan_pin;
				int accountTypeOption;

				char temp[10] = {0};
				char pin[5];
				while (validan_pin.code != STATUS_OK) {
						printf("Unesite PIN (4 cifre): ");
						fflush(stdout);
						scanf("%9s", temp);
						validan_pin = validatePin(pin, temp);
						printf("%s", validan_pin.message);
						fflush(stdout);
				}

			    do {
			        printf("Izaberite tip naloga:\n");
			        printf("1. STANDARD\n");
			        printf("2. PREMIUM\n");
			        printf("Unesite broj (1 ili 2): ");
			    	fflush(stdout);
			        scanf("%d", &accountTypeOption);

			        if (accountTypeOption != 1 && accountTypeOption != 2) {
			            printf("Nepoznata opcija. Pokusajte ponovo.\n");
			        	fflush(stdout);
			        }

			    } while (accountTypeOption != 1 && accountTypeOption != 2);
			    Status gen = {0};
			    int number = generateAccountNumber(&gen);
			    printf("%s", gen.message);
			    fflush(stdout);

			    if (gen.code == STATUS_OK && number != -1) {
			    	Status regStatus = registration(number, pin, accountTypeOption);
			    	printf("%s", regStatus.message);
			    	fflush(stdout);
				} else {
					printf("%s", gen.message);
					fflush(stdout);
				}

				break;
			}
			case 2: {
					int accountNumber = 0;
					char pinCode[5];
					printf("Unesite broj naloga: ");
					fflush(stdout);
					scanf("%d", &accountNumber);

					printf("Unesite pin kod: ");
					fflush(stdout);
					scanf("%s", &pinCode);
					Account* account = login(accountNumber, pinCode);
					if (account != NULL) {
						do {
							printf("1) Uplati na racun\n");
							printf("2) Podigni novac\n");
							printf("3) Provjeri stanje\n");
							printf("0) Odjava sa sistema\n");
							printf("Odaberite opciju: ");
							fflush(stdout);
							scanf("%d", &option);

							switch(option){
							case 1:{
								int money = 0;
								printf("Unesite novac (djeljiv sa 10): ");
								fflush(stdout);
								scanf("%d", &money);
								Status uplataResult = deposit(account, money);
								printf("%s", uplataResult.message);
								break;
							}
							case 2:{
								int money = 0;
								printf("Unesite novac (djeljiv sa 10): ");
								fflush(stdout);
								scanf("%d", &money);
								Status uplataResult = withdraw(account, money);
								printf("%s", uplataResult.message);
								break;
							}
							case 3:
								printf("Vase trenutno stanje je: %d", account->balance);
								fflush(stdout);
								break;
							}
						} while (option != 0);
						free(account); // obavezno oslobodi memoriju
					} else {
						printf("Prijava nije uspjela.\n");
					}
					break;
				}
			}
		} while(option != 0);

	return 0;
}


