# RaspberryPi-GPS-Terminal

# Setup 
gpsd must be installed on your Raspberry Pi before running this program. 
Please visit the link below to install. 
https://gpsd.gitlab.io/gpsd/installation.html 
Here is a brief overview of how to install gpsd. 
1. Check which port is used, in my case it is ttyUSB0: (Use command ls /dev to list and 
check it) 
2. sudo apt-get install gpsd gpsd-clients python-gps 
3. sudo systemctl stop gpsd.socket 
4. sudo systemctl disable gpsd.socket 
5. vi /lib/systemd/system/gpsd.socket 
change 127.0.0.1 to 0.0.0.0 
6. sudo killall gpsd 
gpsd: no process found 
7. sudo gpsd /dev/ttyUSB0 -F /var/run/gpsd.socket 

# Build and Run
1. make clean
2. make
3. ./dcgps
