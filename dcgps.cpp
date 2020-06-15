/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: 	dcgps.cpp - A basic GPS application that will connect to
--  					  	  	satellites through GPS dongle for finding your location.
--
-- PROGRAM: 		Location Finder
--
-- FUNCTIONS:		int main (void)
--
-- DATE: 			November 2, 2019
--
-- REVISIONS: 		
--
-- DESIGNER: 		Victor Phan/Jason Nguyen/Peter Xiong
--
-- PROGRAMMER: 		Victor Phan
--
-- NOTES:
-- The program will find your location by connecting your Embedded platform
-- (such as Raspberry PI) with satellites through GPS dongle. The GPSD daemon
-- and its associated API library will be used to implement the design.
----------------------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <libgpsmm.h>
#include <thread>
#include "gps-utils.hpp"
#include "gpsprint.hpp"

/*-----------------------------------------------------------------------------------------------------------------
-- Function:	main
--
-- DATE:		November 1, 2019
--
-- REVISIONS:	November 1, 2019
--
-- DESIGNER:	Victor Phan/Jason Nguyen/Peter Xiong
--
-- PROGRAMMER:	Victor Phan
--
-- INTERFACE:	int main()
--
-- RETURNS:		0 if successful. 1 if not.
--
-- NOTES:
-- This function is the main function of the program. It will malloc the
-- gps_data_t structure, open the socket connection to GPSD daemon, and
-- start the stream. In addition it will also perform cleanup work and free
-- resources when the application terminates.
-------------------------------------------------------------------------------------------------------------------*/
int main()
{
  gpsmm *gps_rec = new gpsmm("localhost", DEFAULT_GPSD_PORT);
  if (gps_rec->stream(WATCH_ENABLE | WATCH_JSON) == NULL) {
    errorReport("No GPSD running.");
    return 1;
  }
  struct gps_data_t *gpsd_data;
  bool stopProgram = false;
  bool* stop = &stopProgram;
  thread readThread{readGPSData,gps_rec,gpsd_data,stop}; 
  while(!(*stop)) {
	  string userInput;
	  cin >> userInput;
	  if(userInput == "q") {
		  *stop = true;
	  }
  }
  readThread.join();
  delete gpsd_data;
  delete gps_rec;
  return 0;
}

