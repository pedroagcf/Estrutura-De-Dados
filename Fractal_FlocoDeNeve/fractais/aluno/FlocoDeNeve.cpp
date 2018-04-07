#include <lib/pen.h>
#include <iostream>

using namespace std;


void flocoDeNeve(Pen& p, int lado){

    if(lado < 1)
        return;

    for(int i = 0; i < 5; i++){

        p.walk(lado);
        flocoDeNeve(p, lado * 0.39);
        p.setColor(sf::Color::White);
        p.walk(-lado);
        p.setColor(sf::Color::Blue);
        p.left(360/5);

    }
}


void fractal(){

    int alt = 800;
    int lag = 600;

    Pen p(alt, lag);//largura e altura;

    p.setThickness(1);

//    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 300);

//    //faz o pincel apontar pra direita
    p.setHeading(00);

//    //se speed = 0 entao ele faz o mais rapido possivel
//    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(300);

    int lado = 200;

    flocoDeNeve(p, 150);

    // espera clicar no botao de fechar
    p.wait();

}

int main(){

    fractal();

    return 0;
}
