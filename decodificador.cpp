#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>
#include <bitset>

using namespace std;


int main() {
    FILE * img;
    img = fopen ("modificada.ppm","r");

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
    char val;
    fscanf(img,"%c",&val);
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            fscanf(img,"%c%c%c",&r[i][j],&g[i][j],&b[i][j]); 
        }
    }
    fclose(img);

    //Leo Mensaje
    FILE* mensaje=fopen("mensaje_decodificado.txt","w");
    int contador_letras=0;
    int contador_bits=0;
    vector<bitset<8>> decodificacion;
    bitset<8> aux("00000000");
    char letrita;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){    
            //fprintf(img_modificada,"%c",b[i][j]);
            if(contador_bits<8){
                bitset<8> binb(b[i][j]);
                cout<<binb.to_string()<<endl;
                if(binb.test(0)){
                    aux.set(contador_bits);
                }else{
                    aux.set(contador_bits,0);
                }
                contador_bits++;
            }else{
                contador_bits=0;
                cout<<"Ress:  "<<aux.to_string()<<endl;
                char i = aux.to_ulong();
                letrita=static_cast<char>( i );
                fprintf(mensaje,"%c",letrita);
                j--;
                if (letrita==']'){
                    break;
                }  
            }
        }
        if (letrita==']'){
            break;
        }
    }
    fclose(mensaje);



    

    return 0;
}