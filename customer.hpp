#ifndef customer_h
#define customer_h

#include<vector>
#include "book.hpp"
#include "person.hpp"

class Customer : public Person
{
  public:
  Customer(std::string = "Klient", std::string = "Ksiegarni", double = 0);
  ~Customer();

  void work(double s) {money += s;};

  void operator +=(double m) {this->set_money(this->get_money() + m);}
  friend std::ostream& operator<< (std::ostream&, Customer&);
  Customer& operator= (Customer &c2);
};

Customer* new_cust(std::vector<std::string*>&, std::vector<std::string*>&);

#endif
