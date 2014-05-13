#ifndef EX2SZABLON_H
#define EX2SZABLON_H
//---------------------------------------------

//#include <iostream>
#include <cstdarg>
//---------------------------------------------

using namespace std;
//---------------------------------------------

template<class T>
class aghMatrix
{
  private:
    T** tab;
    int c;
	int r;

    // Metoda rozszerzajaca rozmiar tablicy do rozmiaru podanego jako parametr
    void resize(int newR, int newC)
    {
        T** newTab = new T*[newR];
        for (int i = 0; i < newR; ++i)
		{
  	 		newTab[i] = new T[newC];
		}

		for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                newTab[i][j] = tab[i][j];
            }
        }

        for (int i = 0; i < r; i++)
		{
	    	delete tab[i];
		}
		delete tab;

        tab = newTab;
        r = newR;
        c = newC;
    }

  public:
	aghMatrix()
	{
		c = 1;
		r = 1;

		tab = new T*[r];
		for (int i = 0; i < r; ++i)
		{
  	 		tab[i] = new T[c];
		}

		for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                tab[i][j] = 0;
            }
        }
	}


	aghMatrix(int _r, int _c)
	{
		tab = new T*[_r];
		for (int i = 0; i < _r; ++i)
		{
  	 		tab[i] = new T[_c];
		}

		for(int i = 0; i < _r; i++)
        {
            for(int j = 0; j < _c; j++)
            {
                tab[i][j] = 0;
            }
        }

        r = _r;
        c = _c;
	}

	~aghMatrix()
	{
		for (int i = 0; i < r; ++i)
		{
	    	delete tab[i];
		}
		delete tab;
	}

	void setItem(int _r, int _c, T val)
	{
		tab[_r][_c] = val;
	}

	void setItems(T tabVal[])
	{
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                tab[i][j] = tabVal[i*c+j];
            }
            cout << endl;
        }
	}

	void setItems(int _r, int _c, ...)
	{
	    va_list argumenty;

        resize(_r, _c);

	    va_start(argumenty, _c);
	    for(int i = 0; i < _r; i++)
        {
            for(int j = 0; j < _c; j++)
            {
                tab[i][j] = va_arg(argumenty, T);
            }
        }

        va_end(argumenty);
	}

	void print()
	{
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                cout.width(5);
                cout << tab[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl <<endl;
	}


	aghMatrix& operator=(const aghMatrix& macierz)
    {
       T** newTab = new T*[macierz.r];
        for (int i = 0; i < macierz.r; ++i)
		{
  	 		newTab[i] = new T[macierz.c];
		}

		for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                newTab[i][j] = macierz.tab[i][j];
            }
        }

        for (int i = 0; i < r; i++)
		{
	    	delete tab[i];
		}
		delete tab;

        tab = newTab;
        r = macierz.r;
        c = macierz.c;

        return *this;
    }

    bool operator==(const aghMatrix& macierz)
    {
        for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    if(tab[i][j] != macierz.tab[i][j])
                    {
                        return false;
                    };
                }
            }
            return true;
    }

    bool operator!=(const aghMatrix& macierz)
    {
        for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    if(tab[i][j] != macierz.tab[i][j])
                    {
                        return true;
                    };
                }
            }
            return false;
    }

    aghMatrix& operator+(const aghMatrix& macierz)
    {
        aghMatrix<T>* ptr = new aghMatrix<T>(r, c);
        for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    ptr->tab[i][j] = tab[i][j] + macierz.tab[i][j];
                }
            }
        return *ptr ;
    }
};



#endif // EX2SZABLON_H
