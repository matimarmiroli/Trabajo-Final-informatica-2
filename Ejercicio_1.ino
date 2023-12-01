

int i = 2;
int brillo = 0; 
int PULSADOR1 = A0;
int PULSADOR2 = A1;
int PULSADOR3 = A2;
int LED1 = 8;
int LED2 = 9;
int estado;


void setup() 
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(PULSADOR1, INPUT);
  pinMode(PULSADOR2, INPUT);
  pinMode(PULSADOR3, INPUT);
  Serial.begin(9600);
  estado = LED1;
}



void loop() {


  if (analogRead(PULSADOR3) == LOW) 
  {
    if (estado == LED1) 
    {
      estado = LED2;
      i = 2;
      delay(100);
    } 
    else 
    {
      estado = LED1; // Alternar entre LED1 y LED2
      i = 2;
      delay(100);
    }
  }

  if (analogRead(PULSADOR1) == LOW) 
  {
    i = 1;
    brillo = 0; 
    delay(100);
  }

  if (analogRead(PULSADOR2) == LOW) {
    i = 0;
    brillo = 255;
    delay(100);
  }

  if (i == 0 || i == 1) 
  {
    brillo = constrain(brillo, 0, 255); // el brillo esté en el rango válido

    analogWrite(estado,brillo);

    if (i == 0) 
    {
      brillo -= 10; // Decrementa el brillo
    } 
    else if (i == 1)
    {
      brillo += 5; // Incrementa el brillo
      
    }

  delay(50);
  }
   // Actualiza el estado anterior 
}

    
 
