#include "SharedMem.h"

#ifndef SRC_CONSUMER_H_
#define SRC_CONSUMER_H_

extern int current_time;
extern mutex CPU;

class Consumer
{
public:
	Consumer(double period, SharedMem* sm_ptr);
	virtual ~Consumer();
	void* consume(void* arg);
	void start();
private:
	int last_activation;
	double curr_fuel;
	double curr_rpm;
	double curr_temp;
	double curr_gear;
	double curr_speed;
	SharedMem* SM_ptr;
	double period;
};

#endif /* SRC_CONSUMER_H_ */
