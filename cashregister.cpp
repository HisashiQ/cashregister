#include <iostream>
#include <cmath>

void changeAmount(int &a, int &b);
// int round( int &coins, int &pounds);
double round( double value);

int main()
{
    double price;
    double payment, a;
    int pounds, coins, pennyPrice;
    char y = 'y';
    
    while (y == 'y'){
        std::cout<<"How much is the item?"<<std::endl;
        std::cin>>price;
        
        std::cout<<"How much did the customer pay?"<<std::endl;
        std::cin>>payment;
 
        double change = payment - price;
        
        pennyPrice = price * 100;
        pounds = change;
        a = round(payment) * 100;
        coins = a - pennyPrice;
        std::cout<<"Return: "<<pounds<<" pound(s)"<<std::endl;
        
        changeAmount(coins, pounds);
        
        y = 'n';
        
        std::cout<<"Would you like to re-run the program? (y/n)"<<std::endl;
        std::cin>>y;
    }
}


void changeAmount(int &a, int &b)
{
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    a -= b*100;
    std::cout<<a<<std::endl;
    int fifties = 0;
    int twenties = 0;
    int tens = 0;
    int fives = 0;
    int ones = 0;
    
    while(a > 0){
        if(a - 50 >= 0){
            ++fifties;
            a -= 50;
        } else if (a - 20 >= 0){
            ++twenties;
            a -= 20;
        } else if (a - 10 >= 0){
            ++tens;
            a -= 10;
        } else if (a - 5 >= 0){
            ++fives;
            a -= 5;
        } else if (a - 1 >= 0){
            ++ones;
            a -= 0.1;
        }
    }
    std::cout<<"Return: "<<fifties<<" 50p"<<std::endl;
    std::cout<<"Return: "<<twenties<<" 20p"<<std::endl;
    std::cout<<"Return: "<<tens<<" 10p"<<std::endl;
    std::cout<<"Return: "<<fives<<" 5p"<<std::endl;
    std::cout<<"Return: "<<ones<<" 1p"<<std::endl;
}

double round( double value)
{
    return floor( value*100 + 0.5 )/100;
}