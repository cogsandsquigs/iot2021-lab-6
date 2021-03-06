/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/ianp/Documents/iot2021/labs/lab-6/src/lab-6.ino"

#include "oled-wing-adafruit.h"

void setup();
void loop();
#line 4 "/home/ianp/Documents/iot2021/labs/lab-6/src/lab-6.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

const uint16_t temp = A4;

void setup()
{
  pinMode(temp, INPUT);
  display.setup();

  display.clearDisplay();
  display.display(); // cause the display to be updated
}

void loop()
{
  // this chunk inits display for this loop
  display.loop();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  uint64_t reading = analogRead(temp);       // this whole chunk gets temp from sensor
  double voltage = (reading * 3.3) / 4095.0; // gets sensor voltage
  double tempC = (voltage - 0.5) * 100;      // gets celcius temp from voltage
  double tempF = (tempC * 9.0 / 5.0) + 32.0; // gets fahrenheit temp from celcius

  // this chunk prints the temperature out in a ✨pretty✨ format
  display.println("TEMPERATURE");
  display.setCursor(0, 8);
  display.println("Celsius: " + String(tempC));
  display.setCursor(0, 16);
  display.println("Fahrenheit: " + String(tempF));

  display.display();
}