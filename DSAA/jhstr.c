#include "jhstr.h"
#define RANGECHK(m,a,b) ((m >= a && m <= b) ? 0: -1)

int
jhstr_digit_chk(char c)
{
    return RANGECHK(c,'0','9');
}

int
jhstr_lowercase_chk(char c)
{
    return RANGECHK(c, 'a', 'z');
}

int
jhstr_uppercase_chk(char c)
{
    return RANGECHK(c, 'A', 'Z');
}

int
jhstr_alpha_chk(char c)
{
    return
    (jhstr_lowercase_chk(c) == 0 ||
     jhstr_uppercase_chk(c) == 0 ) ? 0 : -1;
}

char
jhstr_alpha_lower(char c)
{ 
    if(jhstr_uppercase_chk(c) == 0)
	c = c + 32;
    return c;
}

char
jhstr_alpha_upper(char c)
{
    if(jhstr_lowercase_chk(c) == 0)
	c = c - 32;
    return c;
}
