#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configurar la pantalla LCD con I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); // Asegúrate que la dirección I2C sea la correcta (0x27 es común)

// Pines del sensor ultrasónico
int trig = 10;
int eco = 9;
int led = 3;
int duracion;
int distancia;

void setup() {
  // Configuración del sensor ultrasónico y el LED
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

  // Inicializar la pantalla LCD
  lcd.init();                // Iniciar la pantalla LCD
  lcd.backlight();           // Encender la luz de fondo
  lcd.setCursor(0, 0);       // Posicionar el cursor al inicio
  lcd.print("Distancia:");   // Mensaje estático inicial
}

void loop() {
  // Enviar el pulso ultrasónico
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Leer el eco
  duracion = pulseIn(eco, HIGH);
  
  // Convertir el tiempo en distancia
  distancia = duracion / 58.2;  // Fórmula para convertir a centímetros
  Serial.print(distancia);
  Serial.println(" cm");

  // Mostrar la distancia en la pantalla LCD
  lcd.setCursor(0, 1);        // Posicionar el cursor en la segunda línea
  lcd.print(distancia);       // Mostrar la distancia
  lcd.print(" cm   ");        // Asegurarse de limpiar caracteres previos

  // Controlar el LED según la distancia
  if (distancia <= 20) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  delay(200);  // Esperar antes de la próxima lectura
}
