/*
 * Scheduler.h
 *
 *  Created on: Sep 7, 2019
 *      Author: keiths to run next and
 *
 *      Chooses which process to run next also determines when its time to switch processes
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#include <queue>
#include "constants.h"
#include "PCB.h"

class Scheduler {
public:
	Scheduler(std::queue<PCB> &queue, bool preemptive = false, int time_slice =
			UNINITIALIZED) :	ready_q(&queue), preemptive(preemptive), time_slice(time_slice){	};
	virtual ~Scheduler() {	};

	//add a process, either a new one or one that
	//had been running on the CPU and has been preempted
	virtual void add(PCB p);

	//get next process
	virtual PCB getNext();

	//returns true if there are no  jobs in the readyQ
	//false otherwise
	bool isEmpty();

	//if process has completed (used all its remaining_cpu_time) or
	//if we are using a preemptive scheduling algorithm and the
	//timeslice is over then its time to switch processes
	//returns:
	//true - switch processes
	//false - do not switch
	virtual bool   time_to_switch_processes(int tick_count, PCB &p);
protected:
	// sort  ready_q based on the scheduler algorithm whenever add(PCB p) is called
	//FIFO 			not preemptive - no sorting, just push job onto back of ready_q
	//SRTF 	    preemptive - sort by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
	//RR 	        	preemptive - no sorting, just push job onto back of ready_q
	virtual void sort()=0;

	//holds jobs that are in memory and ready to run
	//for this program they are leaded into memory at arrival time
	//this is initialized from a reference, it cannot be null
	std::queue<PCB> *ready_q;

	//preemptive algorithm or not
	bool preemptive;

	//number of clock ticks a process can run before its switched out
	int     time_slice;
};

#endif /* SCHEDULER_H_ */
