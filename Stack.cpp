#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int nilai;
    Node *selanjutnya, *sebelumnya;
}*Awal = NULL, *Akhir = NULL;

Node *createNode(int nilai)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->nilai = nilai;
    newNode->selanjutnya = newNode->sebelumnya = NULL;
    return newNode;
}

void insert(int nilai)
{
    Node *newNode = createNode(nilai);
    if(!Awal)
    {
        Awal = Akhir = newNode;
    }else
    {
        Awal->selanjutnya = newNode;
        newNode->sebelumnya = Awal;
        Awal = Awal->selanjutnya;
    }
}

void Delete()
{
    if(!Awal)
    {
        return;
    }else if(!Awal->sebelumnya){
        free(Awal);
    }else
    {
        Node *sekarang = Awal->sebelumnya;
        Awal->sebelumnya = sekarang->selanjutnya = NULL;
        free(Awal);
        Awal = sekarang;
    }
}

void tampilkan()
{
    Node *sekarang = Akhir;
    while(sekarang)
    {
        printf(" node %d ", sekarang->nilai);
        sekarang = sekarang->selanjutnya;
    } puts("");
}

int main ()
{
    insert(30);
    insert(40);
    insert(13);
    insert(37);
    insert(32);
    insert(45);
    tampilkan();
    Delete();
    puts("setelah dihapus");
    tampilkan();
    Delete();
    puts("setelah dihapus");
    tampilkan();
    return 0;
}