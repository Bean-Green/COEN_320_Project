/*
 * PeriodicTimer.cpp
 *
 *  Created on: Apr. 4, 2022
 *      Author: Zach
 *      Derived from Timers.C
 */

#include "PeriodicTimer.h"
PeriodicTimer::PeriodicTimer(){

	previous = 0;
	period = 0;
}

extern "C"{
	void PeriodicTimer::wait_next_activation(sigset_t* sigst) {
		int dummy;
		/* suspend calling process until a signal is pending */
		sigwait(sigst, &dummy);
	}
}
extern "C"{
	void PeriodicTimer::start_periodic_timer(uint64_t offset, int speriod,sigset_t* sigst) {
		struct itimerspec timer_spec;
		struct sigevent sigev;
		timer_t timer;
		const int signal = SIGALRM;
		int res;
		period = speriod;
		/* set timer parameters */
		timer_spec.it_value.tv_sec = offset / ONE_MILLION;
		timer_spec.it_value.tv_nsec = (offset % ONE_MILLION) * ONE_THOUSAND;
		timer_spec.it_interval.tv_sec = period / ONE_MILLION;
		timer_spec.it_interval.tv_nsec = (period % ONE_MILLION) * ONE_THOUSAND;

		sigemptyset(sigst); // initialize a signal set
		sigaddset(sigst, signal); // add SIGALRM to the signal set
		sigprocmask(SIG_BLOCK, sigst, NULL); //block the signal

		/* set the signal event a timer expiration */
		memset(&sigev, 0, sizeof(struct sigevent));
		sigev.sigev_notify = SIGEV_SIGNAL;
		sigev.sigev_signo = signal;

		/* create timer */
		res = timer_create(CLOCK_MONOTONIC, &sigev, &timer);

		if (res < 0) {
			perror("Timer Create");
			exit(-1);
		}

		/* activate the timer */
		if (timer_settime(timer, 0, &timer_spec, NULL)<0){
			perror("Timer Create");
			exit(-1);
		}
	}
}

extern "C"{
	int PeriodicTimer::getTime() {
		//static int cycles = 0;
		static uint64_t start;
		uint64_t current;
		struct timespec tv;

		if (start == 0) {

			clock_gettime(CLOCK_MONOTONIC, &tv);
			start = tv.tv_sec * ONE_THOUSAND + tv.tv_nsec / ONE_MILLION;
		}

		clock_gettime(CLOCK_MONOTONIC, &tv);
		current = tv.tv_sec * ONE_THOUSAND + tv.tv_nsec / ONE_MILLION;

		if ((current - start - previous)/1000 > (uint64_t )period){

			printf("missed deadline");
		}

		previous = (current - start)/1000;

		return previous;
	}
}
