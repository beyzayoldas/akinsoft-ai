#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// Author : Ali �hsan Dalmi� 30.10.2024

// Metin dosyas�n� oku ve bo�luklar� kald�rarak metni d�nd�r
wstring read_and_clean_text(const string& filename) {
    wifstream file(filename);
    file.imbue(locale(locale(), new codecvt_utf8<wchar_t>)); // UTF-8 olarak oku
    wstring word, text;

    if (!file) {
        wcerr << L"Dosya a��lamad�!" << endl;
        return L"";
    }

    while (file >> word) {
        text += word;
    }
    file.close();
    return text;
}

// Matris boyutlar�n� hesapla
void calculate_matrix_dimensions(int length, int& m, int& n) {
    int root = sqrt(length);
    m = root;
    n = (root * root == length) ? root : root + 1;
    if (m * n < length) m++;
}

// Metni m x n matrisine d�n��t�r ve ekrana yazd�r
void print_text_matrix(const wstring& text, int m, int n) {
    vector<vector<wchar_t>> matrix(m, vector<wchar_t>(n, L' '));
    int index = 0;

    for (int i = 0; i < m && index < text.size(); ++i) {
        for (int j = 0; j < n && index < text.size(); ++j) {
            matrix[i][j] = text[index++];
        }
    }

    for (const auto& row : matrix) {
        for (wchar_t ch : row) {
            wcout << ch;
        }
        wcout << endl;
    }
}

int main() {
    // Konsolu UTF-8 i�in ayarla
    locale::global(locale("en_US.UTF-8"));
    wcout.imbue(locale());

    string filename = "metin.txt";
    wstring text = read_and_clean_text(filename);

    if (text.empty()) {
        return 1; // Dosya a��lamad�ysa veya bo�sa program sonlan�r
    }

    int length = text.size();
    int m, n;
    calculate_matrix_dimensions(length, m, n);

    wcout << L"m: " << m << L", n: " << n << endl;
    print_text_matrix(text, m, n);

    return 0;
}
