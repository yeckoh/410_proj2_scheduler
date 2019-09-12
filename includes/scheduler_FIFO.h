/*
 * scheduler_FIFO.h
 *
 *  Created on: Sep 9, 2019
 *      Author: keith
 */

#ifndef SCHEDULER_FIFO_H_
#define SCHEDULER_FIFO_H_
#include "scheduler.h"

class Scheduler_FIFO: public Scheduler {
public:
	//this is a non - preemptive scheduler, so set the preemptive member variable to true
	//when calling the base class
	Scheduler_FIFO(std::queue<PCB> &queue):Scheduler(queue,false,UNINITIALIZED){};
	virtual ~Scheduler_FIFO(){};
	virtual void sort();
};

#endif /* SCHEDULER_FIFO_H_ */
