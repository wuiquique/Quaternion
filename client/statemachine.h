#include <string>
#include <vector>

enum Estado {
    Pregunta,
    Respuestas
};

class StateMachine {

    public:
    void imprimirEstado();
    void nuevoMensaje(std::string mensaje);

    private:
    Estado _estado = Pregunta;

    std::string pregunta = "Emitir pregunta: ";
    std::string respuesta = "Responder pregunta: ";
    std::string finalizar = "Finalizar pregunta";
    std::string preguntaR = "";
    std::vector <std::string> respuestaR;
};