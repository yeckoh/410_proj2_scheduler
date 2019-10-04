/*
 * SchedulerSRTF.h
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#ifndef SCHEDULERSRTF_H_
#define SCHEDULERSRTF_H_
#include "scheduler.h"

class Scheduler_SRTF: public Scheduler {
public:
	//this is a preemptive scheduler, so set the preemptive member variable to true
	//when calling the base class
	bool  time_to_switch_processes(int tick_count, PCB &p);
	Scheduler_SRTF(std::queue<PCB> &queue):Scheduler(queue,true,UNINITIALIZED){};
	virtual ~Scheduler_SRTF(){};
	virtual void sort();
};

#endif /* SCHEDULERSRTF_H_ */
