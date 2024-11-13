#ifndef SCHED_H
#define SCHED_H

#define NUMPROC 5
#define TIMESLICE 20 
#define MAX_PRIORITY 10
#define BOOST_FREQ 1000

enum Status { RUNNING, RUNNABLE, BLOCKED };

struct proc {
    int pid;
    enum Status status;
    int priority;
    int runtime;
};

void scheduler();

#endif