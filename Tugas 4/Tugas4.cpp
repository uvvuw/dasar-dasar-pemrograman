#include <iostream>
#include <string>
using namespace std;

struct Penulis
{
    string nama_pengarang;
};

struct Buku
{
    int id_buku;
    string judul_buku;
    Penulis Pengarang;
    int harga;
};

// Menu tambah buku
void tambahBuku(Buku list_buku[], int &jumlah_buku, int max_buku)
{
    int n;
    cout << "Masukkan jumlah buku yang ingin diinput: ";
    cin >> n;
    cin.ignore();

    if (jumlah_buku + n > max_buku)
    {
        cout << "Kapasitas maksimum tercapai. Tidak dapat menambahkan buku lebih banyak.\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        Buku buku;
        cout << "\nMasukkan ID buku: ";
        cin >> buku.id_buku;
        cin.ignore();

        cout << "Judul Buku: ";
        getline(cin, buku.judul_buku);

        cout << "Nama Pengarang: ";
        getline(cin, buku.Pengarang.nama_pengarang);

        cout << "Harga: ";
        cin >> buku.harga;
        cin.ignore();

        list_buku[jumlah_buku++] = buku;
        cout << "Buku berhasil ditambahkan.\n";
    }
}

// Menu tampilkan daftar buku
void tampilkanDaftarBuku(const Buku list_buku[], int jumlah_buku)
{
    cout << "\nDaftar Buku: " << endl;
    for (int i = 0; i < jumlah_buku; i++)
    {
        cout << "ID Buku: " << list_buku[i].id_buku << endl;
        cout << "Judul: " << list_buku[i].judul_buku << endl;
        cout << "Pengarang: " << list_buku[i].Pengarang.nama_pengarang << endl;
        cout << "Harga:" << list_buku[i].harga << endl;
        cout << " " << endl;
    }
}

// Menu ubah buku
void ubahBuku(Buku list_buku[], int jumlah_buku)
{
    int id;
    cout << "\nMasukkan ID buku yang ingin diubah: ";
    cin >> id;
    cin.ignore();

    for (int i = 0; i < jumlah_buku; i++)
    {
        if (list_buku[i].id_buku == id)
        {
            cout << "Judul Baru: ";
            getline(cin, list_buku[i].judul_buku);

            cout << "Nama Pengarang Baru: ";
            getline(cin, list_buku[i].Pengarang.nama_pengarang);

            cout << "Harga Baru: ";
            cin >> list_buku[i].harga;
            cin.ignore();

            cout << "Data buku berhasil diperbaharui.\n";
            return;
        }
    }
    cout << "Buku dengan ID tersebut tidak ditemukan.\n";
}

// Menu hapus buku
void hapusBuku(Buku list_buku[], int &jumlah_buku)
{
    int id;
    cout << "\nMasukkan ID buku yang ingin dihapus: ";
    cin >> id;
    cin.ignore();

    for (int i = 0; i < jumlah_buku; i++)
    {
        if (list_buku[i].id_buku == id)
        {
            for (int j = i; j < jumlah_buku - 1; j++)
            {
                list_buku[j] = list_buku[j + 1];
            }
            jumlah_buku--;
            cout << "Buku berhasil dihapus.\n";
            return;
        }
    }
    cout << "Buku dengan ID tersebut tidak ditemukan.\n";
}

// Menu total harga pembelian dengan diskon
void hitungTotalHarga(const Buku list_buku[], int jumlah_buku)
{
    int pengarang[100] = {0};
    int total_harga = 0;
    int id;
    string voucher;
    bool diskon_pengarang = false;

    cout << "\nMasukkan jumlah buku yang ingin dibeli: ";
    cin >> jumlah_buku;
    cin.ignore();

    cout << "\nMasukkan ID Buku yang Ingin Dibeli  (0 untuk berhenti)";
    while (true)
    {
        cout << "ID Buku: ";
        cin >> id;

        if (id == 0)
            break;

        bool ditemukan = false;
        for (int i = 0; i < jumlah_buku; i++)
        {
            if (list_buku[i].id_buku == id)
            {
                total_harga += list_buku[i].harga;
                pengarang[i]++;
                if (pengarang[i] >= 2)
                {
                    diskon_pengarang = true;
                }
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan)
        {
            cout << "Buku dengan ID tersebut tidak ditemukan.\n";
        }
    }

    // Diskon 5% jika terdapat 2 atau lebih buku dari penulis yang sama
    if (diskon_pengarang)
    {
        total_harga *= 0.95; // Diskon 5%
    }

    // Diskon tambahan 10% jika menggunakan kode voucher
    cout << "Masukkan kode voucher (kosongkan jika tidak ada): ";
    cin.ignore();
    getline(cin, voucher);
    if (voucher == "JPYUM")
    {
        total_harga *= 0.90; // Diskon 10%
    }

    cout << "Total Harga Setelah Diskon (jika ada): " << total_harga << endl;
}

int main()
{
    const int MAX_BUKU = 100;
    Buku list_buku[MAX_BUKU];
    int jumlah_buku = 0;
    int pilihan;

    do
    {
        cout << "\nMenu Toko Buku:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Daftar Buku\n";
        cout << "3. Ubah Data Buku\n";
        cout << "4. Hapus Buku\n";
        cout << "5. Hitung Total Harga Pembelian dengan Diskon\n";
        cout << "6. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahBuku(list_buku, jumlah_buku, MAX_BUKU);
            break;
        case 2:
            tampilkanDaftarBuku(list_buku, jumlah_buku);
            break;
        case 3:
            ubahBuku(list_buku, jumlah_buku);
            break;
        case 4:
            hapusBuku(list_buku, jumlah_buku);
            break;
        case 5:
            hitungTotalHarga(list_buku, jumlah_buku);
            break;
        case 6:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);

    return 0;
}
