Author:
Benjamin Grant 

Steps on running the project
1.Once added to QNX workplace run COEN_320_Project file that includes main.cpp
2.The console will start by loading it may take 2-5 sec for the database to load and the console will show "Database Created"
3. The system will now ask for the periods of all the tasks one by one, it will look like 
	Input desired FUEL period: X
	Input desired RPM period: y
	Input desired TEMP Period: z
	Input desired GEAR period: a
	Input desired SPEED period: b
	Input desired CONSUMER period: c
4. The system will start running and will show the current time and current sensor values based on the given periods
	----------0----------
	Current FUEL: 0
	Current RPM: 0
	Current TEMP: 0
	Current GEAR: 0
	Current SPEED: 0
5. As that the period for the consumer maybe lower than the period of the sensor values the consumer will show the last writen sensor values
6. A restart is needed to change the periods

