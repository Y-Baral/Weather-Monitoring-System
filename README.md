# Weather-Monitoring-Station
The project consists of 2 parts or “hubs” that monitor the temperature and humidity both 
inside and outside the house and send signals via a Wi-Fi module to the main hub to be 
displayed. There is a button on the main hub that gives the user the ability to choose
between the two hubs. \
The outdoor hub communicates the collected temperature and humidity data to the cloud 
every 10 seconds using the NodeMCU module. ThingSpeak is used to host this project, it allows for historical data 
charting, analysis and many more. The high-level communication diagram can be seen below.
![Cloud_Comms](Assets/cloud_comms.png)

**Hardware I Used:**
1. Arduino UNO + DUE
2. NodeMCU (x2)
3. LCD
4. DHT11 Temperature & Humidity Sensor
5. Power Supply  

**Indoor Module Schematic:** 
![indoor](Assets/indoor_module_schematic.png)

**Outdoor Module Schematic:**
![outdoor](Assets/outdoor_module_schematic.png)

**Final Results:**  
![thingspeak](Assets/results_thingspeak.png)

![result1](Assets/results_outdoor.png)

![results2](Assets/results_indoor.jpg)
