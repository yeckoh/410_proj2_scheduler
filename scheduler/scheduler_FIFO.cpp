/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

//TODO fill in content
#include "../includes/scheduler_FIFO.h"


Scheduler_FIFO::Scheduler_FIFO(std::queue<PCB> &queue):Scheduler(queue,false,UNINITIALIZED) {}

Scheduler_FIFO::~Scheduler_FIFO() {}

//override base class behaviour if necessary, otherwise call it
bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p) {
	return this->Scheduler(&tick_count, &p);
}

//FIFO - not preemptive - no sorting needed
void sort() {}
