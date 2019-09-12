/*
 * PCB.h
 *
 *  Created on: Sep 9, 2019
 *      Author: keith
 *
 *      defines a rudimentary process control block
 */

#ifndef PCB_H_
#define PCB_H_
#include "constants.h"

//this is where the loaded data goes
//currently io_time is unused
struct PCB {
	int process_number, arrival_time,required_cpu_time,io_time;
	int   remaining_cpu_time,start_time,  finish_time	;	//used to calc stats
	PCB(){
		reset();
	}

	void reset(){
		process_number = arrival_time = remaining_cpu_time =required_cpu_time= io_time=start_time = finish_time = UNINITIALIZED;
	}

	//if any fields are uniinitialized then its empty
	bool isEmpty(){
		return (process_number ==UNINITIALIZED);
	}
	//default copy constructor and assignment operator should work correctly given that
	//this object has no dynamicly allocated members

};
#endif /* PCB_H_ */
