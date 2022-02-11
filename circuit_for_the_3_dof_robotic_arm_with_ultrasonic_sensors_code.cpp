// C++ code
//
int switchLeft1 = 0;

int switchRight1 = 0;

int switchLeft2 = 0;

int switchRight2 = 0;

int switchLeft3 = 0;

int switchRight3 = 0;

int rigthSensor = 0;

int leftSensor = 0;

int topSensor = 0;

int unnamed = 0;

int i = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);

  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  topSensor = 0.01723 * readUltrasonicDistance(A2, A2);
  leftSensor = 0.01723 * readUltrasonicDistance(A0, A0);
  rigthSensor = 0.01723 * readUltrasonicDistance(A1, A1);
  Serial.println(topSensor);
  switchLeft1 = digitalRead(7);
  switchRight1 = digitalRead(6);
  switchLeft2 = digitalRead(5);
  switchRight2 = digitalRead(4);
  switchLeft3 = digitalRead(3);
  switchRight3 = digitalRead(2);

  if (switchLeft1 == HIGH || switchRight1 == HIGH) {
    if (leftSensor < 50 || rigthSensor < 50) {
      if (leftSensor < 50) {
        if (switchRight1 == HIGH && rigthSensor > 50) {
          digitalWrite(13, LOW);
          digitalWrite(12, HIGH);
        } else {
          digitalWrite(13, LOW);
          digitalWrite(12, LOW);
        }
      }
      if (rigthSensor < 50) {
        if (switchLeft1 == HIGH && leftSensor > 50) {
          digitalWrite(13, HIGH);
          digitalWrite(12, LOW);
        } else {
          digitalWrite(13, LOW);
          digitalWrite(12, LOW);
        }
      }
    } else {
      if (switchLeft1 == HIGH) {
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
      }
      if (switchRight1 == HIGH) {
        digitalWrite(13, LOW);
        digitalWrite(12, HIGH);
      }
    }
  } else {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }

  if (switchLeft2 == HIGH || switchRight2 == HIGH) {
    if (topSensor < 50) {
      if (switchRight2 == HIGH) {
        digitalWrite(11, LOW);
        digitalWrite(10, HIGH);
      } else {
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
      }
    } else {
      if (switchLeft2 == HIGH) {
        digitalWrite(11, HIGH);
        digitalWrite(10, LOW);
      }
      if (switchRight2 == HIGH) {
        digitalWrite(11, LOW);
        digitalWrite(10, HIGH);
      }
    }
  } else {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }

  if (switchLeft3 == HIGH || switchRight3 == HIGH) {
    if (switchLeft3 == HIGH) {
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
    }
    if (switchRight3 == HIGH) {
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
    }
  } else {
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
  }

  delay(10); // Delay a little bit to improve simulation performance
}