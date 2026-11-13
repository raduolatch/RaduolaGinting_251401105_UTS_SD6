#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int arr[2][3][4];
    int hasil[3][4];

    int k6 = 6;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            arr[0][i][j] = k6;
            k6 += 6;
        }
    }
    
    int k3 = 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            arr[1][i][j] = k3;
            k3 += 3;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            hasil[i][j] = arr[0][i][j] + arr[1][i][j];
        }
    }

    for (int l = 0; l < 2; l++) {
        cout << "Layer " << l + 1 << ":\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                cout << setw(5) << arr[l][i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "Hasil Penjumlahan (3x4):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setw(5) << hasil[i][j];
        }
        cout << endl;
    }

    return 0;
}