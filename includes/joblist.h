/*
 * Joblist.h
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#ifndef JOBLIST_H_
#define JOBLIST_H_
#include "constants.h"
#include "PCB.h"

class Joblist {
public:
	//loads data from filename and sorts
	//it by job start time
	Joblist(){};
	virtual ~Joblist(){};

	int init(const char* filename = SOURCE_FILE_1);

	//returns true if its time for any job to be submitted
	bool has_ready_jobs(int currentTick);

	//returns  a job for submission
	//then erases it from Joblist internal data structure
	PCB get_next_job(int currentTick);

	//returns true if there are still jobs waiting to start
	//false otherwise
	bool isEmpty();

private:
	int retCode;
};
#endif /* JOBLIST_H_ */
