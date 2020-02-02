/*
 * SchedulerSRTF.h
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *     implements SRTF scheduling algorithm
 *     pre-emptive
 */

#ifndef SCHEDULERSRTF_H_
#define SCHEDULERSRTF_H_
#include "scheduler.h"

class Scheduler_SRTF: public Scheduler {
public:
	//this is a  preemptive scheduler, so set the preemptive member variable to true
	//when calling the base class
	Scheduler_SRTF(std::queue<PCB> &queue):Scheduler(queue,true,UNINITIALIZED){};
	virtual ~Scheduler_SRTF(){};

	//override base class behaviour if necessary, otherwise call it
	virtual bool  time_to_switch_processes(int tick_count, PCB &p);

	//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
	virtual void sort();
};

#endif /* SCHEDULERSRTF_H_ */
