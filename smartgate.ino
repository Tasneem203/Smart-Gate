int ldr = 6;
int flag = 5;
int btn = 2;
int x = 0 , guests = 0, i = 0;
int sensorread = 0;
int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;
int buzzer = 7;

void setup()
{
  pinMode(ldr, OUTPUT);            // led room
  pinMode(flag, OUTPUT);          // led laser
  pinMode(buzzer, OUTPUT);       //buzzer variable
  pinMode(btn, INPUT) ;         //button variabe
  pinMode(A0, INPUT);          //LDR sensor
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(btn);
  if (buttonState != lastButtonState){
    if (buttonState == HIGH){
      buttonPushCounter++;
    }
    delay(50);
  }

  lastButtonState = buttonState;
  if (buttonPushCounter % 2 != 0){
    digitalWrite(ldr, LOW);
    digitalWrite(flag, HIGH);
    sensorread = analogRead(A0);
    sensorread = map(sensorread, 0, 1023, 0, 100);
    if (sensorread >= 7) {
      digitalWrite(flag, LOW);
      x = 1;
      guests ++;
      Serial.print("Num of Guests = ");
      Serial.print(guests);
      Serial.println();
      delay(1000);
    }
    if (x == 1) {
      digitalWrite(ldr, HIGH);
    }
  }
  else if (buttonPushCounter % 2 == 0){
    i = 0;
    guests = 0;
    x = 0;
    digitalWrite(flag, LOW);
    digitalWrite(ldr, LOW);
  }
  if (guests == 0) {
    digitalWrite(buzzer, LOW);
  }
  else if (guests == 5) {
    digitalWrite(buzzer, HIGH);
  }
}
