#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//Criação da Classe JogoAdivinhação para realizar nosso jogo.
class JogoAdivinhacao {
    //Estamos usando uma classe privada por não querermos que nossas variáveis sejem modificadas.
    private: 
        int numeroSecreto;
        int tentativas;
    //Aqui fica nosso Construtor. Ele leva o mesmo nome da nossa classe e, por ser um método, leva () realizando uma ação. Aqui ele irá gera um número aleátorio graças ao srand(ctime) toda vez que chamarmos ele.
    public:
        JogoAdivinhacao (){
            //Comando usado para gerar um número aleatório quando acionado. O "time" define o tempo gasto para a ação. Rand defini o limite de números e o 100+1 é usado pois o enunciado pede de 0 a 100. Sem isso iria de 0 até 99.
            srand (time (0));
            numeroSecreto = rand () % 100 + 1;
            tentativas = 0;
        }
        //Quando a classe for acionada nós podemos usar chamar esse método para de fato realizarmos o nosso jogo de adivinhação.
        void Jogar () {
            //Definição da variável palpite. Além disso, também tem a criação da repetição do nosso código. Se não acertarmos o número de primeira ele irá repetir. Sem o do isso não seria possível.
            int palpite;
            do {
                cout << "Digite um número entre 1 e 100: ";
                cin >> palpite;
                tentativas++;
                if (palpite > numeroSecreto){
                    cout << "O número secreto é menor!" << endl;
                } else if (palpite < numeroSecreto) {
                    cout << "O número secreto é maior!" << endl;
                } else {
                    cout << "Parabéns, você acertou o número em " << tentativas << " tentativas!" << endl;
                }
                //Condição para que o código continue repetindo. Nesse caso, se o palpite não for o certo ele irá continuar.
            } while (palpite != numeroSecreto);
        }
};
//Corpo principal. Como definimos muita coisa com a classe JogoAdivinhação basta chamarmos ela aqui, darmos um nome, aqui é "jogo" e depois acionar o método.
int main() {
    JogoAdivinhacao jogo;
    jogo.Jogar();
    return 0;
}
/*O contrutor tem um papel muito importante aqui, pois sem ele não seria nada prático a criação do código. Aqui ele irá gerar, independente de quantas vezes jogarmos, um número aleatório e também zerar nosso contador. Com ele poupamos muitas linhas de código.*/