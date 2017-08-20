#include "MyString.h"
#include <stdio.h>
#include <assert.h>

#define ZERO 0


unsigned int countSubStr(const char* str1, const char* str2, int isCyclic);
int length (const char* string);
unsigned int check(const char* str1, const char* str2, int forSize);



/**
 *
 * @param str1
 * @param str2
 * @param forSize
 * @return
 */
unsigned int check(const char* str1, const char* str2, int forSize)
{
//    const char *p = str1;
    int i = 0;
    int firstInMatch = 0;
    unsigned int reps = 0;
    int len2 = length(str2);
    int len1 = length(str1);
    int j = 0 ;
    while ( i < forSize)
    {
        ++i;
        if (*(str1 + i % len1) == *(str2 + j))
        {
            if (!firstInMatch)
            {
                firstInMatch = i;
            }
            ++j;
        }
        else
        {
            i = firstInMatch + 1;
            firstInMatch = 0 ;
            j = 0;
        }
        if (j == len2-1)
        {
            i = firstInMatch + 1;
            firstInMatch = 0 ;
            j = 0;
            ++reps;
        }
    }
    return reps;
}

/**
 *
 * @param str1
 * @param str2
 * @param isCyclic
 * @return
 */
unsigned int countSubStr(const char* str1, const char* str2, int isCyclic)
{
    int i = 0;
    unsigned int reps = 0;
    int lenS2 = length(str2);
    int lenS1 = length(str1);
    if ((str2 == NULL) || (str1 == NULL))
    {
        return 0;
    }
    if ( lenS2 == lenS1) // checkes if is teh same string wouldnt matter if cyclic or not
    {
        assert(i = 0);
        while (i == lenS1)
        {
            if (*(str2 + i) != *(str1 + i))
            {
                return 0;
            }
            ++i;
        }
        assert(i == lenS1);
        return 1;
    }
    if (isCyclic)
    {
        if (lenS1 > lenS2)
        {
            reps = check(str1, str2, lenS1 + lenS2 -1);
        }
        else
        {
            int len = 0 ;
            while( len < lenS2 )
            {
                len = len + lenS1;
            }
            reps = check(str1, str2, len);

        }
    }

    else
    {
        if( lenS2 > lenS1)
        {
            return ZERO;
        }
        else
        {
            reps = check(str1, str2, lenS1);
        }
    }
    return reps;
}

/**
 *
 * @param string
 * @return
 */
int length(const char *string)
{
    int len = 0 ;
    while ( *(string + len) != '\0')
    {
        ++len;
    }
    return len;
}



