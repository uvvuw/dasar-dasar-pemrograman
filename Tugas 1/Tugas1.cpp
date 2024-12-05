#include <iostream>
using namespace std;

int main()
{
    int angka_tebak;
    int angka_benar = 8;
    string nama, nim;
    bool loginsucces = false;

    while (!loginsucces)
    {
        cout << "Selamat Datang Di Game Tebak angka" << endl;
        cout << "Silahkan Login Terlebih Dahulu" << endl;

        cout << "Masukkan Nama dan NIM" << endl;
        cout << "Masukkan Nama : ";
        cin >> nama;
        cout << "Masukkan NIM : ";
        cin >> nim;
        if (nama == "rara" && nim == "151")
        {
            loginsucces = true;
            do
            {
                cout << "Tebak Angka (1-10) : ";
                cin >> angka_tebak;

                if (angka_tebak > angka_benar)
                {
                    cout << "Angka terlalu besar" << endl;
                }
                else if (angka_tebak < angka_benar)
                {
                    cout << "Angka terlalu kecil" << endl;
                }
                else
                {
                    cout << "Selamat Anda benar, angkanya adalah " << angka_benar << endl;
                    break;
                }

            } while (angka_tebak != angka_benar);
        }
        else if (nama != "rara" && nim != "151")
        {
            cout << "Login gagal. Nama atau NIM salah" << endl;
        }
    }
}
