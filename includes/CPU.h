/*
 * CPU.h
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 *
 *      simulates a CPU with a single core
 */

#ifndef CPU_H_
#define CPU_H_
#include "constants.h"
#include "PCB.h"

class CPU {
public:
	CPU():current_Process(NULL){};
	virtual ~CPU(){};

	//move a process on to the CPU to run
	void put_process_on_core(PCB &pcb);

	//will return the PCB thats currently on the core or an uninitialized PCB
	PCB get_process_off_core();

	//run process on core (subtract 1 from remaining_cpu_time)
	void run();

	//get a COPY of private data or pass back an uninitialized PCB
	//mostly used for diagnostics
	PCB get_COPY_of_Current_Process();
private:
	PCB* current_Process;										//this can be null
};

#endif /* CPU_H_ */
