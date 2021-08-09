#include "Bank.h"

std::string Bank::createIban()
{
	//trebuie exists ca sa fie un iban unic
	std::string iban = "123";
	return iban;
}

Bank::Bank()
{
}

Bank::~Bank()
{
	m_ConturiBancare.clear();
}

void Bank::adaugareCont()
{
	system("CLS");
	std::cout << "Introduceti numele utilizatorului: " << std::endl;
	std::string nume;
	std::cin >> nume;
	std::cout << "Introduceti Prenumele uitilizatorului: " << std::endl;
	std::string prenume;
	std::cin >> prenume;
	std::string iban = createIban();
	ContBancar* cont = new ContBancar(nume, prenume, iban);
	m_ConturiBancare.push_back(cont);
	std::cout <<"1 -> pentru crearea a unui cont\n";
	std::cout <<"2 -> pentru meniul principal\n";
	char optiune;
	std::cin >> optiune;
	switch (optiune)
	{
	case '1':
		adaugareCont();
		break;
	default:
		break;
	}

}
void Bank::vizualizareConturi()
{
	std::cout << "Numarul de conturi in banca este: " << m_ConturiBancare.size() << std::endl;
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		std::cout << "Contul " << i+1 << " " << m_ConturiBancare[i]->getNume();
	}

}

void Bank::modificareCont()
{
	system("CLS");
	//intrebati operatorul care cont doreste sa il modifice
	std::cout << "Introduceti numele si prenumele contului\n";
	std::cout << "Intorduceti numele de famile\n";
	std::string nume;
	std::cin >> nume;
	std::cout << "Intorduceti prenumele\n";
	std::string prenume;
	std::cin >> prenume;

	ContBancar* temp = nullptr;
	//cautam contul
	int foundIndex = 0;
	//for (int i = 0; i < m_ConturiBancare.size(); i++)
	//{
	//	if (nume == m_ConturiBancare[i]->getNume() && prenume == m_ConturiBancare[i]->getPrenume())
	//	{
	//		temp = m_ConturiBancare[i];
	//		foundIndex = i;
	//		break;
	//	}

	//}
	std::vector<ContBancar*>::iterator it;

	for (it  = m_ConturiBancare.begin(); it != m_ConturiBancare.end(); it++)
	{
		if (nume == (*it)->getNume() && prenume == (*it)->getPrenume())
		{
			temp = *it;
			break;
		}
	}

	//in cazul in care nu avem un cont gasit
	if (temp == nullptr)
	{
		std::cout << "Contul nu a fost gasit\n";
		std::cout << "1-> intorcere la meniu principal\n";
		std::cout << "2-> creati un cont\n";
		std::cout << "3-> cautati un alt cont\n";
		char optiune;
		std::cin >> optiune;
		switch (optiune)
		{
		case '1':
			std::cout << "Going back\n";
			break;
		case '2':
			adaugareCont();
			break;
		case '3':
			modificareCont();
			break;
		default:
			break;
		}

	}
	else
	{
		std::cout << "Ce modificari vreti sa faceti?\n";
		std::cout << "1->Pternu stergere cont\n";
		m_ConturiBancare.erase(it);
		/*1 modificati nume
		2 modificati prentume4
		3 modifacti etc
		6 stergeti contul gasit*/
	}



	//cautati contul

			// - daca exista intrebam ce modificari facem?
			// - daca nu exista spunem ca nu exista si dam urmatoarle optiunui:
				// return to maine
				// creati un cont
				// cautati alt cont


}
