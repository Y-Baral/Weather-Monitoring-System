# Weather-Monitoring-Station
The project consists of 2 parts or “hubs” that monitor the temperature and humidity both 
inside and outside the house and send signals via a Wi-Fi module to the main hub to be 
displayed. There is a button on the main hub that gives the user the ability to choose
between the two hubs. \n
The outdoor hub communicates the collected temperature and humidity data to the cloud 
every 10 seconds using the NodeMCU module. ThingSpeak is used to host this project, it allows for historical data 
charting, analysis and many more. The high-level communication diagram can be seen below.
![Cloud_Comms](https://user-images.githubusercontent.com/57636164/117584487-4bbdfa00-b0db-11eb-911a-855005e4bf87.png)

**Hardware I Used:**
1. Arduino UNO + DUE
2. NodeMCU (x2)
3. LCD
4. DHT11 Temperature & Humidity Sensor
5. Power Supply  

**Indoor Module Schematic:** 
![indoor](https://user-images.githubusercontent.com/57636164/117585968-6b592080-b0e3-11eb-8f09-fe9dcaf58ba0.PNG)

**Outdoor Module Schematic:**
![outdoor](https://user-images.githubusercontent.com/57636164/117585979-7449f200-b0e3-11eb-80d2-24d2c0e0b022.PNG)

**Final Results:**  
![thingspeak](https://user-images.githubusercontent.com/57636164/117587013-be35d680-b0e9-11eb-9d17-d35a6b43495c.PNG)

![result1](https://user-images.githubusercontent.com/57636164/117587007-b83ff580-b0e9-11eb-8fa0-bf15e8bd43e5.PNG)
