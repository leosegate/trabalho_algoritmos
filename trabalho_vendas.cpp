#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#include<conio2.h>
#include<windows.h>
#define TF 4
#define TFvendas 20

struct TpData
{
	int Dia, Mes, Ano;
};

struct fornecedor {
	int codFornecedor;
	char nomeFornecedor[20];
	char cidade[20];
};

struct produtos {
	int codProd, estoque;
	char descrProd[30];
	float preco;
	TpData DtValidade;
	int codFornecedor;
};

struct clientes {
	char cpf[12];
	char nomeCliente[10];
	int qtdeCompras;
	float valorTotalComprado;
};

struct vendas {
	int codVenda;
	char cpfCliente[12];
	TpData dataVenda;
	float totalVendas;
};

struct vendas_produtos {
	int codVenda, codProd, qtde;
	float valorUnitario;
};

void linha(void) {printf("----------------------------------------");}
void limpa() {printf("                                                                      ");}

void molduraextra (int ci, int li, int cf,int lf, int cort,int corF)
{
	int i;
	textcolor(cort);
	textbackground(corF);
	gotoxy(1,1);
	printf("%c",201);
	gotoxy(118,1);
	printf("%c",187);
	gotoxy(1,30);
	printf("%c",200);
	gotoxy(1,5);
	printf("%c",204);
	gotoxy(118,5);
	printf("%c",185);
	gotoxy(118,30);
	printf("%c",188);
	for(i=2; i<118; i++)
	{
		gotoxy(i,1); printf("%c",205);
		gotoxy(i,5); printf("%c",205);
		gotoxy(i,30); printf("%c",205);
	}
	
	

	for(i=2; i<5; i++)
	{
		gotoxy(1,i); printf("%c",186);
		gotoxy(118,i); printf("%c",186);
	}
	for(i=6; i<30; i++)
	{
		gotoxy(1,i); printf("%c",186);
		gotoxy(118,i); printf("%c",186);
	}
}



void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF)
{
	int i;
	textcolor(CorT);
	textbackground(CorF);
	gotoxy(CI,LI); printf("%c",201);
	gotoxy(CI,LF); printf("%c",200);
	gotoxy(CF,LI); printf("%c",187);
	gotoxy(CF,LF); printf("%c",188);

	for(i=CI+1; i<CF; i++)
	{
		gotoxy(i,LI); printf("%c",205);
		gotoxy(i,LF); printf("%c",205);
	}
	for(i=LI+1; i<LF; i++)
	{
		gotoxy(CI,i); printf("%c",186);
		gotoxy(CF,i); printf("%c",186);
	}
	textcolor(4);
	textbackground(0);
}


 void QuadDireita() {
    int row;
    for (row = 6; row < 19; row++) {
        gotoxy(31, row);
        printf("                                       ");
    }
}



int buscaCodFornecedor(fornecedor Tab[TF], int TL, int Codigo) {
	int i=0;
	while (i<TL && Codigo!=Tab[i].codFornecedor)
			i++;
	if (i<TL)
		return i; // retorna a posicao q foi encontrada
	else
		return -1; // retorna -1 dizendo q n tem o codigo
}

int buscaCodVenda(vendas Tab[TF], int TL, int Codigo) {
	int i=0;
	while (i<TL && Codigo!=Tab[i].codVenda)
			i++;
	if (i<TL)
		return i; // retorna a posicao q foi encontrada
	else
		return -1; // retorna -1 dizendo q n tem o codigo
}

int buscaCodVendaProdutos(vendas_produtos Tab[TF], int TL, int Codigo) {
	int i=0;
	while (i<TL && Codigo!=Tab[i].codVenda)
			i++;
	if (i<TL)
		return i; // retorna a posicao q foi encontrada
	else
		return -1; // retorna -1 dizendo q n tem o codigo
}

int buscaCodCliente(clientes Tab[TF], int TL, char CPF[11]) {
	int i=0;
	while (i<TL && strcmp(Tab[i].cpf,CPF) != 0)
			i++;
	if (i<TL)
		return i;
	else
		return -1;
}

