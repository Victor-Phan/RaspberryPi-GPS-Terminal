/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: 	gpsprint.hpp - This is the header file of source file gpsprint.cpp.
--
-- PROGRAM: 		Location Finder
--
-- FUNCTIONS:		void printGPSData(gps_data_t *gpsd_data)
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
-- This program is used to handle all of the printing out of GPS report data.
----------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include <libgpsmm.h>

/*-----------------------------------------------------------------------------------------------------------------
-- Function:	printGPSData
--
-- DATE:		November 1, 2019
--
-- REVISIONS:	November 1, 2019
--
-- DESIGNER:	Victor Phan/Jason Nguyen/Peter Xiong
--
-- PROGRAMMER:	Victor Phan
--
-- INTERFACE:	void printGPSData(gps_data_t *gpsd_data)
--				gps_data_t *gpsd_data: Pointer to data in a gps_data_t structcture
--
-- RETURNS:		None.
--
-- NOTES:
-- This function is called from control module (gps-utilis.cpp) when there are valid
-- data available from GPSD daemon and need to be printed out. The minimum list of report
-- data parameters include:
--		Time stamp (UTC)
--		Latitude/Longitude
--		PRN
--		Elevation
--		Azimuth
--		SNR
--		Used flag (Y or N)
-------------------------------------------------------------------------------------------------------------------*/
void printGPSData(gps_data_t *gpsdata);
