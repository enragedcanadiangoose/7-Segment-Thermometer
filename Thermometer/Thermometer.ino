#include "SevenSegment.cpp"
#include <OneWire.h>
#include <DallasTemperature.h>

long long time; //stores the previous millis value for refreshing the data
bool lastState; //used to store the previous state of A2 since there are no interrupts on analogue pins

SevenSegment display(2, 3, 4, 5, 6, 7, 8, 13, 9, 10, 11, 12); //initialize the display using the pins specified for each display segment

OneWire sensor1(A0); //instantiate the 2 onewire temperature sensors
OneWire sensor2(A1);

DallasTemperature indoor(&sensor1); //instantiate the DallasTemperature object used to get the temperature in degrees celcius from the probes
DallasTemperature outdoor(&sensor2);

void setup() {
  pinMode(A2, INPUT); //A2 is the switch between the two couples

  display.begin(); //initializes the display class
  indoor.begin();
  outdoor.begin();

  time = millis(); //sets the timer to be the current runtime
  lastState = digitalRead(A2); //sets the lastState to be the current state of A2, for detection of changes to A2

  if(digitalRead(A2)){ //if A2 is high gets the temperature of the indoor sensor
      indoor.requestTemperatures();
      display.setNumber(abs(indoor.getTempCByIndex(0)*100), (abs(indoor.getTempCByIndex(0)) >= 0)); //sets the display to the temperature of the indoor sensor
  }
  else{ //otherwise gets the temperature of the outdoor sensor
      outdoor.requestTemperatures();
      display.setNumber(abs(outdoor.getTempCByIndex(0)*100), (outdoor.getTempCByIndex(0) >= 0)); //sets the display to the outdoor temperature
  }
}

void loop() {
  if(digitalRead(A2) != lastState){ //if the A2 switch is switched
    time -= (30000); //subtracts 30000 from the time forcing the sensor to refresh
    lastState = digitalRead(A2); //sets the last state to be the current state
  }
  else if(time+30000<millis()){ //runs after 30s or if time is 30 000ms less than the millis() timer
    time = millis(); //sets the time to be the current timer
    if(digitalRead(A2)){ //if A2 is high gets the temperature of the indoor sensor
      indoor.requestTemperatures();
      display.setNumber(abs(indoor.getTempCByIndex(0)*100), (abs(indoor.getTempCByIndex(0)) >= 0));//sets the display to the temperature of the indoor sensor
    }
    else{//otherwise gets the temperature of the outdoor sensor
      outdoor.requestTemperatures();
      display.setNumber(abs(outdoor.getTempCByIndex(0)*100), (outdoor.getTempCByIndex(0) >= 0));//sets the display to the outdoor temperature
    }
  }
  display.drawDisplay(); //draws the 7 segment display
}