int buscaCodProduto(produtos Tab[TF], int TL, int Codigo) {
	int i=0;
	while (i<TL && Codigo!=Tab[i].codProd)
			i++;
	if (i<TL)
		return i; // retorna a posicao q foi encontrada
	else
		return -1; // retorna -1 dizendo q n tem o codigo
}
 


char Menu(void)
{
	clrscr();
	Moldura(1,1,120,23,15,9);
	Moldura(2,2,119,4,15,9);
	Moldura(2,5,28,19,15,9);
	Moldura(29,5,119,19,15,9);
	Moldura(2,20,119,22,15,9);
	
	
	gotoxy(28,3);
	textcolor(15);
	printf("#    #    #    #    #    S I S T E M A    #    #    #    #    #");
	gotoxy(6,6);
	textcolor(15);
	printf("# # # M E N U # # #");
	gotoxy(5,9);
	textcolor(15);
	printf("[A] FORNECEDOR");
	gotoxy(5,10);
	textcolor(15);
	printf("[B] CLIENTE");
	gotoxy(5,11);
	textcolor(15);
	printf("[C] PRODUTOS");
	gotoxy(5,12);
	textcolor(15);
	printf("[D] VENDAS");
	gotoxy(5,21);
	textcolor(15);
	printf("Opcao: ");
	return toupper(getche());

}





char menuProdutos(void)
{
    QuadDireita();
    int x = 33;

    gotoxy(x, 6);
    printf("# # #  OPCOES PRODUTOS  # # #");
    gotoxy(x, 8);
    printf("[A] CADASTRO");
    gotoxy(x, 9);
    printf("[B] EXCLUSAO");
    gotoxy(x, 10);
    printf("[C] MOSTRAR PRODUTOS");
    gotoxy(x, 11);
    printf("Opcao: ");

    return toupper(getche());
}



char menuFornecedor(void) {
    QuadDireita();
    int x = 33;

    gotoxy(x, 6);
    printf("# # #  OPCOES FORNECEDOR  # # #");
    gotoxy(x, 8);
    printf("[A] CADASTRO");
    gotoxy(x, 9);
    printf("[B] EXCLUSAO");
    gotoxy(x, 10);
    printf("[C] MOSTRAR FORNECEDORES");
    gotoxy(x, 11);
    printf("[D] AUMENTAR PRECO FORNECEDOR");
	gotoxy(5,21);
    printf("Opcao: ");

    return toupper(getche());
} 
                                                
void cadastroFornecedor(fornecedor Tab[TF], int &TL)
{
	QuadDireita();
	
	int AuxCod, pos = -1,x = 33;
	
	gotoxy(x, 6);
	printf("# # #  Cadastro de Fornecedor  # # #");
	gotoxy(x, 8);
	printf("Codigo do fornecedor: ");
	scanf("%d",&AuxCod);
	while (TL<TF && AuxCod>0)
	{
		if(TL!=0)
			pos = buscaCodFornecedor(Tab,TL,AuxCod);
		if (pos == -1)
		{
			gotoxy(x, 8);
			limpa();
			gotoxy(x, 8);
			printf("Codigo do fornecedor: %d ",AuxCod);
			Tab[TL].codFornecedor = AuxCod;
			gotoxy(x, 9);
			limpa();
			gotoxy(x, 9);
			printf("Nome do fornecedor: ");
			fflush(stdin);
			gets(Tab[TL].nomeFornecedor);
			gotoxy(x, 10);
			limpa();
			gotoxy(x, 10);
			printf("Cidade: ");
			fflush(stdin);
			gets(Tab[TL].cidade);
			fflush(stdin);
			TL++;
		}
		else
			{
				gotoxy(x, 9);
				printf("Codigo de Fornecedor ja Cadastrado!");
				getch();
				fflush(stdin);
			}
		gotoxy(x, 11);			
		printf("Digite '0' para sair ou um novo codigo para cadastrar: ");
		scanf("%d",&AuxCod);
		gotoxy(x, 11);
		limpa();
		gotoxy(x, 8);
		limpa();
		
	}
	
}

