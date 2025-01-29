#include <iostream>
#include <vector>
#include <random>
#include <ctime>

int main() {
    // Ad ve tarih bilgisi
    std::cout << "Ad: Ali Ihsan Dalmis, Tarih: 30/10/2024\n";

    // Rastgele say� �retici
    std::random_device rd;
    std::mt19937 gen(rd());

    // Mevcut konum, hedef ve ziyaret edilen noktalar dizisi
    int mevcut_konum = 0;
    std::vector<int> ziyaret_edilenler = { mevcut_konum };

    // 10 ad�m gezinti
    while (ziyaret_edilenler.size() < 10) {
        std::uniform_int_distribution<int> dist(0, 20);
        int hedef_konum = dist(gen);

        // Mesafe kontrol� ve ziyaret edilmemi�lik kontrol�
        if (std::abs(hedef_konum - mevcut_konum) >= 5 &&
            std::find(ziyaret_edilenler.begin(), ziyaret_edilenler.end(), hedef_konum) == ziyaret_edilenler.end()) {

            ziyaret_edilenler.push_back(hedef_konum);
            mevcut_konum = hedef_konum;
        }
    }

    // Gezinti noktalar�n� ekrana yazd�r
    std::cout << "Mini Ada'n�n ziyaret etti�i noktalar: ";
    for (int nokta : ziyaret_edilenler) {
        std::cout << nokta << " ";
    }
    std::cout << std::endl;

    return 0;
}
