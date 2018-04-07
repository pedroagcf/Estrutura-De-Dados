#include <lib/pen.h>

void quadrado(Pen &p, int lado){

    auto ang = p.getHeading();

    p.down();
    p.setHeading(0);

    for(int i = 0; i < 4; i++){

        p.walk(lado);
        p.rotate(90);
    }

    p.setHeading(ang);
    p.up();
}

void embua(Pen& p, int lado){

    float ang = 45;
    float dec = 0.90;

    if(lado < 10)
        return;

    p.walk(lado);
    p.right(ang);

    quadrado(p, lado*0.5);

    embua(p, lado*dec);

}

void fractal(){


    Pen p(800, 600);
    p.setThickness(2);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(300,350);
    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(50);

    p.up();
    embua(p, 100);

    //espera clicar no botao de fechar
    p.wait();
}

int main(){

    fractal();

    return 0;
}
