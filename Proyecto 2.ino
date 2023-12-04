int LEDt = 7;   // El LED está conectado al pin digital 7
int LEDh= 8;
int BUZZER_PIN1 = 6;
int BUZZER_PIN2 = 5;
int TMP = A0;  // El sensor está conectado al pin analógico A0
int hum=A5; //El sensor esta conectado al pin analógico A5
float temperatura = 0; // Variable para almacenar la temperatura
float humedad=0;
int umbralCaliente = 30; // Umbral de temperatura para encender el LED (ajusta según tus necesidades)
int umbralHum = 15; 

void setup() {
  pinMode(LEDt, OUTPUT); // Configuramos el pin del LED como salida
  Serial.begin(9600);  // Iniciamos la comunicación serial para depuración
  pinMode(LEDh, OUTPUT); // Configuramos el pin del LED como salida
  Serial.begin(9600);  // Iniciamos la comunicación serial para depuración
  pinMode(BUZZER_PIN1, OUTPUT); // Configuramos el pin del LED como salida
  Serial.begin(9600); 
  pinMode(BUZZER_PIN2, OUTPUT); // Configuramos el pin del LED como salida
  Serial.begin(9600);
}



void loop() {
  temperatura = obtenerTemperatura(); // Leer la temperatura

  // Mostrar la temperatura en el monitor serie
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  // Verificar si la temperatura supera el umbral para encender el LED
  if (temperatura > umbralCaliente) {
    digitalWrite(LEDt, HIGH); // Encender el LED
    Serial.println("¡Caliente!");
      tone(BUZZER_PIN1, 1000);  // Cambia la frecuencia del sonido según tus preferencias
    delay(2000);  // Mantén el sonido durante 2 segundos
    noTone(BUZZER_PIN1);  // Apaga el buzze  
  } else {
    digitalWrite(LEDt, LOW); // Apagar el LED
  }

  delay(1000); // Esperar un segundo entre lecturas
  
   humedad = obtenerHumedad(); // Leer la temperatura

  // Mostrar la humedad en el monitor serie
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println(" g/m¨3");

  // Verificar si la temperatura supera el umbral para encender el LED
  if (humedad > umbralHum) {
    digitalWrite(LEDh, HIGH); // Encender el LED
    Serial.println("¡Muy Humedo!");
    tone(BUZZER_PIN2, 4000);  // Cambia la frecuencia del sonido según tus preferencias
    delay(2000);  // Mantén el sonido durante 2 segundos
    noTone(BUZZER_PIN2);  // Apaga el buzze  
  } else {
    digitalWrite(LEDh, LOW); // Apagar el LED
  }
  
}

float obtenerTemperatura() {
  int lectura = analogRead(TMP); // Leer el valor analógico del sensor
  // Convertir la lectura en grados Celsius (ajusta según tus conexiones)
  float voltaje = (lectura / 1023.0) * 5.0;
  temperatura = (voltaje - 0.5) * 100.0;
 
  
  return temperatura;
 
}

float obtenerHumedad(){
   int lectura=analogRead(hum);
   float voltaje = (lectura / 1023.0) * 5.0;
  humedad = (voltaje - 0.5) * 100.0;
  return humedad;
}