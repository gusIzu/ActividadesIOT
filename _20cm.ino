#include <Wire.h>

#include <LiquidCrystal_I2C.h>

int trig = 10;
int eco = 9;
int led = 3;
int duracion;
int distancia;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
pinMode(trig, OUTPUT);
pinMode(eco, INPUT);
pinMode(led, OUTPUT);
Serial.begin(9600);
lcd.init();
lcd.clear();
//lcd.backlight();

//lcd.print("el objeto esta");



};

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig, HIGH);
delay(1);
digitalWrite(trig, LOW);
duracion = pulseIn(eco, HIGH);
distancia = duracion / 58.2;

//Serial.print("El obj. está a: ");
//Serial.print(distancia);
//Serial.println(" cm");
//delay(1000);

//lcd.scrollDisplayLeft();
lcd.clear();
lcd.print("Distancia");
lcd.setCursor(0, 1);
lcd.print(String(distancia)+ "cm");
delay(100);




if(distancia <= 20){
  digitalWrite(led, HIGH);
  delay(1000);
  
}else{
  digitalWrite(led, LOW);
  delay(100);
}

//valor = analogRead(eco);

}