void exclusaoFornecedor(fornecedor Tab[TF], int &TL) 
{
	
	QuadDireita();
	
	int AuxCod, pos = -1,j,x = 33;
	if(TL>0) {
		gotoxy(x, 6);
		printf("# # #  Exclusao de Fornecedor  # # #");
		gotoxy(x, 8);
		printf("Digite o codigo do fornecedor que deseja excluir: ");
		scanf("%d",&AuxCod);
		while (AuxCod>0) 
		{
			if(TL!=0) {
				pos = buscaCodFornecedor(Tab,TL,AuxCod);
				if (pos != -1)
				{
					for(j=pos;j<TL;j++) {
						Tab[j].codFornecedor = Tab[j+1].codFornecedor;
						strcpy(Tab[j].nomeFornecedor, Tab[j+1].nomeFornecedor);
						strcpy(Tab[j].cidade, Tab[j+1].cidade);
					}
					
					TL--;
				}
				else
					{
						gotoxy(x, 9);
						printf("Codigo nao existe!\n");
						getch();
						fflush(stdin);
					}
			} else {
				gotoxy(x, 9);
				printf("Lista de fornecedores vazia!!");
			}		
			gotoxy(x, 11);		
			printf("Digite 0 para sair ou um novo codigo se deseja excluir mais: ");
			scanf("%d",&AuxCod);
		}
	} else {
		gotoxy(x, 6);
		printf("Lista vazia, faca um cadastro para excluir");
	}
}





void relatorioFornecedor(fornecedor Tab[TF], int &TL) {
	clrscr();
		
	
	QuadDireita();
	molduraextra(1,1,120,80,15,9);
		
	int i,x=33,y=8;
	
	if(TL==0) {
		gotoxy(x,6);
		textbackground(0);
		printf("Nao existe fornecedores, por favor, cadastre um.");
	} else {
		gotoxy(42,3);
		textbackground(0);
		printf("# # #  FORNECEDORES  # # #");
		for(i=0,y=8;i<TL;i++,y++) {
			gotoxy(x,y);
			textbackground(0);
			printf("Nome:%s\tCidade:%s\tCodigo:%d\t", Tab[i].nomeFornecedor, Tab[i].cidade, Tab[i].codFornecedor);
			gotoxy(x,y+2);
			textbackground(0);
//			linha();
		}
	} 
 	getch();
}

void cadastroClientes(clientes Tab[TF], int &TL) {
	
	QuadDireita();
	
	int pos, i=0,x=33;
	char auxCPF[12];
	gotoxy(x, 6);
	printf("# # #  Cadastro de Clientes  # # #");
	gotoxy(x, 8);
	printf("CPF do Cliente(Digite sem os pontos!): ");
	fflush(stdin);
	gets(auxCPF);
	fflush(stdin);
	if(strlen(auxCPF)>0) {
	pos = buscaCodCliente(Tab,TL,auxCPF);
		if (pos == -1)
		{
			fflush(stdin);
			strcpy(Tab[TL].cpf,auxCPF);
			fflush(stdin);
			gotoxy(x, 9);
			printf("Nome do cliente: ");
			fflush(stdin);
			gets(Tab[TL].nomeCliente);
			fflush(stdin);
			Tab[TL].qtdeCompras = 0;
			Tab[TL].valorTotalComprado = 0.00;
			TL++;
		} else {
			gotoxy(x, 9);
			printf("CPF de cliente ja Cadastrado!");
			getch();
			fflush(stdin);
		}
	}		
}


void relatorioClientes(clientes Tab[TF], int &TL) {
	
	QuadDireita();
	
	int i,x=33;
	if(TL==0) {
		gotoxy(x, 6);
		printf("Nao existe clientes, por favor, cadastre um.");
	} else {
		gotoxy(x, 6);
		printf("# # #  CLIENTES  # # #");
		for(i=0;i<TL;i++) {
			gotoxy(x, 8);
			printf("Nome:%s", Tab[i].nomeCliente);
			fflush(stdin);
			printf("\tCPF:%s", Tab[i].cpf);
			fflush(stdin);
			gotoxy(x, 10);
			printf("Qtde Compras: %d\tValor total comprado: %.2f", Tab[i].qtdeCompras, Tab[i].valorTotalComprado);
			getch();
		}
	} 	
	getch();
}

