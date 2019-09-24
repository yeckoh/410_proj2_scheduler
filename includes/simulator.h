/*
 * simulator.h
 *
 *  Created on: Sep 11, 2019
 *      Author: keith
 */

#ifndef SIMULATOR_H_
#define SIMULATOR_H_
#include <vector>
#include "../includes/constants.h"
#include "../includes/scheduler.h"
#include "../includes/PCB.h"

//simulates processes being loaded and unloaded onto a CPU using a dispatcher and scheduler
void simulate(const char* pSourceFile,Scheduler &s,std::vector<PCB> &finished_vector, int time_slice= DEFAULT_TIME_SLICE);

#endif /* SIMULATOR_H_ */
