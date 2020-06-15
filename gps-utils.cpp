/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: 	gps-utilis.cpp - This is the major control module of the application.
--
-- PROGRAM: 		Location Finder
--
-- FUNCTIONS:		void readGPSData(gpsmm *gps_rec, gps_data_t *gpsd_data)
--
-- DATE: 			November 2, 2019
--
-- REVISIONS: 		(Date and Description)
--
-- DESIGNER: 		Victor Phan/Jason Nguyen/Peter Xiong
--
-- PROGRAMMER: 		Victor Phan
--
-- NOTES:
-- This program is used to continuously read data from GPSD daemon and then send
-- data to output module to display if successfully get data from GPSD daemon, or
-- send error message to error checking module to report abnormal conditions,
-- such as the sensor returning errors or termination of the stream.
----------------------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <libgpsmm.h>
#include <string.h>

#include "gpsprint.hpp"
#include "gps-utils.hpp"

using namespace std;

/*-----------------------------------------------------------------------------------------------------------------
-- Function:	readGPSData
--
-- DATE:		November 1, 2019
--
-- REVISIONS:	
--
-- DESIGNER:	Victor Phan/Jason Nguyen/Peter Xiong
--
-- PROGRAMMER:	Victor Phan
--
-- INTERFACE:	void readGPSData(gpsmm *gps_rec, gps_data_t *gpsd_data)
-- 				gpsmm *gps_rec:	Handle of session socket to the GPSD daemon
--				gps_data_t *gpsd_data: Pointer to data in a gps_data_t structcture
--              bool* stop: pointer to a bool that stops the reading thread
--				
-- RETURNS:		None.
--
-- NOTES:
-- This function includes the main GPS loop to continuously read sensor
-- data from gpsd daemon, which is connected to satellites through GPS dongle.
-- When correct data is coming, they will be sent to another function in
-- display module to be printed out.
-------------------------------------------------------------------------------------------------------------------*/
void readGPSData(gpsmm *gps_rec, gps_data_t *gpsd_data, bool* stop) {
	while (!(*stop)) {
      if (!gps_rec->waiting(2000000)) {
		// Error checking
          errorReport("Timeout on waiting for data");
	  } else {
		  gpsd_data = new gps_data_t();
		  if ((gpsd_data = gps_rec->read()) == NULL) {
		      errorReport("GPSD read error.");
			exit(1);
		  } else {
			  printGPSData(gpsd_data);
		  }
      }
    }
}

