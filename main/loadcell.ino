#include "HX711.h"

#define calibration_factor 490000
#define LOADCELL_DOUT_PIN  4
#define LOADCELL_SCK_PIN  3

HX711 scale;

void setupLoadcell() {

  Serial.println("HX711 scale demo");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor);
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0

  Serial.println("Readings:");
}

float weegKip() {
  float gewicht = scale.get_units();
  Serial.print("Reading: ");
  Serial.print(gewicht, 1);
  Serial.print(" kg");
  Serial.println();
  return gewicht;
}
