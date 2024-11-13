#include "sched.h"
#include "switch.h"
#include <stdlib.h>
#include <limits.h>

extern struct proc proc[];

struct proc* select_next(){
    struct proc *candidate = NULL;
    int max_priority = INT_MIN;

    for (int i = 0; i < NUMPROC; i++) {
        if (proc[i].status == RUNNABLE && proc[i].priority > max_priority) {
            candidate = &proc[i];
            max_priority = proc[i].priority;
        }
    }

    return candidate;
}

void scheduler(){
    while (!done()){
        struct proc *candidate = select_next();

        if (candidate != NULL) {
            candidate->status = RUNNING;
            candidate->runtime += swtch(candidate);
            candidate->priority -= 1;
        } else {
            idle();
        }
    }
}