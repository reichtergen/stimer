#ifndef STIMER_H
#define STIMER_H


typedef void * HANDLE;

typedef struct stimer_t {
    long tick;
    void (*call_back)(void);
    int state;
    HANDLE thread;

} stimer_t;



void init_timer(stimer_t *timer, long tick, void (*call_back)(void) );
void start_timer(stimer_t *timer);
void stop_timer(stimer_t *timer);

#endif