void exclusaoClientes(clientes Tab[TF], int &TL) {
	
	QuadDireita();
	
	int pos = -1,j,x=33;
	char cpf[12];
	if(TL>0) {
		gotoxy(x, 6);
		printf("# # #  Exclusao de Clientes  # # #\n");
		gotoxy(x, 8);
		printf("Digite o cpf do cliente que deseja excluir: ");
		fflush(stdin);
		gets(cpf);
		if(TL!=0) {
			pos = buscaCodCliente(Tab, TL, cpf);
			if (pos != -1)
			{
				for(j=pos;j<TL;j++) {
					strcpy(Tab[j].cpf, Tab[j+1].cpf);
					strcpy(Tab[j].nomeCliente, Tab[j+1].nomeCliente);
					Tab[j].qtdeCompras = Tab[j+1].qtdeCompras;
					Tab[j].valorTotalComprado = Tab[j+1].valorTotalComprado;
				}
				TL--;
			}
			else
				{
					gotoxy(x, 9);
					printf("\nCPF nao existe!\n");
					getch();
					fflush(stdin);
				}
		} else {
			gotoxy(x, 9);
			printf("\nLista de clientes vazia!!\n");
		}
	}
}

void cadastroProdutos(produtos Tab[TF], fornecedor TaBF[TF], int &TL, int TLfornecedor) {
	
	QuadDireita();
	
	int AuxCod, pos = -1, verifyFor= -1,x=33;
	gotoxy(x, 6);
	printf("# # #  Cadastro de Produtos  # # #");
	gotoxy(x, 8);
	printf("Codigo do fornecedor do produto: ");
	scanf("%d",&AuxCod);
	if(TLfornecedor != 0) {
		while(verifyFor==-1) {
			verifyFor = buscaCodFornecedor(TaBF,TLfornecedor,AuxCod);
			if(verifyFor == -1) {
				gotoxy(x, 8);
				printf("Cod invalido, digite novamente.");
				gotoxy(x, 9);
				printf("Codigo: ");
				scanf("%d",&AuxCod);
			}
		}
		if(verifyFor != -1) {
			Tab[TL].codFornecedor = AuxCod;
			gotoxy(x, 9);
			printf("Descricao do produto: ");
			fflush(stdin);
			gets(Tab[TL].descrProd);
			gotoxy(x, 10);
			printf("Codigo do produto: ");
			fflush(stdin);
			scanf("%d", &Tab[TL].codProd);
			gotoxy(x, 11);
			printf("Quantidade em estoque: ");
			fflush(stdin);
			scanf("%d", &Tab[TL].estoque);
			gotoxy(x, 12);
			printf("Preco do produto: ");
			fflush(stdin);
			scanf("%f", &Tab[TL].preco);
			gotoxy(x, 13);
			printf("Data de Validade [dd mm aaaa]: ");
			scanf("%d %d %d",&Tab[TL].DtValidade.Dia, &Tab[TL].DtValidade.Mes, &Tab[TL].DtValidade.Ano);
			TL++;
		}
			
	} else {
		gotoxy(x, 9);
		printf("AINDA NAO EXISTE FORNECEDOR CADASTRADO");
	}
}

