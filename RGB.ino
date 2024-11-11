int rojo = 9;
int azul = 10;
int verde = 11;

void setup() {
  // put your setup code here, to run once:

  pinMode(rojo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(azul, 0);
  digitalWrite(verde, 255);
  digitalWrite(rojo, 0);
  delay(2000);

   digitalWrite(azul, 255);
  digitalWrite(verde, 255);
  digitalWrite(rojo, 255);
  delay(2000);

   digitalWrite(azul, 255);
  digitalWrite(verde, 255);
  digitalWrite(rojo, 255);
  delay(2000);

 







}
