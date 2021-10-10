//#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <time.h>


using namespace sf;


int main(){
    srand(time(0));
    RenderWindow app(VideoMode(400, 400), "Inicia o Campo Minado");

    int w = 32;
    int grid[12][12];
    int sgrid[12][12];

    Texture texture;
    texture.loadFromFile("img/icones.jpg");
    Sprite s(texture);

    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            sgrid[i][j]=10;
        }
    }

    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed){
                app.close();
            }
        }

        app.clear(Color::White);
        for (int i = 1; i <= 10;i++) {
            for (int j = 1; j <= 10;j++) {
                s.setTextureRect(IntRect(sgrid[i][j] * w, 0, w, w));
                s.setPosition(i * w, j * w);
                app.draw(s);
            }
        }
        app.display();
    }
}
