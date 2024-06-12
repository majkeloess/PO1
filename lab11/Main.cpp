//Stwórz szablon funkcji mnożącej asynchronicznie (z użyciem std::async()) dwie macierze kwadratowe dowolnych rozmiarów.
//Macierze te są reprezentowane przez wektory wektorów.
//Każdy element macierzy wynikowej jest obliczany w oddzielnym wątku, którego zhaszowany identyfikator jest wypisywany na ekran,
// tak jak to pokazano na wydruku poniżej.
//
//Wskazówka:
//Do zhaszowania identyfikatora wątku użyj poniższych instrukcji:
//std::hash<std::thread::id> hasher;
//long id =hasher(std::this_thread::get_id());

#include "MatMulAsync.h"
#include <complex>
using std::complex;
using namespace std::complex_literals;
int main() {
    // Przykładowe macierze
    std::vector<std::vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> matrix2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // Mnożenie macierzy
    std::vector<std::vector<int>> result_int = multiplyMatrices(matrix1, matrix2);
    // Wyświetlanie wyniku
    std::cout << "Wynik mnożenia macierzy:" << std::endl;
    displayMatrix(result_int);

    std::vector<std::vector<double>> matrix3 = {{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}};
    std::vector<std::vector<double>> matrix4 = {{9.1, 8.1, 7.1}, {6.1, 5.1, 4.1}, {3.1, 2.1, 1.1}};

    // Mnożenie macierzy
    std::vector<std::vector<double>> result_double = multiplyMatrices(matrix3, matrix4);
    // Wyświetlanie wyniku
    std::cout << "Wynik mnożenia macierzy:" << std::endl;
    displayMatrix(result_double);

    std::vector<std::vector<complex<double>>> matrix5 = {{0., -1i}, {1i, 0.}};
    std::vector<std::vector<complex<double>>> matrix6 = {{0., -1i}, {1i, 0.}};;

    // Mnożenie macierzy
    std::vector<std::vector<complex<double>>> result_complex = multiplyMatrices(matrix5, matrix6);
    // Wyświetlanie wyniku
    std::cout << "Wynik mnożenia macierzy:" << std::endl;
    displayMatrix(result_complex);

    return 0;
}

//Wątek -1643678212384661549 oblicza element (0,0)
//Wątek 1362080638672535051 oblicza element (2,1)
//Wątek 3734504096879222707 oblicza element (0,2)
//Wątek 7192468387369268874 oblicza element (2,2)
//Wątek 4615549267549480836 oblicza element (0,1)
//Wątek -5993321486016935974 oblicza element (1,1)
//Wątek 34040437824474923 oblicza element (2,0)
//Wątek 2612129187665001469 oblicza element (1,0)
//Wątek -866191707566161087 oblicza element (1,2)
//Wynik mnożenia macierzy:
//30 24 18
//84 69 54
//138 114 90
//Wątek -1643678212384661549 oblicza element (0,0)
//Wątek 4615549267549480836 oblicza element (0,1)
//Wątek 3734504096879222707 oblicza element (0,2)
//Wątek -1643678212384661549 oblicza element (1,0)
//Wątek 2612129187665001469 oblicza element (1,1)
//Wątek 4615549267549480836 oblicza element (1,2)
//Wątek 3734504096879222707 oblicza element (2,0)
//Wątek -1643678212384661549 oblicza element (2,1)
//Wątek -5993321486016935974 oblicza element (2,2)
//Wynik mnożenia macierzy:
//9.1 8.1 7.1
//6.1 5.1 4.1
//3.1 2.1 1.1
//Wątek -1643678212384661549 oblicza element (0,0)
//Wątek 3734504096879222707 oblicza element (0,1)
//Wątek -1643678212384661549 oblicza element (1,0)
//Wątek 4615549267549480836 oblicza element (1,1)
//Wynik mnożenia macierzy:
//(1,0) (0,0)
//(0,0) (1,0)