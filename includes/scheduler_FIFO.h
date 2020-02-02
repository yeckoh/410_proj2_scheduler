/*
 * scheduler_FIFO.h
 *
 *  Created on: Sep 9, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

#ifndef SCHEDULER_FIFO_H_
#define SCHEDULER_FIFO_H_
#include "scheduler.h"

class Scheduler_FIFO: public Scheduler {
public:
	//this is a non - preemptive scheduler, set the preemptive member variable to false
	//when calling the base class
	Scheduler_FIFO(std::queue<PCB> &queue):Scheduler(queue,false,UNINITIALIZED){};
	virtual ~Scheduler_FIFO(){};

	//override base class behaviour if necessary, otherwise call it
	virtual bool  time_to_switch_processes(int tick_count, PCB &p);

	//FIFO - not preemptive - no sorting needed
	virtual void sort();
};

#endif /* SCHEDULER_FIFO_H_ */
