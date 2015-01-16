#include<defs.h>
#include<ustdlib.h>

void memset(void *s, unsigned char c, uint32_t n)
{
    unsigned char* p= (unsigned char*)s;
    while(n--)
        *p++ = (unsigned char)c;
}