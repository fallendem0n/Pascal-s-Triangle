#include <iostream>
#include <vector>
#include <iomanip> // std::setw (��kt�y� g�zelle�tirmek i�in)

using namespace std;

// ��geni ekrana basan yard�mc� fonksiyon
void printTriangle(const vector<vector<int>>& triangle) {
    cout << "\nUretilen Pascal Ucgeni:\n" << endl;

    for (const auto& row : triangle) {
        // Her sat�rdaki elemanlar� gez
        for (int val : row) {
            // her say� i�in 6 karakterlik yer ay�rarak d�zg�n g�r�nmesini sa�la
            cout << setw(6) << val;
        }
        cout << endl; // Sat�r� bitir
    }
}

int main() {
    int numRows;
    cout << "Pascal Ucgeni icin satir sayisini girin: ";
    cin >> numRows;

    // Kullan�c� 0 veya negatif bir say� girerse program� bitir
    if (numRows <= 0) {
        cout << "Gecerli bir satir sayisi girilmedi." << endl;
        return 1;
    }

    // Ana ��geni tutacak d�� vekt�r�m�z
    vector<vector<int>> triangle;

    // 1. D�� D�ng� (Sat�r Olu�turucu): i = 0'dan (numRows-1)'e kadar
    for (int i = 0; i < numRows; i++) {

        // O anki sat�r i�in bir i� vekt�r olu�tur
        // i. sat�rda (i+1) adet eleman bulunur
        vector<int> currentRow;

        // 2. �� D�ng� (Eleman Olu�turucu): j = 0'dan i'ye kadar
        for (int j = 0; j <= i; j++) {

            // 3. Kural Kontrol�
            // Kenar kural�: Sat�r�n ba�� (j==0) veya sonu (j==i) mu?
            if (j == 0 || j == i) {
                currentRow.push_back(1);
            }
            else {
                // �� say� kural�: Bir �nceki sat�ra bak
                // Bir �nceki sat�ra eri� (triangle[i-1])
                // ve [j-1] (sol-�st) ile [j] (sa�-�st) elemanlar�n� topla
                int val = triangle[i - 1][j - 1] + triangle[i - 1][j];
                currentRow.push_back(val);
            }
        }

        // 4. Tamamlanan 'currentRow'u ana 'triangle' vekt�r�ne ekle
        triangle.push_back(currentRow);
    }

    // 5. �retilen ��geni ekrana bas
    printTriangle(triangle);

    return 0;
}
