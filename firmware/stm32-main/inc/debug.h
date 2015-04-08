#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

/* for SWV debug (with printf) */

#ifdef _DEBUG
    #include <stdio.h>
    int fputc(int ch, FILE *f){
        return (ITM_SendChar(ch));
    }
#endif

void debug(char* format, ...){
    #ifdef _DEBUG
        printf(format);
    #endif
};

#endif /* DEBUG_H_INCLUDED */
