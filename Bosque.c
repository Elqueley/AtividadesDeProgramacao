#include <stdio.h>

typedef struct y
{
	char especie [25]; 
	char porte [15];
	int anoDePlantio;
	char nomeQuemPlantou [25];
}arvores;

typedef struct x
{
	int numeroSetor;
	char nomeSetor [25];
	float altura;
	float largura;
	int quantidadeArvoresPlantadas;
	int quantidadeConstrucao;
	arvores a[10];
}setor;

void menu();
void cadastrarSetor(setor s[10],int quantidadeSetor);
void listarSetor(setor s[10],int quantidadeSetor);
int setorIndice(setor s[10],int quantidadeSetor,int numeroSetor);
void cadastrarArvore(setor s[10],int indiceArvore);
void listarArvores(setor s[10],int indiceArvore);

int main(int argc, char const *argv[])
{
	setor s[10];
	int quantidadeSetor=0,op,numeroSetor,indice;
	do{
		menu();
		scanf("%d",&op);
		switch(op){
			case 1:
				cadastrarSetor(s,quantidadeSetor);
				quantidadeSetor++;
				break;
			case 2:
				listarSetor(s,quantidadeSetor);
				break;
			case 3:
				printf("Numero Setor: ");
				scanf("%i",&numeroSetor);
				indice=setorIndice(s,quantidadeSetor,numeroSetor);
				if(indice<0){
					printf("Setor nao encontrada\n");
				}else{
					cadastrarArvore(s,indice);
				}
				break;
			case 4:
				printf("Numero Setor: ");
				scanf("%i",&numeroSetor);
				indice=setorIndice(s,quantidadeSetor,numeroSetor);
				if(indice<0){
					printf("tuma nao encontrada\n");
				}else{
					listarArvores(s,indice);
				}
				break;
		}

	}while(op!=0);
	
	
	return 0;
}

void menu(){
	printf("\n------------menu--------------\n\n");
	printf("1) cadastrar Setores\n");
	printf("2) listar setor\n");
	printf("3) cadastrar Arvores\n");
	printf("4) listar Arvores\n");
	printf("0) sair\n");

}

void cadastrarSetor(setor s[10],int quantidadeSetor){
	
	printf("Nome do setor: ");
	scanf("%s",s[quantidadeSetor].nomeSetor);
	
	printf("Numero do setor: ");
	scanf("%i",&s[quantidadeSetor].numeroSetor);
	
	printf("Altura: ");
	scanf("%f",&s[quantidadeSetor].altura);
	
	printf("largura: ");
	scanf("%f",&s[quantidadeSetor].largura);
	
	printf("Quantidade de costrucao: ");
	scanf("%i",&s[quantidadeSetor].quantidadeConstrucao);
	
	s[quantidadeSetor].quantidadeArvoresPlantadas=0;
}

void listarSetor(setor s[10],int quantidadeSetor){
	int i;
	for (i = 0; i < quantidadeSetor	; ++i)
	{	
	
		printf("\n----------------------\n");
		printf("Nome do setor: : %s\n",s[i].nomeSetor);
		printf("Numero do setor: %i\n",s[i].numeroSetor);
		printf("Altura: %f\n",s[i].altura);
		printf("largura: %f\n",s[i].largura);
		printf("Quantidade de costrucao:  %i",s[i].quantidadeConstrucao);
	}
}

int setorIndice(setor s[10],int quantidadeSetor,int numeroSetor){
	int i;
	for (i = 0; i < quantidadeSetor	; ++i)
	{
		if(s[i].numeroSetor==numeroSetor){
			return i;
		}
	}
	return -1;
}

void cadastrarArvore(setor s[10],int indiceArvore){

	int i=s[indiceArvore].quantidadeArvoresPlantadas;

	printf("Especie da Arvorte:\n");
	scanf("%s",s[indiceArvore].a[i].especie);
	
	printf("Porte da Arvore:\n");
	scanf("%s",s[indiceArvore].a[i].porte);
	
	printf("Ano de plantio:\n");
	scanf("%i",& s[indiceArvore].a[i].anoDePlantio);
	
	printf("Nome de quem plantou:\n");
	scanf("%s",s[indiceArvore].a[i].nomeQuemPlantou);
	
	s[indiceArvore].quantidadeArvoresPlantadas++;

}

void listarArvores(setor s[10],int indiceArvore){
	int i ;
	for (i = 0; i < s[indiceArvore].quantidadeArvoresPlantadas; ++i)
	{
		printf("Especie: %s\n",s[indiceArvore].a[i].especie);
		printf("Porte: %s\n",s[indiceArvore].a[i].porte);
		printf("Ano de plantiu: %i \n",s[indiceArvore].a[i].anoDePlantio);
		printf("Nome de quem plantou: %s \n",s[indiceArvore].a[i].nomeQuemPlantou);
	}
}
