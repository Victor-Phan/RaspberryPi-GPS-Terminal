/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: 	gpsprint.cpp - This is output module of the application. It
--								   will print out GPS report data.
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

#include <iostream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include "gpsprint.hpp"

using namespace std;

/*-----------------------------------------------------------------------------------------------------------------
-- Function:	printGPSData
--
-- DATE:		November 1, 2019
--
-- REVISIONS:	November 1, 2019
--
-- DESIGNER:	Victor Phan/Jason Nguyen/Peter Xiong
--
-- PROGRAMMER:	Victor Phan, Jason Nguyen
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
void printGPSData(gps_data_t *gpsd_data) {
      system("clear");
      cout << "Type 'q' and enter to quit." << endl;
      if (gpsd_data->satellites_visible > 0) {
		for (int i = 0; i < gpsd_data->satellites_visible; i++) {
			cout << left << setw(9) << "PRN: " << gpsd_data->skyview[i].PRN << "\t";
			cout << "Elevation: " << gpsd_data->skyview[i].elevation << "\t";
			cout << "Azimuth: " << gpsd_data->skyview[i].azimuth << "\t";
			cout << fixed << setprecision(0) << "SNR: " << gpsd_data->skyview[i].ss << "\t";
			cout << "Used: " << (gpsd_data->skyview[i].used ? "Y" : "N") << endl;
		}
		cout << endl;
	  }
      
	  if (gpsd_data->fix.mode >= MODE_2D) {
		  timestamp_t ts { gpsd_data->fix.time };
		  auto latitude  { gpsd_data->fix.latitude };
		  auto longitude { gpsd_data->fix.longitude };
		  auto altitude { gpsd_data->fix.altitude };
	  	  // convert GPSD's timestamp_t into time_t
		  time_t seconds { (time_t)ts };
		  auto tm = *std::localtime(&seconds);
		  ostringstream oss;
		  oss << std::put_time(&tm, "%d-%m-%Y %H:%M:%S");
		  auto time_str { oss.str() };

		  // set decimal precision
		  cout.precision(6);
		  cout.setf(ios::fixed, ios::floatfield);
		  cout << (gpsd_data->fix.mode == 2 ? "2D Fix, " : "3D Fix, ");
		  cout << time_str << ", ";
		  cout << "Latitude: " << abs(latitude) << (latitude > 0 ? " N, " : " S, ");
		  cout << "Longitude: " << abs(longitude) << (longitude > 0 ? " E, " : " W, ");
		  cout << "Altitude: " << (gpsd_data->fix.mode == 3 ? to_string(altitude) : "N/A") << endl;
	  }else {
		  cout << (gpsd_data->fix.mode == 0 ? "Not Seen." : "No Fix.") << endl;
	  }
}

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
-- 				string errorMsg: error message needed to be outputted
--
-- RETURNS:		None.
--
-- NOTES:
-- This function is called to report error messages when abnormal conditions
-- such as the sensor returning errors or termination of the stream.
-------------------------------------------------------------------------------------------------------------------*/
void errorReport(string errorMsg) {
    cerr << errorMsg << endl;
}
