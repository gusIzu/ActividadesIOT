
int trig = 10;
int eco =9;
int led = 3;
int duracion;
int distancia;

void setup (){
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}
void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);

  //convertir
  duracion = pulseIn(eco, HIGH);
  distancia = duracion / 58.2;//por defecto que usa el ultrasonico
  Serial.print(distancia);
  Serial.print("Centimetros");
  Serial.println();

  delay(200);

  if(distancia <=20){
    digitalWrite(led,HIGH);
    delay(100);
  } else{
    digitalWrite(led, LOW);
    delay(100);
  }


}
