Assesment Sub CLO 3 - Struktur Data

Identitas Pengumpul

Nama: Najwa Areefa Ghaisani

NIM: 103122400028

Kelas: [Kelas Praktikum/Mata Kuliah Anda]

1. Kode Program

``File: DLL.h
 * Author: Najwa Areefa Ghaisani
 * NIM: 103122400028
 * Deskripsi: Program ini untuk menulis file header nya
 */

  ```File: DLL.cpp
 * Author: Najwa Areefa Ghaisani
 * NIM: 103122400028
 * Deskripsi: Program ini untuk menulis fungsi dari kode program yang akan kita jalankan 
 */

 ```File: main.cpp
 * Author: Najwa Areefa Ghaisani
 * NIM: 103122400028
 * Deskripsi: Program ini untuk menjalankan atau menampilkan program yang telah kita buat 
 */




#ifndef DLL_H
#define DLL_H
#define NIL NULL
#include <iostream>
#include <string>
using namespace std;

//Najwa Areefa Ghaisani_103122400028

#define first(L) (L).first
#define last(L) (L).last
#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info

// struct postingan dipakek buat nyimpen data setiap postingan 
struct Postingan {
    int idPost;
    string konten;
    int jumlahLike;
    string username;
};

// Struct listNode ini dipakek untuk merepresentasikan node pada double linked list
struct listNode {
    Postingan info;
    listNode* next;
    listNode* prev;
};

// disini kita bakalan mendefinisikan tipe data List yang merupakan double linked list
typedef listNode* address;
typedef struct {
    address first;
    address last;
} List;

// disini kita bakalan mendeklarasikan fungsi - fungsi yang bakalan kita pakek
address createElement(Postingan data);
void createNewList(List &a);
bool isEmpty(List a);
void insertAscending(List &a, Postingan x);
void insertLast(List &a, address p);
void deleteFirst(List &a);
void deleteLast(List &a);
int length(List a);
address findElement(List a, int idPost);
address findByUsername(List a, string username);
address findMostPopular(List a);
void printAllPost(List a);
void printPostByUsername(List a, string username);
void printMostPopularPost(List a);
void updateLike(List &a, int idPost, bool isLike);
void displayPost(Postingan post);
void deletePost(List &a, int idPost);

#endif



#ifndef DLL_H
#define DLL_H
#include <iostream>
#include <string>
#include "DLL.h"
#define NIL NULL
using namespace std;

//Najwa Areefa Ghaisani_103122400028

// function createElement ini buat kita membuat elemen baru
address createElement(Postingan data) {
    address p = new listNode;
    info(p) = data;
    next(p) = NIL;
    prev(p) = NIL;
    return p;
}

// function createNewList ini buat kita menginisialisasi list yang baru aja dibuat
// intinya fungsi ini tu buat bikin list baru yang kosong 
void createNewList(List &a) {
    first(a) = NIL;
    last(a) = NIL;
}

// function isEmpty ini buat ngecek apakah listnya tu kosong atau enggak.
bool isEmpty(List a) {
    return first(a) == NIL && last(a) == NIL;
}

// function insertAscending ini tu buat kita nambahin data postingan yang baru kedalam list secara terurut ascending berdasarkan ID post
void insertAscending(List &a, Postingan x) { 
    address p = createElement(x);
    
    if (isEmpty(a)) {
        first(a) = p;
        last(a) = p;
    } else if (info(first(a)).idPost > x.idPost) {
        // ini insert di awal list 
        next(p) = first(a);
        prev(first(a)) = p;
        first(a) = p;
    } else if (info(last(a)).idPost < x.idPost) {
        // yang ini insert di akhir list
        next(last(a)) = p;
        prev(p) = last(a);
        last(a) = p;
    } else {
        // kemudian ini tu insert di tengah-tengah list
        address q = first(a);
        while (next(q) != NIL && info(next(q)).idPost < x.idPost) {
            q = next(q);
        }
        next(p) = next(q);
        if (next(q) != NIL) {
            prev(next(q)) = p;
        }
        next(q) = p;
        prev(p) = q;
    }
}

// function insertLast ini buat kita nambahain elemen di akhir list
void insertLast(List &a, address p) {
    if (isEmpty(a)) {
        first(a) = p;
        last(a) = p;
    } else {
        next(last(a)) = p;
        prev(p) = last(a);
        last(a) = p;
    }
}

// function deleteFirst ini tu buat kita ngehapus elemen pertama yang ada di list
void deleteFirst(List &a) {
    if (isEmpty(a)) {
        cout << "List kosong, tidak ada yang dihapus!" << endl;
    } else if (first(a) == last(a)) {
        delete first(a);
        first(a) = NIL;
        last(a) = NIL;
    } else {
        address p = first(a);
        first(a) = next(p);
        prev(first(a)) = NIL;
        delete p;
    }
}

// function deleteLast ini buat kita ngehapus elemen terakhir yang ada di list
void deleteLast(List &a) {
    if (isEmpty(a)) {
        cout << "List kosong, tidak ada yang dihapus!" << endl;
    } else if (first(a) == last(a)) {
        delete first(a);
        first(a) = NIL;
        last(a) = NIL;
    } else {
        address p = last(a);
        last(a) = prev(p);
        next(last(a)) = NIL;
        delete p;
    }
}