void exclusaoProdutos(produtos Tab[TF], int &TL) {
	
	QuadDireita();
	
	int AuxCod, pos = -1,j,x=33;
	if(TL>0) {
		gotoxy(x, 6);
		printf("# # #  Exclusao de Produtos  # # #");
		gotoxy(x, 8);
		printf("Digite o codigo do produto que deseja excluir: ");
		scanf("%d",&AuxCod);
		while (AuxCod>0) 
		{
			if(TL!=0) {
				pos = buscaCodProduto(Tab,TL,AuxCod);
				if (pos != -1)
				{
					for(j=pos;j<TL;j++) {
						Tab[j].codFornecedor = Tab[j+1].codFornecedor;
						strcpy(Tab[j].descrProd, Tab[j+1].descrProd);
						Tab[j].codProd = Tab[j+1].codProd;
						Tab[j].estoque = Tab[j+1].estoque;
						Tab[j].preco = Tab[j+1].preco;
						Tab[j].DtValidade.Dia = Tab[j+1].DtValidade.Dia;
						Tab[j].DtValidade.Mes = Tab[j+1].DtValidade.Mes;
						Tab[j].DtValidade.Ano = Tab[j+1].DtValidade.Ano;
					}
					TL--;
				}
				else
					{
						gotoxy(x, 9);
						printf("Codigo nao existe!");
						getch();
						fflush(stdin);
					}
			} else {
				gotoxy(x, 9);
				printf("Lista de produtos vazia!!");
			}
			gotoxy(x, 11);			
			printf("Digite 0 para sair ou um novo codigo se deseja excluir mais: ");
			scanf("%d",&AuxCod);
		}
	} else {
		gotoxy(x, 6);
		printf("Lista vazia, faca um cadastro para excluir");
	}
}

void relatorioProdutos(produtos Tab[TF], int &TL) {
	
	QuadDireita();
	
	int i,x=33;
	if(TL==0) {
		gotoxy(x, 6);
		printf("Nao existe produtos, por favor, cadastre um.");
	} else {
		gotoxy(x, 6);
		printf("# # # PRODUTOS  # # #");
		for(i=0;i<TL;i++) {
			gotoxy(x, 8);
			limpa();
			gotoxy(x, 8);
			printf("Cod:%d\tDescricao:%s", Tab[i].codProd, Tab[i].descrProd);
			gotoxy(x, 9);
			limpa();
			gotoxy(x, 9);
			printf("Estoque: %d\tPreco: %.2f\tFornecedor: %d", Tab[i].estoque, Tab[i].preco, Tab[i].codFornecedor);
			gotoxy(x, 10);
			limpa();
			gotoxy(x, 10);
			printf("Validade: %d/%d/%d", Tab[i].DtValidade.Dia, Tab[i].DtValidade.Mes, Tab[i].DtValidade.Ano);
			getch();
		}
	} 
	getch();	
}

