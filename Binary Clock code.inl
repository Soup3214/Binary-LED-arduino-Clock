#include <Wire.h>
#include "RTClib.h"
RTC_DS3231 rtc;
 //arduino pins
int oneTenHours = 13; //this is the tens integer for Hours first bit
int twoTenHours = 12;
int oneOneHours = 11; //this is the ones integer for Hours first bit
int twoOneHours = 10;
int fourOneHours = 9;
int eightOneHours = 8;
int oneTenMinutes = 7; //this is the tens integer for minutes first bit
int twoTenMinutes = 6;
int fourTenMinutes = 5;
int oneOneMinutes = 4; //this is the ones integer for minutes first bit
int twoOneMinutes = 3;
int fourOneMinutes = 2;
int eightOneMinutes = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(oneTenMinutes, OUTPUT);
  pinMode(twoTenMinutes, OUTPUT);
  pinMode(fourTenMinutes, OUTPUT);
  pinMode(oneOneMinutes, OUTPUT);
  pinMode(twoOneMinutes, OUTPUT);
  pinMode(fourOneMinutes, OUTPUT);
  pinMode(eightOneMinutes, OUTPUT);
  pinMode(oneTenHours, OUTPUT);
  pinMode(twoTenHours, OUTPUT);
  pinMode(oneOneHours, OUTPUT);
  pinMode(twoOneHours, OUTPUT);
  pinMode(fourOneHours, OUTPUT);
  pinMode(eightOneHours, OUTPUT);
  
  Serial.begin(9600);
  delay(3000);

  if(! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();
  //seperates into four digits
  int hr = now.hour();
  int mn = now.minute();
  int oneHours = (hr%10);
  int tenHours = ((hr/10)%10);
  int oneMinutes = (mn%10);
  int tenMinutes = ((mn/10)%10);

  setMinutesOnes(oneMinutes);
  setMinutesTens(tenMinutes);
  setHoursOnes(oneHours);
  setHoursTens(tenHours);
  Serial.println(oneMinutes);
  delay(1000);
  Serial.println(tenMinutes);
  delay(1000);
  Serial.println(oneHours);
  delay(1000);
  Serial.println(tenHours);
  delay(1000);  
}
//LED time keeping
void setMinutesTens(int myMinutes){ //minutes is an integer between 0-5, represented by 3 LEDs (1,2,4)
  if(myMinutes == 0){
    digitalWrite(oneTenMinutes, LOW);
    digitalWrite(twoTenMinutes, LOW);
    digitalWrite(fourTenMinutes, LOW);
  }
  else if(myMinutes == 1){
    digitalWrite(oneTenMinutes, HIGH);
    digitalWrite(twoTenMinutes, LOW);
    digitalWrite(fourTenMinutes, LOW);
  }
  else if(myMinutes == 2){
    digitalWrite(oneTenMinutes, LOW);
    digitalWrite(twoTenMinutes, HIGH);
    digitalWrite(fourTenMinutes, LOW);
  }
  else if(myMinutes == 3){
    digitalWrite(oneTenMinutes, HIGH);
    digitalWrite(twoTenMinutes, HIGH);
    digitalWrite(fourTenMinutes, LOW);
  }
  else if(myMinutes == 4){
    digitalWrite(oneTenMinutes, LOW);
    digitalWrite(twoTenMinutes, LOW);
    digitalWrite(fourTenMinutes, HIGH);
  }
  else if(myMinutes == 5){
    digitalWrite(oneTenMinutes, HIGH);
    digitalWrite(twoTenMinutes, LOW);
    digitalWrite(fourTenMinutes, HIGH);
  }
}

