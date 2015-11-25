#ifndef INC_hierSysParserTokenTypes_hpp_
#define INC_hierSysParserTokenTypes_hpp_

/* $ANTLR 2.7.7 (2006-11-01): "hierSys.g" -> "hierSysParserTokenTypes.hpp"$ */

#ifndef CUSTOM_API
# define CUSTOM_API
#endif

#ifdef __cplusplus
struct CUSTOM_API hierSysParserTokenTypes {
#endif
	enum {
		EOF_ = 1,
		SYSTEM = 4,
		SIMPLE_IDENTIFIER = 5,
		LIBRARY = 6,
		IN = 7,
		NOBLOCK = 8,
		PIPE = 9,
		SIGNAL = 10,
		UINTEGER = 11,
		DEPTH = 12,
		OUT = 13,
		LBRACE = 14,
		RBRACE = 15,
		INSTANCE = 16,
		COLON = 17,
		IMPLIES = 18,
		LIFO = 19,
		UINT = 20,
		LESS = 21,
		GREATER = 22,
		THREAD = 23,
		DEFAULT = 24,
		NOW = 25,
		TICK = 26,
		STRING = 27,
		VARIABLE = 28,
		CONSTANT = 29,
		ASSIGNEQUAL = 30,
		SPLIT = 31,
		LPAREN = 32,
		RPAREN = 33,
		NuLL = 34,
		GOTO = 35,
		LOG = 36,
		IF = 37,
		ELSE = 38,
		BINARY = 39,
		HEXADECIMAL = 40,
		COMMA = 41,
		REQ = 42,
		ACK = 43,
		LBRACKET = 44,
		RBRACKET = 45,
		SLICE = 46,
		MUX = 47,
		NOT = 48,
		OR = 49,
		AND = 50,
		NOR = 51,
		NAND = 52,
		XOR = 53,
		XNOR = 54,
		SHL = 55,
		SHR = 56,
		ROL = 57,
		ROR = 58,
		PLUS = 59,
		MINUS = 60,
		MUL = 61,
		DIV = 62,
		EQUAL = 63,
		NOTEQUAL = 64,
		LESSEQUAL = 65,
		GREATEREQUAL = 66,
		CONCAT = 67,
		INTEGER = 68,
		UNSIGNED = 69,
		SIGNED = 70,
		ARRAY = 71,
		OF = 72,
		GROUP = 73,
		EMIT = 74,
		WHITESPACE = 75,
		SINGLELINECOMMENT = 76,
		ALPHA = 77,
		DIGIT = 78,
		NULL_TREE_LOOKAHEAD = 3
	};
#ifdef __cplusplus
};
#endif
#endif /*INC_hierSysParserTokenTypes_hpp_*/
