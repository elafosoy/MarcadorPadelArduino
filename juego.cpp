#include "juego.h"

void Juego::setOtherJuego(Juego *otherJuego) { m_otherJuego = otherJuego; }

void Juego::setOtherEquipo(Equipo *otherEquipo) { m_otherEquipo = otherEquipo; }

Juego::Juego(Equipo *equipo) {
  m_equipo = equipo;
  m_puntos = 0;
}

void Juego::suma() {
  m_puntos += 15;
  m_otherPuntos = m_otherJuego->puntos();
}

void Juego::resta() {
  if (m_puntos == 40)
    m_puntos -= 10;
  else
    m_puntos -= 15;

  m_otherPuntos = m_otherJuego->puntos();
}

int Juego::puntos() {
  if (m_puntos == 45)  //
    m_puntos = 40;

  if (m_puntos < 0)  //
    m_puntos = 0;

  if (m_puntos > 40 && m_otherPuntos < 40) {
    m_equipo->sumaJuego(m_otherEquipo);
    clear();
    m_otherJuego->clear();
  } else if (m_puntos < 40 && m_otherPuntos > 40) {
    m_equipo->sumaJuego(m_otherEquipo);
    clear();
    m_otherJuego->clear();
  } else if ((m_puntos > 55) && ((m_puntos - m_otherPuntos > 15))) {
    // Cuando se ha lleado a 4 y hay que ganar de 2 puntos
    m_equipo->sumaJuego(m_otherEquipo);
    clear();
    m_otherJuego->clear();
  }

  return m_puntos;
}

void Juego::clear() {
  m_puntos = 0;
  m_otherPuntos = 0;
}
