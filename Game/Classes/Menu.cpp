#include "headers/Menu.h"

Menu::Menu(sf::RenderWindow &window,sf::Image background_Recieved, sf::Font fonte)
{
    sf::Texture texture;
    texture.loadFromImage(background_Recieved);

    this->background.setTexture(texture);
    this->fonte = fonte;
    this->window = window;

    Selecionar.setFont(this->fonte);
    ComoJogar.setFont(this->fonte);

    Selecionar.setString("Selecionar modo de Jogo");
    ComoJogar.setString("Como Jogar");

    Selecionar.setCharacterSize(10);
    ComoJogar.setCharacterSize(10);

    Selecionar.setFillColor(Color::Black);
    ComoJogar.setFillColor(Color::Black);
}

void Menu::drawMenu()
{
    //Coloca o background na posição correta na tela
    background.setPosition(0,0);
    window.draw(background);

    //Cria o retangulo
    sf:: rectangle(100,30);
    rectangle.setFillColor(Color::Blue);
    rectangle.setPosition(30, 80);
    //Desenha o retângulo na parte superior esquerda
    window.draw(rectangle);
    sf::Vector2f size = window.getSize();
    int width = size.x;
    int heigh = size.y;
    rectangle.setPosition(widht - 130, 80);
    //Desenha o retangulo na parte superior direita
    window.draw(rectangle);
    ComoJogar.setPosition(35,85);
    Selecionar.setPosition(widht - 135, 85);
}

bool Menu::cliqueIniciar()
{
    return (mouseButton.position.x > window.getSize().x - 130) && (mouseButton.position.x < window.getSize().x - 30) && (mouseButton.position.y > 80) && (mouseButton.position.y < 110)
}