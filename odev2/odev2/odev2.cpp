#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

// Author: Ali �hsan Dalmi�, Tarih: 30.10.2024

class MetinDuzenleyici {
private:
    string metin;
    stack<string> islemGecmisi;  // Geri alma i�lemleri i�in y���n

    // G�ncel metni yazd�rma
    void metinYazdir() const {
        cout << "G�ncel Metin: " << metin << endl;
    }

public:
    // 1. Ekleme komutu
    void append(const string& veri) {
        islemGecmisi.push(metin);
        metin += veri;
        metinYazdir();
    }

    // 2. Silme komutu
    void delete_last(int k) {
        if (k > metin.length()) k = metin.length();
        islemGecmisi.push(metin);
        metin.erase(metin.length() - k);
        metinYazdir();
    }

    // 3. Yazd�rma komutu
    void print(int k) const {
        if (k > metin.length()) k = metin.length();
        cout << "�lk " << k << " karakter: " << metin.substr(0, k) << endl;
    }

    // 4. Geri alma komutu
    void undo() {
        if (!islemGecmisi.empty()) {
            metin = islemGecmisi.top();
            islemGecmisi.pop();
            metinYazdir();
        }
        else {
            cout << "Geri al�nacak i�lem yok." << endl;
        }
    }

    // 5. Kaydetme komutu
    void save(const string& dosyaAdi) {
        ofstream dosya(dosyaAdi);
        if (dosya.is_open()) {
            dosya << metin;
            dosya.close();
            cout << "Metin " << dosyaAdi << " dosyas�na kaydedildi." << endl;
        }
        else {
            cout << "Dosya a��lamad�!" << endl;
        }
    }
};

int main() {
    MetinDuzenleyici duzenleyici;
    string komut, param;
    int k;

    cout << "Metin d�zenleyiciye ho� geldiniz! Komutlar: 1, 2, 3, 4, 5" << endl;
    while (true) {
        cout << "Komut girin (1: append, 2: delete, 3: print, 4: undo, 5: save): ";
        cin >> komut;

        if (komut == "1") {  // Ekleme komutu
            cin.ignore();
            getline(cin, param);
            duzenleyici.append(param);
        }
        else if (komut == "2") {  // Silme komutu
            cin >> k;
            duzenleyici.delete_last(k);
        }
        else if (komut == "3") {  // Yazd�rma komutu
            cin >> k;
            duzenleyici.print(k);
        }
        else if (komut == "4") {  // Geri alma komutu
            duzenleyici.undo();
        }
        else if (komut == "5") {  // Kaydetme komutu
            cin >> param;
            duzenleyici.save(param);
            break;
        }
        else {
            cout << "Ge�ersiz komut. L�tfen tekrar deneyin." << endl;
        }
    }

    return 0;
}
