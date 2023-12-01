import processing.serial.*;

Serial miPuerto;

int LED1 = #ff0040;
int LED2 = #00ff51;
boolean L1 = false;
boolean L2 = false;

void setup() {
  size(960, 480);
  background(255);
  miPuerto = new Serial(this, Serial.list()[1], 9600);
  miPuerto.bufferUntil('\n');
}

void draw() {
  int margen1 = width/6;
  int margenTXT1 = width/6+25;
  float margen2 = width/2;
  float margenTXT2 = width/2+25;
  float margen3 = width/1.5;
  float margenTXT3 = width/1.5+25;
  int altura1 = height/2-100;
  int altura2 = height/2+50;
  int altura1TXT = height/2-70;
  int altura2TXT = height/2+80;

  fill(#318ca3);
  rect(margen1, altura1, 150, 50);

  fill(#ffa6ac);
  rect(margen2, altura1, 80, 50);

  fill(#c7f2ce);
  rect(margen3, altura1, 80, 50);

  fill(L1 ? LED1 : color(255));
  circle(margen2+38, altura2+20, 65);

  fill(L2 ? LED2 : color(255));
  circle(margen3+38, altura2+20, 65);

  fill(0);
  textSize(25);
  text("Entradas",margenTXT1, altura1TXT);

  fill(0);
  textSize(25);
  text("E1",margenTXT2, altura1TXT);

  fill(0);
  textSize(25);
  text("E2",margenTXT3, altura1TXT);

  fill(0);
  textSize(25);
  text("L1",margenTXT2, altura2TXT);

  fill(0);
  textSize(25);
  text("L2",margenTXT3, altura2TXT);

  fill(#f2e4b8);
  rect(margen1, altura2, 150, 50);
  fill(0);
  textSize(25);
  text("Entradas",margenTXT1, height/2+80);
}

void mousePressed() {
  float margen2 = width/2;
  float margen3 = width/1.5;
  int altura1 = height/2-100;

  if (mouseX > margen2 && mouseX < margen2 + 80 && mouseY > altura1 && mouseY < altura1 + 50) {
    L1 = !L1;
    miPuerto.write(L1 ? "\nencendido1\n" : "\napagado1\n");
  }

  if (mouseX > margen3 && mouseX < margen3 + 80 && mouseY > altura1 && mouseY < altura1 + 50) {
    L2 = !L2;
    miPuerto.write(L2 ? "\nencendido2\n" : "\napagado2\n");
  }
}

void serialEvent(Serial miPuerto) {
  String inString = miPuerto.readStringUntil('\n');
  if (inString != null) {
    inString = trim(inString);
    int[] leds = int(split(inString, ','));
    if (leds.length >= 2) {
      boolean nuevoL1 = leds[0] == 1;
      boolean nuevoL2 = leds[1] == 1;
      if (nuevoL1 != L1) {
        L1 = nuevoL1;
      }
      if (nuevoL2 != L2) {
        L2 = nuevoL2;
      }
    }
  }
}
