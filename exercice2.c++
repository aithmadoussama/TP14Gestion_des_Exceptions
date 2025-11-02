#include <iostream>
#include <string>
using namespace std;

class StockInsuffisantException : exception
{
public:
    const char *what() const noexcept override
    {
        return "stock insuffisant pour la commande";
    }
};

class Produit
{
public:
    int stock;
    Produit(int s) : stock(s) {}
    void vendre(int v)
    {
        if (v > stock)
        {
            throw StockInsuffisantException();
        }
    }
};

int main(int argc, char const *argv[])
{
    std::cout << "creation d un produit de stock 100" << std::endl;
    std::cout << "vendre 150 de ce produit" << std::endl;
    std::cout << "" << std::endl;
    Produit produit1(100);
    try
    {

        produit1.vendre(150);
    }
    catch (const StockInsuffisantException &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
