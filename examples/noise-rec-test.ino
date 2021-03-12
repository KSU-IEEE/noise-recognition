#include <noise-recognition.h>

noise_recognition::noiseRecognition nr (A1, 20, 600);

void setup() {
  // put your setup code here, to run once:
  // led pin
  Serial.begin(115200);
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  bool found = nr.listenFor(600);
  Serial.println(found);
  digitalWrite(10, found ? HIGH : LOW);
}
