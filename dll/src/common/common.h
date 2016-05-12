#ifndef COMMON_H
#define COMMON_H

#include "mbfunctions.h"

#pragma warning(push, 0)
#define NOMINMAX //don't import min/max from windows.h
#include <windows.h>
#define EXPORT extern "C" __declspec(dllexport)
#pragma warning(pop)

EXPORT double better_rand();
EXPORT int sort_char_array_all( char* array[], int array_len );
EXPORT int sort_char_array( char* array[], int start_pos, int end_pos );
EXPORT int regex_test( char* s_input, char* s_match );
EXPORT const char* regex_match( char* s_input, char* s_match );
EXPORT int regex_match_multiple( char* s_input, char* s_match, char* s_matches[] );
EXPORT int regex_match_all( char* s_input, char* s_match, char* s_matches[] );
EXPORT int regex_replace( char* s_input, char* s_match, char* s_replace, char* s_dest );

#endif // COMMON_H
