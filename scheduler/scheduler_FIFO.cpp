/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *  	Author: wchang 00960978
 *	 LModified: Feb 13, 2020
 *     Project: CNU-SP20-CS410 p2_scheduler
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

#include "../includes/scheduler_FIFO.h"

//override base class behaviour if necessary, otherwise call it
bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p) {
	return this->Scheduler::time_to_switch_processes(tick_count, p);
	//return this->Scheduler::time_to_switch_processes(tick_count, p); // preemptive is true, base evaluation should be ok?
}

//FIFO - not preemptive - no sorting needed
 void Scheduler_FIFO::sort() {}
