#include <iostream>
#include <string>
#include "DLL.h"
#include "DLL.cpp"
#define NIL NULL
using namespace std;

// FdisplayMenu() ini kita bakalan nampilin menu apa aja yang ada di aplikasi MY Telu
void displayMenu() {
    cout << "\n";
    cout << "           APLIKASI MY TELU         " << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << "1. Tambah Postingan Baru" << endl;
    cout << "2. Tampilkan Semua Postingan" << endl;
    cout << "3. Tampilkan Postingan Berdasarkan Username" << endl;
    cout << "4. Tampilkan Postingan Terpopuler (Like Terbanyak)" << endl;
    cout << "5. Like/Unlike Postingan" << endl;
    cout << "6. Hapus Postingan" << endl;
    cout << "7. Keluar" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << "Pilih menu (1-7): ";
}

// Fungsi untuk input data postingan baru
Postingan inputPostingan() {
    Postingan post;
    cout << "\n--- INPUT POSTINGAN BARU ---" << endl;
    cout << "Masukkan ID Post: ";
    cin >> post.idPost;
    cin.ignore();
    
    cout << "Input Username: ";
    getline(cin, post.username);
    
    cout << "Input Konten: ";
    getline(cin, post.konten);
    
    post.jumlahLike = 0;
    
    return post;
}

int main() {
    List myList;
    createNewList(myList);
    
    int pilihan;
    
    // ini data buat kita nampilin beberapa postingan
    Postingan post1;
    post1.idPost = 101;
    post1.username = "@najwarre";
    post1.konten = "aduhaiii";
    post1.jumlahLike = 70;
    insertAscending(myList, post1);
    
    Postingan post2;
    post2.idPost = 103;
    post2.username = "@lee_haechan";
    post2.konten = "anyeongggg!";
    post2.jumlahLike = 1000;
    insertAscending(myList, post2);
    
    Postingan post3;
    post3.idPost = 102;
    post3.username = "@nadiaTambunan";
    post3.konten = "makan apa yaa hari iniii";
    post3.jumlahLike = 100;
    insertAscending(myList, post3);
    
    Postingan post4;
    post4.idPost = 104;
    post4.username = "@jenoyaa123";
    post4.konten = "Ganteng banget gweh!";
    post4.jumlahLike = 1500;
    insertAscending(myList, post4);
    
    while (true) {
        displayMenu();
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1: {
                // ini ketika kita mau nambah postingan baru
                Postingan postBaru = inputPostingan();
                insertAscending(myList, postBaru);
                cout << "\n Postingan berhasil diupload!" << endl;
                cout << "Postingan diurutkan berdasarkan ID Post secara ascending." << endl;
                break;
            }
            case 2: {
                // ini ketika kita mau nampilin semua postingan 
                printAllPost(myList);
                cout << "\nTotal postingan: " << length(myList) << endl;
                break;
            }
            case 3: {
                // ini kalau kita mau nampilin postingan berdasarkan username yang kita pilih aja
                string username;
                cout << "\nInput Username: ";
                getline(cin, username);
                printPostByUsername(myList, username);
                break;
            }
            case 4: {
                // ini kalau kita mau nampilin postingan yang paling popouler 
                printMostPopularPost(myList);
                break;
            }
            case 5: {
                // ini buat kita like / unlike postingan 
                int idPost;
                int aksi;
                
                cout << "\nInput ID Postingan: ";
                cin >> idPost;
                
                cout << "Pilih aksi:" << endl;
                cout << "1. Like (+1)" << endl;
                cout << "2. Unlike (-1)" << endl;
                cout << "Pilihan: ";
                cin >> aksi;
                
                if (aksi == 1) {
                    updateLike(myList, idPost, true);
                } else if (aksi == 2) {
                    updateLike(myList, idPost, false);
                } else {
                    cout << "\nPilihan tidak valid!" << endl;
                }
                break;
            }
            case 6: {
                // ini buat kita ngehapus postingan 
                int idPost;
                cout << "\nInput ID Postingan yang ingin dihapus: ";
                cin >> idPost;
                deletePost(myList, idPost);
                cout << "\nPostingan berhasil dihapus!" << endl;
                break;
            }
            case 7: {
                cout << "Program selesai." << endl;
                return 0;
            }
            default:
                cout << "\nPilihan tidak valid! Coba lagiii" << endl;
        }
    }
    
    return 0;
}