void venderProdutos(int sequencia, vendas Tab[TFvendas], int &TLvendas, vendas_produtos TabV[TFvendas], int &TLVP, produtos TabP[TF], int TLProduto, clientes TabC[TF], int TLClientes) {
	
	QuadDireita();
	
	int codProduto, posInStructClientes_CPF, posCodInProduto, qntdeProduto, valortotal=0,x=33;
	char CPF[12];
	//digitar o cpf do cliente para entrar
	//em um looping onde as vendas serao realizadas nesse cpf
	if(TLClientes!=0 && TLProduto!=0) {
		gotoxy(x, 6);
		printf("# # # VENDA  # # #");
		gotoxy(x, 8);
		printf("Digite o CPF do cliente que deseja fazer a compra: ");
		fflush(stdin);
		gets(CPF);
		while(strlen(CPF) != 11) {
			gotoxy(x, 9);
			printf("                                               ");
			gotoxy(x, 9);
			printf("CPF invalido, digite novamente: ");
			fflush(stdin);
			gets(CPF);
		}
		posInStructClientes_CPF = buscaCodCliente(TabC, TLClientes, CPF);
		if(posInStructClientes_CPF > -1) {
			
			int continuar = 1;
			int comprasCPF = 0;
			while(continuar == 1) {
				gotoxy(x, 10);
				printf("                                                   ");
				gotoxy(x, 10);
				printf("Digite o codigo do produto que deseja comprar: ");
				fflush(stdin);
				scanf("%d", &codProduto);
				posCodInProduto = buscaCodProduto(TabP, TLProduto, codProduto);
				while(posCodInProduto == -1) {
					gotoxy(x, 11);
					limpa();
					gotoxy(x, 11);
					printf("Nao existe esse codigo, digite outro: ");
					fflush(stdin);
					scanf("%d", &codProduto);
					posCodInProduto = buscaCodProduto(TabP, TLProduto, codProduto);
				}
				TabV[TLVP].codProd = codProduto; //insere
				gotoxy(x, 11);
				printf("                                                           ");
				gotoxy(x, 11);
				printf("Digite a quantidade desse produto que deseja comprar: ");
				scanf("%d", &qntdeProduto);
				while(TabP[posCodInProduto].estoque < qntdeProduto) { //verifica se tem a quantidade
					gotoxy(x, 12);
					printf("Estoque insuficiente digite outro valor: ");
					scanf("%d", &qntdeProduto);
					gotoxy(x, 12);
					printf("                                               ");
				}
				TabV[TLVP].qtde = qntdeProduto; //insere
				TabC[posInStructClientes_CPF].qtdeCompras = TabC[posInStructClientes_CPF].qtdeCompras + qntdeProduto; //adiciona no clientes
				TabP[posCodInProduto].estoque = TabP[posCodInProduto].estoque - qntdeProduto; //desconta o produto
				TabV[TLVP].valorUnitario = TabP[posCodInProduto].preco;
				TabV[TLVP].codVenda = sequencia;
				/*if(comprasCPF > 0)
						TabV[TLVP].codVenda = TabV[TLVP-1].codVenda;
				else
					if(TLVP == 0)
						TabV[TLVP].codVenda = 1;
					else
						TabV[TLVP].codVenda = TabV[TLVP-1].codVenda + 1;*/
				
				valortotal = valortotal + (TabV[TLVP].qtde * TabV[TLVP].valorUnitario);
				comprasCPF++;
				TLVP++;
				gotoxy(x, 15);
				printf("Deseja comprar outro produto neste CPF?('1' - sim // '0' - nao): ");
				scanf("%d", &continuar);
				gotoxy(x, 15);
				limpa();			
			}
			
			//vendas
			strcpy(Tab[TLvendas].cpfCliente, CPF);
 			Tab[TLvendas].totalVendas = valortotal;
			TabC[posInStructClientes_CPF].valorTotalComprado = TabC[posInStructClientes_CPF].valorTotalComprado + valortotal;
			gotoxy(x, 16);
			printf("Data da Venda [dd mm aaaa]: ");
			scanf("%d %d %d",&Tab[TLvendas].dataVenda.Dia, &Tab[TLvendas].dataVenda.Mes, &Tab[TLvendas].dataVenda.Ano);
			if(TLvendas == 0) 
				Tab[TLvendas].codVenda = 1;
			else 
				Tab[TLvendas].codVenda = Tab[TLvendas-1].codVenda + 1;
			TLvendas++;	
					
		} else {
			gotoxy(x, 10);
			printf("Nao existe esse cpf cadastrado.");
		}
	} else {
		gotoxy(x, 6);
			printf("Nao existe clientes ou produtos cadastrados.");
	}
}

void aumentoPrecoFornecedor(fornecedor Tab[TF], int TLF, produtos TabP[TF],int TLP) {
	int i;
	int auxCod;
	float auxAumento;
	int x=33;
	
	
	QuadDireita();
	gotoxy(x, 6);
	printf("# # # AUMENTO DE PRECO POR PORCENTAGEM # # #");
	gotoxy(x, 8);
	printf("Digite o codigo do fornecedor: ");
	scanf("%d", &auxCod);
	if(TLF!=0 && TLP!=0) {
		while(buscaCodFornecedor(Tab, TLF, auxCod) == -1) {
			gotoxy(x, 8);
			limpa();
			gotoxy(x, 8);
			printf("Codigo nao encontrado. Digite novamente: ");
			scanf("%d", &auxCod);
		}
		gotoxy(x, 9);
		printf("Digite a porcentagem que voce quer aumentar: ");
		scanf("%f", &auxAumento);
		for(i=0; i<TLP; i++) {
			if(TabP[i].codFornecedor == auxCod)
				TabP[i].preco = (TabP[i].preco*(auxAumento/100)) + TabP[i].preco;			
		}
	} else {
		gotoxy(x, 9);
		printf("Nao existe nenhum fornecedor/produto ainda.");
	}
}

