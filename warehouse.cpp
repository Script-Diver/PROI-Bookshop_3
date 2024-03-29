#include "warehouse.hpp"
#include "functions.hpp"

Warehouse::Warehouse(std::string n, std::string l, int a): Building(n, l, a)
{
  D(std::cout<<"Tworze magazyn"<<std::endl;)
}

std::ostream& operator << (std::ostream &os, Warehouse &w)
{
  os<<w.name<<"  "<<w.loc<<"  "<<w.area<<std::endl;
  return os;
}

Warehouse::~Warehouse()
{
  D(std::cout<<"Usuwam magazyn"<<std::endl;)
}

void Warehouse::show()
{
  unsigned int i;
  if(bo.empty())
    std::cout<<"Nie ma jeszcze zadnych ksiazek"<<std::endl;
  else
    for(i = 0 ; i < bo.size() ; i++)
      std::cout<<i+1<<". "<<*(bo[i].b)<<"Liczba egzemplarzy: "<<bo[i].n<<std::endl;
}

//cotygodniowe uzupelnianie magazynu
void Warehouse::reset()
{
  unsigned int i;
  for(i = 0 ; i < bo.size() ; i++)
  bo[i].n = 20;
}

//dodawanie pojedynczej ksiazki do magazynu - ma isc w parze z tworzeniem nowej ksiazki
void Warehouse::add(unsigned n, Book *bn)
{
  Bookn boo;
  boo.b = bn;
  boo.n = n;

  if(bo.size() < bo.max_size() && area > bo.size()/factor)
    bo.push_back(boo);
  else
    std::cout<<"Nie mozna juz dodac zadnej ksiazki"<<std::endl;
}

//dodawanie ksiazek do magazynu na poczatku dzialania programu - dodaje wszystkie ksiazki
void Warehouse::add_all(unsigned n, std::vector<Book*> &books)
{
  unsigned i;
  Bookn boo;
  boo.n = n;

  for(i = 0 ; i < books.size() ; i++)
  {
    boo.b = books[i];
    if(bo.size() < bo.max_size() && bo.size() < area/factor)
      bo.push_back(boo);
    else
      break;
  }
}

void Warehouse::delete_b(unsigned n) {  bo.erase(bo.begin()+n);  }

void Warehouse::delete_b()
{
  unsigned n;
  if(bo.size() > 0)
  {
    this->show();
    std::cout<<"Usun: ";
    n = load_n();
    n--;
    n%=bo.size();
    this->delete_b(n);
  }
  else
    std::cout<<"Brak pracownikow do usuniecia"<<std::endl;
}
