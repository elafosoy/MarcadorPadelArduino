#include "marcador.h"

Marcador::Marcador() {
  m_juegoA = new Juego(&m_equipoA);
  m_juegoB = new Juego(&m_equipoB);

  m_juegoA->setOtherEquipo(&m_equipoB);
  m_juegoB->setOtherEquipo(&m_equipoA);
  m_juegoA->setOtherJuego(m_juegoB);
  m_juegoB->setOtherJuego(m_juegoA);
}

void Marcador::sumaA() { m_juegoA->suma(); }

void Marcador::sumaB() { m_juegoB->suma(); }

void Marcador::restaA() { m_juegoA->resta(); }

void Marcador::restaB() { m_juegoB->resta(); }

void Marcador::refreshResults(Pantalla *pantalla) {
  // Calculo dos veces por que si no borra al marcar juego
  m_juegoA->puntos();
  m_juegoB->puntos();

  pantalla->puntosA = m_juegoA->puntos();
  pantalla->puntosB = m_juegoB->puntos();

  pantalla->juegosA = m_equipoA.totalJuegosGanados();
  pantalla->juegosB = m_equipoB.totalJuegosGanados();

  pantalla->setsA = m_equipoA.totalSetsGanados();
  pantalla->setsB = m_equipoB.totalSetsGanados();
}
