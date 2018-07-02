/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: root
 *
 * Created on 21 de Maio de 2016, 15:24
 */
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <list>
#include "quebra_cabeca.h"
#include <fstream>

using namespace std;

void sucessor_largura(No *pai,int linha, int coluna,list<No>&fila){
    
    No *filho;
    NoP p = new No(pai->estado,pai->pai,pai->profundidade);
    
    if(linha == 0 && coluna == 0){
        filho = new No(pai->estado,p,pai->profundidade+1);
        filho->estado[0][0] = pai->estado[0][1];
        filho->estado[0][1] = pai->estado[0][0];
        
        if(filho->profundidade<2)
            fila.push_back(*filho);
        else
            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                fila.push_back(*filho);   
        
        filho = new No(pai->estado,p,pai->profundidade+1);
        filho->estado[0][0] = pai->estado[1][0];
        filho->estado[1][0] = pai->estado[0][0];
        
        if(filho->profundidade<2)
            fila.push_back(*filho);
        else
            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                fila.push_back(*filho);
    }else
        if(linha == 0 && coluna == 2){
            filho = new No(pai->estado,p,pai->profundidade+1);
            filho->estado[0][2] = pai->estado[0][1];
            filho->estado[0][1] = pai->estado[0][2];
            
            if(filho->profundidade<2)
                fila.push_back(*filho);
            else
                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                    fila.push_back(*filho);
            
            filho = new No(pai->estado,p,pai->profundidade+1);
            filho->estado[0][2] = pai->estado[1][2];
            filho->estado[1][2] = pai->estado[0][2];
            
            if(filho->profundidade<2)
                fila.push_back(*filho);
            else
                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                    fila.push_back(*filho);
        }else
            if(linha == 2 && coluna == 0){
                filho = new No(pai->estado,p,pai->profundidade+1);
                filho->estado[2][0] = pai->estado[2][1];
                filho->estado[2][1] = pai->estado[2][0];
                
                if(filho->profundidade<2)
                    fila.push_back(*filho);
                else
                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                        fila.push_back(*filho);
                
                filho = new No(pai->estado,p,pai->profundidade+1);
                filho->estado[2][0] = pai->estado[1][0];
                filho->estado[1][0] = pai->estado[2][0];
                
                if(filho->profundidade<2)
                    fila.push_back(*filho);
                else
                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                        fila.push_back(*filho);
            }else
                if(linha == 2 && coluna == 2){
                    filho = new No(pai->estado,p,pai->profundidade+1);
                    filho->estado[2][2] = pai->estado[2][1];
                    filho->estado[2][1] = pai->estado[2][2];
                    
                    if(filho->profundidade<2)
                        fila.push_back(*filho);
                    else
                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                            fila.push_back(*filho);
                    
                    filho = new No(pai->estado,p,pai->profundidade+1);
                    filho->estado[2][2] = pai->estado[1][2];
                    filho->estado[1][2] = pai->estado[2][2];
                    
                    if(filho->profundidade<2)
                        fila.push_back(*filho);
                    else
                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                            fila.push_back(*filho);
                }else
                    if(linha == 0 && coluna == 1){
                        filho = new No(pai->estado,p,pai->profundidade+1);
                        filho->estado[0][1] = pai->estado[0][0];
                        filho->estado[0][0] = pai->estado[0][1];
                        
                        if(filho->profundidade<2)
                            fila.push_back(*filho);
                        else
                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                fila.push_back(*filho);
                        
                        filho = new No(pai->estado,p,pai->profundidade+1);
                        filho->estado[0][1] = pai->estado[0][2];
                        filho->estado[0][2] = pai->estado[0][1];
                        
                        if(filho->profundidade<2)
                            fila.push_back(*filho);
                        else
                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                fila.push_back(*filho);
                        
                        filho = new No(pai->estado,p,pai->profundidade+1);
                        filho->estado[0][1] = pai->estado[1][1];
                        filho->estado[1][1] = pai->estado[0][1];
                        
                        if(filho->profundidade<2)
                            fila.push_back(*filho);
                        else
                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                fila.push_back(*filho);
                    }else
                        if(linha == 1 && coluna == 0){
                            filho = new No(pai->estado,p,pai->profundidade+1);
                            filho->estado[1][0] = pai->estado[0][0];
                            filho->estado[0][0] = pai->estado[1][0];
                            
                            if(filho->profundidade<2)
                                fila.push_back(*filho);
                            else
                                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                    fila.push_back(*filho);
                            
                            filho = new No(pai->estado,p,pai->profundidade+1);
                            filho->estado[1][0] = pai->estado[1][1];
                            filho->estado[1][1] = pai->estado[1][0];
                            
                            if(filho->profundidade<2)
                                fila.push_back(*filho);
                            else
                                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                    fila.push_back(*filho);
                            
                            filho = new No(pai->estado,p,pai->profundidade+1);
                            filho->estado[1][0] = pai->estado[2][0];
                            filho->estado[2][0] = pai->estado[1][0];
                            
                            if(filho->profundidade<2)
                                fila.push_back(*filho);
                            else
                                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                    fila.push_back(*filho);
                        }else
                            if(linha == 1 && coluna == 2){
                                filho = new No(pai->estado,p,pai->profundidade+1);
                                filho->estado[1][2] = pai->estado[0][2];
                                filho->estado[0][2] = pai->estado[1][2];
                                
                                if(filho->profundidade<2)
                                    fila.push_back(*filho);
                                else
                                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                        fila.push_back(*filho);
                                
                                filho = new No(pai->estado,p,pai->profundidade+1);
                                filho->estado[1][2] = pai->estado[1][1];
                                filho->estado[1][1] = pai->estado[1][2];
                                
                                if(filho->profundidade<2)
                                    fila.push_back(*filho);
                                else
                                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                        fila.push_back(*filho);
                                
                                filho = new No(pai->estado,p,pai->profundidade+1);
                                filho->estado[1][2] = pai->estado[2][2];
                                filho->estado[2][2] = pai->estado[1][2];
                                
                                if(filho->profundidade<2)
                                    fila.push_back(*filho);
                                else
                                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                        fila.push_back(*filho);
                            }else
                                if(linha == 2 && coluna == 1){
                                    
                                    filho = new No(pai->estado,p,pai->profundidade+1);
                                    filho->estado[2][1] = pai->estado[1][1];
                                    filho->estado[1][1] = pai->estado[2][1];
                                    
                                    if(filho->profundidade<2)
                                        fila.push_back(*filho);
                                    else
                                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                            fila.push_back(*filho);
                                    
                                    filho = new No(pai->estado,p,pai->profundidade+1);
                                    filho->estado[2][1] = pai->estado[2][0];
                                    filho->estado[2][0] = pai->estado[2][1];
                                    
                                    if(filho->profundidade<2)
                                        fila.push_back(*filho);
                                    else
                                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                            fila.push_back(*filho);
                                    
                                    filho = new No(pai->estado,p,pai->profundidade+1);
                                    filho->estado[2][1] = pai->estado[2][2];
                                    filho->estado[2][2] = pai->estado[2][1];
                                    
                                    if(filho->profundidade<2)
                                        fila.push_back(*filho);
                                    else
                                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                            fila.push_back(*filho);

                                }else
                                    if(linha == 1 && coluna == 1){
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[0][1];
                                        filho->estado[0][1] = pai->estado[1][1];
                                        
                                        if(filho->profundidade<2)
                                            fila.push_back(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                fila.push_back(*filho);
                                        
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[1][0];
                                        filho->estado[1][0] = pai->estado[1][1];
                                        
                                        if(filho->profundidade<2)
                                            fila.push_back(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                fila.push_back(*filho);
                                        
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[1][2];
                                        filho->estado[1][2] = pai->estado[1][1];

                                        if(filho->profundidade<2)
                                            fila.push_back(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                fila.push_back(*filho);
                                        
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[2][1];
                                        filho->estado[2][1] = pai->estado[1][1];
                                        
                                        if(filho->profundidade<2)
                                            fila.push_back(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                fila.push_back(*filho);                                 
                                    }
}

void sucessor_profundidade(No *pai,int linha, int coluna,list<No>&pilha){
                
    No *filho;
    NoP p = new No(pai->estado,pai->pai,pai->profundidade);
    
    if(linha == 0 && coluna == 0){
        filho = new No(pai->estado,p,pai->profundidade+1);
        filho->estado[0][0] = pai->estado[0][1];
        filho->estado[0][1] = pai->estado[0][0];
        
        if(filho->profundidade<2)
            pilha.push_front(*filho);
        else
            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                pilha.push_front(*filho);
        
        filho = new No(pai->estado,p,pai->profundidade+1);
        filho->estado[0][0] = pai->estado[1][0];
        filho->estado[1][0] = pai->estado[0][0];
        
        if(filho->profundidade<2)
            pilha.push_front(*filho);
        else
            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                pilha.push_front(*filho);
    }else
        if(linha == 0 && coluna == 2){
            filho = new No(pai->estado,p,pai->profundidade+1);
            filho->estado[0][2] = pai->estado[0][1];
            filho->estado[0][1] = pai->estado[0][2];
            
            if(filho->profundidade<2)
                pilha.push_front(*filho);
            else
                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                    pilha.push_front(*filho);
            
            filho = new No(pai->estado,p,pai->profundidade+1);
            filho->estado[0][2] = pai->estado[1][2];
            filho->estado[1][2] = pai->estado[0][2];
            
            if(filho->profundidade<2)
                pilha.push_front(*filho);
            else
                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                    pilha.push_front(*filho);
        }else
            if(linha == 2 && coluna == 0){
                filho = new No(pai->estado,p,pai->profundidade+1);
                filho->estado[2][0] = pai->estado[2][1];
                filho->estado[2][1] = pai->estado[2][0];
                
                if(filho->profundidade<2)
                    pilha.push_front(*filho);
                else
                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                        pilha.push_front(*filho);
                
                filho = new No(pai->estado,p,pai->profundidade+1);
                filho->estado[2][0] = pai->estado[1][0];
                filho->estado[1][0] = pai->estado[2][0];
                
                if(filho->profundidade<2)
                    pilha.push_front(*filho);
                else
                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                        pilha.push_front(*filho);
            }else
                if(linha == 2 && coluna == 2){
                    filho = new No(pai->estado,p,pai->profundidade+1);
                    filho->estado[2][2] = pai->estado[2][1];
                    filho->estado[2][1] = pai->estado[2][2];
                    
                    if(filho->profundidade<2)
                        pilha.push_front(*filho);
                    else
                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                            pilha.push_front(*filho);
                    
                    filho = new No(pai->estado,p,pai->profundidade+1);
                    filho->estado[2][2] = pai->estado[1][2];
                    filho->estado[1][2] = pai->estado[2][2];
                    
                    if(filho->profundidade<2)
                        pilha.push_front(*filho);
                    else
                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                            pilha.push_front(*filho);
                }else
                    if(linha == 0 && coluna == 1){
                        filho = new No(pai->estado,p,pai->profundidade+1);
                        filho->estado[0][1] = pai->estado[0][0];
                        filho->estado[0][0] = pai->estado[0][1];
                        
                        if(filho->profundidade<2)
                            pilha.push_front(*filho);
                        else
                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                pilha.push_front(*filho);
                        
                        filho = new No(pai->estado,p,pai->profundidade+1);
                        filho->estado[0][1] = pai->estado[0][2];
                        filho->estado[0][2] = pai->estado[0][1];
                        
                        if(filho->profundidade<2)
                            pilha.push_front(*filho);
                        else
                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                pilha.push_front(*filho);
                        
                        filho = new No(pai->estado,p,pai->profundidade+1);
                        filho->estado[0][1] = pai->estado[1][1];
                        filho->estado[1][1] = pai->estado[0][1];
                        
                        if(filho->profundidade<2)
                            pilha.push_front(*filho);
                        else
                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                pilha.push_front(*filho);
                    }else
                        if(linha == 1 && coluna == 0){
                            filho = new No(pai->estado,p,pai->profundidade+1);
                            filho->estado[1][0] = pai->estado[0][0];
                            filho->estado[0][0] = pai->estado[1][0];
                            
                            if(filho->profundidade<2)
                                pilha.push_front(*filho);
                            else
                                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                    pilha.push_front(*filho);
                            
                            filho = new No(pai->estado,p,pai->profundidade+1);
                            filho->estado[1][0] = pai->estado[1][1];
                            filho->estado[1][1] = pai->estado[1][0];
                            
                            if(filho->profundidade<2)
                                pilha.push_front(*filho);
                            else
                                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                    pilha.push_front(*filho);
                            
                            filho = new No(pai->estado,p,pai->profundidade+1);
                            filho->estado[1][0] = pai->estado[2][0];
                            filho->estado[2][0] = pai->estado[1][0];
                            
                            if(filho->profundidade<2)
                                pilha.push_front(*filho);
                            else
                                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                    pilha.push_front(*filho);
                        }else
                            if(linha == 1 && coluna == 2){
                                filho = new No(pai->estado,p,pai->profundidade+1);
                                filho->estado[1][2] = pai->estado[0][2];
                                filho->estado[0][2] = pai->estado[1][2];
                                
                                if(filho->profundidade<2)
                                    pilha.push_front(*filho);
                                else
                                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                        pilha.push_front(*filho);
                                
                                filho = new No(pai->estado,p,pai->profundidade+1);
                                filho->estado[1][2] = pai->estado[1][1];
                                filho->estado[1][1] = pai->estado[1][2];
                                
                                if(filho->profundidade<2)
                                    pilha.push_front(*filho);
                                else
                                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                        pilha.push_front(*filho);
                                
                                filho = new No(pai->estado,p,pai->profundidade+1);
                                filho->estado[1][2] = pai->estado[2][2];
                                filho->estado[2][2] = pai->estado[1][2];
                                
                                if(filho->profundidade<2)
                                    pilha.push_front(*filho);
                                else
                                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))                                        
                                        pilha.push_front(*filho);
                            }else
                                if(linha == 2 && coluna == 1){
                                    
                                    filho = new No(pai->estado,p,pai->profundidade+1);
                                    filho->estado[2][1] = pai->estado[1][1];
                                    filho->estado[1][1] = pai->estado[2][1];
                                    
                                    if(filho->profundidade<2)
                                        pilha.push_front(*filho);
                                    else
                                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                            pilha.push_front(*filho);
                                    
                                    filho = new No(pai->estado,p,pai->profundidade+1);
                                    filho->estado[2][1] = pai->estado[2][0];
                                    filho->estado[2][0] = pai->estado[2][1];
                                    
                                    if(filho->profundidade<2)
                                        pilha.push_front(*filho);
                                    else
                                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                            pilha.push_front(*filho);
                                    
                                    filho = new No(pai->estado,p,pai->profundidade+1);
                                    filho->estado[2][1] = pai->estado[2][2];
                                    filho->estado[2][2] = pai->estado[2][1];
                                    
                                    if(filho->profundidade<2)
                                        pilha.push_front(*filho);
                                    else
                                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                            pilha.push_front(*filho);

                                }else
                                    if(linha == 1 && coluna == 1){
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[0][1];
                                        filho->estado[0][1] = pai->estado[1][1];
                                        
                                        if(filho->profundidade<2)
                                            pilha.push_front(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                pilha.push_front(*filho);
                                        
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[1][0];
                                        filho->estado[1][0] = pai->estado[1][1];
                                        
                                        if(filho->profundidade<2)
                                            pilha.push_front(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                pilha.push_front(*filho);
                                        
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[1][2];
                                        filho->estado[1][2] = pai->estado[1][1];

                                        if(filho->profundidade<2)
                                            pilha.push_front(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                pilha.push_front(*filho);
                                        
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[2][1];
                                        filho->estado[2][1] = pai->estado[1][1];
                                        
                                        if(filho->profundidade<2)
                                            pilha.push_front(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                pilha.push_front(*filho);                                   
                                    }

}

void sucessor_gulosa_pecas_fora(No *pai,int linha, int coluna,list<No>&pilha){
    
    No *filho;
    list<No> filhos,aux;
    NoP p = new No(pai->estado,pai->pai,pai->profundidade);
    
    if(linha == 0 && coluna == 0){
        No *filho1, *filho2;
        
        filho1 = new No(pai->estado,p,pai->profundidade+1);
        filho1->estado[0][0] = pai->estado[0][1];
        filho1->estado[0][1] = pai->estado[0][0];  
        
        filho2 = new No(pai->estado,p,pai->profundidade+1);
        filho2->estado[0][0] = pai->estado[1][0];
        filho2->estado[1][0] = pai->estado[0][0];       
        
        if(filho1->profundidade<2){
            if(pecas_fora(filho1->estado) <= pecas_fora(filho2->estado))
                pilha.push_front(*filho1);
            else
                pilha.push_front(*filho2);
        }
        else
        {
            if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                pilha.push_front(*filho1);
            else
                pilha.push_front((*filho2));            
        }      
        
        
    }else
        if(linha == 0 && coluna == 2){
            No *filho1, *filho2;
            
            filho1 = new No(pai->estado,p,pai->profundidade+1);
            filho1->estado[0][2] = pai->estado[0][1];
            filho1->estado[0][1] = pai->estado[0][2];
            
            filho2 = new No(pai->estado,p,pai->profundidade+1);
            filho2->estado[0][2] = pai->estado[1][2];
            filho2->estado[1][2] = pai->estado[0][2];
            
            if(filho1->profundidade<2){
                if(pecas_fora(filho1->estado) <= pecas_fora(filho2->estado))
                    pilha.push_front(*filho1);
                else
                    pilha.push_front(*filho2);
            }
            else
            {
                if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                    pilha.push_front(*filho1);
                else
                    pilha.push_front((*filho2));
            }
            
        }else
            if(linha == 2 && coluna == 0){
                No *filho1, *filho2;
                
                filho1 = new No(pai->estado,p,pai->profundidade+1);
                filho1->estado[2][0] = pai->estado[2][1];
                filho1->estado[2][1] = pai->estado[2][0];
                
                filho2 = new No(pai->estado,p,pai->profundidade+1);
                filho2->estado[2][0] = pai->estado[1][0];
                filho2->estado[1][0] = pai->estado[2][0];

                if(filho1->profundidade<2){
                    if(pecas_fora(filho1->estado) <= pecas_fora(filho2->estado))
                        pilha.push_front(*filho1);
                    else
                        pilha.push_front(*filho2);
                }
                else
                {
                    if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                        pilha.push_front(*filho1);
                    else
                        pilha.push_front((*filho2));            
                }
                
            }else
                if(linha == 2 && coluna == 2){
                    No *filho1, *filho2;
                    
                    filho1 = new No(pai->estado,p,pai->profundidade+1);
                    filho1->estado[2][2] = pai->estado[2][1];
                    filho1->estado[2][1] = pai->estado[2][2];
                    
                    filho2 = new No(pai->estado,p,pai->profundidade+1);
                    filho2->estado[2][2] = pai->estado[1][2];
                    filho2->estado[1][2] = pai->estado[2][2];
                    
                    if(filho1->profundidade<2){
                        if(pecas_fora(filho1->estado) <= pecas_fora(filho2->estado))
                            pilha.push_front(*filho1);
                        else
                            pilha.push_front(*filho2);
                    }
                    else
                    {
                        if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                            pilha.push_front(*filho1);
                        else
                            pilha.push_front((*filho2));            
                    }
                    
                }else
                    if(linha == 0 && coluna == 1){
                        No *filho1, *filho2, *filho3;
                        
                        filho1 = new No(pai->estado,p,pai->profundidade+1);
                        filho1->estado[0][1] = pai->estado[0][0];
                        filho1->estado[0][0] = pai->estado[0][1];
                        
                        filho2 = new No(pai->estado,p,pai->profundidade+1);
                        filho2->estado[0][1] = pai->estado[0][2];
                        filho2->estado[0][2] = pai->estado[0][1];
                        
                        filho3 = new No(pai->estado,p,pai->profundidade+1);
                        filho3->estado[0][1] = pai->estado[1][1];
                        filho3->estado[1][1] = pai->estado[0][1];
                        
                        if(filho1->profundidade<2){
                            if(pecas_fora(filho1->estado) <= pecas_fora(filho2->estado) && pecas_fora(filho1->estado) <= pecas_fora(filho3->estado))
                                pilha.push_front(*filho1);
                            else
                                if(pecas_fora(filho2->estado) <= pecas_fora(filho3->estado))
                                    pilha.push_front(*filho2);
                                else
                                    pilha.push_front(*filho3);                     
                        }
                        else
                        {
                            if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                                filhos.push_front(*filho1);
                            if(!estado_repetido(filho2->estado,filho2->pai->pai->estado))
                                filhos.push_front(*filho2);
                            if(!estado_repetido(filho3->estado,filho3->pai->pai->estado))
                                filhos.push_front(*filho3);
                            
                            aux.push_front(filhos.front());
                            filhos.pop_front();
                            
                            while(!filhos.empty()){
                                if(pecas_fora(filhos.front().estado)<=pecas_fora(aux.front().estado)){
                                    aux.push_front(filhos.front());  
                                }
                                filhos.pop_front();
                            }
                            pilha.push_front(aux.front());                          
                        }                       
                        
                    }else
                        if(linha == 1 && coluna == 0){
                            No *filho1, *filho2, *filho3;
                            
                            filho1 = new No(pai->estado,p,pai->profundidade+1);
                            filho1->estado[1][0] = pai->estado[0][0];
                            filho1->estado[0][0] = pai->estado[1][0];
         
                            filho2 = new No(pai->estado,p,pai->profundidade+1);
                            filho2->estado[1][0] = pai->estado[1][1];
                            filho2->estado[1][1] = pai->estado[1][0];

                            filho3 = new No(pai->estado,p,pai->profundidade+1);
                            filho3->estado[1][0] = pai->estado[2][0];
                            filho3->estado[2][0] = pai->estado[1][0];
                            
                            if(filho1->profundidade<2){
                                if(pecas_fora(filho1->estado) <= pecas_fora(filho2->estado) && pecas_fora(filho1->estado) <= pecas_fora(filho3->estado))
                                    pilha.push_front(*filho1);
                                else
                                    if(pecas_fora(filho2->estado) <= pecas_fora(filho3->estado))
                                        pilha.push_front(*filho2);
                                    else
                                        pilha.push_front(*filho3);                     
                        }
                        else
                        {
                            if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                                filhos.push_front(*filho1);
                            if(!estado_repetido(filho2->estado,filho2->pai->pai->estado))
                                filhos.push_front(*filho2);
                            if(!estado_repetido(filho3->estado,filho3->pai->pai->estado))
                                filhos.push_front(*filho3);
                            
                            aux.push_front(filhos.front());
                            filhos.pop_front();
                            
                            while(!filhos.empty()){
                                if(pecas_fora(filhos.front().estado)<=pecas_fora(aux.front().estado)){
                                    aux.push_front(filhos.front());                                    
                                }
                                filhos.pop_front();
                            }
                            pilha.push_front(aux.front());                          
                        } 

                        }else
                            if(linha == 1 && coluna == 2){
                                No *filho1, *filho2, *filho3;
                                
                                filho1 = new No(pai->estado,p,pai->profundidade+1);
                                filho1->estado[1][2] = pai->estado[0][2];
                                filho1->estado[0][2] = pai->estado[1][2];
                                
                                filho2 = new No(pai->estado,p,pai->profundidade+1);
                                filho2->estado[1][2] = pai->estado[1][1];
                                filho2->estado[1][1] = pai->estado[1][2];
                                
                                filho3 = new No(pai->estado,p,pai->profundidade+1);
                                filho3->estado[1][2] = pai->estado[2][2];
                                filho3->estado[2][2] = pai->estado[1][2];
                                
                                if(filho1->profundidade<2){
                                    if(pecas_fora(filho1->estado) <= pecas_fora(filho2->estado) && pecas_fora(filho1->estado) <= pecas_fora(filho3->estado))
                                        pilha.push_front(*filho1);
                                    else
                                        if(pecas_fora(filho2->estado) <= pecas_fora(filho3->estado))
                                            pilha.push_front(*filho2);
                                        else
                                            pilha.push_front(*filho3);                     
                                }
                                else
                                {
                                    if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                                        filhos.push_front(*filho1);
                                    if(!estado_repetido(filho2->estado,filho2->pai->pai->estado))
                                        filhos.push_front(*filho2);
                                    if(!estado_repetido(filho3->estado,filho3->pai->pai->estado))
                                        filhos.push_front(*filho3);
                                    
                                    aux.push_front(filhos.front());
                                    filhos.pop_front();
                                    
                                    while(!filhos.empty()){
                                        if(pecas_fora(filhos.front().estado)<=pecas_fora(aux.front().estado)){
                                            aux.push_front(filhos.front());                                    
                                        }
                                        filhos.pop_front();
                                    }
                                    pilha.push_front(aux.front());                          
                                }
                            }
                            else
                                if(linha == 2 && coluna == 1){
                                    No *filho1, *filho2, *filho3;
                                    
                                    filho1 = new No(pai->estado,p,pai->profundidade+1);
                                    filho1->estado[2][1] = pai->estado[1][1];
                                    filho1->estado[1][1] = pai->estado[2][1];
                                    
                                    filho2 = new No(pai->estado,p,pai->profundidade+1);
                                    filho2->estado[2][1] = pai->estado[2][0];
                                    filho2->estado[2][0] = pai->estado[2][1];

                                    filho3 = new No(pai->estado,p,pai->profundidade+1);
                                    filho3->estado[2][1] = pai->estado[2][2];
                                    filho3->estado[2][2] = pai->estado[2][1];
                                    
                                    if(filho1->profundidade<2){
                                        if(pecas_fora(filho1->estado) <= pecas_fora(filho2->estado) && pecas_fora(filho1->estado) <= pecas_fora(filho3->estado))
                                            pilha.push_front(*filho1);
                                        else
                                            if(pecas_fora(filho2->estado) <= pecas_fora(filho3->estado))
                                                pilha.push_front(*filho2);
                                            else
                                                pilha.push_front(*filho3);                     
                                    }
                                    else
                                    {
                                        if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                                            filhos.push_front(*filho1);
                                        if(!estado_repetido(filho2->estado,filho2->pai->pai->estado))
                                            filhos.push_front(*filho2);
                                        if(!estado_repetido(filho3->estado,filho3->pai->pai->estado))
                                            filhos.push_front(*filho3);
                                        
                                        aux.push_front(filhos.front());
                                        filhos.pop_front();
                                        
                                        while(!filhos.empty()){
                                            if(pecas_fora(filhos.front().estado)<=pecas_fora(aux.front().estado)){
                                                aux.push_front(filhos.front());                                    
                                            }                                            
                                            filhos.pop_front();
                                        }
                                        pilha.push_front(aux.front());                          
                                    }    
                                }else
                                    if(linha == 1 && coluna == 1){
                                        No *filho1, *filho2, *filho3, *filho4;
                                        
                                        filho1 = new No(pai->estado,p,pai->profundidade+1);
                                        filho1->estado[1][1] = pai->estado[0][1];
                                        filho1->estado[0][1] = pai->estado[1][1];
                      
                                        filho2 = new No(pai->estado,p,pai->profundidade+1);
                                        filho2->estado[1][1] = pai->estado[1][0];
                                        filho2->estado[1][0] = pai->estado[1][1];
         
                                        filho3 = new No(pai->estado,p,pai->profundidade+1);
                                        filho3->estado[1][1] = pai->estado[1][2];
                                        filho3->estado[1][2] = pai->estado[1][1];
                                        
                                        filho4 = new No(pai->estado,p,pai->profundidade+1);
                                        filho4->estado[1][1] = pai->estado[2][1];
                                        filho4->estado[2][1] = pai->estado[1][1];
                                        
                                        if(filho1->profundidade<2){
                                            if(pecas_fora(filho1->estado) <= pecas_fora(filho2->estado) && pecas_fora(filho1->estado) <= pecas_fora(filho3->estado) && pecas_fora(filho1->estado) <= pecas_fora(filho4->estado))
                                                pilha.push_front(*filho1);
                                            else
                                                if(pecas_fora(filho2->estado) <= pecas_fora(filho3->estado) && pecas_fora(filho2->estado) <= pecas_fora(filho4->estado))
                                                    pilha.push_front(*filho2);
                                                else
                                                    if(pecas_fora(filho3->estado) <= pecas_fora(filho4->estado))
                                                        pilha.push_front(*filho3);
                                                    else
                                                        pilha.push_front(*filho4);                     
                                        }
                                        else
                                        {
                                            if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                                                filhos.push_front(*filho1);
                                            if(!estado_repetido(filho2->estado,filho2->pai->pai->estado))
                                                filhos.push_front(*filho2);
                                            if(!estado_repetido(filho3->estado,filho3->pai->pai->estado))
                                                filhos.push_front(*filho3);
                                            if(!estado_repetido(filho4->estado,filho4->pai->pai->estado))
                                                filhos.push_front(*filho4);
                                            
                                            aux.push_front(filhos.front());
                                            
                                            filhos.pop_front();
                                            
                                            while(!filhos.empty()){
                                                if(pecas_fora(filhos.front().estado)<=pecas_fora(aux.front().estado)){
                                                    aux.push_front(filhos.front());                                    
                                                }
                                                filhos.pop_front();
                                            }
                                            pilha.push_front(aux.front());                          
                                        }
                                    }
}
                                    
void sucessor_gulosa_manhattan(No *pai,int linha, int coluna,list<No>&pilha){
    
    No *filho;
    list<No> filhos,aux;
    NoP p = new No(pai->estado,pai->pai,pai->profundidade);
    
    if(linha == 0 && coluna == 0){
        No *filho1, *filho2;
        
        filho1 = new No(pai->estado,p,pai->profundidade+1);
        filho1->estado[0][0] = pai->estado[0][1];
        filho1->estado[0][1] = pai->estado[0][0];  
        
        filho2 = new No(pai->estado,p,pai->profundidade+1);
        filho2->estado[0][0] = pai->estado[1][0];
        filho2->estado[1][0] = pai->estado[0][0];       
        
        if(filho1->profundidade<2){
            if(distancia_manhattan(filho1->estado) <= distancia_manhattan(filho2->estado))
                pilha.push_front(*filho1);
            else
                pilha.push_front(*filho2);
        }
        else
        {
            if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                pilha.push_front(*filho1);
            else
                pilha.push_front((*filho2));            
        }      
        
        
    }else
        if(linha == 0 && coluna == 2){
            No *filho1, *filho2;
            
            filho1 = new No(pai->estado,p,pai->profundidade+1);
            filho1->estado[0][2] = pai->estado[0][1];
            filho1->estado[0][1] = pai->estado[0][2];
            
            filho2 = new No(pai->estado,p,pai->profundidade+1);
            filho2->estado[0][2] = pai->estado[1][2];
            filho2->estado[1][2] = pai->estado[0][2];
            
            if(filho1->profundidade<2){
                if(distancia_manhattan(filho1->estado) <= distancia_manhattan(filho2->estado))
                    pilha.push_front(*filho1);
                else
                    pilha.push_front(*filho2);
            }
            else
            {
                if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                    pilha.push_front(*filho1);
                else
                    pilha.push_front((*filho2));
            }
            
        }else
            if(linha == 2 && coluna == 0){
                No *filho1, *filho2;
                
                filho1 = new No(pai->estado,p,pai->profundidade+1);
                filho1->estado[2][0] = pai->estado[2][1];
                filho1->estado[2][1] = pai->estado[2][0];
                
                filho2 = new No(pai->estado,p,pai->profundidade+1);
                filho2->estado[2][0] = pai->estado[1][0];
                filho2->estado[1][0] = pai->estado[2][0];

                if(filho1->profundidade<2){
                    if(distancia_manhattan(filho1->estado) <= distancia_manhattan(filho2->estado))
                        pilha.push_front(*filho1);
                    else
                        pilha.push_front(*filho2);
                }
                else
                {
                    if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                        pilha.push_front(*filho1);
                    else
                        pilha.push_front((*filho2));            
                }
                
            }else
                if(linha == 2 && coluna == 2){
                    No *filho1, *filho2;
                    
                    filho1 = new No(pai->estado,p,pai->profundidade+1);
                    filho1->estado[2][2] = pai->estado[2][1];
                    filho1->estado[2][1] = pai->estado[2][2];
                    
                    filho2 = new No(pai->estado,p,pai->profundidade+1);
                    filho2->estado[2][2] = pai->estado[1][2];
                    filho2->estado[1][2] = pai->estado[2][2];
                    
                    if(filho1->profundidade<2){
                        if(distancia_manhattan(filho1->estado) <= distancia_manhattan(filho2->estado))
                            pilha.push_front(*filho1);
                        else
                            pilha.push_front(*filho2);
                    }
                    else
                    {
                        if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                            pilha.push_front(*filho1);
                        else
                            pilha.push_front((*filho2));            
                    }
                    
                }else
                    if(linha == 0 && coluna == 1){
                        No *filho1, *filho2, *filho3;
                        
                        filho1 = new No(pai->estado,p,pai->profundidade+1);
                        filho1->estado[0][1] = pai->estado[0][0];
                        filho1->estado[0][0] = pai->estado[0][1];
                        
                        filho2 = new No(pai->estado,p,pai->profundidade+1);
                        filho2->estado[0][1] = pai->estado[0][2];
                        filho2->estado[0][2] = pai->estado[0][1];
                        
                        filho3 = new No(pai->estado,p,pai->profundidade+1);
                        filho3->estado[0][1] = pai->estado[1][1];
                        filho3->estado[1][1] = pai->estado[0][1];
                        
                        if(filho1->profundidade<2){
                            if(distancia_manhattan(filho1->estado) <= distancia_manhattan(filho2->estado) && distancia_manhattan(filho1->estado) <= distancia_manhattan(filho3->estado))
                                pilha.push_front(*filho1);
                            else
                                if(distancia_manhattan(filho2->estado) <= distancia_manhattan(filho3->estado))
                                    pilha.push_front(*filho2);
                                else
                                    pilha.push_front(*filho3);                     
                        }
                        else
                        {
                            if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                                filhos.push_front(*filho1);
                            if(!estado_repetido(filho2->estado,filho2->pai->pai->estado))
                                filhos.push_front(*filho2);
                            if(!estado_repetido(filho3->estado,filho3->pai->pai->estado))
                                filhos.push_front(*filho3);
                            
                            aux.push_front(filhos.front());
                            filhos.pop_front();
                            
                            while(!filhos.empty()){
                                if(distancia_manhattan(filhos.front().estado)<=distancia_manhattan(aux.front().estado)){
                                    aux.push_front(filhos.front());  
                                }
                                filhos.pop_front();
                            }
                            pilha.push_front(aux.front());                          
                        }                       
                        
                    }else
                        if(linha == 1 && coluna == 0){
                            No *filho1, *filho2, *filho3;
                            
                            filho1 = new No(pai->estado,p,pai->profundidade+1);
                            filho1->estado[1][0] = pai->estado[0][0];
                            filho1->estado[0][0] = pai->estado[1][0];
         
                            filho2 = new No(pai->estado,p,pai->profundidade+1);
                            filho2->estado[1][0] = pai->estado[1][1];
                            filho2->estado[1][1] = pai->estado[1][0];

                            filho3 = new No(pai->estado,p,pai->profundidade+1);
                            filho3->estado[1][0] = pai->estado[2][0];
                            filho3->estado[2][0] = pai->estado[1][0];
                            
                            if(filho1->profundidade<2){
                                if(distancia_manhattan(filho1->estado) <= distancia_manhattan(filho2->estado) && distancia_manhattan(filho1->estado) <= distancia_manhattan(filho3->estado))
                                    pilha.push_front(*filho1);
                                else
                                    if(distancia_manhattan(filho2->estado) <= distancia_manhattan(filho3->estado))
                                        pilha.push_front(*filho2);
                                    else
                                        pilha.push_front(*filho3);                     
                        }
                        else
                        {
                            if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                                filhos.push_front(*filho1);
                            if(!estado_repetido(filho2->estado,filho2->pai->pai->estado))
                                filhos.push_front(*filho2);
                            if(!estado_repetido(filho3->estado,filho3->pai->pai->estado))
                                filhos.push_front(*filho3);
                            
                            aux.push_front(filhos.front());
                            filhos.pop_front();
                            
                            while(!filhos.empty()){
                                if(distancia_manhattan(filhos.front().estado)<=distancia_manhattan(aux.front().estado)){
                                    aux.push_front(filhos.front());                                    
                                }
                                filhos.pop_front();
                            }
                            pilha.push_front(aux.front());                          
                        } 

                        }else
                            if(linha == 1 && coluna == 2){
                                No *filho1, *filho2, *filho3;
                                
                                filho1 = new No(pai->estado,p,pai->profundidade+1);
                                filho1->estado[1][2] = pai->estado[0][2];
                                filho1->estado[0][2] = pai->estado[1][2];
                                
                                filho2 = new No(pai->estado,p,pai->profundidade+1);
                                filho2->estado[1][2] = pai->estado[1][1];
                                filho2->estado[1][1] = pai->estado[1][2];
                                
                                filho3 = new No(pai->estado,p,pai->profundidade+1);
                                filho3->estado[1][2] = pai->estado[2][2];
                                filho3->estado[2][2] = pai->estado[1][2];
                                
                                if(filho1->profundidade<2){
                                    if(distancia_manhattan(filho1->estado) <= distancia_manhattan(filho2->estado) && distancia_manhattan(filho1->estado) <= distancia_manhattan(filho3->estado))
                                        pilha.push_front(*filho1);
                                    else
                                        if(distancia_manhattan(filho2->estado) <= distancia_manhattan(filho3->estado))
                                            pilha.push_front(*filho2);
                                        else
                                            pilha.push_front(*filho3);                     
                                }
                                else
                                {
                                    if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                                        filhos.push_front(*filho1);
                                    if(!estado_repetido(filho2->estado,filho2->pai->pai->estado))
                                        filhos.push_front(*filho2);
                                    if(!estado_repetido(filho3->estado,filho3->pai->pai->estado))
                                        filhos.push_front(*filho3);
                                    
                                    aux.push_front(filhos.front());
                                    filhos.pop_front();
                                    
                                    while(!filhos.empty()){
                                        if(distancia_manhattan(filhos.front().estado)<=distancia_manhattan(aux.front().estado)){
                                            aux.push_front(filhos.front());                                    
                                        }
                                        filhos.pop_front();
                                    }
                                    pilha.push_front(aux.front());                          
                                }                       
                        
                                
                                

                            }else
                                if(linha == 2 && coluna == 1){
                                    No *filho1, *filho2, *filho3;
                                    
                                    filho1 = new No(pai->estado,p,pai->profundidade+1);
                                    filho1->estado[2][1] = pai->estado[1][1];
                                    filho1->estado[1][1] = pai->estado[2][1];
                                    
                                    filho2 = new No(pai->estado,p,pai->profundidade+1);
                                    filho2->estado[2][1] = pai->estado[2][0];
                                    filho2->estado[2][0] = pai->estado[2][1];

                                    filho3 = new No(pai->estado,p,pai->profundidade+1);
                                    filho3->estado[2][1] = pai->estado[2][2];
                                    filho3->estado[2][2] = pai->estado[2][1];
                                    
                                    if(filho1->profundidade<2){
                                        if(distancia_manhattan(filho1->estado) <= distancia_manhattan(filho2->estado) && distancia_manhattan(filho1->estado) <= distancia_manhattan(filho3->estado))
                                            pilha.push_front(*filho1);
                                        else
                                            if(distancia_manhattan(filho2->estado) <= distancia_manhattan(filho3->estado))
                                                pilha.push_front(*filho2);
                                            else
                                                pilha.push_front(*filho3);                     
                                    }
                                    else
                                    {
                                        if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                                            filhos.push_front(*filho1);
                                        if(!estado_repetido(filho2->estado,filho2->pai->pai->estado))
                                            filhos.push_front(*filho2);
                                        if(!estado_repetido(filho3->estado,filho3->pai->pai->estado))
                                            filhos.push_front(*filho3);
                                        
                                        aux.push_front(filhos.front());
                                        filhos.pop_front();
                                        
                                        while(!filhos.empty()){
                                            if(distancia_manhattan(filhos.front().estado)<=distancia_manhattan(aux.front().estado)){
                                                aux.push_front(filhos.front());                                    
                                            }                                            
                                            filhos.pop_front();
                                        }
                                        pilha.push_front(aux.front());                          
                                    }    
                                }else
                                    if(linha == 1 && coluna == 1){
                                        No *filho1, *filho2, *filho3, *filho4;
                                        
                                        filho1 = new No(pai->estado,p,pai->profundidade+1);
                                        filho1->estado[1][1] = pai->estado[0][1];
                                        filho1->estado[0][1] = pai->estado[1][1];
                      
                                        filho2 = new No(pai->estado,p,pai->profundidade+1);
                                        filho2->estado[1][1] = pai->estado[1][0];
                                        filho2->estado[1][0] = pai->estado[1][1];
         
                                        filho3 = new No(pai->estado,p,pai->profundidade+1);
                                        filho3->estado[1][1] = pai->estado[1][2];
                                        filho3->estado[1][2] = pai->estado[1][1];
                                        
                                        filho4 = new No(pai->estado,p,pai->profundidade+1);
                                        filho4->estado[1][1] = pai->estado[2][1];
                                        filho4->estado[2][1] = pai->estado[1][1];
                                        
                                        if(filho1->profundidade<2){
                                            if(distancia_manhattan(filho1->estado) <= distancia_manhattan(filho2->estado) && distancia_manhattan(filho1->estado) <= distancia_manhattan(filho3->estado) && distancia_manhattan(filho1->estado) <= distancia_manhattan(filho4->estado))
                                                pilha.push_front(*filho1);
                                            else
                                                if(distancia_manhattan(filho2->estado) <= distancia_manhattan(filho3->estado) && distancia_manhattan(filho2->estado) <= distancia_manhattan(filho4->estado))
                                                    pilha.push_front(*filho2);
                                                else
                                                    if(distancia_manhattan(filho3->estado) <= distancia_manhattan(filho4->estado))
                                                        pilha.push_front(*filho3);
                                                    else
                                                        pilha.push_front(*filho4);                     
                                        }
                                        else
                                        {
                                            if(!estado_repetido(filho1->estado,filho1->pai->pai->estado))
                                                filhos.push_front(*filho1);
                                            if(!estado_repetido(filho2->estado,filho2->pai->pai->estado))
                                                filhos.push_front(*filho2);
                                            if(!estado_repetido(filho3->estado,filho3->pai->pai->estado))
                                                filhos.push_front(*filho3);
                                            if(!estado_repetido(filho4->estado,filho4->pai->pai->estado))
                                                filhos.push_front(*filho4);
                                            
                                            aux.push_front(filhos.front());
                                            
                                            filhos.pop_front();
                                            
                                            while(!filhos.empty()){
                                                if(distancia_manhattan(filhos.front().estado)<=distancia_manhattan(aux.front().estado)){
                                                    aux.push_front(filhos.front());                                    
                                                }
                                                filhos.pop_front();
                                            }
                                            pilha.push_front(aux.front());                          
                                        }
                                    }
}

void sucessor_AEstrela_pecas_fora(No *pai,int linha, int coluna,list<No>&pilha){
    
    No *filho;
    NoP p = new No(pai->estado,pai->pai,pai->profundidade);
    
    if(linha == 0 && coluna == 0){
        filho = new No(pai->estado,p,pai->profundidade+1);
        filho->estado[0][0] = pai->estado[0][1];
        filho->estado[0][1] = pai->estado[0][0];
        filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
        
        
        if(filho->profundidade<2)
            pilha.push_front(*filho);
        else
            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                pilha.push_front(*filho);   
        
        filho = new No(pai->estado,p,pai->profundidade+1);
        filho->estado[0][0] = pai->estado[1][0];
        filho->estado[1][0] = pai->estado[0][0];
        filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
        
        if(filho->profundidade<2)
            pilha.push_front(*filho);
        else
            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                pilha.push_front(*filho);
    }else
        if(linha == 0 && coluna == 2){
            filho = new No(pai->estado,p,pai->profundidade+1);
            filho->estado[0][2] = pai->estado[0][1];
            filho->estado[0][1] = pai->estado[0][2];
            filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
            
            if(filho->profundidade<2)
                pilha.push_front(*filho);
            else
                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                    pilha.push_front(*filho);
            
            filho = new No(pai->estado,p,pai->profundidade+1);
            filho->estado[0][2] = pai->estado[1][2];
            filho->estado[1][2] = pai->estado[0][2];
            filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
            
            if(filho->profundidade<2)
                pilha.push_front(*filho);
            else
                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                    pilha.push_front(*filho);
        }else
            if(linha == 2 && coluna == 0){
                filho = new No(pai->estado,p,pai->profundidade+1);
                filho->estado[2][0] = pai->estado[2][1];
                filho->estado[2][1] = pai->estado[2][0];
                filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                
                if(filho->profundidade<2)
                    pilha.push_front(*filho);
                else
                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                        pilha.push_front(*filho);
                
                filho = new No(pai->estado,p,pai->profundidade+1);
                filho->estado[2][0] = pai->estado[1][0];
                filho->estado[1][0] = pai->estado[2][0];
                filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                
                if(filho->profundidade<2)
                    pilha.push_front(*filho);
                else
                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                        pilha.push_front(*filho);
            }else
                if(linha == 2 && coluna == 2){
                    filho = new No(pai->estado,p,pai->profundidade+1);
                    filho->estado[2][2] = pai->estado[2][1];
                    filho->estado[2][1] = pai->estado[2][2];
                    filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                    
                    if(filho->profundidade<2)
                        pilha.push_front(*filho);
                    else
                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                            pilha.push_front(*filho);
                    
                    filho = new No(pai->estado,p,pai->profundidade+1);
                    filho->estado[2][2] = pai->estado[1][2];
                    filho->estado[1][2] = pai->estado[2][2];
                    filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                    
                    if(filho->profundidade<2)
                        pilha.push_front(*filho);
                    else
                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                            pilha.push_front(*filho);
                }else
                    if(linha == 0 && coluna == 1){
                        filho = new No(pai->estado,p,pai->profundidade+1);
                        filho->estado[0][1] = pai->estado[0][0];
                        filho->estado[0][0] = pai->estado[0][1];
                        filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                        
                        if(filho->profundidade<2)
                            pilha.push_front(*filho);
                        else
                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                pilha.push_front(*filho);
                        
                        filho = new No(pai->estado,p,pai->profundidade+1);
                        filho->estado[0][1] = pai->estado[0][2];
                        filho->estado[0][2] = pai->estado[0][1];
                        filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                        
                        if(filho->profundidade<2)
                            pilha.push_front(*filho);
                        else
                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                pilha.push_front(*filho);
                        
                        filho = new No(pai->estado,p,pai->profundidade+1);
                        filho->estado[0][1] = pai->estado[1][1];
                        filho->estado[1][1] = pai->estado[0][1];
                        filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                        
                        if(filho->profundidade<2)
                            pilha.push_front(*filho);
                        else
                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                pilha.push_front(*filho);
                    }else
                        if(linha == 1 && coluna == 0){
                            filho = new No(pai->estado,p,pai->profundidade+1);
                            filho->estado[1][0] = pai->estado[0][0];
                            filho->estado[0][0] = pai->estado[1][0];
                            filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                            
                            if(filho->profundidade<2)
                                pilha.push_front(*filho);
                            else
                                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                    pilha.push_front(*filho);
                            
                            filho = new No(pai->estado,p,pai->profundidade+1);
                            filho->estado[1][0] = pai->estado[1][1];
                            filho->estado[1][1] = pai->estado[1][0];
                            filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                            
                            if(filho->profundidade<2)
                                pilha.push_front(*filho);
                            else
                                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                    pilha.push_front(*filho);
                            
                            filho = new No(pai->estado,p,pai->profundidade+1);
                            filho->estado[1][0] = pai->estado[2][0];
                            filho->estado[2][0] = pai->estado[1][0];
                            filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                            
                            if(filho->profundidade<2)
                                pilha.push_front(*filho);
                            else
                                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                    pilha.push_front(*filho);
                        }else
                            if(linha == 1 && coluna == 2){
                                filho = new No(pai->estado,p,pai->profundidade+1);
                                filho->estado[1][2] = pai->estado[0][2];
                                filho->estado[0][2] = pai->estado[1][2];
                                filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                                
                                if(filho->profundidade<2)
                                    pilha.push_front(*filho);
                                else
                                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                        pilha.push_front(*filho);
                                
                                filho = new No(pai->estado,p,pai->profundidade+1);
                                filho->estado[1][2] = pai->estado[1][1];
                                filho->estado[1][1] = pai->estado[1][2];
                                filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                                
                                if(filho->profundidade<2)
                                    pilha.push_front(*filho);
                                else
                                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                        pilha.push_front(*filho);
                                
                                filho = new No(pai->estado,p,pai->profundidade+1);
                                filho->estado[1][2] = pai->estado[2][2];
                                filho->estado[2][2] = pai->estado[1][2];
                                filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                                
                                if(filho->profundidade<2)
                                    pilha.push_front(*filho);
                                else
                                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                        pilha.push_front(*filho);
                            }else
                                if(linha == 2 && coluna == 1){
                                    
                                    filho = new No(pai->estado,p,pai->profundidade+1);
                                    filho->estado[2][1] = pai->estado[1][1];
                                    filho->estado[1][1] = pai->estado[2][1];
                                    filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                                    
                                    if(filho->profundidade<2)
                                        pilha.push_front(*filho);
                                    else
                                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                            pilha.push_front(*filho);
                                    
                                    filho = new No(pai->estado,p,pai->profundidade+1);
                                    filho->estado[2][1] = pai->estado[2][0];
                                    filho->estado[2][0] = pai->estado[2][1];
                                    filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                                    
                                    if(filho->profundidade<2)
                                        pilha.push_front(*filho);
                                    else
                                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                            pilha.push_front(*filho);
                                    
                                    filho = new No(pai->estado,p,pai->profundidade+1);
                                    filho->estado[2][1] = pai->estado[2][2];
                                    filho->estado[2][2] = pai->estado[2][1];
                                    filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                                    
                                    if(filho->profundidade<2)
                                        pilha.push_front(*filho);
                                    else
                                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                            pilha.push_front(*filho);

                                }else
                                    if(linha == 1 && coluna == 1){
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[0][1];
                                        filho->estado[0][1] = pai->estado[1][1];
                                        filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                                        
                                        if(filho->profundidade<2)
                                            pilha.push_front(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                pilha.push_front(*filho);
                                        
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[1][0];
                                        filho->estado[1][0] = pai->estado[1][1];
                                        filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                                        
                                        if(filho->profundidade<2)
                                            pilha.push_front(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                pilha.push_front(*filho);
                                        
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[1][2];
                                        filho->estado[1][2] = pai->estado[1][1];
                                        filho->heuristica = filho->profundidade+pecas_fora(filho->estado);

                                        if(filho->profundidade<2)
                                            pilha.push_front(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                pilha.push_front(*filho);
                                        
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[2][1];
                                        filho->estado[2][1] = pai->estado[1][1];
                                        filho->heuristica = filho->profundidade+pecas_fora(filho->estado);
                                        
                                        if(filho->profundidade<2)
                                            pilha.push_front(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                pilha.push_front(*filho);                                   
                                    }

}

void sucessor_AEstrela_manhattan(No *pai,int linha, int coluna,list<No>&pilha){
    
    No *filho;
    NoP p = new No(pai->estado,pai->pai,pai->profundidade);
    
    if(linha == 0 && coluna == 0){
        filho = new No(pai->estado,p,pai->profundidade+1);
        filho->estado[0][0] = pai->estado[0][1];
        filho->estado[0][1] = pai->estado[0][0];
        filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
        
        
        if(filho->profundidade<2)
            pilha.push_front(*filho);
        else
            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                pilha.push_front(*filho);   
        
        filho = new No(pai->estado,p,pai->profundidade+1);
        filho->estado[0][0] = pai->estado[1][0];
        filho->estado[1][0] = pai->estado[0][0];
        filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
        
        if(filho->profundidade<2)
            pilha.push_front(*filho);
        else
            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                pilha.push_front(*filho);
    }else
        if(linha == 0 && coluna == 2){
            filho = new No(pai->estado,p,pai->profundidade+1);
            filho->estado[0][2] = pai->estado[0][1];
            filho->estado[0][1] = pai->estado[0][2];
            filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
            
            if(filho->profundidade<2)
                pilha.push_front(*filho);
            else
                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                    pilha.push_front(*filho);
            
            filho = new No(pai->estado,p,pai->profundidade+1);
            filho->estado[0][2] = pai->estado[1][2];
            filho->estado[1][2] = pai->estado[0][2];
            filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
            
            if(filho->profundidade<2)
                pilha.push_front(*filho);
            else
                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                    pilha.push_front(*filho);
        }else
            if(linha == 2 && coluna == 0){
                filho = new No(pai->estado,p,pai->profundidade+1);
                filho->estado[2][0] = pai->estado[2][1];
                filho->estado[2][1] = pai->estado[2][0];
                filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                
                if(filho->profundidade<2)
                    pilha.push_front(*filho);
                else
                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                        pilha.push_front(*filho);
                
                filho = new No(pai->estado,p,pai->profundidade+1);
                filho->estado[2][0] = pai->estado[1][0];
                filho->estado[1][0] = pai->estado[2][0];
                filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                
                if(filho->profundidade<2)
                    pilha.push_front(*filho);
                else
                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                        pilha.push_front(*filho);
            }else
                if(linha == 2 && coluna == 2){
                    filho = new No(pai->estado,p,pai->profundidade+1);
                    filho->estado[2][2] = pai->estado[2][1];
                    filho->estado[2][1] = pai->estado[2][2];
                    filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                    
                    if(filho->profundidade<2)
                        pilha.push_front(*filho);
                    else
                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                            pilha.push_front(*filho);
                    
                    filho = new No(pai->estado,p,pai->profundidade+1);
                    filho->estado[2][2] = pai->estado[1][2];
                    filho->estado[1][2] = pai->estado[2][2];
                    filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                    
                    if(filho->profundidade<2)
                        pilha.push_front(*filho);
                    else
                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                            pilha.push_front(*filho);
                }else
                    if(linha == 0 && coluna == 1){
                        filho = new No(pai->estado,p,pai->profundidade+1);
                        filho->estado[0][1] = pai->estado[0][0];
                        filho->estado[0][0] = pai->estado[0][1];
                        filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                        
                        if(filho->profundidade<2)
                            pilha.push_front(*filho);
                        else
                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                pilha.push_front(*filho);
                        
                        filho = new No(pai->estado,p,pai->profundidade+1);
                        filho->estado[0][1] = pai->estado[0][2];
                        filho->estado[0][2] = pai->estado[0][1];
                        filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                        
                        if(filho->profundidade<2)
                            pilha.push_front(*filho);
                        else
                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                pilha.push_front(*filho);
                        
                        filho = new No(pai->estado,p,pai->profundidade+1);
                        filho->estado[0][1] = pai->estado[1][1];
                        filho->estado[1][1] = pai->estado[0][1];
                        filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                        
                        if(filho->profundidade<2)
                            pilha.push_front(*filho);
                        else
                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                pilha.push_front(*filho);
                    }else
                        if(linha == 1 && coluna == 0){
                            filho = new No(pai->estado,p,pai->profundidade+1);
                            filho->estado[1][0] = pai->estado[0][0];
                            filho->estado[0][0] = pai->estado[1][0];
                            filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                            
                            if(filho->profundidade<2)
                                pilha.push_front(*filho);
                            else
                                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                    pilha.push_front(*filho);
                            
                            filho = new No(pai->estado,p,pai->profundidade+1);
                            filho->estado[1][0] = pai->estado[1][1];
                            filho->estado[1][1] = pai->estado[1][0];
                            filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                            
                            if(filho->profundidade<2)
                                pilha.push_front(*filho);
                            else
                                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                    pilha.push_front(*filho);
                            
                            filho = new No(pai->estado,p,pai->profundidade+1);
                            filho->estado[1][0] = pai->estado[2][0];
                            filho->estado[2][0] = pai->estado[1][0];
                            filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                            
                            if(filho->profundidade<2)
                                pilha.push_front(*filho);
                            else
                                if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                    pilha.push_front(*filho);
                        }else
                            if(linha == 1 && coluna == 2){
                                filho = new No(pai->estado,p,pai->profundidade+1);
                                filho->estado[1][2] = pai->estado[0][2];
                                filho->estado[0][2] = pai->estado[1][2];
                                filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                                
                                if(filho->profundidade<2)
                                    pilha.push_front(*filho);
                                else
                                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                        pilha.push_front(*filho);
                                
                                filho = new No(pai->estado,p,pai->profundidade+1);
                                filho->estado[1][2] = pai->estado[1][1];
                                filho->estado[1][1] = pai->estado[1][2];
                                filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                                
                                if(filho->profundidade<2)
                                    pilha.push_front(*filho);
                                else
                                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                        pilha.push_front(*filho);
                                
                                filho = new No(pai->estado,p,pai->profundidade+1);
                                filho->estado[1][2] = pai->estado[2][2];
                                filho->estado[2][2] = pai->estado[1][2];
                                filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                                
                                if(filho->profundidade<2)
                                    pilha.push_front(*filho);
                                else
                                    if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                        pilha.push_front(*filho);
                            }else
                                if(linha == 2 && coluna == 1){
                                    
                                    filho = new No(pai->estado,p,pai->profundidade+1);
                                    filho->estado[2][1] = pai->estado[1][1];
                                    filho->estado[1][1] = pai->estado[2][1];
                                    filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                                    
                                    if(filho->profundidade<2)
                                        pilha.push_front(*filho);
                                    else
                                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                            pilha.push_front(*filho);
                                    
                                    filho = new No(pai->estado,p,pai->profundidade+1);
                                    filho->estado[2][1] = pai->estado[2][0];
                                    filho->estado[2][0] = pai->estado[2][1];
                                    filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                                    
                                    if(filho->profundidade<2)
                                        pilha.push_front(*filho);
                                    else
                                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                            pilha.push_front(*filho);
                                    
                                    filho = new No(pai->estado,p,pai->profundidade+1);
                                    filho->estado[2][1] = pai->estado[2][2];
                                    filho->estado[2][2] = pai->estado[2][1];
                                    filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                                    
                                    if(filho->profundidade<2)
                                        pilha.push_front(*filho);
                                    else
                                        if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                            pilha.push_front(*filho);

                                }else
                                    if(linha == 1 && coluna == 1){
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[0][1];
                                        filho->estado[0][1] = pai->estado[1][1];
                                        filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                                        
                                        if(filho->profundidade<2)
                                            pilha.push_front(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                pilha.push_front(*filho);
                                        
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[1][0];
                                        filho->estado[1][0] = pai->estado[1][1];
                                        filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                                        
                                        if(filho->profundidade<2)
                                            pilha.push_front(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                pilha.push_front(*filho);
                                        
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[1][2];
                                        filho->estado[1][2] = pai->estado[1][1];
                                        filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);

                                        if(filho->profundidade<2)
                                            pilha.push_front(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                pilha.push_front(*filho);
                                        
                                        filho = new No(pai->estado,p,pai->profundidade+1);
                                        filho->estado[1][1] = pai->estado[2][1];
                                        filho->estado[2][1] = pai->estado[1][1];
                                        filho->heuristica = filho->profundidade+distancia_manhattan(filho->estado);
                                        
                                        if(filho->profundidade<2)
                                            pilha.push_front(*filho);
                                        else
                                            if(!estado_repetido(filho->estado,filho->pai->pai->estado))
                                                pilha.push_front(*filho);                                   
                                    }

}

void guarda_caminho(NoP n,list<NoP> &lista){
    if(n){
        lista.push_front(n);
        guarda_caminho(n->pai,lista);
    }
}

void imprime(list<NoP> s,list<No> f, int n){
        
    while(!s.empty()){        
        
        cout << "+---+---+---+"<< endl;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(s.front()->estado[i][j] == '9')
                cout <<"|   ";
            else
                cout << "| " << s.front()->estado[i][j] << " ";
            }
            cout << "|" << endl;
            cout << "+---+---+---+"<< endl;
        }
        s.pop_front();
        cout << endl;
        cout << "SOLUÇAO ENCONTRADA: tecle enter para ver o próximo passo!" << endl;
        cout << "Nós testados: " << n << endl;
        cout << "Profundidade: " << f.front().profundidade << endl; 
        cout << "Nós na lista: " <<f.size() << endl; 
        cin.get();
        system("clear");
    }

    cout << "+---+---+---+"<< endl;
    for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(f.front().estado[i][j] == '9')
                cout <<"|   ";
            else
                cout << "| " << f.front().estado[i][j] << " ";
            }
            cout << "|" << endl;
            cout << "+---+---+---+"<< endl;
        }
        
    cout << endl;
    cout << "Nós testados: " << n << endl;
    cout << "Profundidade: " << f.front().profundidade << endl; 
    cout << "Nós na lista: " <<f.size() << endl;    
}

void ordena(list<No>&lista){
    
    list<No> a;
    list<No> b;
    
    a.push_front(lista.front());
    lista.pop_front();
    
    while(!lista.empty()){
        if(lista.front().heuristica >= a.front().heuristica){
            a.push_front(lista.front());
            lista.pop_front();
        }
        else
            if(lista.front().heuristica <= a.back().heuristica){
                a.push_back(lista.front());
                lista.pop_front();
            }
            else
            {
                while(a.front().heuristica > lista.front().heuristica){
                    b.push_back(a.front());
                    a.pop_front();
                }
                a.push_front(lista.front());
                lista.pop_front();                
                while(!b.empty()){
                    a.push_front(b.back());
                    b.pop_back();
                }    
            }
    }
    while(!a.empty()){
        lista.push_back(a.back());
        a.pop_back();
    }
}

void busca_largura(char mat[3][3]){

    list<No> fila;
    list<No> visitados;
    list<NoP> solucao;   
    
    No *pai;     
    pai = new No(mat);
    int linha,coluna;
    
    fila.push_back(*pai);
    
    char opc = 'p';
    
    while(pecas_fora(fila.front().estado)){
        espaco_vazio(fila.front().estado,linha,coluna);
        sucessor_largura(&fila.front(),linha, coluna,fila);

        visitados.push_front(fila.front());
        fila.pop_front();

        if(fila.front().profundidade == 25 && opc == 'p'){
            cout << "Chegamos à Profundidade 25, a partir daqui a solução" << endl;
            cout << "pode demorar muito tempo para ser encontrada!"<< endl;
            cout << "Você deseja continuar? [S/n]";
            cin >> opc;
            system("clear");
            
            if(opc == 'n' || opc == 'N')
                break;
            else
                opc = 'x';
        }
    }
    
    if(pecas_fora(fila.front().estado)){
        cout << "SOLUÇÃO NÃO ENCONTRADA!" << endl;
        cout << "Nos testados: " << visitados.size() << endl;
        cout << "Profundidade: " << fila.front().profundidade << endl;
        cout << "Nos na lista: " << fila.size() << endl;
    }
    else
    {    
        guarda_caminho(fila.front().pai,solucao);
        imprime(solucao,fila,visitados.size()+1);
    }    
}

void busca_profundidade(char mat[3][3]){

    list<No> pilha;
    list<No> visitados;
    list<NoP> solucao;   
    
    No *pai;     
    pai = new No(mat);
    int linha,coluna;
    
    pilha.push_front(*pai);
    
    while(pecas_fora(pilha.front().estado) && !pilha.empty()){
        visitados.push_front(pilha.front());
        pilha.pop_front();       
        if(visitados.front().profundidade <= 20){
            espaco_vazio(visitados.front().estado,linha,coluna);
            sucessor_profundidade(&visitados.front(),linha,coluna,pilha);                
        }
    }    
    
    if(pilha.empty()){
        cout << "SOLUÇÃO NÃO ENCONTRADA!" << endl;
        cout << "Nos testados: " << visitados.size() << endl;
        cout << "Profundidade: " << visitados.front().profundidade << endl;
        cout << "Nos na lista: " << pilha.size() << endl;
    }
    else
    {
        guarda_caminho(pilha.front().pai,solucao);
        imprime(solucao,pilha,visitados.size()+1);    
    }
}

void busca_gulosa_pecas_fora(char mat[3][3]){

    list<No> pilha;
    list<NoP> solucao;   
    
    No *pai;     
    pai = new No(mat);
    int linha,coluna;
    
    pilha.push_front(*pai);
    
    while(pecas_fora(pilha.front().estado) && pilha.front().profundidade <= 3000000){
            espaco_vazio(pilha.front().estado,linha,coluna);
            sucessor_gulosa_pecas_fora(&pilha.front(),linha,coluna,pilha);   
    }    
    
    if(pecas_fora(pilha.front().estado)){
        cout << "SOLUÇÃO NÃO ENCONTRADA!" << endl;
        cout << "Nos testados: " << pilha.size() << endl;
        cout << "Profundidade: " << pilha.front().profundidade << endl;
        cout << "Nos na lista: " << pilha.size() << endl;
    }
    else
    {    
        guarda_caminho(pilha.front().pai,solucao);
        imprime(solucao,pilha,pilha.size());    
    }
    
    
}

void busca_gulosa_manhattan(char mat[3][3]){

    list<No> pilha;
    list<NoP> solucao;   
    
    No *pai;     
    pai = new No(mat);
    int linha,coluna;
    
    pilha.push_front(*pai);
    
    while(pecas_fora(pilha.front().estado) && pilha.front().profundidade <= 3000000){
     
            espaco_vazio(pilha.front().estado,linha,coluna);
            sucessor_gulosa_manhattan(&pilha.front(),linha,coluna,pilha);   
    }    
    
    if(pecas_fora(pilha.front().estado)){
        cout << "SOLUÇÃO NÃO ENCONTRADA!" << endl;
        cout << "Nos testados: " << pilha.size() << endl;
        cout << "Profundidade: " << pilha.front().profundidade << endl;
        cout << "Nos na lista: " << pilha.size() << endl;
    }
    else
    {    
        guarda_caminho(pilha.front().pai,solucao);
        imprime(solucao,pilha,pilha.size());    
    }    
}

void busca_AEstrela_pecas_fora(char mat[3][3]){

    list<No> pilha;
    list<No> visitados;
    list<NoP> solucao;   
    
    No *pai;     
    pai = new No(mat);
    int linha,coluna;
    
    pilha.push_front(*pai);
    
    while(pecas_fora(pilha.front().estado) && !pilha.empty()){
        visitados.push_front(pilha.front());
        pilha.pop_front();       
        if(visitados.front().profundidade <= 30){
            espaco_vazio(visitados.front().estado,linha,coluna);
            sucessor_AEstrela_pecas_fora(&visitados.front(),linha,coluna,pilha);
            ordena(pilha);
        }
    }    
    
    if(pilha.empty()){
        cout << "SOLUÇÃO NÃO ENCONTRADA!" << endl;
        cout << "Nos testados: " << visitados.size() << endl;
        cout << "Profundidade: " << visitados.front().profundidade << endl;
        cout << "Nos na lista: " << pilha.size() << endl;
    }
    else
    {
        guarda_caminho(pilha.front().pai,solucao);
        imprime(solucao,pilha,visitados.size()+1);    
    }
}

void busca_AEstrela_manhattan(char mat[3][3]){

    list<No> pilha;
    list<No> visitados;
    list<NoP> solucao;   
    
    No *pai;     
    pai = new No(mat);
    int linha,coluna;
    
    pilha.push_front(*pai);
    
    while(pecas_fora(pilha.front().estado) && !pilha.empty()){
        visitados.push_front(pilha.front());
        pilha.pop_front();       
        if(visitados.front().profundidade <= 30){
            espaco_vazio(visitados.front().estado,linha,coluna);
            sucessor_AEstrela_manhattan(&visitados.front(),linha,coluna,pilha);
            ordena(pilha);
        }
    }    
    
    if(pilha.empty()){
        cout << "SOLUÇÃO NÃO ENCONTRADA!" << endl;
        cout << "Nos testados: " << visitados.size() << endl;
        cout << "Profundidade: " << visitados.front().profundidade << endl;
        cout << "Nos na lista: " << pilha.size() << endl;
    }
    else
    {
        guarda_caminho(pilha.front().pai,solucao);
        imprime(solucao,pilha,visitados.size()+1);    
    }
}

int main(int argc, char** argv) {
    
    //Exemplo: 7 2 4 5 9 6 8 3 1    
    char mat[3][3];   
    char opc = 's';
    char rep_estado = 'n', execucoes = 0;
    
    while (opc == 's' || opc == 'S'){
        
        execucoes++;
        
        cout << "+-------------------------+" << endl;
        cout << "|   ALGORíTMOS DE BUSCA   |" << endl;
        cout << "|PROBLEMA DO QUEBRA CABEÇA|" << endl;
        cout << "|      DAS 8 PEÇAS        |" << endl;
        cout << "+-------------------------+" << endl;
        cout << "|[1]Busca Em Largura      |" << endl;
        cout << "|[2]Busca Em Profundidade |" << endl;
        cout << "|[3]Busca Gulosa h1       |" << endl;
        cout << "|[4]Busca Gulosa h2       |" << endl;
        cout << "|[5]Busca A* h1           |" << endl;
        cout << "|[6]Busca A* h2           |" << endl;
        cout << "|                         |" << endl;
        cout << "|Heurísticas:             |" << endl;
        cout << "|h1: peças fora do lugar  |" << endl;
        cout << "|h2: caminho de Manhattan |" << endl;
        cout << "+-------------------------+" << endl;
        cout << "Qual algorítmo você deseja testar? [1..6]";
       
        cin >> opc;       

        system("clear");
        
        if(execucoes > 1){
            cout << "Você deseja usar os valores anteriores? [S/n]";
            cin >> rep_estado;
            system("clear");
        }

        if(rep_estado == 'n' || rep_estado == 'N'){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                mat[i][j] = '9';                
            }
        }
        mat[0][0] = 'x';
        cout << "+---+---+---+"<< endl;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(mat[i][j] == '9')
                    cout <<"|   ";
                else
                    cout << "| " << mat[i][j] << " ";
            }
            cout << "|" << endl;
            cout << "+---+---+---+"<< endl;
        }

        for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cout << "No lugar do 'x', preencha de [1 a 8] para 'peças' e [9] para 'Espço Vazio'";
                    cin >> mat[i][j];
                    system("clear");
                    mat[i][j+1] = 'x';
                    cout << "+---+---+---+"<< endl;
                    for(int i=0; i<3; i++){
                        for(int j=0; j<3; j++){
                            if(mat[i][j] == '9')
                                cout <<"|   ";
                            else
                                cout << "| " << mat[i][j] << " ";
                        }
                        cout << "|" << endl;
                        cout << "+---+---+---+"<< endl;
                    }
                }
        }
        }
        system("clear");
        cin.get();

        if(opc == '1')
            busca_largura(mat);
        else
            if(opc == '2')
                busca_profundidade(mat);
            else
                if(opc == '3')
                    busca_gulosa_pecas_fora(mat);
                else
                    if(opc == '4')
                        busca_gulosa_manhattan(mat);
                    else
                        if(opc == '5')
                            busca_AEstrela_pecas_fora(mat);
                        else
                            if(opc == '6')
                                busca_AEstrela_manhattan(mat);
             
        cout << endl;                
        cout << "Você deseja continuar? [S/n]";
        cin >> opc;               
        system("clear");
    }   
    
    return 0;
}