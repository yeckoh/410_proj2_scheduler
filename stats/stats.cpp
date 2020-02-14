/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *  	Author: wchang 00960978
 *	 LModified: Feb 13, 2020
 *     Project: CNU-SP20-CS410 p2_scheduler
 *
 */

#include "../includes/stats.h"
using namespace std;

// how come only stats doesn't get initializer lists in header?
Stats::Stats(std::vector<PCB> &finished_vector) : vec(&finished_vector), av_wait_time(0), av_turnaround_time(0), av_response_time(0) {}

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo() {
	for (PCB p : *vec) // 2 spaces between req_time & arrived
		printf("Process %d Required CPU time:%d  arrived:%d started:%d finished:%d\n",
				p.process_number, p.required_cpu_time, p.arrival_time, p.start_time, p.finish_time );
}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time() {
	float total = 0;
	for (PCB p : *vec)
		total += p.start_time - p.arrival_time;
	return total / vec->size();
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time() {
	float total = 0;
	for (PCB p : *vec)
		total += p.finish_time - p.arrival_time;
	return total / vec->size();
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this function returns the average over all processes
float Stats::get_av_wait_time() {
	float total = 0;
	for (PCB p : *vec)
		total += p.finish_time - p.arrival_time - p.required_cpu_time;
	return total / vec->size();
}

