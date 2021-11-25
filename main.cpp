
#include "Foca.hpp"


using namespace std;

string print_boneco(int pontos){
  string str;
  if(pontos == 1){
  str ="  o \n   \n   \n";
  }else if(pontos ==2){
    str =" o \n | \n   \n";
  }else if(pontos == 3){
    str =" o \n/| \n   \n";
  }else if(pontos == 4){
    str =" o \n(|)\n   \n";
  }else if(pontos == 5){
    str =" o \n(|)\n|  \n";
  }else if(pontos == 6){
    str =" o \n(|)\n| |\n";
  }else{
    str ="   \n   \n   \n";
  }
  return str;
}

int reiniciar(){
  int MENU;
  string resposta;
    cout<<"reiniciar jogo?\n1-sim\n2-não\nresposta: ";
  cin>>resposta;
  if(resposta=="1"){
    return 1;
  }else if(resposta == "2"){
    return 0;
  }else{
    cout<<"resposta inválida";
    return 0;
  }
}

void Salvar_player(string nome, vector<string> palavras_usadas, int pontos, string scores){
  fstream soc(scores);
  vector<string> players;
  string salva;
  while(soc){
    getline(soc, salva);
    players.push_back(salva);
  }
  for(int i = 0; i < players.size(); i++){
    soc<<players[i];
    soc<<endl;
  }
  soc<<" ";
  soc<<nome;
  soc<<";";
  for(int i = 0; i >palavras_usadas.size(); i++ ){
    soc<<palavras_usadas[i]<<".";
  }
  soc<<";";
  soc<<pontos;
  
  soc.close();
}


int main(int argc, char *argv[]){
  //imprime todos os argumentos recebidos na execução
  //do programa, para testar, compile e faça
  //./a.out arg1 arg2 arg2
  //o primeiro argumento é sempre o nome 
  //do programa (a.out, neste exemplo)
  for(int i=0; i<argc; i++)
        cout<<"Argumento["<<i<<"]: "<<argv[i]<<endl;
  int MENU= 1;
   string resposta, nome = argv[1];

  cout << "lendo arquivos de palavras [argv[2]] e scores [argv[3]], por favor aquarde..\n";

  Forca * JOGO;
  string palavras = argv[2], scores = argv[3];
  JOGO = new Forca(palavras, scores);
  JOGO->carrega_arquivos();
  
    

  while (MENU != 0)
  {
    
    
    cout<<"MENU.\nIniciar novo jogo ->1\nScores ->2";
    cout <<"\nsua escolha:  ";
    cin>>resposta;
    while(resposta != "1" && resposta != "2"){
      cout<<"resultado inválido\n";
      cout<<"\nMENU.\nIniciar novo jogo ->1\nScores ->2\n";
      cout <<"sua escolha:  ";
      string resposta;
      cin>>resposta;
    }
    if (resposta == "2"){
      fstream soc(scores);
      int tamanho = 0;
      vector<string> jogadores;
      string dados;
      while(soc){
        getline(soc,dados);
        jogadores.push_back(dados);
      }
      for(int i=0; i < jogadores.size(); i++){
        cout<<jogadores[i]<<endl;
      }
      soc.close();
    }
    else if(resposta == "1"){
      cout<<"primeiramente!! escolha a dificuldade\n1-FÁCIL\n2-MÉDIO\n3-DIFÍCIL\nsua escolha: ";
      cin>>resposta;
      if(resposta == "1"){
        JOGO->set_dificuldade(JOGO->FACIL);
      }else if(resposta == "2"){
        JOGO->set_dificuldade(JOGO->MEDIO);
      }else if(resposta == "3"){
        JOGO->set_dificuldade(JOGO->DIFICIL);
      }
      vector<string> palpites, palpites_certos, palavras_usadas;
      
      int pontos = 0, ok = 0;
      JOGO->set_tentativas_restantes(6);
      JOGO->proxima_palavra();
      while(JOGO->game_over() == false){
        palpites ={}, palpites_certos={};
        int  erros = 0, acertos = 0;
        JOGO->set_tentativas_restantes(6);

      
        string teste;
        
        while(teste.size() != JOGO->get_palavra_atual().size()  && erros != 6){
            teste = "";

          cout<<"\nComençando jogo!!!\npontos: "<<pontos<<endl;

          cout<<print_boneco(erros)<<endl;

          for(int a = 0; a < JOGO->get_palavra_atual().size(); a++){
            ok = 0;
            for(int i = 0; i < palpites_certos.size();i++ ){
              if(JOGO->get_palavra_atual()[a] == palpites_certos[i][0]){
                cout<<palpites_certos[i][0];
                teste.push_back(palpites_certos[i][0]);
                ok = 1;
              }
            }
            if (ok == 0){
              cout<<"_";
            }
          }

          if (teste.size() == JOGO->get_palavra_atual().size()) break;

          cout<<"\npalpite:  ";
          cin>>resposta;
          
          if(resposta == JOGO->get_palavra_atual()){
            pontos = pontos + JOGO->get_palavra_atual().size() - acertos;
            break;
          }


          for(int i = 0; i < palpites.size();i++ ){
            if(resposta == palpites[i]){
              cout<<"\nja fez essa escolha\n";
              while(resposta == palpites[i]){
                cin>>resposta;
              }
            }
          }
          
          
          if(JOGO->palpite(resposta) == true){
            acertos += 1;
            palpites_certos.push_back(resposta);
            palpites.push_back(resposta);
            pontos ++;
          
          }else{
            
            erros += 1;
            JOGO->set_tentativas_restantes(6 - erros);
            palpites.push_back(resposta);
            pontos --;
          }
        }

        if(JOGO->game_over() == true){

          cout<<"\nfim de jogo!!\n";
          MENU = reiniciar();
          Salvar_player(nome,palavras_usadas,pontos,scores);
          
        }else{

          cout<<"\nótimo!!!\n";
          palavras_usadas.push_back(JOGO->get_palavra_atual());

          if(palavras_usadas.size() + 1 == JOGO->get_lista().size() / 2){
            cout<<"não tem mais palavras\n";
            JOGO->set_tentativas_restantes(0);
            MENU = reiniciar();
            Salvar_player(nome,palavras_usadas,pontos,scores);
          }else{

            int check = 0;

            while(check == 0){
              check = 1;

              for(int i = 0; i < palavras_usadas.size(); i++){
                if(JOGO->get_palavra_atual() == palavras_usadas[i]){
                JOGO->proxima_palavra();
                check = 0;
                }
              }

            }
          }
        }
        
      }
    }
  }  
return 0;
}