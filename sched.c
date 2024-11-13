#include "sched.h"
#include "switch.h"
#include <stdlib.h>
#include <limits.h>

extern struct proc proc[];
int last = 0;

struct proc* select_next(){
    for (int i = 0; i < NUMPROC; i++) {
        int next = (last + i) % NUMPROC;
        if (proc[next].status == RUNNABLE) {
            last = next;
            return &proc[next];
        }
    }
    return NULL;
}

void scheduler(){
    while (!done()){
        struct proc *candidate = select_next();

        if (candidate != NULL) {
            candidate->status = RUNNING;
            candidate->runtime += swtch(candidate);
        } else {
            idle();
        }
    }
}