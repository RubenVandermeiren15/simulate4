#include <ezButton.h>
#include <Servo.h>

const int ldrPin = A0;
float gewicht;
boolean potWasOpen = false;
boolean donker;
boolean wasDonker;
boolean deurIsDicht;
ezButton knop(8);
Servo myservo;

int pos = 0;


void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  knop.setDebounceTime(50);
  setupLoadcell();
  setupMotor();
  myservo.attach(2);
  donker = meetLicht();
  wasDonker = donker;
  potDicht();
}

void loop() {

  gewicht = weegKip();

  if (gewicht > 1 && !potWasOpen) {
    potOpen();
    potWasOpen = true;
  } else if (gewicht < 1 && potWasOpen)
  {
    potDicht();
    potWasOpen = false;
  }
  donker = meetLicht();
  if (donker && !wasDonker && !deurIsDicht) {
    deurDicht();
    deurIsDicht = true;
  }
  if (!donker && wasDonker && deurIsDicht) {
    deurOpen();
    deurIsDicht = false;
  }
  wasDonker = meetLicht();
  knop.loop();
  if (knop.isReleased() == 1) {
    Serial.println("knop");
    if (deurIsDicht) {
      deurOpen();
      deurIsDicht = false;
    } else if (!deurIsDicht) {
      deurDicht();
      deurIsDicht = true;
    }
  }
  delay(200);
}
