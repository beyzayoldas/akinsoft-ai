#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// �sim ve tarih
// Ali �hsan Dalmi� - 30/10/2024

// Rastgele dizi olu�turma fonksiyonu
void createRandomArray(vector<int>& array, int n) {
    srand(static_cast<unsigned int>(time(0))); // Rastgele say�lar i�in seed
    for (int i = 0; i < n; i++) {
        array[i] = (rand() % 2001) - 1000; // -1000 ile 1000 aras�nda rastgele say�lar
    }
}

// �kili �iftleri bulma fonksiyonu
void findPairs(const vector<int>& array, int n, int k) {
    bool pairFound = false; // En az bir �ift bulunup bulunmad���n� kontrol i�in

    // T�m indis �iftleri �zerinde d�ng�
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((array[i] + array[j]) % k == 0) { // �iftlerin toplam� k'ya tam b�l�n�yorsa
                cout << "(" << i << ", " << j << ")" << endl;
                pairFound = true;
            }
        }
    }

    // �ift bulunmad�ysa ��kt�y� bo� b�rak�r
    if (!pairFound) {
        cout << "Hi�bir �ift bulunamad�." << endl;
    }
}

int main() {
    int n, k;

    // Kullan�c�dan n ve k de�erlerini alma
    cout << "Dizi uzunlu�unu girin (n): ";
    cin >> n;
    cout << "Pozitif bir tam say� girin (k): ";
    cin >> k;

    // K�s�tlar�n kontrol�
    if (n <= 2 || n >= 1000 || k <= 1 || k >= 100) {
        cout << "K�s�t de�erlerine uygun de�il." << endl;
        return 1;
    }

    vector<int> array(n); // n uzunlu�unda bir dizi tan�mlama
    createRandomArray(array, n); // Rastgele diziyi olu�turma

    // �iftleri bulma ve ekrana yazd�rma
    findPairs(array, n, k);

    return 0;
}
