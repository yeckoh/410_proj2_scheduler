/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *  	Author: wchang 00960978
 *	 LModified: Feb 13, 2020
 *     Project: CNU-SP20-CS410 p2_scheduler
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include <algorithm>
#include "../includes/scheduler_SRTF.h"
using namespace std;

//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	sort();
	if(ready_q->front().remaining_cpu_time < p.remaining_cpu_time)
		return true;
	//if(!ready_q->empty())
	//return ready_q->front().remaining_cpu_time < p.remaining_cpu_time;
	return this->Scheduler::time_to_switch_processes(tick_count, p);
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	// make a vector with all the stuff on it
	vector<PCB> pcb_vec;
	while(!ready_q->empty()) { 		// fill vec & clear the queue using copy smallbrain mode
		pcb_vec.push_back(ready_q->front());
		ready_q->pop();
	}
	// use bigbrain std::sort w/ lambda again
	std::sort(pcb_vec.begin(), pcb_vec.end(), [](const PCB& l, const PCB& r) {return l.remaining_cpu_time < r.remaining_cpu_time;});
	// put sorted PCBs back
	for(PCB p : pcb_vec)
		ready_q->push(p);
}
