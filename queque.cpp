#include <stdio.h>
#include <stdlib.h>

struct Node{
    int nilai;
    Node *selanjutnya;
};
Node *pala = NULL;
Node *buntut = NULL;

Node *createNode(int nilai)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->nilai = nilai;
    newNode->selanjutnya = NULL;
    return newNode;
}

void Nodebaru(int nilai)
{
    Node *newNode = createNode(nilai);
    if(!buntut){
        pala = buntut = newNode;
    }else{
        buntut->selanjutnya = newNode;
        buntut = buntut->selanjutnya;
    }
}

void Hapus()
{
    Node *sekarang = pala->selanjutnya;
    pala->selanjutnya=NULL;
    free(pala);
    pala = sekarang;
}

void Tampilkan()
{
    Node *sekarang = pala;
    while(sekarang)
    {
        printf("node %d ", sekarang->nilai);
        sekarang = sekarang->selanjutnya;
    }
    printf("\n");
}

int main(){

Nodebaru(20);
Nodebaru(15);
Nodebaru(35);
Nodebaru(40);
Nodebaru(55);
Nodebaru(45);
Nodebaru(10);
Tampilkan();
Hapus();
puts("setelah dihapus");
Tampilkan();
puts("setelah dihapus");
Hapus();
Tampilkan();

    return 0;
}