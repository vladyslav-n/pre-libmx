#include "../inc/libmx.h"

bool mx_isspace(char c) {
	if (   c == '\t' 
		|| c == '\n' 
		|| c == '\v' 
		|| c == '\r' 
		|| c == '\f' 
		|| c == ' ' )
		return 1;
	else
		return 0;
}
