#include <iostream>
#include <string>

void gambarPersegiPanjang(int panjang, int lebar) {
    for (int i = 0; i < lebar; ++i) {
        std::string baris = "";  // Menyimpan baris yang akan dihasilkan
        for (int j = 0; j < panjang; ++j) {
            baris += "* ";
        }
        baris += "\n";
        std::cout << baris;
    }
}

int main() {
    // Meminta input dari pengguna untuk panjang dan lebar persegi panjang
    int panjangPersegi, lebarPersegi;
    std::cout << "Masukkan panjang persegi panjang: ";
    std::cin >> panjangPersegi;
    std::cout << "Masukkan lebar persegi panjang: ";
    std::cin >> lebarPersegi;

    // Memanggil fungsi untuk menggambar persegi panjang
    gambarPersegiPanjang(panjangPersegi, lebarPersegi);

    return 0;
}


std::string gambarPersegiPanjangRekursif(int panjang, int lebar, int currentLebar,std::string baris) {

    if (currentLebar == lebar-1) {
        return baris;
    } else {
        std::string baris = "";
        for (int j = 0; j < panjang; ++j) {
            baris += "* ";
        }
        baris += "\n";


        return baris + gambarPersegiPanjangRekursif(panjang, lebar, currentLebar + 1,baris);
    }
}

int main() {

    int panjangPersegi, lebarPersegi;
    std::cout << "Masukkan panjang persegi panjang: ";
    std::cin >> panjangPersegi;
    std::cout << "Masukkan lebar persegi panjang: ";
    std::cin >> lebarPersegi;


    std::cout << gambarPersegiPanjangRekursif(panjangPersegi, lebarPersegi, 0,"");

����return�0;
}


//2 phy

def count_unique_elements_naive(arr):
    unique_elements = []
    for elem in arr:
        if elem not in unique_elements:
            unique_elements.append(elem)
    return len(unique_elements)
//vs
def count_unique_elements_set(arr):
    unique_elements_set = set(arr)
    return len(unique_elements_set)

//3 phy

def linear_sum(arr):
    sum = 0
    for element in arr:
        sum += element
    return sum
//vs
def divide_and_conquer_sum(arr):
    if len(arr) == 1:
        return arr[0]
    else:
        mid = len(arr) // 2
        left_sum = divide_and_conquer_sum(arr[:mid])
        right_sum = divide_and_conquer_sum(arr[mid:])
        return left_sum + right_sum
