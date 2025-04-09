#define trigPin 12
#define echoPin 13
int distance = 0;

#define in1 8  
#define in2 7  
#define in3 6  
#define in4 5  
#define ena 9  
#define enb 3  
int tocdo = 100;

#define cbt A0
#define cbg A1
#define cbp A2
int command = 0;
int a = 1;  
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(cbt, INPUT_PULLUP);
  pinMode(cbg, INPUT_PULLUP);
  pinMode(cbp, INPUT_PULLUP);

  analogWrite(ena, tocdo);
  analogWrite(enb, tocdo);
}

void loop() {
  if (a == 1) {
    DoLineDigital();
  } else {
    Remote();
  }

}
void Remote() {
  if (Serial.available() > 0) {
    command = (char)Serial.read();
    switch (command) {
      case 'F':
        Tien();
        break;
      case 'B':
        Lui();
        break;
      case 'L':
        Trai();
        break;
      case 'R':
        Phai();
        break;
      case 'S':
        Dung();
        break;

      default:;
    }
  }
}
void DoLineDigital() {
  if ((digitalRead(cbg) == 1) && (digitalRead(cbt) == 1) && (digitalRead(cbp) == 1)) {
    Dung();
    Serial.println("Dung");
  } else if ((digitalRead(cbg) == 1) && (digitalRead(cbt) == 1)) {
    Serial.println("Xoay Trai");
  } else if ((digitalRead(cbg) == 1) && (digitalRead(cbp) == 1)) {
    Serial.println("Xoay Phai");
  } else if (digitalRead(cbt) == 1) {
    Phai();
    Serial.println("Phai");
  } else if (digitalRead(cbp) == 1) {
    Trai();
    Serial.println("Trai");
  } else if (digitalRead(cbg) == 1) {
    Tien();
    Serial.println("Tien");
  }
}

void TranhVatCan() {
  KhoangCach();
  Serial.print(distance);
  Serial.println("cm");
  if (distance < 40) {
    Dung();
    Xoay();
    delay(1000);
  } else {
    Tien();
  }
}

void XoayTrai() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}
void XoayPhai() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void Tien() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}
void Lui() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void Trai() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}
void Phai() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}
void Dung() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}
void Xoay() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void KhoangCach() {
  int duration = 0;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
}