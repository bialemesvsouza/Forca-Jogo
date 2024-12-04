#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

#define NUM_NIVEIS 3
#define PALAVRAS_POR_NIVEL 10

char *palavras[NUM_NIVEIS][PALAVRAS_POR_NIVEL] = {
    {"banana", "computador", "abacate", "leopardo", "quadra", "chuteira", "bule", "vencedor", "boliche", "dentadura"},
    {"avestruz", "paralelepipedo", "anexo", " amedrontador", "extase", "hostil", "lisonjeado", "trivial", "sororidade", "anedota"},
    {"concerne", "embocadura", "guisa", "despota", "mentecapto", "muxoxo", "perdeu", "lexicografo", "odaxelagnia", "uxorilocalidade"}
};

char *dica[NUM_NIVEIS][PALAVRAS_POR_NIVEL] = {
    {"fruta", "eletrônico", "fruta", "animal", "esporte", "futebol", "chá", "competição", "strike", "boca"},
    {"animal", "pedra", "junto", "medo", "felicidade", "grosso", "elogio", "comum", "irmandade", "piada"},
    {"pertence", "boca", "jeito", "tirano", "maluco", "afago", "sem dica", "dicionaristas", "palavreado","casamento"}
};
void escolherPalavra(char *palavra, int nivel, char *dicaa) {
    int indice = rand() % PALAVRAS_POR_NIVEL;
    strcpy(palavra, palavras[nivel - 1][indice]);
    strcpy(dicaa, dica[nivel - 1][indice]);
    
}

int main(){
	setlocale(LC_ALL,"portuguese");
	srand(time(NULL));
	char palavra[30], letra, lacuna[30]="", dicaa[30]="";
	int a, i, vida=7, cont, venceu=0, pontos=0,nivel=0;


	printf("Bem-vindo ao Jogo da Forca!! \n\n");
	printf("Descubra a palavra, você tem 7 vidas para acertar as letras que compõe a palavra misteriosa. \n");
	printf("Ah, e não se esqueça de usar a dica como sua aliada!\n");
	printf("Boa sorte!\n\n");
	
	printf("Insira o nivel desejado (1, 2 ou 3): ");
	scanf("%i",&nivel);
	
	escolherPalavra(palavra, nivel,dicaa);

	for(i=0; i<strlen(palavra); i++)
    {
        if(palavra[i]!=' ') lacuna[i] = '_';
        else lacuna[i] = ' ';
    }
	   
	   
	   
	while(vida > 0 && venceu == 0)
	{
		system("cls");
		printf("Dica: %s\n", dicaa);
		printf("Quantidade de letras: %d\n", strlen(palavra));
		printf("Vidas: %d\n\n", vida);
		
		printf("%s", lacuna);
		printf("\n\n");

		printf("Digite uma letra: ");
		letra = getch();
	
		printf("%c\n", letra);

		for(a=0; a<strlen(palavra); a++)
		{
			if(palavra[a]==letra)
			{
				lacuna[a] = letra;
				cont++;
				pontos+=2;
			}
		}

		if(cont==0)
		{
			printf("Voce errou uma letra!\n");
			vida--;
			Sleep(1000);
		}

		if(cont>0)
		{
			printf("Voce acertou uma letra!\n");
			Sleep(1000);
		}
		if(vida == 0) venceu=-1;

		if(strcmp(palavra, lacuna)==0) venceu=1;
		cont=0;

	}

	printf("\n");
	if(venceu==1) printf("Parabens! Voce venceu! Fez %d pontos.\n\n", pontos+vida*3);
	if(venceu==-1) printf("Voce perdeu! Fez %d pontos.\n\n", pontos);
	printf("A palavra certa era: %s", palavra);
	Sleep(3000);
	
	system("cls");
	printf("Agradecemos por jogar! \n");
	printf("Feito por: Beatriz Lemes, Larissa Ming, Júlia Arduin. \n");
	printf("\n");
	
	
	printf("Pressione qualquer tecla para continuar...");
	getch();

}
