#include <SimpleDHT.h>
#include <LiquidCrystal.h>

int pinDHT11 = 53;
SimpleDHT11 dht11(pinDHT11);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
static bool module = true;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
static String incoming = "Connecting...";

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  attachInterrupt(digitalPinToInterrupt(22), switch_module, RISING);
  //waiting for a communication link to establish with the NodeMCU
  while(!Serial){
    Serial.println("Serial...");
  }
}

void loop() {
 lcd.setCursor(0, 0);
 double temp = analogRead(A0);
 //reading analog temp from the sensor
 temp = (temp/1024.0)*5000;
 temp = (temp/10) - 17;  
 delay(1000);
  //displays indoor data 
  if (module == true) {
    lcd.clear();
    lcd.print("Indoor Module: ");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print(" *C");
  }
  //displays outdoor data
  if (module == false) {
    if(Serial.available()){
      incoming = Serial.readString();
    }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Outdoor Data");
    lcd.setCursor(0, 1);
    lcd.print(incoming);
  }

}
//switch module with button press
void switch_module() {
  Serial.print("button pressed");
  module = !module;
}
