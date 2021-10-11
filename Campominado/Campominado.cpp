//#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <time.h>


using namespace sf;


int main(){
    //inicia o rng(random number generator)
    srand(time(0)); 
    //2D drawing
    RenderWindow app(VideoMode(400, 400), "Inicia o Campo Minado"); 

    int w = 32;
    //tem o grid completo
    int grid[11][11];
    //mostra o gird pro usuario
    int sgrid[11][11];

    Texture texture;
    //carrega a textura da imagem com todos os icones
    texture.loadFromFile("img/icones.jpg");
    //separa a textura em sprites
    Sprite s(texture); 

    //preenche as matrizes com sprite
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            sgrid[i][j] = 10;

            if (rand() % 5 == 0) {
                grid[i][j] = 9;//preenche com bomba
            }
            else {
                grid[i][j] = 0;//preenche com nada
            }
        }

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            int n = 0;
            if (grid[i][j] == 9) continue;
            if (grid[i + 1][j] == 9) n++;
            if (grid[i][j + 1] == 9) n++;
            if (grid[i - 1][j] == 9) n++;
            if (grid[i][j - 1] == 9) n++;

            if (grid[i + 1][j + 1] == 9) n++;
            if (grid[i - 1][j - 1] == 9) n++;
            if (grid[i - 1][j + 1] == 9) n++;
            if (grid[i + 1][j - 1] == 9) n++;

            grid[i][j] = n;
        }

    while (app.isOpen())
    {
        Vector2i pos = Mouse::getPosition(app);
        int x = pos.x / w;
        int y = pos.y / w;

        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();

            if (e.type == Event::MouseButtonPressed)
                //mostra o que tem na celula clicada
                if (e.key.code == Mouse::Left) sgrid[x][y] = grid[x][y];
                //marca com flag a celula clicada
                else if (e.key.code == Mouse::Right) sgrid[x][y] = 11;
/*          Tentativa de power up/releva o tabuleiro quando apertar a barra de espaço
            if (e.type == Event::KeyPressed) 
                if(e.key.code == Keyboard::Space) app.draw(s);
*/                

        }

        app.clear(Color::White);
        for (int i = 1; i <= 10; i++)
            for (int j = 1; j <= 10; j++) {

                if (sgrid[x][y] == 9) sgrid[i][j] = grid[i][j];

                s.setTextureRect(IntRect(sgrid[i][j] * w, 0, w, w));
                s.setPosition(i * w, j * w);
                app.draw(s);
            }

        app.display();
    }
}
