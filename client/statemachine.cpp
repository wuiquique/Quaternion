#include "statemachine.h"

#include <iostream>
#include <string>
#include <vector>

void StateMachine::imprimirEstado() {
    std::cout << "Estado: " << _estado << "\n";
}

void StateMachine::nuevoMensaje(std::string mensaje) {

    switch (_estado) {

        case Pregunta:
            if (mensaje.find(pregunta) != std::string::npos) {
                preguntaR = mensaje.erase(0,17);
                _estado = Respuestas;
            }
        case Respuestas:
            if (mensaje.find(respuesta) != std::string::npos) {
                respuestaR.push_back(mensaje.erase(0,20));
            }
            else if (mensaje.find(finalizar) != std::string::npos) {

                std::cout << "La pregunta es: " << preguntaR << "\n";
                std::cout << "La(s) respuesta(s) fue(ron): \n";

                int size = respuestaR.size();

                for (int i = 0; i < size; i++) {
                    std::cout << respuestaR[i] << "\n";
                }

                _estado = Pregunta;
                respuestaR.clear();
                preguntaR = "";
            }
        default:
            std::cout << "\n"; 
    }
}