#include "fdf.h"

void    display_iso(mlx, points, grid)
{
    ez;
}

/*
nao sei se escrevo as coordenadas aqui ou no put points
se quero reutilizar esta funçao nos eventos, tenho que colocar aqui

mlx para criar e pushar imagem
points para cords
grid para total i guess, ou line/rows

ponto inicial? meio ecra?
vou usar 2:1, mas com que valores em concreto?

valor minimo é o 2:1 (para mapas mt grandes) e se exceder temos pena
fica fora do frame
tenho 800v600? faco entre 600v500
600 / rows
600 tem que ocupar duma ponta a outra

tier 1: >300 pontos diagonais (2:1)
tier 2: 150-300 (4:2)
tier 3: 75-150 (8:4)
tier 4: 37-75 (16:8)
tier 5: <35 (32:16)
*/

/*
display iso pode servir tambem como evento, premir tecla "i"
da reset na imagem e zooms e volta a meter as coordenadas isometricas
iniciais
ou nao, se for dificil demais
*/