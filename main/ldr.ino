boolean meetLicht() {
  int ldrStatus = analogRead(ldrPin);

  if (ldrStatus <= 250) {
    Serial.print("het is donker, de deur is dicht");
    Serial.println(ldrStatus);
    return true;
  }
  else {
    Serial.print("het is licht, de deur staat open");
    Serial.println(ldrStatus);
    return false;
  }
}
