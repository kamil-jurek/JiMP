#include "aghInclude.h"
// --------------------------------------------------------

void showTestResult(int, bool);
// --------------------------------------------------------

int main(void)
{
    cout << "main by kk. Last updated 20.09.2011\n";

    ///////////////////////////////////////////////////////

    int it1[] = {84, 23, 84, 21, 120, 93, -131, 238};
    int it2[] = {249, 24, 82, 3};
    int it3[] = {439, 828, 39, 230, 95, 1, -242, 34};

    aghMatrix<int>* imptr1 = new aghMatrix<int>(2, 4);
    aghMatrix<int>* imptr2 = new aghMatrix<int>(4, 1);
    aghMatrix<int>* imptr3 = new aghMatrix<int>(4, 1);
    aghMatrix<int>* imptr4 = new aghMatrix<int>(2, 4);
    aghMatrix<int> imtest1, imtest2, imtest3;

    imtest1.setItems(4, 1, 249, 24, 82, 3);
    imtest2.setItems(2, 4, 500+23, 851, 123, 251, 215, 94, -373, 272);
    imtest3.setItems(2, 1, 28419, 22084);

    aghMatrix<int>& imref1 = *imptr1;
    aghMatrix<int>& imref2 = *imptr2;
    aghMatrix<int>& imref3 = *imptr3;
    aghMatrix<int>& imref4 = *imptr4;

    imptr1->setItems(it1);
    imptr2->setItems(it2);
    imref3 = imref2;
    imptr4->setItems(it3);


    // 1st test - operator przypisania
    showTestResult(1, imref3 == imtest1);

    // 2nd test - operator przypisania
    try
    {
        imref3 = imref3;

        showTestResult(2, imref3 == imref2);
    }
    catch(...)
    {
        showTestResult(2, false);
    }

    // 3rd test - jawne wywolanie destruktora
    imref2.~aghMatrix();
    try
    {
        showTestResult(3, imref3 != imref2);
    }
    catch(...)
    {
        showTestResult(3, false);
    }

    // 4th test - destruktor
    //try
    //{
     //   delete imptr2;
     //   showTestResult(4, true);
    //}
    //catch(...)
    //{
    //    showTestResult(4, false);
    //}

    // 5th test - kopiowanie wartosci
    showTestResult(5, imref3 == imtest1);

    // 6th test - operator dodawania
    try
    {
        showTestResult(6, (imref1+imref4) == imtest2);


    }
    catch(...)
    {
        showTestResult(6, false);
    }

    return 0;
}
// --------------------------------------------------------

void showTestResult(int _ti, bool _r)
{
    if(_r)
        cout << "Test" << _ti << " PASSED\n";
    else
        cout << "Test" << _ti << " FAILED\n";
}
// ---------------------------------------------------------


