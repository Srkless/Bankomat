/*
 * utils.h
 *
 *  Created on: Aug 12, 2025
 *      Author: sgrujic
 */

#ifndef INCLUDE_UTILS_H_
#define INCLUDE_UTILS_H_

#include "types.h"
#include "config.h"
#include "status.h"
#include <stdio.h>

int getAccountLimit(AccountType type);
Status updateAccountInFile(Account *account);

#endif /* INCLUDE_UTILS_H_ */
