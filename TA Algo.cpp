
#include <iostream>
#include <string>
#include <limits>
using namespace std;


std::string nama[100];
const int maksimal = 100;
int jumlah = 0;

bool IsEmpty()
{
  return jumlah == 0;
}

bool IsFull()
{
  return jumlah >= maksimal;
}

int ItemsRemaining()
{
  return maksimal - jumlah;
}

int Count()
{
  return jumlah;
}

int MaximumSize()
{
  return maksimal;
}

void tambahAntrian()
{
  if (IsFull())
  {
    cout << "Antrian sudah penuh!" << endl;
    return;
  }

  string input_nama;
  cout << "Masukan data: ";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin,input_nama);
  cin.clear();
  jumlah += 1;
  nama[jumlah] = input_nama;
  cout << "Data sudah diinputkan " << input_nama << endl;
}

void Panggil()
{
  if (IsEmpty())
  {
    cout << "Antrian masih kosong!" << endl;
    return;
  }

  cout << nama[1] <<" masuk"<< endl;
  for (auto i = 1; i <= jumlah; i++)
  {
    nama[i] = nama[i + 1];
  }

  jumlah -= 1;
}

void Bersihkan()
{
  jumlah = 0;
  cout << "Antrian sudah bersih" << endl;
}

void Cetak()
{
  if (IsEmpty())
  {
    cout << "Antrian masih kosong!" << endl;
    return;
  }

  cout << "\t";
  for (size_t i = 1; i <= jumlah; i++)
  {
    cout << "[" << nama[i] << "]";
  }
}

int main()
{
  auto pilihan_user = 0;
  auto isLoop = true;

  while (isLoop)
  {
    cout << "======================================\n"
         << "|    Aplikasi antrian rumah sakit    |"
         << "\n|1. Apakah antrian kosong            |"
         << "\n|2. Apakah antrian penuh             |"
         << "\n|3. Tambah Antrian                   |"
         << "\n|4. Panggil masuk antrian terdepan   |"
         << "\n|5. Cetak antrian                    |"
         << "\n|6. Bersihkan antrian                |"
         << "\n|7. Quit                             |" 
         << "\n======================================"<< endl;
    cout << "Masukan pilihan: ";
    cin >> pilihan_user;

    switch (pilihan_user)
    {
    case 1:
      if (IsEmpty())
      {
        cout << "Antrian masih kosong." << endl;
        cout << endl;
        break;
      }

      cout << "Antrian sudah terisi " << Count() << " elemen" << endl;
      cout << endl;
      break;

    case 2:
      if (IsFull())
      {
        cout << "Antrian sudah penuh." << endl;
        cout << endl;
        break;
      }

      cout << "batas antrian masih tersisa " << ItemsRemaining() << endl;
      cout << endl;
      break;

    case 3:
      tambahAntrian();
      cout << endl;
      break;

    case 4:
      Panggil();
      cout << endl;
      break;

    case 5:
      Cetak();
      cout << endl;
      break;

    case 6:
      Bersihkan();
      cout << endl;
      break;

    case 7:
      isLoop = false;
      cout << "Bye!" << endl;
      break;

    default:
      cout << "Salah input!" << endl;
      cout << endl;
      break;
    }
  }
}