void setMinutesOnes(int mineMinutes){ //minutes is an integer between 0-5, represented by 3 LEDs (1,2,4)
  if(mineMinutes == 0){
    digitalWrite(oneOneMinutes, LOW);
    digitalWrite(twoOneMinutes, LOW);
    digitalWrite(fourOneMinutes, LOW);
    digitalWrite(eightOneMinutes, LOW);
  }
  else if(mineMinutes == 1){
    digitalWrite(oneOneMinutes, HIGH);
    digitalWrite(twoOneMinutes, LOW);
    digitalWrite(fourOneMinutes, LOW);
    digitalWrite(eightOneMinutes, LOW);
  }
  else if(mineMinutes == 2){
    digitalWrite(oneOneMinutes, LOW);
    digitalWrite(twoOneMinutes, HIGH);
    digitalWrite(fourOneMinutes, LOW);
    digitalWrite(eightOneMinutes, LOW);
  }
  else if(mineMinutes == 3){
    digitalWrite(oneOneMinutes, HIGH);
    digitalWrite(twoOneMinutes, HIGH);
    digitalWrite(fourOneMinutes, LOW);
    digitalWrite(eightOneMinutes, LOW);
  }
  else if(mineMinutes == 4){
    digitalWrite(oneOneMinutes, LOW);
    digitalWrite(twoOneMinutes, LOW);
    digitalWrite(fourOneMinutes, HIGH);
    digitalWrite(eightOneMinutes, LOW);
  }
  else if(mineMinutes == 5){
    digitalWrite(oneOneMinutes, HIGH);
    digitalWrite(twoOneMinutes, LOW);
    digitalWrite(fourOneMinutes, HIGH);
    digitalWrite(eightOneMinutes, LOW);
  }
  else if(mineMinutes == 6){
    digitalWrite(oneOneMinutes, LOW);
    digitalWrite(twoOneMinutes, HIGH);
    digitalWrite(fourOneMinutes, HIGH);
    digitalWrite(eightOneMinutes, LOW);
  }
  else if(mineMinutes == 7){
    digitalWrite(oneOneMinutes, HIGH);
    digitalWrite(twoOneMinutes, HIGH);
    digitalWrite(fourOneMinutes, HIGH);
    digitalWrite(eightOneMinutes, LOW);
  }
  else if(mineMinutes == 8){
    digitalWrite(oneOneMinutes, LOW);
    digitalWrite(twoOneMinutes, LOW);
    digitalWrite(fourOneMinutes, LOW);
    digitalWrite(eightOneMinutes, HIGH);
  }
  else if(mineMinutes == 9){
    digitalWrite(oneOneMinutes, HIGH);
    digitalWrite(twoOneMinutes, LOW);
    digitalWrite(fourOneMinutes, LOW);
    digitalWrite(eightOneMinutes, HIGH);
  }
}

void setHoursTens(int Hours){ //Hours is an integer between 0-5, represented by 3 LEDs (1,2,4)
  if(Hours == 0){
    digitalWrite(oneTenHours, LOW);
    digitalWrite(twoTenHours, LOW);
  }
  else if(Hours == 1){
    digitalWrite(oneTenHours, HIGH);
    digitalWrite(twoTenHours, LOW);
  }
  else if(Hours == 2){
    digitalWrite(oneTenHours, LOW);
    digitalWrite(twoTenHours, HIGH);
  }
}

void setHoursOnes(int myHours){ //Hours is an integer between 0-5, represented by 3 LEDs (1,2,4)
  if(myHours == 0){
    digitalWrite(oneOneHours, LOW);
    digitalWrite(twoOneHours, LOW);
    digitalWrite(fourOneHours, LOW);
    digitalWrite(eightOneHours, LOW);
  }
  else if(myHours == 1){
    digitalWrite(oneOneHours, HIGH);
    digitalWrite(twoOneHours, LOW);
    digitalWrite(fourOneHours, LOW);
    digitalWrite(eightOneHours, LOW);
  }
  else if(myHours == 2){
    digitalWrite(oneOneHours, LOW);
    digitalWrite(twoOneHours, HIGH);
    digitalWrite(fourOneHours, LOW);
    digitalWrite(eightOneHours, LOW);
  }
  else if(myHours == 3){
    digitalWrite(oneOneHours, HIGH);
    digitalWrite(twoOneHours, HIGH);
    digitalWrite(fourOneHours, LOW);
    digitalWrite(eightOneHours, LOW);
  }
  else if(myHours == 4){
    digitalWrite(oneOneHours, LOW);
    digitalWrite(twoOneHours, LOW);
    digitalWrite(fourOneHours, HIGH);
    digitalWrite(eightOneHours, LOW);
  }
  else if(myHours == 5){
    digitalWrite(oneOneHours, HIGH);
    digitalWrite(twoOneHours, LOW);
    digitalWrite(fourOneHours, HIGH);
    digitalWrite(eightOneHours, LOW);
  }
  else if(myHours == 6){
    digitalWrite(oneOneHours, LOW);
    digitalWrite(twoOneHours, HIGH);
    digitalWrite(fourOneHours, HIGH);
    digitalWrite(eightOneHours, LOW);
  }
  else if(myHours == 7){
    digitalWrite(oneOneHours, HIGH);
    digitalWrite(twoOneHours, HIGH);
    digitalWrite(fourOneHours, HIGH);
    digitalWrite(eightOneHours, LOW);
  }
  else if(myHours == 8){
    digitalWrite(oneOneHours, LOW);
    digitalWrite(twoOneHours, LOW);
    digitalWrite(fourOneHours, LOW);
    digitalWrite(eightOneHours, HIGH);
  }
  else if(myHours == 9){
    digitalWrite(oneOneHours, HIGH);
    digitalWrite(twoOneHours, LOW);
    digitalWrite(fourOneHours, LOW);
    digitalWrite(eightOneHours, HIGH);
  }
}
