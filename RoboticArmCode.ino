 #include <Servo.h>

Servo rotateS;
Servo ceneS;
Servo yukseklikS;
int xPin = A0;
int yPin = A1;
int buttonPin = 2;

int xPozisyon;
int yPozisyon;
int butonDurum;
int zeroSerie = 0;
int eksen = 90;
int eksenY = 0;


int degisken = 1;
int ceneDegisken = 1;

void setup() {
Serial.begin(9600);
pinMode(xPin, init);
pinMode(yPin, init);
pinMode(buttonPin, INPUT_PULLUP);
rotateS.attach(3);
ceneS.attach(4);
yukseklikS.attach(5);
yukseklikS.write(0);
ceneS.write(180);
rotateS.write(90);
}
void cene() {
if(ceneDegisken % 2 == 0)
ceneS.write(35);
if(ceneDegisken % 2 == 1)
ceneS.write(180);
delay(500);
}
void rotate() {
if(degisken % 2 == 0){
  if (eksen < 0){
    eksen += 1;
  if (eksen > 180){
    eksen -= 1;
  }
  }
  if (xPozisyon > 150 && yPozisyon < 20){
    eksen += 5;
    rotateS.write(eksen);
  }
  if (yPozisyon > 150 && xPozisyon < 20){
    eksen -= 5;
    rotateS.write(eksen);
  }
}
}
void yukseklik() {
if(degisken %2 != 0){
  if (eksenY < 0){
    eksenY += 1;
  if (eksenY > 180){
    eksenY -= 1;
  }
  }
  if (xPozisyon > 150 && yPozisyon < 20){
    eksenY += 5;
    yukseklikS.write(eksenY);
  }
  if (yPozisyon > 150 && xPozisyon < 20){
    eksenY -= 5;
    yukseklikS.write(eksenY);
  }
}
}
void loop() {
  if(butonDurum == 0)
  degisken ++;
  if(xPozisyon > 300 && yPozisyon > 300)
  ceneDegisken ++;
  rotate();
  yukseklik();
  if(xPozisyon > 300 && yPozisyon > 300)
  cene();
  butonDurum = digitalRead(buttonPin);
  xPozisyon = analogRead(xPin);
  yPozisyon = analogRead(yPin);
  /*Serial.print("X Pozisyonu: ");
  Serial.print(xPozisyon);
  Serial.print(" | Y Pozisyonu: ");
  Serial.print(yPozisyon);
  Serial.print(" | Buton Durum: ");
  Serial.print(butonDurum);
  Serial.print(" | degisken: ");
  Serial.print(degisken);
  Serial.print(" | cenedegisken: ");
  Serial.println(ceneDegisken);*/
}
