//#include <syscall.h>
#include <defs.h>
#include <ustdlib.h>
#include <stdarg.h>

uint16_t write(const char* buf){
  __asm__("movq $0x2, %rax;\n\tint $0x80;"); 
  return 0;
}

int printf(const char *fmt, ...) {
       const char *p;
       char buf[100];
       uint16_t ind,cnt=0;
       int i; 
       char *s; 
       va_list arg_p; 
       va_start(arg_p, fmt); 
       for(p=fmt; *p ; p++){
               if(*p != '%'){
                        buf[cnt++] = *p;
                       continue;
               }
               switch(*++p){
                       case 'c': i = va_arg(arg_p, int);
                                 buf[cnt++] = i;
                                 break;
                       case 's': s = va_arg(arg_p, char*);
                                 ind = 0;
                                 while(s[ind])
                                      buf[cnt++] = s[ind++];
                                 break;
               }
       }
       va_end(arg_p);
       write((const char*)buf);
       memset(buf, '\0', sizeof(buf));
	return 0;
}
