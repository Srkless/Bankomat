/*
 * auth.h
 *
 *  Created on: Aug 12, 2025
 *      Author: sgrujic
 */

#ifndef INCLUDE_AUTH_H_
#define INCLUDE_AUTH_H_

#include "types.h"
#include "config.h"
#include "status.h"

Account* login(int accountNumber, const char pinCode[5]);
Status registration(int number, char pin[5], int accountTypeOption);


#endif /* INCLUDE_AUTH_H_ */
