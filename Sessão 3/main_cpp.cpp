#include <cstdio>
#include <cstring>

class Animal {
public:
    int numero_de_patas;
    char som[20];
    bool tem_pelo;
    bool eh_mamifero;
    char nome[20];

    Animal(const char* nome, int numero_de_patas, bool tem_pelo, bool eh_mamifero, char const* som) {
        this->numero_de_patas = numero_de_patas;
        this->tem_pelo = tem_pelo;
        this->eh_mamifero = eh_mamifero;
        strncpy(this->som, som, 20);
        strncpy(this->nome, nome, 20);
    }

    void comer() {
        printf("%s comeu!\n", this->nome);
    }

    void fazer_som() {
        printf("%s\n", this->som);
    }

};


class Passaro : public Animal{
private:        // Acessível apenas dentro da classe (encapsulamento)
    char tipo_de_bico[60];
    char cor[20];
    char porte[20];
    bool inicializado;
    bool voando;


public:         // Acessível dentro e fora da classe
    int atributo_publico = 42;

    Passaro(const char* nome, const char* tipo_de_bico, const char* canto, const char* cor, const char* porte) : 
    Animal(nome, 2, false, false, canto) {
        strncpy(this->tipo_de_bico, tipo_de_bico, 60);
        strncpy(this->cor, cor, 20);
        strncpy(this->porte, porte, 20);
        this->inicializado = true;
    }


    void voar() {
        if (this->inicializado == true && this->voando == false){
            this->voando = true;
            printf("%s vôou.\n", this->nome);
        }
    }

    void pousar() {
        if (this->inicializado == true && this->voando == true) {
            this->voando = false;
            printf("%s pousou.\n", this->nome);
        }
    }

};





int main() {
    Passaro galinha = Passaro("Galinha", "Pontudo e pequeno", "Pó pó!", "Marrom", "Pequeno");
    galinha.voar();
    galinha.pousar();
    return 0;
}