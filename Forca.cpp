
#include <random>



#include "Foca.hpp"

using namespace std;

Forca::Forca ( std::string palavras, std::string scores ){
             m_arquivo_palavras = palavras;
            
            m_arquivo_scores = scores;
            eh_valido(m_arquivo_palavras);
          
        }

std::pair<bool, std::string> Forca::eh_valido(std::string palavras){
            std::ifstream pal(m_arquivo_palavras);
            
           

             std::pair<bool, std::string> check;
            if(pal.bad()){
                check.first = false;
                check.second = "arquivo não encontrado";
            }else{
                check.first = true;
                check.second = "";
            }
            pal.close();
            return check;

        }


void Forca::carrega_arquivos(){
            std::string str = m_arquivo_palavras;
            std::ifstream pal(m_arquivo_palavras);
            std::string check;
            
            
            int i = 0, a;

            while(pal >> check){
                pair<string,int> p;
                
                a = stoi(check);
                p.second = a;
               
                pal >> check;
                p.first = check;
                
                m_palavras.push_back(p);
                
            }
            return;
}

void Forca::set_dificuldade(Dificuldade B){
    d = B;
    return;
}

std::string Forca::proxima_palavra(){
    if(d == FACIL){
         int s;
            s = rand() % sizeof(m_palavras) / sizeof(int );
            m_palavra_atual = m_palavras[s].first;
            while (m_palavras[s].second < 640000)
            {
                s = rand() % m_palavras.size();
                m_palavra_atual = m_palavras[s].first;
            }
            
            return m_palavra_atual;

    }else if(d == MEDIO){
        int s;
            s = rand() % m_palavras.size();
            m_palavra_atual = m_palavras[s].first;
            while (m_palavras[s].second < 640000)
            {
               s = rand() % sizeof(m_palavras) / sizeof(int );
            m_palavra_atual = m_palavras[s].first;
            }
            return m_palavra_atual;
    }else if(d == DIFICIL){
        int s;
            s = rand() % sizeof(m_palavras) / sizeof(int );
            m_palavra_atual = m_palavras[s].first;
            while (m_palavras[s].second > 640000)
            {
               s = rand() % m_palavras.size();
            m_palavra_atual = m_palavras[s].first;
            }
            return m_palavra_atual;
    }

  
  return m_palavra_atual;

}

std::string Forca::get_palavra_atual(){
    return m_palavra_atual;
}
 
bool Forca::palpite(std::string palpite){

    for(int i =0; i < m_palavra_atual.size(); i++){

         if (palpite[0] == m_palavra_atual[i]){
            return true;
         }
    }
    m_tentativas_restantes --;
    return false;
}

bool Forca::game_over(){
    if(m_tentativas_restantes == 0){
        return true;
    }else{
        return false;
    }
}
 
 void Forca::set_tentativas_restantes(int tentativas){
     m_tentativas_restantes = tentativas;
     
 }
 

 int Forca::get_tentativas_restantes(){
     return m_tentativas_restantes;
 }

 vector < pair<string, int> > Forca::get_lista(){
     return m_palavras;
 }
