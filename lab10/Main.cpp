#include <iostream>
#include <algorithm>

//Zrobilem to wszystko w jednym pliku .cpp, poniewaz jak robilem w plikach .h i .cpp gdy robilem template i tworzylem funkcje lambda to cos sie nie dolaczalo a przy lambdach mi wyskakiwalo cos ze podwojna deklaracja, oczywiscie przeze mnie bo robilem to w zly sposob

//Kompilowalem to jako zwykly plik cpp: g++ -o Main Main.cpp


//funkcja swap
auto swap = [](auto& a, auto& b) {
    auto temp = a;
    a = b;
    b = temp;
};


//LOMUTO NIE DZIALA DAJE MI SEGMENTATION FAULTA
//lomutoPartition
// auto lomutoPartition = [](auto arr, int p, int r) {
//     auto x = arr[r];
//     int i = p - 1;
//     for (int j = p; j <= r - 1; j++) {
//         if (arr[j] < x) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[r]);
//     return i + 1;
// };
auto lomutoPartition = [](auto arr, int p, int r) {
    auto x = arr[p];
    int i = p - 1, j = r + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < x);
        do {
            j--;
        } while (arr[j] > x);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
};

//hoare partition
auto hoarePartition = [](auto arr, int p, int r) {
    auto x = arr[p];
    int i = p - 1, j = r + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < x);
        do {
            j--;
        } while (arr[j] > x);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
};


//funkcja rekurencyjna QuickSort, przyjmujaca tablice kazdego typu
template<typename T, typename Partition>
void QuickSort(T arr[], int p, int r, Partition partition) {
    if (p < r) {
        int q = partition(arr, p, r);
        QuickSort(arr, p, q, partition);
        QuickSort(arr, q + 1, r, partition);
    }
}

//printowanie tablic kazdego typu
template<typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int tab1[] = {8, 7, 5, 3, 2, 6, 1, 4, 9};
    int tab2[9];
    std::copy(&tab1[0], &tab1[0] + 9, &tab2[0]);
    double tab3[] = {2.3, 1.4, 6.5, 0.3, 1.1};
    double tab4[5];
    std::copy(&tab3[0], &tab3[0] + 5, &tab4[0]);

    std::cout << "QuickSort tablicy int z partycjonowaniem Lomuto:\n";
    std::cout << "Przed: "; printArray(tab1, 9); std::cout << std::endl;
    QuickSort(tab1, 0, 8, lomutoPartition);
    std::cout << "Po: "; printArray(tab1, 9); std::cout << std::endl;
    
    std::cout << "QuickSort tablicy int z partycjonowaniem Hoare:\n";
    std::cout << "Przed: "; printArray(tab2, 9); std::cout << std::endl;
    QuickSort(tab2, 0, 8, hoarePartition);
    std::cout << "Po: "; printArray(tab2, 9); std::cout << std::endl;

    std::cout << "QuickSort tablicy double z partycjonowaniem Lomuto:\n";
    std::cout << "Przed: "; printArray(tab3, 5); std::cout << std::endl;
    QuickSort(tab3, 0, 4, lomutoPartition);
    std::cout << "Po: "; printArray(tab3, 5); std::cout << std::endl;
    
    std::cout << "QuickSort tablicy double z partycjonowaniem Hoare:\n";
    std::cout << "Przed: "; printArray(tab4, 5); std::cout << std::endl;
    QuickSort(tab4, 0, 4, hoarePartition);
    std::cout << "Po: "; printArray(tab4, 5); std::cout << std::endl;

    return 0;
}
