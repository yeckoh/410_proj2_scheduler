/*
 * scheduler_RR.h
 *
 *  Created on: Sep 9, 2019
 *      Author: keith
 */

#ifndef SCHEDULER_RR_H_
#define SCHEDULER_RR_H_
#include "scheduler.h"

class Scheduler_RR: public Scheduler {
public:
	//this is a preemptive scheduler, so set the preemptive member variable to true
	//when calling the base class
	Scheduler_RR(std::queue<PCB> &queue,int time_slice =
			UNINITIALIZED):Scheduler(queue,true,time_slice){};
	virtual ~Scheduler_RR(){};
	virtual void sort();
};

#endif /* SCHEDULER_RR_H_ */
