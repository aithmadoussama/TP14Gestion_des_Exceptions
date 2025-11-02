#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void lireFichier(string nomFichier)
{
    ifstream fichier(nomFichier);
    if (!fichier.is_open())
    {
        throw("Erreur dans la lecture du fichier");
    }
    string l;
    while (getline(fichier, l))
    {
        std::cout << l << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    try
    {
        std::cout << "lecture du fichier ...." << std::endl;
        lireFichier("tes.txt");
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
    
    return 0;
}
