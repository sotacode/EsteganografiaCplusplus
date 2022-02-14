#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>
#include <bitset>

using namespace std;


int main() {
    FILE * img;
    img = fopen ("luffytaro.ppm","r");

    char letra;
    int tipo;
    int height;
    int width;
    int rgb_max;


    //Leo la imgaen original
    fscanf(img,"%c%d %d %d %d",&letra,&tipo,&width,&height,&rgb_max);
    printf("%c%d\n%d %d\n%d\n",letra,tipo,width,height,rgb_max);
    char r[height][width];
    char g[height][width];
    char b[height][width];
    char aux;
    char val;
    fscanf(img,"%c",&val);
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            fscanf(img,"%c%c%c",&r[i][j],&g[i][j],&b[i][j]); 
        }
    }
    fclose(img);

    //Leo Mensaje
    FILE* mensaje=fopen("mensaje.txt","r");
    if (mensaje == NULL) { 
        printf("File Not Found!\n"); 
        return -1; 
    } 
    fseek(mensaje, 0L, SEEK_END); 
    int tam = ftell(mensaje);
    char message[tam];
    fclose(mensaje);
    mensaje=fopen("mensaje.txt","r");
    for (int i = 0; i < tam; i++){
        fscanf(mensaje,"%c",&message[i]);
    }
    vector< bitset<8> > bits_message;
    for (int i = 0; i < tam; i++){
        bitset<8> bin(message[i]);
        bits_message.push_back(bin);
    }
    //printf("%d\n",bits_message.size());
    fclose(mensaje);

    



    //Guardo la imagen
    FILE * img_modificada;
    img_modificada = fopen("modificada.ppm","w");
    fprintf(img_modificada,"%c%d\n%d %d\n%d%c",letra,tipo,width,height,rgb_max,val);
    int contador_letras=0;
    int contador_bits=0;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            fprintf(img_modificada,"%c%c",r[i][j],g[i][j]);
            if(contador_letras<tam){
                bitset<8> letrita(b[i][j]);
                cout<<"B    "<<b[i][j]<<"    "<<letrita.to_string()<<"    "<<bits_message[contador_letras]<<endl;
                if(bits_message[contador_letras].test(contador_bits)){
                    letrita.set(0);
                }else{
                    letrita.set(0,0);
                }
                char i = letrita.to_ulong();
                b[i][j]=i;
                fprintf(img_modificada,"%c",b[i][j]);
                cout<<"B    "<<b[i][j]<<"    "<<letrita.to_string()<<endl;
                contador_bits++;
                if(contador_bits==8){
                    contador_letras++;
                    contador_bits=0;
                }
            }else{
                fprintf(img_modificada,"%c",b[i][j]);
            }
            //printf("%c\n\n",b[i][j]);
        }
    }
    fclose(img_modificada);



    

    return 0;
}