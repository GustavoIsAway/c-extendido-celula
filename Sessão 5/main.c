#include "raylib.h"
#include <stdbool.h>

#define TARGET_FPS 60
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


typedef struct {
    float posX; // Tudo é dado em pixels
    float posY;
    float size;
    int speed;
} Entity;

float Rect_get_center_x(float x, float size_x) {
    return x + (size_x / 2);
}

float Rect_get_center_y(float y, float size_y) {
    return y + (size_y / 2);
}


int main() {
    // Criar uma janela
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Meu Jogo!");
    // Definir as configurações iniciais
    SetTargetFPS(TARGET_FPS);

    Entity meu_jogador = {
        .posX = (SCREEN_WIDTH / 2.0) - 50.0,
        .posY = (SCREEN_HEIGHT / 2.0) - 50.0,
        .size = 100.0,
        .speed = 5
    };

    int centro_jogador[2] = { 0 };  // (x, y) --> [0] = x; [1] = y
    int centro_bala[2] = { 0 };


    Entity bala = {
        .posX = 0,
        .posY = 0,
        .size = 25,
        .speed = 15
    };

    bool wasShot = false;

    while(!WindowShouldClose()) {
        centro_jogador[0] = Rect_get_center_x(meu_jogador.posX, meu_jogador.size);
        centro_jogador[1] = Rect_get_center_y(meu_jogador.posY, meu_jogador.size);
        centro_bala[0] = Rect_get_center_x(bala.posX, bala.size);
        centro_bala[1] = Rect_get_center_y(bala.posY, bala.size);

        // LÓGICA DE JOGO
        if (IsKeyDown(KEY_A)) {
            meu_jogador.posX -= meu_jogador.speed;
        }
        if (IsKeyDown(KEY_D)) {
            meu_jogador.posX += meu_jogador.speed;
        }

        if (IsKeyDown(KEY_W)) {
            meu_jogador.posY -= meu_jogador.speed;
        }
        if (IsKeyDown(KEY_S)) {
            meu_jogador.posY += meu_jogador.speed;
        }

        if (IsKeyPressed(KEY_SPACE) && !wasShot) { // Lógica de tiro
            bala.posX = centro_jogador[0];  // Vai pro X do centro do quadrado do jogador
            bala.posY = centro_jogador[1];  // Vai pro Y do centro do quadrado do jogador
            wasShot = true;
        }

        if (bala.posX > SCREEN_WIDTH) {
            bala.posX = 0;
            bala.posY = 0;
            wasShot = false;
        }



        // DESENHO DA TELA
        BeginDrawing();
        ClearBackground(BLACK);

        if (wasShot){
            bala.posX += bala.speed;
            DrawRectangle(          // Desenho da bala
                bala.posX, 
                bala.posY, 
                bala.size, 
                bala.size, 
                RED
            );
        }
        

        DrawRectangle(          // Desenha retângulo no "centro" da tela, de tamanho 100x100
            meu_jogador.posX, 
            meu_jogador.posY, 
            meu_jogador.size, 
            meu_jogador.size, 
            BLUE
        );

        

        DrawFPS(0, 0);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}