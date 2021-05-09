#include <DHT.h>  
#define DHTTYPE DHT11
#define DHTPIN 5
DHT dht(DHTPIN, DHTTYPE);
#include <ESP8266WiFi.h>

//wifi login credentials
String apiKey = "***********";
String name =  "Node_Wifi";
String pass =  "********";
String server = "api.thingspeak.com";

WiFiClient client;

void setup()
{

  Serial.begin(115200);
  delay(10);
  Serial.println("Connecting to ");
  Serial.println(name);
  dht.begin();
  WiFi.begin(name, pass);
    
  //tries to connect to wifi every 5 seconds
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(5000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop()
{
  //reading temperature data
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }


  //sending data to thingspeak
  if (client.connect(server, 80))
  {
    String string_write = apiKey;
    string_write += "&field1=";
    string_write += String(t);
    string_write += "&field2=";
    string_write += String(h);
    string_write += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(string_write.length());
    client.print("\n\n");
    client.print(string_write);

    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" degrees Celcius, Humidity: ");
    Serial.print(h);
    Serial.println("%. Send to Thingspeak.");
  }
  client.stop();
  Serial.println("Waiting...");
  delay(10000);

}
