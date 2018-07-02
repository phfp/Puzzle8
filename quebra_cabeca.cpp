/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "quebra_cabeca.h"
#include <iostream>

using namespace std;

void espaco_vazio(char mat[3][3], int &linha, int &coluna){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(mat[i][j]=='9'){
                linha = i;
                coluna = j;
                break;
            }
        }
    }
}

int pecas_fora(char mat[3][3]){
    
    int pecas_fora = 0;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(mat[i][j]!='1' && i==0 && j==0){
                pecas_fora ++;}
            else
                if(mat[i][j]!='2' && i==0 && j==1){
                    pecas_fora ++;}
                else
                    if(mat[i][j]!='3' && i==0 && j==2){
                        pecas_fora ++;}
                    else
                        if(mat[i][j]!='4' && i==1 && j==0){
                            pecas_fora ++;}
                        else
                            if(mat[i][j]!='5' && i==1 && j==1){
                                pecas_fora ++;}
                            else
                                if(mat[i][j]!='6'&& i==1 && j==2){
                                    pecas_fora ++;}
                                else
                                    if(mat[i][j]!='7' && i==2 && j==0){
                                        pecas_fora ++;}
                                    else
                                        if(mat[i][j]!='8'&& i==2 && j==1){
                                            pecas_fora ++;}
        }
    }
    return pecas_fora;   
}

bool estado_repetido(char matA[3][3], char matB[3][3]){
    int x = 0;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matA[i][j] != matB[i][j]){
                return false;                
            }
        }
     }
    return true;
}

