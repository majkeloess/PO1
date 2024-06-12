#ifndef MATMULASYNC_H
#define MATMULASYNC_H

#include <iostream>
#include <vector>
#include <future>



//Funkcja uzywana do obliczania iloczynu macierzy z wykorzystaniem biblioteki future, zwraca wynik mnozenie macierzy
template <typename T>
std::vector<std::vector<T>> multiplyMatrices(const std::vector<std::vector<T>>& vec1, const std::vector<std::vector<T>>& vec2) {
    
    
    size_t size = vec1.size();

    //Wektor wynikowy mnozenia macierzy 
    std::vector<std::vector<T>> result(size, std::vector<T>(size, 0));


    //Wyrazenie lambda sluzace do wypisania watku oraz policzenia jednego elementu macierzy
    auto el = [&](size_t r, size_t c) {
        T sum = 0;
        for (size_t i = 0; i < size; ++i) {
            sum += vec1[r][i] * vec2[i][c];
        }

        //Hasher sluzacy do hashowania id watku i wypisaniu go na glowny strumien
        std::hash<std::thread::id> hasher;
        long id = hasher(std::this_thread::get_id());
        std::cout << "Wątek " << id << ", (" << r << "," << c << ")\n";


        return sum;
    };

    std::vector<std::future<T>> futures(size * size);


    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            futures[i * size + j] = std::async(std::launch::async, el, i, j);
        }
    }


    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            result[i][j] = futures[i * size + j].get();
        }
    }

    return result;
}

//Funkcja typu void sluzaca do wypisywania macierzy
template <typename T>
void displayMatrix(const std::vector<std::vector<T>>& vec) {
    for (const auto& row : vec) {
        for (T element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

#endif