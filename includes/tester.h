/*
 * tester.h
 *
 *  Created on: Sep 11, 2019
 *      Author: keith
 *
 *      Just some quick testers
 */

#ifndef TESTER_H_
#define TESTER_H_
#include <string>
#include <vector>

const float TOLERANCE = 0.01;
const int ZERO_FAILED_TEST = 0;

//returns true if expectedVal is withen tolerance of actualVal AND actualVal is a number
bool EXPECT_NEAR(std::string info, float expectedVal, float actualVal,float tolerance=TOLERANCE);

//creates a Stats object from data in finished_vector, pulls performance metrics from Stats object, and then
//runs the above test for  av_wait_time, av_response_time,  and av_turnaround_time
int verify_stats( std::string info, std::vector<PCB> &finished_vector, float av_wait_time,float av_response_time, float  av_turnaround_time);

#endif /* TESTER_H_ */
