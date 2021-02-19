#ifndef EQUIPO_H
#define EQUIPO_H

class Equipo {
  int m_juegos;
  int m_sets;

 public:
  Equipo();

  void sumaJuego(Equipo *other);
  int totalJuegosGanados();
  int totalSetsGanados();

  void sumaSet();
  void clearJuegos();
};

#endif  // EQUIPO_H
