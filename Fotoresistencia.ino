int ldr =A5;
int valor;
int led = 5;
int limite = 700;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(ldr,INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int valor = analogRead(ldr);
  Serial.println(valor);
  delay(100);

  if(valor <= limite){
    digitalWrite(led, LOW);
    delay(100);
  }
  else{
    digitalWrite(led, HIGH);
    delay(100);
    }

}
