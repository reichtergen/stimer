#include <stdio.h> // for printf()
#include <synchapi.h> // for Sleep()

#include "stimer.h"


void func( void ) {
    printf("hello timer!\n");
}

int main( void ) {

    stimer_t timer;

    init_timer(&timer, 1000, func);

    start_timer(&timer);

    printf("**** timer started! ****\n");
    
    Sleep(10000); /* Wait for 10 sec */

    stop_timer(&timer);
    printf("**** timer stopped! ****\n");

    getchar(); 
    return 0;
}