//pin setup for all the sensors
int const ultrasonic_echo = 5;
int const ultraSonic_trig = 6;
int const buzzer = 11;
void setup() {
  pinMode(ultraSonic_trig, OUTPUT); // pulse output
  pinMode(ultrasonic_echo, INPUT); // input to get pulse width
  pinMode(buzzer, OUTPUT); // output to control buzzering
  Serial.begin(9600);

}
//this module is only used for the alarm as the NodeMCU couldnt output 5V
void loop() {
  int duration, distance;
  digitalWrite(ultraSonic_trig, HIGH);
  delay(1);
  digitalWrite(ultraSonic_trig, LOW);
  duration = pulseIn(ultrasonic_echo, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance <= 5 && distance >= 0) {
    digitalWrite(buzzer, HIGH);
    delay (50);
    digitalWrite(buzzer, LOW);
    delay (200);

  }
  else {
    digitalWrite(buzzer, LOW);
  }
  
}
