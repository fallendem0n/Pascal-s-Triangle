#include <iostream>
#include <vector>
#include <iomanip> // std::setw (çýktýyý güzelleþtirmek için)

using namespace std;

// Üçgeni ekrana basan yardýmcý fonksiyon
void printTriangle(const vector<vector<int>>& triangle) {
    cout << "\nUretilen Pascal Ucgeni:\n" << endl;

    for (const auto& row : triangle) {
        // Her satýrdaki elemanlarý gez
        for (int val : row) {
            // her sayý için 6 karakterlik yer ayýrarak düzgün görünmesini saðla
            cout << setw(6) << val;
        }
        cout << endl; // Satýrý bitir
    }
}

int main() {
    int numRows;
    cout << "Pascal Ucgeni icin satir sayisini girin: ";
    cin >> numRows;

    // Kullanýcý 0 veya negatif bir sayý girerse programý bitir
    if (numRows <= 0) {
        cout << "Gecerli bir satir sayisi girilmedi." << endl;
        return 1;
    }

    // Ana üçgeni tutacak dýþ vektörümüz
    vector<vector<int>> triangle;

    // 1. Dýþ Döngü (Satýr Oluþturucu): i = 0'dan (numRows-1)'e kadar
    for (int i = 0; i < numRows; i++) {

        // O anki satýr için bir iç vektör oluþtur
        // i. satýrda (i+1) adet eleman bulunur
        vector<int> currentRow;

        // 2. Ýç Döngü (Eleman Oluþturucu): j = 0'dan i'ye kadar
        for (int j = 0; j <= i; j++) {

            // 3. Kural Kontrolü
            // Kenar kuralý: Satýrýn baþý (j==0) veya sonu (j==i) mu?
            if (j == 0 || j == i) {
                currentRow.push_back(1);
            }
            else {
                // Ýç sayý kuralý: Bir önceki satýra bak
                // Bir önceki satýra eriþ (triangle[i-1])
                // ve [j-1] (sol-üst) ile [j] (sað-üst) elemanlarýný topla
                int val = triangle[i - 1][j - 1] + triangle[i - 1][j];
                currentRow.push_back(val);
            }
        }

        // 4. Tamamlanan 'currentRow'u ana 'triangle' vektörüne ekle
        triangle.push_back(currentRow);
    }

    // 5. Üretilen üçgeni ekrana bas
    printTriangle(triangle);

    return 0;
}
