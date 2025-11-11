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