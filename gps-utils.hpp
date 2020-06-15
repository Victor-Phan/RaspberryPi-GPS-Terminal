#pragma once
#include <iostream>
using namespace std;
/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: 	gps-utilis.hpp - This is the header file of source file gps-utilis.cpp.
--
-- PROGRAM: 		Location Finder
--
-- FUNCTIONS:		void readGPSData(gpsmm *gps_rec, gps_data_t *gpsd_data)
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
-- This program is used to continuously read data from GPSD daemon and then send
-- data to output module to display if successfully get data from GPSD daemon, or
-- send error message to error checking module to report abnormal conditions,
-- such as the sensor returning errors or termination of the stream.
----------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------------
-- Function:	readGPSData
--
-- DATE:		November 1, 2019
--
-- REVISIONS:	(Date and Description)
--
-- DESIGNER:	Victor Phan/Jason Nguyen/Peter Xiong
--
-- PROGRAMMER:	Victor Phan
--
-- INTERFACE:	void readGPSData(gpsmm *gps_rec, gps_data_t *gpsd_data)
-- 				gpsmm *gps_rec:	Handle of session socket to the GPSD daemon
--				gps_data_t *gpsd_data: Pointer to data in a gps_data_t structcture
--
-- RETURNS:		None.
--
-- NOTES:
-- This function includes the main GPS loop to continuously read sensor
-- data from gpsd daemon, which is connected to satellites through GPS dongle.
-- When correct data is coming, they will be sent to another function in
-- display module to be printed out.
-------------------------------------------------------------------------------------------------------------------*/
void readGPSData(gpsmm *gps_rec, gps_data_t *gpsd_data, bool* stop);

/*-----------------------------------------------------------------------------------------------------------------
-- Function:	errorReport
--
-- DATE:		November 2, 2019
--
-- REVISIONS:	
--
-- DESIGNER:	Victor Phan/Jason Nguyen/Peter Xiong
--
-- PROGRAMMER:	Peter Xiong
--
-- INTERFACE:	void errorReport(string errorMsg)
-- 				string errorMsg: error message need to be outputted
--
-- RETURNS:		None.
--
-- NOTES:
-- This function is called to report error message when abnormal conditions
-- such as the sensor returning errors or termination of the stream.
-------------------------------------------------------------------------------------------------------------------*/
void errorReport(string errorMsg);
