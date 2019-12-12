#include "headers/Menu.h"

Menu::Menu(sf::RenderWindow &window, sf::Font fonte)
{
    this->fonte = fonte;
    this->window = &window;

//Coloca a fonte, o texto, o tamanho de caracter e a cor do texto Modo de Jogo
    Selecionar.setFont(this->fonte);
    Selecionar.setString("Modo de Jogo");
    Selecionar.setCharacterSize(15);
    Selecionar.setFillColor(sf::Color::Black);

//Coloca a fonte, o texto, o tamanho  de caracter e a cor do texto Titulo
    Titulo.setFont(this->fonte);
    Titulo.setString("Jogo da Velha");
    Titulo.setCharacterSize(45);
    Titulo.setFillColor(sf::Color::Black);
}

void Menu::drawMenu()
{
    sf::Vector2f meio(window.getSize().x/2, window.getSize().y/2);
    //Deixa a tela branca, para que coloqemos as coisas por cima
    window.clear(sf::Color::White);
    //Cria o retangulo
    sf::RectangleShape rectangle(190, 35);
    rectangle.setColor(Color::Black);
    rectangle.setPosition(meio.x - 85, meio.y - 45);
    window.draw(rectangle);
    //Desenha o texto dentro do retangulo desenhado
    Selecionar.setPosition(meio.x-80, meio.y - 40);
    window.draw(Selecionar);
    Titulo.setPosition(meio.x - 293, 20);
}

bool Menu::cliqueIniciar()
{
    return (mouseButton.position.x > window.getSize().x - 85) && (mouseButton.position.x < window.getSize().x + 85) && (mouseButton.position.y > window.getSize().y/2 - 45) && (mouseButton.position.y < window.getSize().y/2 - 10);
}