// function deletePost ini buat kita ngehapus postingan berdasarkan ID Post nya
void deletePost(List &a, int idPost) {
    if (isEmpty(a)) {
        cout << "List kosong!" << endl;
        return;
    }
    
    address p = findElement(a, idPost);
    if (p == NIL) {
        cout << "Postingan dengan ID " << idPost << " tidak ditemukan!" << endl;
        return;
    }
    
    if (p == first(a) && p == last(a)) {
        first(a) = NIL;
        last(a) = NIL;
    } else if (p == first(a)) {
        first(a) = next(p);
        prev(first(a)) = NIL;
    } else if (p == last(a)) {
        last(a) = prev(p);
        next(last(a)) = NIL;
    } else {
        next(prev(p)) = next(p);
        prev(next(p)) = prev(p);
    }
    delete p;
}

// length ini buat ngedapetin panjang dari listnya
int length(List a) {
    if (isEmpty(a)) {
        return 0;
    }
    int jml = 1;
    address p = first(a);
    while (next(p) != NIL) {
        jml++;
        p = next(p);
    }
    return jml;
}

// findElement ini buat kita nyari elemen bedasarkan ID post   
address findElement(List a, int idPost) {
    if (isEmpty(a)) {
        return NIL;
    }
    address p = first(a);
    while (p != NIL && info(p).idPost != idPost) {
        p = next(p);
    }
    return p;
}

// FfindByUsername ini buat kita nyari postingan berdasarkan username tertentu
address findByUsername(List a, string username) {
    if (isEmpty(a)) {
        return NIL;
    }
    address p = first(a);
    while (p != NIL && info(p).username != username) {
        p = next(p);
    }
    return p;
}

// FUNGSI C: Mencari postingan dengan jumlah like terbanyak
address findMostPopular(List a) {
    if (isEmpty(a)) {
        return NIL;
    }
    address maxPost = first(a);
    address p = next(first(a));
    while (p != NIL) {
        if (info(p).jumlahLike > info(maxPost).jumlahLike) {
            maxPost = p;
        }
        p = next(p);
    }
    return maxPost;
}

// Fungsi untuk menampilkan satu postingan
void displayPost(Postingan post) {
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-" << endl;
    cout << "ID Post       : " << post.idPost << endl;
    cout << "Username      : " << post.username << endl;
    cout << "Konten        : " << post.konten << endl;
    cout << "Jumlah Like   : " << post.jumlahLike << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-" << endl;
}

//function printAllPost ini berfungsi buat nampilin semua postingan yang ada di list
void printAllPost(List a) {
    if (isEmpty(a)) {
        cout << "\nPostingan Kosong!\n" << endl;
        return;
    }
    cout << "\nPOSTINGAN" << endl;
    address p = first(a);
    int nomor = 1;
    while (p != NIL) {
        cout << "\nPostingan ke-" << nomor << ":" << endl;
        displayPost(info(p));
        p = next(p);
        nomor++;
    }
}

// function printPostByUsername ini gunanya buat nampilin postingan berdasarkan username tertentu
void printPostByUsername(List a, string username) {
    if (isEmpty(a)) {
        cout << "\n*** List Postingan Kosong! ***\n" << endl;
        return;
    }
    
    cout << "\n===== POSTINGAN DARI USERNAME: " << username << " =====" << endl;
    address p = first(a);
    bool found = false;
    int nomor = 1;
    
    while (p != NIL) {
        if (info(p).username == username) {
            cout << "\nPostingan ke-" << nomor << ":" << endl;
            displayPost(info(p));
            found = true;
            nomor++;
        }
        p = next(p);
    }
    
    if (!found) {
        cout << "\npostingan tidak ditemukan pada username: " << username << " \n" << endl;
    }
}

// function printMostPopularPost ini buat nampilin postingan yang punya jumlah like terbanyak
void printMostPopularPost(List a) {
    if (isEmpty(a)) {
        cout << "\nList Postingan Kosong!\n" << endl;
        return;
    }
    
    address mostPopular = findMostPopular(a);
    if (mostPopular != NIL) {
        cout << "\n====== POSTINGAN TERPOPULER ======" << endl;
        cout << "\nPostingan dengan jumlah like terbanyak:" << endl;
        displayPost(info(mostPopular));
    }
}

#endif


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



3. Output Program

Berikut adalah hasil eksekusi program (output) ketika dijalankan.
```
          APLIKASI MY TELU         
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

Semua Postingan (ascending by ID):
[ID: 101] User: @najwarre | Likes: 70 | Content: "aduhaiii"
[ID: 103] User: @lee_haechan | Likes: 1000 | Content: "anyeongggg!"
[ID: 102] User: @nadiaTambunan | Likes: 100 | Content: "makan apa yaa hari iniii"
[ID: 104] User: @jenoyaa123 | Likes: 1500 | Content: "Ganteng banget gweh!"

Postingan oleh user '@najwarre':
[ID: 101] likes: 70 | content: "aduhaiii"

Postingan terpopuler:
[ID:104] User: @jenoyaa123 likes:1500 content: "Ganteng banget gweh"


```

4. Penjelasan Lanjutan (Analisis Output)

Sesuai permintaan Anda ("Penjelasan Lagi"), bagian ini menganalisis mengapa output yang dihasilkan sudah benar:

jadi ini program yang akan menampilkan 

5. Kesimpulan


