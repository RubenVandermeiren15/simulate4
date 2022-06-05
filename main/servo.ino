void potDicht() {
  for (pos = 0; pos <= 170; pos += 1) {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);
  }
}
void potOpen() {
  for (pos = 170; pos >= 0; pos -= 1) {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);
  }
}
