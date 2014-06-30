/*
 * =====================================================================================
 *
 *       Filename:  strlen.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/27/14 15:25:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  NDSL UESTC
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstddef>
#include <assert.h>

using namespace std;

size_t strlen(const char* str) {
    const char *s;
    for (s = str; *s; ++s) { }
    return (s - str);
}

char* strcpy(char* to, const char *from) {
    assert(to != NULL && from != NULL);
    char *p = to;
    while(*from) {
        *p++ = *from++;
    }
    return to;
}

char * strstr(const char* const haystack, const char* const needle) {
    const char* ph;
    const char* pn;
    const char* p_advance = haystack;

    for (pn = needle+1; *pn; ++pn) {
        p_advance++;
    }

    for (ph = haystack; *p_advance; ++ph, ++p_advance) {
        const char* ph_new = ph;
        pn = needle;
        while(*ph_new && *pn && *ph_new == *pn) {
            ph_new++;
            pn++;
        }
        if (!*pn) return (char*)ph;
    }
    return NULL;
}

const int INT_MAX = 2147483647;
const int INT_MIN = -2147483648;


int atoi(const char *str) {
    int num = 0;
    int sign = 1;
    const int len = strlen(str);
    int i = 0;

    while (str[i] == ' ' && i < len) i++;

    if (str[i] == '+') i++;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }

    for (; i < len; ++i) {
        if (str[i] < '0' || str[i] > '9' ) 
            break;
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + str[i] - '0';
    }
    return num * sign;
}

int main() {
    char *str = (char *)"abacacc";
    //size_t len = strlen(str);
    //cout << "len = " << len << endl;
    
    char to[100];
    char* pto = strcpy(to, str);
    //cout << pto << endl;

    char *needle = (char*)"cac";
    pto = strstr(str, needle);
    //cout << pto << endl;


    char *pNum = (char*) "  - 890x90";
    cout << atoi(pNum) << endl;

}
