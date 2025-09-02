/*
 * transaction.h
 *
 *  Created on: Aug 13, 2025
 *      Author: sgrujic
 */

#ifndef INCLUDE_TRANSACTION_H_
#define INCLUDE_TRANSACTION_H_

#include "status.h"
#include "types.h"
#include "utils.h"

Status deposit(Account *account, int money);
Status withdraw(Account *account, int money);;


#endif /* INCLUDE_TRANSACTION_H_ */
