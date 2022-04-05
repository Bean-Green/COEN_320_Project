/*
 * PeriodicTimer.h
 *
 *  Created on: Apr. 4, 2022
 *      Author: Zach
 */
extern "C"{
	#include <sys/time.h>
	#include <signal.h>
	#include <time.h>
	#include <stdlib.h>
	#include <stdint.h>
	#include <string.h>
	#include <stdio.h>
}


#ifndef SRC_PERIODICTIMER_H_
#define SRC_PERIODICTIMER_H_

#define ONE_THOUSAND	1000
#define ONE_MILLION		1000000


class PeriodicTimer {
public:
	PeriodicTimer();

	void wait_next_activation(sigset_t *);
	void start_periodic_timer(uint64_t offset, int speriod, sigset_t* sigst);
	int getTime();
private:
	int previous;
	int period;
};

#endif /* SRC_PERIODICTIMER_H_ */
