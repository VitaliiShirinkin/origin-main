#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    int a1, a2;
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    fin >> a1;

    int* mass1 = new int[a1];
    for (int i = 0; i < a1; ++i)
    {
        fin >> mass1[i];
    }

    fin >> a2;
    fout << a2 << endl;
    int* mass2 = new int[a2];

    for (int y = 0; y < a2; ++y)
    {
        fin >> mass2[y];
    }
    int t = mass2[a2 - 1];
    for (int z = (a2 - 2); z >= 0; --z)
    {
        mass2[z + 1] = mass2[z];
    }
    mass2[0] = t;
    for (int y = 0; y < a2; ++y) {
        fout << mass2[y] << " ";
    }


    fout << endl << a1 << endl;

    int c = mass1[0];
    for (int z = 1; z < a1; ++z)
    {
        mass1[z - 1] = mass1[z];
    }
    mass1[a1 - 1] = c;
    for (int y = 0; y < a1; ++y) {
        fout << mass1[y] << " ";
    }
    delete[] mass1;
    delete[] mass2;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}