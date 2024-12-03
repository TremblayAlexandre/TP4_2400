#include "ObservateurRabais.hpp"

ObservateurRabais::ObservateurRabais(const string& nomRabais, double rabais, chrono::time_point<chrono::system_clock> dateFin) :
	nomRabais(nomRabais), rabais(rabais), dateFin(dateFin) {
};
