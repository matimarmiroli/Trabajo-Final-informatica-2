int PULSADORL1=5;
int PULSADORL2=6;
int LED1=10;
int LED2=11;
boolean Led1Encendido=false;
boolean Led2Encendido=false;
int data;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(PULSADORL1, INPUT);
  pinMode(PULSADORL2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2,OUTPUT);
  Serial.begin(9600);

}

void loop() 
{
    //VERIFICIO QUE ENCIENDAN EL LED1 DESDE LA PROTOBOARD//
   if(digitalRead(PULSADORL1)==HIGH)
    {
          if(Led1Encendido==false)
          {
                digitalWrite(LED1, HIGH);
                Led1Encendido=true;
                Serial.write(1);
                delay(150);
          }
          else
          {
                digitalWrite(LED1,LOW);
                Serial.write(0);
                Led1Encendido=false;
                delay(150);
          }
    } 
   if(digitalRead(PULSADORL2)==HIGH)
    {
          if(Led2Encendido==false)
          {
                digitalWrite(LED2, HIGH);
                Led2Encendido=true;
                Serial.write(2);
                delay(150);
          }
          else
          {
                digitalWrite(LED2,LOW);
                Serial.write(3);
                Led2Encendido=false;
                delay(150);
          }
    } 

  if(Serial.available()>0)
  {
   data=Serial.read();
    // put your main code here, to run repeatedly:



    //VERIFICIO QUE ME ENCIENDAN EL LED DESDE PROCESSING//
    if(data==1)
    {
        digitalWrite(LED1, HIGH);
        Led1Encendido=true;
        Serial.write(1);

    }
    if(data==0)
    {
        digitalWrite(LED1, LOW);
        Led1Encendido=true;
        Serial.write(0);

    }

   if(data==2)
    {
        digitalWrite(LED2, HIGH);
        Led1Encendido=true;
        Serial.write(2);

    }
    if(data==3)
    {
        digitalWrite(LED2, LOW);
        Led1Encendido=true;
        Serial.write(3);

    }

  }
}
