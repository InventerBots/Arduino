//  pins
const uint8_t ch2Pin   = 6;
const uint8_t dirPin   = 2;
const uint8_t motorPin = 4;

//  global
int pwm   = 1500; // initalise to neutral
int motor = 0;    // motor is off
boolean dir   = 1;    // 0 = reverse, 1 = forward

void setup() {
  Serial.begin(115200);
  pinMode(ch2Pin,   INPUT);
  pinMode(dirPin,   OUTPUT);
  pinMode(motorPin, OUTPUT);

  // attach an interrupt to ch2Pin
  attachInterrupt(digitalPinToInterrupt(ch2Pin), readChannal, FALLING);
}

void loop() {
  //Serial.println((pwm-1500)/1.96078);

  if (pwm > 1550 || pwm < 1450) {
    motor = abs((pwm - 1500) / 2);
    if (pwm < 1500) {
      dir = 0;
    } else {
      dir = 1;
    }
    digitalWrite(dirPin, 0);
    analogWrite(motorPin, motor);
    
  } else {
    //analogWrite(motorPin, 0);
    motor = 0;
  }
  Serial.println(motor);
  delay(50);
}

void readChannal() {
  pwm = pulseIn(ch2Pin, HIGH);
}
