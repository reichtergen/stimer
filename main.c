#include <stdio.h> // for printf()
#include <synchapi.h> // for Sleep()

#include "stimer.h"


void func( void ) {
    printf("hello timer!\n");
}

void func2( void ) {
    printf("Goodbye timer!\n");
}

int main( void ) {

    stimer_t timer, timer2;

    init_timer(&timer, 1000, func);
    init_timer(&timer2, 500, func2);

    start_timer(&timer2);
    start_timer(&timer);

    printf("**** timer started! ****\n");
    
    Sleep(10000); /* Wait for 10 sec */

    stop_timer(&timer);
    stop_timer(&timer2);
    printf("**** timer stopped! ****\n");

    getchar(); 
    return 0;
}