int distancia_manhattan(char mat[3][3]){
    int soma = 0;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(mat[i][j]=='1'){
                if(i==0 && j==0)
                    soma;
                else
                    if(i==0 && j==1)
                        soma+=1;
                    else
                        if(i==0 && j==2)
                            soma+=2;
                        else
                            if(i==1 && j==0)
                                soma+=1;
                            else
                                if(i==1 && j==1)
                                    soma+=2;
                                else
                                    if(i==1 && j==2)
                                        soma+=3;
                                    else
                                        if(i==2 && j==0)
                                            soma+=2;
                                        else
                                            if(i==2 && j==1)
                                                soma+=3;
                                            else
                                                if(i==2 && j==2)
                                                    soma+=4;
                        
            }
            else
                if(mat[i][j] == '2'){
                    if(i==0 && j==0)
                        soma+=1;
                    else
                        if(i==0 && j==1)
                            soma;
                        else
                            if(i==0 && j==2)
                                soma+=1;
                            else
                                if(i==1 && j==0)
                                    soma+=2;
                                else
                                    if(i==1 && j==1)
                                        soma+=1;
                                    else
                                        if(i==1 && j==2)
                                            soma+=2;
                                        else
                                            if(i==2 && j==0)
                                                soma+=3;
                                            else
                                                if(i==2 && j==1)
                                                    soma+=2;
                                                else
                                                    if(i==2 && j==2)
                                                        soma+=3;
                    
                }
                else
                    if(mat[i][j] == '3'){
                        if(i==0 && j==0)
                            soma+=2;
                        else
                            if(i==0 && j==1)
                                soma+=1;
                            else
                                if(i==0 && j==2)
                                    soma;
                                else
                                    if(i==1 && j==0)
                                        soma+=3;
                                    else
                                        if(i==1 && j==1)
                                            soma+=2;
                                        else
                                            if(i==1 && j==2)
                                                soma+=1;
                                            else
                                                if(i==2 && j==0)
                                                    soma+=4;
                                                else
                                                    if(i==2 && j==1)
                                                        soma+=3;
                                                    else
                                                        if(i==2 && j==2)
                                                            soma+=2;
                    }
                    else
                        if(mat[i][j] == '4'){
                            if(i==0 && j==0)
                                soma+=1;
                            else
                                if(i==0 && j==1)
                                    soma+=2;
                                else
                                    if(i==0 && j==2)
                                        soma+=3;
                                    else
                                        if(i==1 && j==0)
                                            soma;
                                        else
                                            if(i==1 && j==1)
                                                soma+=1;
                                            else
                                                if(i==1 && j==2)
                                                    soma+=2;
                                                else
                                                    if(i==2 && j==0)
                                                        soma+=1;
                                                    else
                                                        if(i==2 && j==1)
                                                            soma+=2;
                                                        else
                                                            if(i==2 && j==2)
                                                                soma+=3;
                        }
                        else
                            if(mat[i][j] == '5'){
                                if(i==0 && j==0)
                                    soma+=2;
                                else
                                    if(i==0 && j==1)
                                        soma+=1;
                                    else
                                        if(i==0 && j==2)
                                            soma+=2;
                                        else
                                            if(i==1 && j==0)
                                                soma+=1;
                                            else
                                                if(i==1 && j==1)
                                                    soma;
                                                else
                                                    if(i==1 && j==2)
                                                        soma+=1;
                                                    else
                                                        if(i==2 && j==0)
                                                            soma+=2;
                                                        else
                                                            if(i==2 && j==1)
                                                                soma+=1;
                                                            else
                                                                if(i==2 && j==2)
                                                                    soma+=2;
                            }
                            else
                                if(mat[i][j] == '6'){
                                    if(i==0 && j==0)
                                        soma+=3;
                                    else
                                        if(i==0 && j==1)
                                            soma+=2;
                                        else
                                            if(i==0 && j==2)
                                                soma+=1;
                                            else
                                                if(i==1 && j==0)
                                                    soma+=2;
                                                else
                                                    if(i==1 && j==1)
                                                        soma+=1;
                                                    else
                                                        if(i==1 && j==2)
                                                            soma;
                                                        else
                                                            if(i==2 && j==0)
                                                                soma+=3;
                                                            else
                                                                if(i==2 && j==1)
                                                                    soma+=2;
                                                                else
                                                                    if(i==2 && j==2)
                                                                        soma+=1;
                                }
                                else
                                    if(mat[i][j] == '7'){
                                        if(i==0 && j==0)
                                            soma+=2;
                                        else
                                            if(i==0 && j==1)
                                                soma+=3;
                                            else
                                                if(i==0 && j==2)
                                                    soma+=4;
                                                else
                                                    if(i==1 && j==0)
                                                        soma+=1;
                                                    else
                                                        if(i==1 && j==1)
                                                            soma+=2;
                                                        else
                                                            if(i==1 && j==2)
                                                                soma+=3;
                                                            else
                                                                if(i==2 && j==0)
                                                                    soma;
                                                                else
                                                                    if(i==2 && j==1)
                                                                        soma+=1;
                                                                    else
                                                                        if(i==2 && j==2)
                                                                            soma+=2;
                                    }
                                    else
                                        if(mat[i][j] == '8'){
                                            if(i==0 && j==0)
                                                soma+=3;
                                            else
                                                if(i==0 && j==1)
                                                    soma+=2;
                                                else
                                                    if(i==0 && j==2)
                                                        soma+=3;
                                                    else
                                                        if(i==1 && j==0)
                                                            soma+=2;
                                                        else
                                                            if(i==1 && j==1)
                                                                soma+=1;
                                                            else
                                                                if(i==1 && j==2)
                                                                    soma+=2;
                                                                else
                                                                    if(i==2 && j==0)
                                                                        soma+=1;
                                                                    else
                                                                        if(i==2 && j==1)
                                                                            soma;
                                                                        else
                                                                            if(i==2 && j==2)
                                                                                soma+=1;
                                        }
                                        else
                                            if(mat[i][j] == '9'){
                                                if(i==0 && j==0)
                                                    soma+=4;
                                                else
                                                    if(i==0 && j==1)
                                                        soma+=3;
                                                    else
                                                        if(i==0 && j==2)
                                                            soma+=2;
                                                        else
                                                            if(i==1 && j==0)
                                                                soma+=3;
                                                            else
                                                                if(i==1 && j==1)
                                                                    soma+=2;
                                                                else
                                                                    if(i==1 && j==2)
                                                                        soma+=1;
                                                                    else
                                                                        if(i==2 && j==0)
                                                                            soma+=2;
                                                                        else
                                                                            if(i==2 && j==1)
                                                                                soma+=1;
                                                                            else
                                                                                if(i==2 && j==2)
                                                                                    soma;
                                            }
        }
    }
    return soma;
}