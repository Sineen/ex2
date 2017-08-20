//#include "MyString.h"
//#include <stdio.h>
//
//unsigned int countSubStr(const char* str1, const char* str2, int isCyclic);
//
//
//unsigned int countSubStr(const char* str1, const char* str2, int isCyclic)
//{
//    if ((*str2 == NULL) || (*str1 == NULL))
//    {
//        return 0;
//    }
//    if (isCyclic)
//    {
//
//    }
//    else
//    {
//        const char* i;
//        const char* j;
//        for(i = str2; *i != '/0'; i++ )
//        {
//            //i is a pointer
//            for(j = str1; *j != '/0'; j++ )
//            {
//
//            }
//        }
//    }
//    return 0;
//}
//
//int main()
//{
//    char *str1 = "abab";
//    char *str2 = "aba";
//    int res = countSubStr(str1,str2,0);
//    if (1 != res)
//    {
//        printf("calling countSubStr with str1: \"abab\", str2: \"aba\" and isCyclic=0 should return 1\n");
//        return 1;
//    }
//
//    res = countSubStr(str1,str2,1);
//    if (2 != res)
//    {
//        printf("calling countSubStr with str1: \"abab\", str2: \"aba\" and isCyclic=1 should return 2\n");
//        return 1;
//    }
//
//    printf("running example passed\n");
//
////    char c = 'a';
////    int ascii = (int) c;
////    return 0;
//}