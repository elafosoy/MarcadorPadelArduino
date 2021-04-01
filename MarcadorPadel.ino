#include "marcador.h"
#define BUTTON_A D7
#define BUTTON_B D6
#define BUTTON_RESTA D5

Marcador m_marcador;
Pantalla m_pantalla;

unsigned long lastTime = 0; 
bool isShowTime = false;

void ICACHE_RAM_ATTR sumaPuntoEquipoA() {  
  unsigned long currentTime = millis(); 
  
  if ((lastTime+500) < currentTime){  
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
  unsigned long currentTime = millis(); 
  
  if ((lastTime+500) < currentTime){     
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
  m_marcador.refreshResults(&m_pantalla);  
  m_pantalla.refresh();
  isShowTime = false;
}

void showTime(){
  unsigned long current = millis();
  int minutes =  (unsigned int)(current / 60000);
  int resto = (current) % 60000;
  int seconds = (int)(resto) / 1000;
  
  char chminutes[2];
  sprintf(chminutes, "%0.2d", minutes);  
  
  char chseconds[4];
  sprintf(chseconds, "%0.2d", seconds);  
  
  m_pantalla.showTime(chminutes,chseconds);
}

void setup() {
  Serial.begin(115200);

  m_pantalla.write("by  AFO");
  delay(1000);
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   

  pinMode(BUTTON_A, INPUT_PULLUP);
  attachInterrupt(BUTTON_A,sumaPuntoEquipoA,HIGH);

  pinMode(BUTTON_B, INPUT_PULLUP);
  attachInterrupt(BUTTON_B,sumaPuntoEquipoB,HIGH);

  pinMode(BUTTON_RESTA, INPUT_PULLUP);

  Serial.println("Runing padel-pointer");

  refreshScreen();
}

void loop() { 
  unsigned long current = millis();
  if (current%2000 == 0){
    if (isShowTime)
      m_pantalla.refresh();
    else
      showTime();

    isShowTime = !isShowTime;  
  }
}
