const uint8_t motorPin = 11;

int power = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (power <= 255) {
    Serial.println(power);
    analogWrite(motorPin, power);
    power += 2;
    delay(500);
  }
  power = 0;

  //delay (100000);
}
