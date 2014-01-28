#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkit.h"

struct account {
	int amount;
	int status; /* =1 if trusted, 0 if not */
};
typedef struct account Account;


#endif
