#include "marcador.h"
#define BUTTON_A D4
#define BUTTON_B D3
#define BUTTON_RESTA D7

Marcador m_marcador;

unsigned long lastTime = 0;


void ICACHE_RAM_ATTR sumaPuntoEquipoA() {  
  long currentTime = millis();
  if ((lastTime+3000) < currentTime){  
    if (digitalRead(BUTTON_RESTA) > LOW){
      m_marcador.sumaA();
      refreshScreen();
    } else{  
      restaPuntoEquipoA();      
    }
    lastTime = millis(); 
  } 
}
void ICACHE_RAM_ATTR sumaPuntoEquipoB() {
  
  long currentTime = millis();
  if ((lastTime+3000) < currentTime){     
    if(digitalRead(BUTTON_RESTA) > LOW){ 
      Serial.println("sumaPuntoEquipoB()");
      m_marcador.sumaB();
      refreshScreen();    
    } else{
      restaPuntoEquipoB();      
    }  
    lastTime = millis();   
  } 
}

void restaPuntoEquipoA() {
  Serial.println("Resta A");
  m_marcador.restaA();
  refreshScreen();
}
void restaPuntoEquipoB() {
  Serial.println("Resta B");
  m_marcador.restaB();
  refreshScreen();
}

void refreshScreen() { 
  Pantalla pantalla;
  m_marcador.refreshResults(&pantalla); 

  if (pantalla.puntosA > 40) {
    if (pantalla.puntosA > pantalla.puntosB) {
      //ui->lcdPointsA->display("1");
      //ui->lcdPointsA->setStyleSheet("Background-color:green");
    } else if (pantalla.puntosA == pantalla.puntosB) {
      //ui->lcdPointsA->display("-");
      //ui->lcdPointsA->setStyleSheet("Background-color:red");
    }
  } else {
    //ui->lcdPointsA->display(pantalla.puntosA);
  }

  if (pantalla.puntosB > 40) {
    if (pantalla.puntosB > pantalla.puntosA) {
      //ui->lcdPointsB->display("1");
      //ui->lcdPointsB->setStyleSheet("Background-color:green");
    } else if (pantalla.puntosA == pantalla.puntosB) {
      //ui->lcdPointsB->display("-");
      //ui->lcdPointsB->setStyleSheet("Background-color:red");
    }
  } else {
    //ui->lcdPointsB->display(pantalla.puntosB);
  } 

  char cadena[18];
  Serial.println("------------------------");
  sprintf(cadena, "Puntos: %d - %d", pantalla.puntosA,pantalla.puntosB );
  Serial.println(cadena);
  sprintf(cadena, "Juegos: %d - %d", pantalla.juegosA,pantalla.juegosB );
  Serial.println(cadena);
  sprintf(cadena, "Sets:   %d - %d", pantalla.setsA,pantalla.setsB );
  Serial.println(cadena);
  Serial.println("------------------------");
  Serial.println("");
}


void setup() {
  Serial.begin(115200);
  Serial.println("Setup");
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   

  pinMode(BUTTON_A, INPUT_PULLUP);
  attachInterrupt(BUTTON_A,sumaPuntoEquipoA,FALLING);

  pinMode(BUTTON_B, INPUT_PULLUP);
  attachInterrupt(BUTTON_B,sumaPuntoEquipoB,FALLING);

  pinMode(BUTTON_RESTA, INPUT_PULLUP);

  Serial.println("Runing padel-pointer");
}

void loop() { 


  
}
