// Incluimos la librería LiquidCrystal
#include <LiquidCrystal.h>

// Definimos los pines del sensor de ultrasonido
const int trigPin = 2;
const int echoPin = 3;

// Definimos los pines del LCD
const int rs = 4, en = 6, d4 = 7, d5 = 8, d6 = 9, d7 = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Inicializamos el LCD con sus dimensiones
  lcd.begin(16, 2);
 
  // Inicializamos el sensor de ultrasonido
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  // Mostramos el mensaje de bienvenida en el LCD
  lcd.setCursor(0,0);
  lcd.print("Medidor de distancia");
  lcd.setCursor(0,1);
  lcd.print("con Ultrasonido");
  delay(2000);
}

void loop() {
  // Declaramos las variables necesarias
  long duration, distance;
 
  // Generamos un pulso en el pin de trigger del sensor de ultrasonido
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Medimos la duración del eco del sensor de ultrasonido
  duration = pulseIn(echoPin, HIGH);
 
  // Calculamos la distancia en centímetros
  distance = duration * 0.034 / 2;
 
  // Mostramos la distancia en el LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distancia:");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print(" cm");
 
  // Esperamos 500 ms antes de medir la distancia de nuevo
  delay(500);
}
  
