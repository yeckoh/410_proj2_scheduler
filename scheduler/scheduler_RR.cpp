/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *  	Author: wchang 00960978
 *	 LModified: Feb 13, 2020
 *     Project: CNU-SP20-CS410 p2_scheduler
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include "../includes/scheduler_RR.h"

//override base class behaviour if necessary, otherwise call it
bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
	//return tick_count % time_slice == 0;
	//return (p.required_cpu_time-p.remaining_cpu_time) % time_slice == 0;
	return p.remaining_cpu_time <= 0 || (p.required_cpu_time-p.remaining_cpu_time) % time_slice == 0;
	//return this->Scheduler::time_to_switch_processes(tick_count, p); // preemptive is true, base evaluation should be ok?
}

//RR - preemptive - no sorting of ready_q needed.
 void Scheduler_RR::sort() {}



