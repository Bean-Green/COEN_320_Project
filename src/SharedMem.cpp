/*
 * SharedMem.cpp
 *
 *  Created on: Apr. 3, 2022
 *      Author: JBGra
 */

#include "SharedMem.h"
const int SHM_SIZE = 4096;



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


double SharedMem::access_mem(int rw, int type , double value) //(READ/WRITE, FUEL/RPM/TEMP/GEAR/SPEED, if write VALUE written)
{
	double temp = 0;
	string* string_ptr;
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
			mtx_fuel->unlock();
			return 101;

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

			string_ptr = (string*)ptr;
			temp = stod(*string_ptr);

			close(shm_fd);
			mtx_fuel->unlock();
			return temp;
		}
	}
	if (type == RPM)
	{
		mtx_rpm->lock();
		if (rw == WRITE)
		{
			int shm_fd;
			void *ptr;

			/* create the shared memory segment */
			shm_fd = shm_open("/mem_rpm", O_CREAT | O_RDWR, 0667); if (shm_fd == -1){
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
			mtx_rpm->unlock();
			return 101;

		}
		else if (rw == READ)
		{
			int shm_fd;
			void *ptr;
			/* open the shared memory segment */
			shm_fd = shm_open("/mem_rpm", O_RDONLY, 0667);
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


			string_ptr = (string*)ptr;
			temp = stod(*string_ptr);

			close(shm_fd);
			mtx_rpm->unlock();
			return temp;
		}
	}
	if (type == TEMP)
	{
		mtx_temp->lock();
		if (rw == WRITE)
		{
			int shm_fd;
			void *ptr;

			/* create the shared memory segment */
			shm_fd = shm_open("/mem_temp", O_CREAT | O_RDWR, 0667); if (shm_fd == -1){
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
			mtx_temp->unlock();
			return 101;

		}
		else if (rw == READ)
		{
			int shm_fd;
			void *ptr;
			/* open the shared memory segment */
			shm_fd = shm_open("/mem_temp", O_RDONLY, 0667);
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

			string_ptr = (string*)ptr;
			temp = stod(*string_ptr);

			close(shm_fd);
			mtx_temp->unlock();
			return temp;
		}
	}
	if (type == GEAR)
	{
		mtx_gear->lock();
		if (rw == WRITE)
		{
			int shm_fd;
			void *ptr;

			/* create the shared memory segment */
			shm_fd = shm_open("/mem_gear", O_CREAT | O_RDWR, 0667); if (shm_fd == -1){
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
			mtx_gear->unlock();
			return 101;

		}
		else if (rw == READ)
		{
			int shm_fd;
			void *ptr;
			/* open the shared memory segment */
			shm_fd = shm_open("/mem_gear", O_RDONLY, 0667);
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


			string_ptr = (string*)ptr;
			temp = stod(*string_ptr);

			close(shm_fd);
			mtx_gear->unlock();
			return temp;
			}
		}
	if (type == SPEED)
	{
		mtx_speed->lock();
		if (rw == WRITE)
		{
			int shm_fd;
			void *ptr;

			/* create the shared memory segment */
			shm_fd = shm_open("/mem_speed", O_CREAT | O_RDWR, 0667); if (shm_fd == -1){
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
			mtx_speed->unlock();
			return 101;

		}
		else if (rw == READ)
		{
			int shm_fd;
			void *ptr;
			/* open the shared memory segment */
			shm_fd = shm_open("/mem_speed", O_RDONLY, 0667);
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

			string_ptr = (string*)ptr;
			temp = stod(*string_ptr);

			close(shm_fd);
			mtx_speed->unlock();
			return temp;
		}
	}
return 404;
}

