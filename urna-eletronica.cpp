

#include <iostream>
#include <vector>
#include <string>
#include <map>

struct eleitor
{
  std::string primeiroNome;
  int idade;
  int identificador;
  int voto;
};

struct candidato:eleitor
{
  int numero;
  int votosRecebidos;
};

std::vector < eleitor > eleitores;
std::vector < candidato > candidatos;

bool
identificador_existe (int identificador)
{
for (const auto & e:eleitores)
	{
	  if (e.identificador == identificador)
		{
		 return true;}
		 }
for (const auto & c:candidatos)
		 {
		 if (c.identificador == identificador)
		 {
		  return true;}
		  }
		  return false;}

		  void incluir_eleitor ()
		  {
		  eleitor novo_eleitor;
		  std::cout << "digite o primeiro nome do eleitor: ";
		  std::cin >> novo_eleitor.primeiroNome;
		  std::cout << "digite a idade do eleitor: ";
		  std::cin >> novo_eleitor.idade;
		  std::cout << "digite o identificador: ";
		  std::cin >> novo_eleitor.identificador;
		  if (novo_eleitor.identificador < 0
			  || novo_eleitor.identificador > 99999
			  || identificador_existe (novo_eleitor.identificador))
		  {
		  std::cout << "erro em incluir eleitor\n"; return;}

		  eleitores.push_back (novo_eleitor);
		  std::cout << "eleitor adicionado com sucesso!\n";}

		  void incluir_candidato ()
		  {
		  candidato novo_candidato;
		  std::cout << "digite o primeiro nome do candidato: ";
		  std::cin >> novo_candidato.primeiroNome;
		  std::cout << "digite a idade do candidato: ";
		  std::cin >> novo_candidato.idade;
		  std::cout << "digite o identificador: ";
		  std::cin >> novo_candidato.identificador;
		  std::cout << "digite o numero do candidato: ";
		  std::cin >> novo_candidato.numero;
		  if (novo_candidato.identificador < 0
			  || novo_candidato.identificador > 99999
			  || identificador_existe (novo_candidato.identificador))
		  {
		  std::cout << "erro em incluir candidato\n"; return;}

		  candidatos.push_back (novo_candidato);
		  eleitores.push_back (novo_candidato);
		  std::cout << "candidato adicionado com sucesso!\n";}

		  void iniciar_eleicao ()
		  {
std::map < int, int >contagem_votos; for (const auto & e:eleitores)
		  {
		  std::cout << "eleitor: " << e.
		  primeiroNome <<
		  ", vote em um candidato (ou -1 para voto em branco): "; int voto;
		  std::cin >> voto; if (voto >= -1 && voto <= 99999)
		  {
		  if (contagem_votos.find (voto) != contagem_votos.end ())
		  {
		  contagem_votos[voto]++;}
		  else
		  {
		  contagem_votos[voto] = 1;}
		  }
		  else
		  {
		  std::cout << "voto invalido.\n";}
		  }

int vencedor_identificador = -1; int max_votos = 0; for (const auto & par:contagem_votos)
		  {
		  if (par.second > max_votos)
		  {
		   max_votos = par.second; vencedor_identificador = par.first;}
		   else
		   if (par.second == max_votos)
		   {
  for (const auto & c:candidatos)
		   {
		   if (c.identificador == par.first
			   && c.idade < candidatos[vencedor_identificador].idade)
		   {
			vencedor_identificador = par.first;}
			else
			if (c.identificador == par.first
				&& c.idade == candidatos[vencedor_identificador].idade)
			{
			if (c.identificador <
				candidatos[vencedor_identificador].identificador)
			{
			vencedor_identificador = par.first;}
			}
			}
			}
			}

for (const auto & c:candidatos)
			{
			if (c.identificador == vencedor_identificador)
			{
			 std::cout << "o vencedor da eleicao e: " << c.
			 primeiroNome << " (numero " << c.numero << ")\n"; return;}
			 }
			 }

			 int main ()
			 {
			 int comando; while (true)
			 {
			 std::cout << "escolha um comando:\n";
			 std::cout << "1. incluir eleitor\n";
			 std::cout << "2. incluir candidato\n";
			 std::cout << "3. iniciar eleicao\n";
			 std::cin >> comando; switch (comando)
			 {
case 1:
incluir_eleitor (); break; case 2:
incluir_candidato (); break; case 3:
iniciar_eleicao (); return 0; default:
			 std::cout << "opcao invalida\n"; break;}
			 }

			 return 0;}
