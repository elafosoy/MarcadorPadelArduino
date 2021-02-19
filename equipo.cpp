#include "equipo.h"

Equipo::Equipo() {
  m_juegos = 0;
  m_sets = 0;
}

void Equipo::sumaJuego(Equipo *other) {
  m_juegos++;

  int juegosOther = other->totalJuegosGanados();

  if ((m_juegos >= 6) && (m_juegos > (juegosOther + 2))) {
    clearJuegos();
    other->clearJuegos();
    sumaSet();
  } else if ((juegosOther >= 6) && (juegosOther > (m_juegos + 2))) {
    clearJuegos();
    other->clearJuegos();
    other->sumaSet();
  }
}

int Equipo::totalJuegosGanados() { return m_juegos; }

int Equipo::totalSetsGanados() { return m_sets; }

void Equipo::sumaSet() { m_sets++; }

void Equipo::clearJuegos() { m_juegos = 0; }
