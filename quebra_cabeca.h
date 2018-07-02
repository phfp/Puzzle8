/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   teste.h
 * Author: root
 *
 * Created on 21 de Maio de 2016, 15:25
 */

#ifndef TESTE_H
#define TESTE_H

#include "list"

class No;
typedef No *NoP;

class No{

public:   
    NoP pai;
    char estado[3][3];    
    int profundidade;    
    int heuristica;
    
    No(char m[3][3],NoP p = 0, int c = 0)
    {
        for(int i=0; i<3; i++){ 
            for(int j=0; j<3; j++){
                estado[i][j] = m[i][j];
            }
        }        
        profundidade = c;
        pai = p;
    }
};

void espaco_vazio(char mat[3][3], int &i, int &j);
int pecas_fora(char mat[3][3]);
bool estado_repetido(char matA[3][3], char matB[3][3]);
int distancia_manhattan(char mat[3][3]);

#endif /* TESTE_H */

