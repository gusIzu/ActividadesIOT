#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int trig = 10;
int eco = 9;
int duracion;
int distancia;

// Pines para los LEDs
int ledPins[] = {3, 4, 5, 6, 7};

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() { 
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight();

  // Configurar cada LED como salida
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);  // Asegurar que estén apagados al inicio
  }
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);  // Cambiado a microsegundos para mayor precisión
  digitalWrite(trig, LOW);

  duracion = pulseIn(eco, HIGH);
  distancia = duracion / 58.2;

  Serial.print(distancia);
  Serial.println(" cm");

  lcd.clear();
  lcd.print("Distancia");
  lcd.setCursor(0, 1);
  lcd.print(String(distancia) + "cm");
  delay(100);

  // Encender LEDs según la distancia
  if (distancia <= 5) {
    encenderLEDs(6);  // Encender los 6 LEDs
  } else if (distancia <= 10) {
    encenderLEDs(5);
  } else if (distancia <= 15) {
    encenderLEDs(4);
  } else if (distancia <= 20) {
    encenderLEDs(3);
  } else if (distancia <= 25) {
    encenderLEDs(2);
  } else if (distancia <= 30) {
    encenderLEDs(1);
  } else {
    encenderLEDs(0);  // Apagar todos los LEDs si está fuera del rango
  }
}

// Función para encender una cantidad de LEDs
void encenderLEDs(int cantidad) {
  for (int i = 0; i < 6; i++) {
    if (i < cantidad) {
      digitalWrite(ledPins[i], HIGH);  // Encender LED
    } else {
      digitalWrite(ledPins[i], LOW);   // Apagar LED
    }
  }
}
