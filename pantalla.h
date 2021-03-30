#ifndef PANTALLA_H
#define PANTALLA_H
#include "MatrizLedAFO.h"

class Pantalla { 

MatrizLed pantalla;

  int m_velocidad; // Milisegundos entre frames 
  int m_brillo; // intensidad entre 0 y 15 (maximo brillo)

  int m_numDisplayMatrix = 8;
  
public:
  int puntosA = 0;
  int puntosB = 0;
  int juegosA = 0;
  int juegosB = 0;
  int setsA = 0;
  int setsB = 0;

  Pantalla(){
    puntosA = 0;
    puntosB = 0;
    juegosA = 0;
    juegosB = 0;
    setsA = 0;
    setsB = 0;
    m_velocidad = 150; // Milisegundos entre frames
    m_brillo = 0; 
    
    pantalla.begin(D4, D2, D3, m_numDisplayMatrix); // dataPin, clkPin, csPin, numero de matrices de 8x8
    pantalla.rotar(false);
    pantalla.setIntensidad(m_brillo); 
    pantalla.borrar();
     refresh();
    }

  void write(char *text, bool scroll = false){     
    pantalla.encender();
    pantalla.borrar();
    if (scroll)
      pantalla.escribirFraseScroll(text, m_velocidad);
    else
      pantalla.escribirFrase(text);
  }

  void refresh(){
    pantalla.borrar();
    pintaPuntos(puntosA,0,puntosB);
    pintaJuegos(juegosA,24);
    pintaSets(setsA,16);
           
    pintaPuntos(puntosB,32,puntosA);    
    pintaJuegos(juegosB,56);
    pintaSets(setsB,48);
  }

  void setBrillo(int brillo){
    m_brillo = brillo;
    pantalla.setIntensidad(m_brillo); 
  }

  void pintaPuntos(int puntos, int pos, int puntosOther){
    if(puntos<45){
      char a[2];
      sprintf(a, "%d", puntos);
      pantalla.escribirFrase(a,pos);
    }else if (puntos > puntosOther){
      pantalla.escribirFrase("AD",pos);
    }else if (puntos < puntosOther){
      pantalla.escribirFrase("40",pos);
    }else if (puntos == puntosOther){
      pantalla.escribirFrase("40",pos);
    }

  }

  void pintaJuegos(int juegos, int pos){
    char a[2];
    sprintf(a, "%d", juegos);
    pantalla.escribirFrase(a,pos,true);
  }

   void pintaSets(int sets, int pos){
//    char a[2];
//    sprintf(a, "%d", juegos);
//    pantalla.escribirFrase(a,pos,true);
  }

  void showTime(const char* minutes,const char* seconds){
    pantalla.borrar();
    pantalla.escribirFrase(minutes,32);
    pantalla.escribirFrase(seconds,48,true);
  }
  
};

#endif  // MARCADOR_H
