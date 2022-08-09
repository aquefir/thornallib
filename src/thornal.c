/*****************************************************************************\
 *                          Thornal Numeric Library                          *
 *                                                                           *
 *                        Copyright (C) 2022 Aquefir.                        *
 *                  Released under Artisan Software Licence                  *
\*****************************************************************************/

#include <thornal.h>

#include <uni/err.h>

#define ASCII2THORNAL_IMPL( ) \
	do { \
	if(s == NULL || r == NULL) \
	{ \
	uni_die( ); \
	return 0; \
	} \
	{ \
	ptri i; \
	for(i = 0, *r = 0; s[i] != '\0'; ++i) \
	{ \
	const u8 d = (u8)(s[i]); \
	if(d >= 128 || ascii2thornal[d] == 255) \
	{ \
	return 1; \
	} \
	*r += ascii2thornal[d]; \
	} \
	} \
	return 0; \
	} while(0)

#define THORNAL2ASCII_IMPL( BITS ) \
	do { \
	if(s == NULL) \
	{ \
	return (BITS / 5) + 1; \
	} \
	{ \
	u32 bits = 0; \
	u32 i = 0; \
	while(bits < BITS) \
	{ \
	s[i] = thornal2ascii[(n >> bits) & 0x1F]; \
	i++; \
	bits += 5; \
	} \
	} \
	return 0; \
	} while(0)

static const u8 ascii2thornal[] = {
	/* NUL */
	255,
	/* SOH */
	255,
	/* STX */
	255,
	/* ETX */
	255,
	/* EOT */
	255,
	/* ENQ */
	255,
	/* ACK */
	255,
	/* BEL */
	255,
	/* BS */
	255,
	/* HT */
	255,
	/* LF */
	255,
	/* VT */
	255,
	/* FF */
	255,
	/* CR */
	255,
	/* SO */
	255,
	/* SI */
	255,
	/* DLE */
	255,
	/* DC1 */
	255,
	/* DC2 */
	255,
	/* DC3 */
	255,
	/* DC4 */
	255,
	/* NAK */
	255,
	/* SYN */
	255,
	/* ETB */
	255,
	/* CAN */
	255,
	/* EM */
	255,
	/* SUB */
	255,
	/* ESC */
	255,
	/* FS */
	255,
	/* GS */
	255,
	/* RS */
	255,
	/* US */
	255,
	/* (space) */
	255,
	/* ! */
	255,
	/* " */
	255,
	/* # */
	255,
	/* $ */
	255,
	/* % */
	255,
	/* & */
	255,
	/* ' */
	255,
	/* ( */
	255,
	/* ) */
	255,
	/* * */
	255,
	/* + */
	255,
	/* , */
	255,
	/* - */
	255,
	/* . */
	255,
	/* / */
	255,
	/* 0 */
	255,
	/* 1 */
	255,
	/* 2 */
	0,
	/* 3 */
	1,
	/* 4 */
	2,
	/* 5 */
	3,
	/* 6 */
	4,
	/* 7 */
	5,
	/* 8 */
	6,
	/* 9 */
	7,
	/* : */
	255,
	/* ; */
	255,
	/* < */
	255,
	/* = */
	255,
	/* > */
	255,
	/* ? */
	255,
	/* @ */
	255,
	/* A */
	8,
	/* B */
	9,
	/* C */
	10,
	/* D */
	11,
	/* E */
	12,
	/* F */
	13,
	/* G */
	14,
	/* H */
	15,
	/* I */
	255,
	/* J */
	16,
	/* K */
	17,
	/* L */
	18,
	/* M */
	19,
	/* N */
	20,
	/* O */
	255,
	/* P */
	21,
	/* Q */
	22,
	/* R */
	23,
	/* S */
	24,
	/* T */
	25,
	/* U */
	26,
	/* V */
	27,
	/* W */
	28,
	/* X */
	29,
	/* Y */
	30,
	/* Z */
	31,
	/* [ */
	255,
	/* \ */
	255,
	/* ] */
	255,
	/* ^ */
	255,
	/* _ */
	255,
	/* ` */
	255,
	/* a */
	8,
	/* b */
	9,
	/* c */
	10,
	/* d */
	11,
	/* e */
	12,
	/* f */
	13,
	/* g */
	14,
	/* h */
	15,
	/* i */
	255,
	/* j */
	16,
	/* k */
	17,
	/* l */
	18,
	/* m */
	19,
	/* n */
	20,
	/* o */
	255,
	/* p */
	21,
	/* q */
	22,
	/* r */
	23,
	/* s */
	24,
	/* t */
	25,
	/* u */
	26,
	/* v */
	27,
	/* w */
	28,
	/* x */
	29,
	/* y */
	30,
	/* z */
	31,
	/* { */
	255,
	/* | */
	255,
	/* } */
	255,
	/* ~ */
	255,
	/* DEL */
	255
};

static const char thornal2ascii[] = {
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'A',
	'B',
	'C',
	'D',
	'E',
	'F',
	'G',
	'H',
	'J',
	'K',
	'L',
	'M',
	'N',
	'P',
	'Q',
	'R',
	'S',
	'T',
	'U',
	'V',
	'W',
	'X',
	'Y',
	'Z'
};

int thornal_to_u64( char * s, u64 * r )
{
	ASCII2THORNAL_IMPL( );
}

int thornal_to_u32( char * s, u32 * r )
{
	ASCII2THORNAL_IMPL( );
}

int thornal_to_u16( char * s, u16 * r )
{
	ASCII2THORNAL_IMPL( );
}

ptri thornal_from_u64( u64 n, char * s )
{
	THORNAL2ASCII_IMPL( 64 );
}

ptri thornal_from_u32( u32 n, char * s )
{
	THORNAL2ASCII_IMPL( 32 );
}

ptri thornal_from_u16( u16 n, char * s )
{
	THORNAL2ASCII_IMPL( 16 );
}
