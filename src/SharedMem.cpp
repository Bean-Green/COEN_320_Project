/*
 * SharedMem.cpp
 *
 *  Created on: Apr. 3, 2022
 *      Author: JBGra
 */

#include "SharedMem.h"
const int SHM_SIZE = 4096;
const int MSG_SIZE = 100;



SharedMem::SharedMem() {

	this->mtx_fuel = new mutex();
	this->mtx_rpm = new mutex();
	this->mtx_temp = new mutex();
	this->mtx_gear = new mutex();
	this->mtx_speed = new mutex();

}

SharedMem::~SharedMem() {
	// TODO Auto-generated destructor stub
}

double SharedMem::access_mem(int rw, int type , double value)
{
	double temp = 0;
	if (type == FUEL)
	{
		mtx_fuel->lock();
		if (rw == WRITE)
		{
			int shm_fd;
			void *ptr;

			/* create the shared memory segment */
			shm_fd = shm_open("/mem_fuel", O_CREAT | O_RDWR, 0666); if (shm_fd == -1){
				perror("In shm_open()");
				exit(1);
			}

			/* configure the size of the shared memory segment */
			ftruncate(shm_fd, SHM_SIZE);

			/* now map the shared memory segment in the address space of the process */
			ptr = mmap(0,SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
			if (ptr == MAP_FAILED) {
				printf("Map failed\n"); return -1;
			}

			string str_value = to_string(value);
			char* chr_value = &str_value[0];
			sprintf((char*)ptr,"%s",  chr_value);

			close(shm_fd);

			cout << "memory was created " << endl;

			return 1;

		}
		else if (rw == READ)
		{
			int shm_fd;
			void *ptr;
			/* open the shared memory segment */
			shm_fd = shm_open("/mem_fuel", O_RDONLY, 0666);
			if (shm_fd == -1) {
		    	perror("in shm_open()");
				exit(1);
			}

			/* now map the shared memory segment in the address space of the process */
			ptr = mmap(0,SHM_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
			if (ptr == MAP_FAILED) {
		    	perror("in mmap()");
				exit(1);
			}

			/* now read from the shared memory region */
			printf("Content in the shared memory:\n");
			printf("    %s", ptr);

			close(shm_fd);

			return temp;

		}
		mtx_fuel->unlock();
	}
}

