int LEDt = 7;   
int LEDh= 8; 
int BUZZER_PIN1 = 6;
int BUZZER_PIN2 = 5;
int TMP = A0;  
int hum=A5; 
float temperatura = 0; // Variable para almacenar la temperatura
float humedad=0; // Variable para almacenar la humedad
int umbralCaliente = 30; // Umbral de temperatura para encender el LED 
int umbralHum = 15;  // Umbral de humedad para encender el LED 

void setup() {
  pinMode(LEDt, OUTPUT); // Configuramos el pin del LED de temperatura como salida
  Serial.begin(9600);  // Iniciamos la comunicación serial para depuración
  pinMode(LEDh, OUTPUT); // Configuramos el pin del LED de humedad como salida
  Serial.begin(9600);  // Iniciamos la comunicación serial para depuración
  pinMode(BUZZER_PIN1, OUTPUT); // Configuramos el pin del BUZZZER de temperatura como salida
  Serial.begin(9600); 
  pinMode(BUZZER_PIN2, OUTPUT); // Configuramos el pin del BUZZZER de humedad como salida
  Serial.begin(9600);
}



void loop() {
  temperatura = obtenerTemperatura(); // Leer la temperatura

  // Mostrar la temperatura en el monitor serie
  Serial.print("Temperatura: ");
  Serial.print(temperatura); //FUNCION OBTENERTEMPERATURA
  Serial.println(" °C");

  // Verificar si la temperatura supera el umbral para encender el LED
  if (temperatura > umbralCaliente) {
    digitalWrite(LEDt, HIGH); 
    Serial.println("¡Caliente!");
      tone(BUZZER_PIN1, 1000);  //Se puede modificar la frecuencia del buzzer
    delay(2000);  
    noTone(BUZZER_PIN1); 
  } else {
    digitalWrite(LEDt, LOW); 
  }

  delay(1000); // Esperar un segundo entre lecturas
  
   humedad = obtenerHumedad(); // Leer la humedad

  // Mostrar la humedad en el monitor serie
  Serial.print("Humedad: ");
  Serial.print(humedad); //FUNCION OBTENERHUMEDAD
  Serial.println(" g/m¨3");

  // Verificar si la temperatura supera el umbral para encender el LED
  if (humedad > umbralHum) {
    digitalWrite(LEDh, HIGH); // Encender el LED
    Serial.println("¡Muy Humedo!");
    tone(BUZZER_PIN2, 4000);  
    delay(2000);  
    noTone(BUZZER_PIN2);   
  } else {
    digitalWrite(LEDh, LOW); 
  }
  
}

float obtenerTemperatura() {
  int lectura = analogRead(TMP); // Lectura del valor analógico del sensor
  // Convertir la lectura en grados Celsius (ajusta según tus conexiones)
  float voltaje = (lectura / 1023.0) * 5.0; // (lectura / 1023.0) normaliza la lectura al rango de 0 a 1 y luego multiplica por el voltaje de referencia
  temperatura = (voltaje - 0.5) * 100.0;

  //toma el voltaje medido por el sensor, corrige , y  escala el resultado para obtener una estimación de la temperatura en grados Celsius.
 
  
  return temperatura;
 
}

float obtenerHumedad(){
   int lectura=analogRead(hum);
   float voltaje = (lectura / 1023.0) * 5.0;
  humedad = (voltaje - 0.5) * 100.0;
  return humedad;
}