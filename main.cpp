/**
 
 * File: vectors.cpp
  
 * Developer: Adrian Venegas
  
 * Email:venegasa137168@student.vvc.edu
  
 * Description: Prints out a bank statement of the day,how much you want to put in the bank,and a decription.Then outputs the interest rate and fee if you dont have a minimum balance. 
 
 **/
 
 
#include <iostream>
#include <string>
#include <vector>


class Bank
{
   public:
      Bank();
      void print();
      void get_interest(int day);
      double add_balance(double a);
      double average_daily(double a);
      double min_daily(double a);
      
   private:
      double total_balance;
      double interest_rate;

};

Bank::Bank()

{

   total_balance = 0.0;
   
   interest_rate= 0.5;

}


void Bank::print()

{

   std::cout << "Initial balance is: " << total_balance << std::endl;

}


void Bank::get_interest(int day)

{

   if(day >=30)

   {

      for(int i = 30; i <= day; i++)

      {

         if(!(i % 30))

         {

            total_balance = total_balance * interest_rate;

            std::cout << "Current Balance with interest is: " << total_balance << std::endl;

         }

      }

   }

}


double Bank::add_balance(double a)

{

   total_balance = total_balance + a;

}

double Bank::average_daily(double a)

{

   int day;

   if(day > 30)

   {

      for(int i = 30; i > day; i+30)

      {
        
        
      }

   }

}

double Bank::min_daily(double a = 20) // subtracts 20 

{

   if(total_balance < 200) //if total_balance is less than 200

   {
      total_balance = total_balance - a;     //subtracts 20 dollars if you have less than 200

      std::cout << "Your account has been charged 20 dollars due to having less than 200 dollars in your account." << std::endl;

   }

}


class Transaction

{

   public:
      Transaction();
      void read();
      void print() const; 
      int get_day();
      double get_amount();


   private:

      int day;
      double amount;
      std::string description;

};



Transaction::Transaction()  //deafult to 0

{

   day = 0;  
   amount = 0.0;

}



void Transaction::read()

{

  std::cout << "Day: ";                  //Input/questions
  std::cin >> day; 
  std::cout << "Amount: ";
  std::cin >> amount; 
  std::cout <<"Description: ";
  std::cin.ignore();
  std::getline(std::cin,description);
  
}



void Transaction::print() const

{

   std::cout << "Day: " << day << std::endl;                 ///output
   std::cout << "Amount: " << amount << std::endl;
   std::cout << "Description: " << description << std::endl;

}

int Transaction::get_day()

{

   return day;

}


double Transaction::get_amount()

{

   return amount;

}


void print_transactions(const std::vector<Transaction> t)

{

   for(int i = 0; i < t.size();i++)

      t[i].print();

}



int main()

{

   Bank b;

   

   std::vector<Transaction> transaction;

   bool more = true;

   while(more)

   {

      Transaction t;

      double temp_addtobal = 0.0;

      int day;

      t.read();

      

      temp_addtobal = t.get_amount();

      b.add_balance(temp_addtobal);

      day = t.get_day();

      b.print();

      b.get_interest(day);

      b.min_daily();

      

      transaction.push_back(t);
      std::cout << "Enter another Transaction? y or n" << std::endl;

      char response;
      std::cin >> response;      

      if(response != 'y' && response != 'Y')
         more = false;

    }

    print_transactions(transaction);

    b.print();



return 0;

}
