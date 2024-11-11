int rojo = 2;
int amarillo = 3;
int verde = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(rojo, HIGH);
  delay(6000);
  digitalWrite(rojo,LOW);
  
 
  for (int i = 0; i < 3; i++){
  digitalWrite(amarillo, HIGH);
  delay(500);
  digitalWrite(amarillo, LOW);
 delay(500);
  }

  
  digitalWrite(verde, HIGH);
  delay(4000);
  digitalWrite(verde, LOW);
}
