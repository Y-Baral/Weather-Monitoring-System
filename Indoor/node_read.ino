#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <SoftwareSerial.h>

//wifi login credentials
String name = "Node_Wifi";
String pass = "**********";
int statusCode = 0;
WiFiClient  client;

//thingspeak channel number
unsigned long channel_num = 1348678;  
//thinspeak read api key 
const char * api_read = "************"; 
const int feild1 = 1;
const int feild2 = 2;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  
  //station
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop()
{
    //tries to connect to wifi every 5 seconds
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(name, pass);
      delay(5000);
    }

    Serial.println("Connected to ");
    Serial.println(name);
    delay(1000);
  



  long temperature = ThingSpeak.readLongField(channel_num, feild1, api_read);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {

    Serial.print("Temperature : ");
    Serial.print(temperature);
    Serial.println(" *C");
  }
  else
  {
    Serial.println("Unable to read temperature...");

  }
  delay(100);


  long humidity = ThingSpeak.readLongField(channel_num, feild2, api_read);
  statusCode = ThingSpeak.getLastReadStatus();
  //http 200 OK
  if (statusCode == 200)
  {
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println("%   ");
  }
  else
  {
    Serial.println("Unable to read humidity...");
  }
  delay(3000);
  
  
  //sends the data to the arduino after receiving it
  sendArduino(temperature, humidity);
}

//serial communication between NodeMCU and the Arduino
void sendArduino(long temperature, long humidity) {
  String str = String("T:") + String(temperature) + String(" *C | H:") + String(humidity) + String("% ");
  Serial1.println(str);
  Serial.println(str);
}
