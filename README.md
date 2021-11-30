# Trabalho-1
Repositório contendo as especificações do Trabalho 1 da disciplina de LP1

# Documento de Especificação

Leia o documento de especificação contido em [Especificação do Trabalho 1](https://docs.google.com/document/d/1X3VDW6EBE_ZRDHCoRNwqva17R1EZMpwDunRgDg9N4HU/edit?usp=sharing). Preencha o [author.md](author.md) com as informações relativas ao grupo/autor.


.Para executar o projeto é preciso acessar a past build dento da pasta out no terminal e usar o comando 
make. Em seguida o certo seria Usar o comando <./FORCA {-Nome do jogador-} Lista.txt scores.txt>

.**Porblemas com o código e com a execução**
 Em geral, tudu foi mais simples de se fazer, as funções das classes foram feitas da forma esperada. Porém a forma de salvar
um score de um Jodador novo deu algum problem, eu segui a orientação de apagar cada linha salvando a informaçãos para depois
preencher tudo denovo, pelo menos foi o entendido naquele dia, mas não tive exito. 

CMAKE: eu tive muita dificuldade de entender como funcionava o cmake, eu consegui copliar um projeto simples, mas não aconsegui 
fazer com que o código lesse os arquivos txt, por algum motivo ele os ignora mesmo fazendo uma bilblioteca apara eles da um 
segmetn erro. Porém  o código funciona normalmente, no replit por exemplo o programa executou de forma perfeita.

Doxygen: tentei usar documentação basica do Doxygen mas saiu um monte de documentos em branco.


# Avaliação

## Código | Funcionalidades
1. Classe forca 10/10

2. Interface textual 10/10

3. Execução completa do jogo 10/15
- A forma como a dificuldade é calculada está com números fixos, ou seja vc não calcula a frequencia média.
- Também não são sorteadas as letras que devem ser exibidas nos modos fácil e médio.

4. Validação dos arquivos de texto 1/5
- Vc implementou algumas validações então vou considerar um pouco aqui.

5. Arquivos de teste de validação dos casos de erro 0/5

6. Arquivos de teste de validação dos níveis de dificuldade 1/5
- Aqui era esperado que vc enviasse arquivos de teste para os níveis de dificuldade

7. Observações gerais
- Você não precisava usar a classe forca com new
- A forma como vc tentou pegar o tamanho do vetor de palavras está errada, você até acertou em um ponto e usou `sizeof`
em outros. A função `sizeof` serve para retornar o tamanho em bytes que um __tipo__ ocupa e não para tamanho de vetores.
Em C quando um vetor é int[10], o tipo dele também é int[10], logo `sizeof` retorna o tamanho dele, no entanto se o vetor
for int* sizeof não serve mais para calcular o tamanho, logo também não vai calcular o tamanho se for um std::vector ou outro
container.
- Não era necessário configurar o Doxyfile

## Código | Boas práticas

1. Documentação do código e readme 0/10
- não foram documentados os métodos e funções implementadas

2. Organização e indentação 2/10
- A indentação está realmente muito ruim no forca.hpp, bem como você não seguiu a organização src/include/data

3. Compilação automatizada 5/5
- Vou considerar embora a organização não esteja correta

