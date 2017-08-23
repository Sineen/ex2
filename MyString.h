/**
 * The header file for the countSubStr function.
 */


#ifndef COUNT_SUB_STR_H
#define COUNT_SUB_STR_H

#include <stdio.h>


/**
 * Counts the amount of str1 substrings that are equal to str2.
 * In case one (or two) of the strings is empty- returns 0.
 * @str1 - the string
 * @str2 -  the substring
 * @isCycic != 0 - search also for cyclic appearnce 
 * @return number appearance of str2 as substring of str1
 */
unsigned int countSubStr(const char* str1, const char* str2, int isCyclic);
/**
 *
 * @param string
 * @return teh lingth of teh string
 */
int length (const char* string);
/**
 *
 * @param str1 the first  string we compare with
 * @param str2 teh second string we want to find
 * @param forSize how many times we need to run depends of if cyclic or of str 2 bigger or smaller that str1
 * @return how many times it was found
 */
unsigned int check(const char* str1, const char* str2, int forSize);

#endif

