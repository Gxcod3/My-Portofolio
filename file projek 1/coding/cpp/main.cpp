#include <iostream>

using namespace std;

int pertambahan(int x, int y) {
    return x + y;
}

int pengurangan(int x, int y) {
    return x - y;
}

int perkalian(int x, int y) {
    return x * y;
}

int pembagian(int x, int y) {
    return x / y;
}

void log(int result) {
    cout << "hasilnya adalah " << result << endl;
}

int main() {
    int tambah = pertambahan(5, 20); //25
    int kurang = pengurangan(10, 15); //-5
    int kali = perkalian(2, 4); //8
    int bagi = pembagian(20, 5); //4
    log(tambah);
    log(kurang);
    log(kali);
    log(bagi);
    return 0;
}