void relatorioVendas(produtos TabP[TF], int TLP, vendas TabV[TFvendas], int TLV, vendas_produtos TabVP[TFvendas], int TLVP, fornecedor TabF[TF], int TLF) {
	
	QuadDireita();
	
	int i, j, posCodProd, posCodFor,x=33;
	float valorProdutos, valorTotal;
	for(i=0; i<TLV; i++) {
		valorProdutos = 0;
		valorTotal = 0;
		gotoxy(x, 6);
		limpa();
		gotoxy(x, 6);
		printf("Codigo de Venda: %d", TabV[i].codVenda);
		gotoxy(x, 7);
		limpa();
		gotoxy(x, 7);
		printf("Produtos: ");
		for(j=0; j<TLVP; j++) {
			if(TabV[i].codVenda == TabVP[j].codVenda) {
				gotoxy(x, 8);
				printf("%d\t", TabVP[j].codProd);
				posCodProd = buscaCodProduto(TabP, TLP, TabVP[j].codProd);
				printf("%s\t", TabP[posCodProd].descrProd);
				printf("%d\t", TabVP[j].qtde);
				
				valorProdutos = TabVP[j].qtde * TabVP[j].valorUnitario;
				printf("R$%.2f\t", valorProdutos);
				posCodFor = buscaCodFornecedor(TabF, TLF, TabP[posCodProd].codFornecedor);
				printf("%s", TabF[posCodFor].nomeFornecedor);
				
				valorTotal = valorTotal + valorProdutos;
			}
		}
		gotoxy(x, 15);
		printf("Total R$ %.2f\n", valorTotal);
		getch();
	}
	getch();
}

char menuClientes(void)
{
	QuadDireita();
	
	int x=33;
	gotoxy(x, 6);
	printf("# # #  OPCOES CLIENTES  # # #");
	gotoxy(x, 8);
	printf("[A] CADASTRO");
	gotoxy(x, 9);
	printf("[B] EXCLUSAO");
	gotoxy(x, 10);
	printf("[C] MOSTRAR CLIENTES");
	gotoxy(5, 21);
	printf("Opcao: ");
	return toupper(getche());
}

char menuVendas(void)
{
	QuadDireita();
	
	int x=33;
	
	gotoxy(x, 6);
	printf("# # #  OPCOES VENDAS  # # #");
	gotoxy(x, 8);
	printf("[A] VENDER");
	gotoxy(x, 9);
	printf("[B] RELATORIO");
	gotoxy(x, 10);
	printf("[C] EXCLUIR VENDA");
	gotoxy(5, 21);
	printf("Opcao: ");
	return toupper(getche());
}

void excluirVendas(clientes clientes[TF], int &TLC, vendas vendas[TFvendas], int &TLV, vendas_produtos vp[TFvendas], int &TLVP) {
	int posVenda, i, posCliente, auxCod, posVendaProdutos;
	int x=33;
	
	clrscr();
	Moldura(1,1,120,23,15,9);
	Moldura(2,2,119,4,15,9);
	Moldura(2,5,28,19,15,9);
	Moldura(29,5,119,19,15,9);
	Moldura(2,20,119,22,15,9);
	QuadDireita();


	if(TLV != 0) {
		gotoxy(x, 6);
		printf("Digite o codigo de venda que queira excluir: ");
		scanf("%d", &auxCod);
		posVenda = buscaCodVenda(vendas, TLV, auxCod);
		while(posVenda == -1)	{
			gotoxy(x, 6);
			printf("                                                         ");
			gotoxy(x, 6);
			printf("\nCodigo nao encontrado, digite novamente: ");
			scanf("%d", &auxCod);
		}
		posCliente = buscaCodCliente(clientes, TLC, vendas[posVenda].cpfCliente);
		clientes[posCliente].valorTotalComprado = clientes[posCliente].valorTotalComprado - vendas[posVenda].totalVendas;\
		
		for(i=posVenda;i<TLV;i++) {
			vendas[i].codVenda = vendas[i+1].codVenda;
			strcpy(vendas[i].cpfCliente, vendas[i+1].cpfCliente);
			vendas[i].dataVenda = vendas[i+1].dataVenda;
			vendas[i].totalVendas = vendas[i+1].totalVendas;
			TLV--;
		}
		posVendaProdutos = buscaCodVendaProdutos(vp, TLVP, auxCod);
	
		i = posVendaProdutos;
		while(vp[i].codVenda == auxCod) {
			clientes[posCliente].qtdeCompras = clientes[posCliente].qtdeCompras - vp[posVendaProdutos].qtde;
			i++;
		}
		int j;
		int teste = posVendaProdutos;


		for(i=0;i<TLVP;i++)
			if(vp[teste].codVenda != auxCod) {
				for(j=i;j<TLVP;j++) {
					vp[j].codVenda = vp[j+1].codVenda;
					vp[j].codProd = vp[j+1].codProd;
					vp[j].qtde = vp[j+1].qtde;
					vp[j].valorUnitario = vp[j+1].valorUnitario;
					TLVP--;
				}
			}	
	} else {
		gotoxy(x, 6);
		printf("\nNao existe vendas ainda.");
	}
}

