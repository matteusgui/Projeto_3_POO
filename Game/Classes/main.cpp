#include <SFML/Graphics.hpp>
#include "headers/Game.h"

const int HEIGHT = 600;
const int WIDTH = 800;


int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tic Tae Toe");

    sf::Image xImage;
    if (!xImage.loadFromFile("../Images/x.png"))
    {
        cout << "Erro na leitura do arquivo 'x.png'" <<endl;    
    }

    sf::Image oImage;
    if (!oImage.loadFromFile("../Images/circle.png"))
    {
        cout << "Erro na leitura do arquivo 'circle.png'" <<endl;    
    }
    
    Player *a = new Player("vitor", 'X');
    Bot *b = new Bot('O');

    Game game(a, b);
    sf::Vector2f gamePosition(200,100);
    game.setPosition(gamePosition);
    game.setSize(400);
    game.setWindow(&window);
    game.setImages(xImage, oImage);


    while (!game.isFull() && !game.winner())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                //Verifica se clique foi dentro do jogo
                if(event.mouseButton.x > game.getPosition().x &&
                   event.mouseButton.x < game.getPosition().x + game.getSize() &&
                   event.mouseButton.y > game.getPosition().y &&
                   event.mouseButton.y < game.getPosition().y + game.getSize())
                    {   
                        //Converte coordenada do clique em linha e coluna da matriz 
                        int col = (event.mouseButton.x - game.getPosition().x) / (game.getSize() / 3);
                        int lin = (event.mouseButton.y - game.getPosition().y) / (game.getSize() / 3);
                        
                        //Executa a Jogada
                        if(game.play(lin*3 + col))
                        {
                            if(game.getActive()->isBot())
                                cout << game.play(game.getActive()->play(game.getMatrix()));
                        }
                    }
            }
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }

        window.clear(sf::Color(255,255,255));
        game.drawPlays();
        game.drawGrade();
        window.display();
    }

    window.close();
    return 0;
}