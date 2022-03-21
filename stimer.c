#include "stimer.h"

#include <processthreadsapi.h>
#include <synchapi.h>
#include <handleapi.h>
#include <time.h>


void init_timer(stimer_t *timer, long tick, void (*call_back)(void) ) {
    timer->tick = tick;
    timer->call_back = call_back;
    timer->state = 0;
    
}

static DWORD WINAPI timer_process(stimer_t *timer) {

    while (timer->state) {

        Sleep(timer->tick);
        
        timer->call_back(); 
    }

    return 0;
}

void start_timer(stimer_t *timer) {

    timer->state = 1;
    timer->thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)timer_process, timer, 0, NULL);
 
}

void stop_timer(stimer_t *timer) {
    timer->state = 0;
    CloseHandle(timer->thread);
}