int main(void) {
	int sequencia=1;
	char opcao, opcao2;
	struct produtos Produtos[TF];
	struct fornecedor Fornecedor[TF];
	struct clientes Clientes[TF];
	struct vendas Vendas[TFvendas];
	struct vendas_produtos Vendas_produtos[TFvendas];
	
	int TLF=1; //TL dos fornecedores
	int TLC=1; //TL dos clientes
	int TLP=1; //TL dos produtos
	int TLV=0; //TL das vendas
	int TLVP=0; //TL das vendas_produtos
	
	Produtos[0].codFornecedor = 1;
	Produtos[0].codProd = 100;
	strcpy(Produtos[0].descrProd, "Banana");
	Produtos[0].estoque = 20;
	Produtos[0].preco = 2.99;
	
	strcpy(Fornecedor[0].cidade, "Matao");
	Fornecedor[0].codFornecedor = 1;
	strcpy(Fornecedor[0].nomeFornecedor, "Loja");
	
	strcpy(Clientes[0].cpf, "11111111111");
	strcpy(Clientes[0].nomeCliente, "Teste");
	Clientes[0].qtdeCompras = 0;
	Clientes[0].valorTotalComprado = 0.00;
	 
	do
	{
		opcao = Menu();
		switch(opcao)
		{
			case 'A': opcao2 = menuFornecedor();
					  switch(opcao2)
					  {
					  	
					  	case 'A': cadastroFornecedor(Fornecedor, TLF);
					  		break;
					  	case 'B': exclusaoFornecedor(Fornecedor, TLF);
					  		break;
					  	case 'C': clrscr(), relatorioFornecedor(Fornecedor, TLF), getch;
					  		break;
					  	case 'D': aumentoPrecoFornecedor(Fornecedor, TLF, Produtos, TLP);
					  	 	break;
					  }
					  break;
			case 'B': opcao2 = menuClientes();
					  switch(opcao2)
					  {
					  	case 'A': cadastroClientes(Clientes, TLC);
					  		break;
					  	case 'B': exclusaoClientes(Clientes, TLC);
							break;
						case 'C': relatorioClientes(Clientes, TLC);
							break;
					  }
					  break;
			case 'C': opcao2 = menuProdutos();
					  switch(opcao2)
					  {
					  	case 'A': cadastroProdutos(Produtos, Fornecedor, TLP, TLF);
					  		break;
					  	case 'B': exclusaoProdutos(Produtos, TLP);
					  		break;
					  	case 'C': relatorioProdutos(Produtos, TLP);
					  		break;
					  }
					  break;
			case 'D': opcao2 = menuVendas();
					  switch(opcao2)
					  {
					  	case 'A': venderProdutos(sequencia,Vendas, TLV, Vendas_produtos, TLVP, Produtos, TLP, Clientes, TLC);
					  		  sequencia++;
							  break;
					  	case 'B': relatorioVendas(Produtos, TLP, Vendas, TLV, Vendas_produtos, TLVP, Fornecedor, TLF);
					  		break;
					  	case 'C': excluirVendas(Clientes, TLC, Vendas, TLV, Vendas_produtos, TLVP);
							break;				  
					  }
				      break;
		}
	}while(opcao!=27);
		
	return 0;
}
