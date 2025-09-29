/*
 * account.h
 *
 *  Created on: Aug 6, 2025
 *      Author: sgrujic
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "config.h"
#include "status.h"

Status isAccountExists(int accountNumber);
int generateAccountNumber(Status* status);

#endif /* ACCOUNT_H_ */
