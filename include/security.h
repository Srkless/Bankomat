/*
 * security.h
 *
 *  Created on: Aug 12, 2025
 *      Author: sgrujic
 */

#ifndef INCLUDE_SECURITY_H_
#define INCLUDE_SECURITY_H_

#include "status.h"
#include "config.h"

Status validatePin(char* pinBuffer, char temp[10]);
void hashPin(const char *pin, char *output);


#endif /* INCLUDE_SECURITY_H_ */
