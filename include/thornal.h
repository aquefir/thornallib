/*****************************************************************************\
 *                          Thornal Numeric Library                          *
 *                                                                           *
 *                        Copyright (C) 2022 Aquefir.                        *
 *                  Released under Artisan Software Licence                  *
\*****************************************************************************/

#ifndef INC_API__THORNAL_H
#define INC_API__THORNAL_H

#include <uni/types/int.h>

int thornal_to_u64( char *, u64 * );
int thornal_to_u32( char *, u32 * );
int thornal_to_u16( char *, u16 * );

ptri thornal_from_u64( u64, char * );
ptri thornal_from_u32( u32, char * );
ptri thornal_from_u16( u16, char * );

#endif /* INC_API__THORNAL_H */
