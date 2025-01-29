#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Ýsim ve tarih
// Ali Ýhsan Dalmiþ - 30/10/2024

// Rastgele dizi oluþturma fonksiyonu
void createRandomArray(vector<int>& array, int n) {
    srand(static_cast<unsigned int>(time(0))); // Rastgele sayýlar için seed
    for (int i = 0; i < n; i++) {
        array[i] = (rand() % 2001) - 1000; // -1000 ile 1000 arasýnda rastgele sayýlar
    }
}

// Ýkili çiftleri bulma fonksiyonu
void findPairs(const vector<int>& array, int n, int k) {
    bool pairFound = false; // En az bir çift bulunup bulunmadýðýný kontrol için

    // Tüm indis çiftleri üzerinde döngü
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((array[i] + array[j]) % k == 0) { // Çiftlerin toplamý k'ya tam bölünüyorsa
                cout << "(" << i << ", " << j << ")" << endl;
                pairFound = true;
            }
        }
    }

    // Çift bulunmadýysa çýktýyý boþ býrakýr
    if (!pairFound) {
        cout << "Hiçbir çift bulunamadý." << endl;
    }
}

int main() {
    int n, k;

    // Kullanýcýdan n ve k deðerlerini alma
    cout << "Dizi uzunluðunu girin (n): ";
    cin >> n;
    cout << "Pozitif bir tam sayý girin (k): ";
    cin >> k;

    // Kýsýtlarýn kontrolü
    if (n <= 2 || n >= 1000 || k <= 1 || k >= 100) {
        cout << "Kýsýt deðerlerine uygun deðil." << endl;
        return 1;
    }

    vector<int> array(n); // n uzunluðunda bir dizi tanýmlama
    createRandomArray(array, n); // Rastgele diziyi oluþturma

    // Çiftleri bulma ve ekrana yazdýrma
    findPairs(array, n, k);

    return 0;
}
