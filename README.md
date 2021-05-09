# Weather-Monitoring-Station
The project consists of 2 parts or “hubs” that monitor the temperature and humidity both 
inside and outside the house and send signals via a Wi-Fi module to the main hub to be 
displayed. There is a button on the main hub that gives the user the ability to choose
between the two hubs.
The outdoor hub communicates the collected temperature and humidity data to the cloud 
every 10 seconds using the NodeMCU module that is equipped with Wi-Fi communication 
protocols. ThingSpeak is used to host this project in the cloud, it allows for historical data 
charting and analysis and many more useful functions. The high-level communication 
diagram can be seen below
