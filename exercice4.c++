#include <iostream>
#include <string>
using namespace std;

class MontantInvalideException : exception
{
public:
    const char *what() const noexcept override
    {
        return "Mantant invalide.";
    }
};
class SoldeInsuffisantException : exception
{
public:
    const char *what() const noexcept override
    {
        return "Solde insuffisant.";
    }
};

class Compte
{
public:
    int montant;
    Compte(int m) : montant(m) {}

    void deposer(int m)
    {
        if (m < 0)
        {
            throw MontantInvalideException();
        }
        montant += m;
    }

    void retirer(int m)
    {
        if (m < 0)
        {
            throw MontantInvalideException();
        }
        if (m > montant)
        {
            throw SoldeInsuffisantException();
        }
        montant -= m;
    }
};

int main(int argc, char const *argv[])
{
    Compte compte(1000);
    try
    {
        compte.retirer(3000);
    }
    catch (const MontantInvalideException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const SoldeInsuffisantException &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
