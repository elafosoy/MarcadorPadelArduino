#ifndef JUEGO_H
#define JUEGO_H
#include "equipo.h"

class Juego {
  Equipo *m_equipo;
  Equipo *m_otherEquipo;
  Juego *m_otherJuego;
  int m_puntos;
  int m_otherPuntos;
  bool m_service;
  
 public:
  Juego(Equipo *equipo, bool service);
  void setOtherJuego(Juego *otherJuego);

  void suma();
  void resta();
  int puntos();
  bool service(){return m_service;}
  void setService(bool service) {m_service = service;}

  void clear();
  void setOtherEquipo(Equipo *otherEquipo);
  
  private:
  void changeService();
};

#endif  // JUEGO_H
