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



