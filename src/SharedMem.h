#include <mutex>
#include <iostream>
#include <string>

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/mman.h>

using namespace std;


#ifndef SRC_SHAREDMEM_H_
#define SRC_SHAREDMEM_H_

enum data_enum {
	FUEL = 1,
	RPM = 2,
	TEMP = 3,
	GEAR = 4,
	SPEED = 5
};

enum en_rw{
	WRITE = 0,
	READ = 1
};

class SharedMem {
public:
	SharedMem();
	virtual ~SharedMem();
	double access_mem(int rw, int type, double value);
	mutex* mtx_fuel;
	mutex* mtx_rpm;
	mutex* mtx_temp;
	mutex* mtx_gear;
	mutex* mtx_speed;

};

#endif /* SRC_SHAREDMEM_H_ */
