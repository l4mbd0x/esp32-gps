# esp32-gps
An ESP32 w/ GY-NEO6Mv2 gps sensor tester written in C/C++ 

# Info
This code works well on Funtoo Linux 1.4 and enables the reception of gps info.
Note: Beware that the gps sensor might take about 30s after correctly connected to get connected under optimal conditions, after that it will be able to connect to a gps in about 5s or so.
Note2: This code has been tested inside a house, while raining heavily outside and that made the initial connection take 1 min, working fine after that.

# Hardware required
- ESP32 board (currently configured for WROOM32) with at least 2 RX TX (aka control) pins.
- GY-NEO6Mv2 gps sensor

# Software required
- PlatformIO, all project dependencies are solved when the project is opened.

Suggestions are well appreciated



