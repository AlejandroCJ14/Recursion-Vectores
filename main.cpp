#include <iostream>
using namespace std;

class Vector {
private:
    static const int max = 100;
    int v[max];
    int tamano;
    
public:
    Vector() {
        tamano = 0;
    }
    
    int getvalue(int i){
        return v[i];
    }
    
    void intercambiar(int i, int j) {
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
    
    bool esPar(int ele){
        if(ele % 2 == 0) return true;
        return false;
    }
    
    //e1
    void cargar(int t) {
        if (t < 0 || t > max) return;
        
        if (t >= tamano) tamano = t;
        
        if (t == 0) return;
        
        cargar(t-1); // tener cuidado en donde pongo la funcion por recursividad si la pongo despues del cin sale invertido
        
        cout << "Ingrese un numero " << t  << " : ";
        cin >> v[t-1];
        
    }
    
    //e2
    void mostrar(int i) {
        if (i == tamano) {
            cout << "]\n";
            return;
        }
        if (i == 0) cout << "[";
        cout << v[i];
        if (i < tamano - 1) cout << ", ";
        mostrar(i + 1);
    }
    
    //e3
    void invertir(int i) {
        if (i >= tamano / 2) return;
        
        int aux = v[i];
        v[i] = v[tamano - 1 - i];
        v[tamano - 1 - i] = aux;
        
        invertir(i + 1);
    }
    
    //e4
    int sumarElementos(int i) {
        if (i == tamano) return 0;
        
        return v[i] + sumarElementos(i + 1);
    }
    
    //e5
    int contarPares(int i){
        int cont = 0;
        if (i == tamano) return cont;
        
        if(v[i] % 2 == 0) cont ++;
        
        return cont + contarPares(i+1);
    }
    
    //e6
    void contarPosNeg0(int i, int &pos, int &neg, int &ceros) {
        if (i == tamano) return;
        
        if (v[i] > 0) pos++;
        
        else if (v[i] < 0) neg++;
        
        else ceros++;
        
        contarPosNeg0(i + 1, pos, neg, ceros);
    }
    
    //e7
    double promedio(int i) {
        if (i == tamano) return 0;

        return (double)v[i] / tamano + promedio(i + 1);
    }
    
    //e8
    int contarMultiplosDeK(int i, int k){
        int cont = 0;
        if (i == tamano) return 0;
        
        if(v[i] % k == 0) cont ++;
        
        return cont + contarMultiplosDeK(i + 1, k);
    }
    
    //9
    int encontrarMayor(int i) {
        if (i == tamano - 1) return v[i];

        int mayor = encontrarMayor(i + 1);

        if (v[i] > mayor)
            return v[i];

        return mayor;
    }
    
    //e10
    void encontarMenorYPos(int i, int& men, int& pos){
        if (i == tamano-1){
            men = v[i];
            pos = i;
            return;
        }
        
        encontarMenorYPos(i+1, men, pos);
        
        if (v[i] <= men){ // tener cuidado la recursividad va del ultimo al primero por eso <=
            men = v[i];
            pos = i;
        }
    }
    
    //e11
    int buscarPosicionElemento(int i, int x){
        if (i == tamano) return -1;
        
        if (v[i] == x) return i;
        
        return buscarPosicionElemento(i+1, x);
    }
    
    //e12
    int contarReperticionesDeX(int i, int x){
        int cont = 0;
        if (i == tamano) return 0;
        
        if (v[i] == x) cont++;
        
        return cont + contarReperticionesDeX(i+1, x);
    }
    
    //e13
    void cambiarXporY(int i, int x , int y){
        if (i == tamano) return;
        
        cambiarXporY(i+1, x, y);
        
        if(v[i] == x) v[i] = y;
        
    }
    
    // e14 es el mismo que el e3
    
    bool esASC(int i) {
        if (i == tamano - 1) return true;

        if (v[i] > v[i + 1]) return false;

        return esASC(i + 1);
    }
    
    //e15
    void sumarPosParEImpar(int i, int& sp, int& si){
        if (i == tamano) return;
        
        sumarPosParEImpar(i+1, sp, si);
        
        if (i % 2 == 0){
            sp += v[i];
        } else si += v[i];
    }
    
    //e16
    void eliminarPos(int i){
        if (i == tamano -1){
            tamano--;
            return;
        }
        
        v[i] = v[i+1];
        
        eliminarPos(i+1);
    }
    
    //17
    int posicionMenor(int i, int pos) {
        if (i == tamano) return pos;

        if (v[i] < v[pos])
            pos = i;

        return posicionMenor(i + 1, pos);
    }
    
    //e18
    void ordenarASC(int i) {
        if (i == tamano - 1) return;

        int pos = posicionMenor(i, i);

        intercambiar(i, pos);

        ordenarASC(i + 1);
    }
    
    //e19
    int encontarxEnVectorOrdenadoASC(int i, int x){
        if (i == tamano) return -1;
        
        ordenarASC(0);
        
        if (v[i] == x) return i;
        
        return encontarxEnVectorOrdenadoASC(i+1, x);
        
    }
    
    //e20
    void eliminarRepetidosDe(int i, int j) {
        if (j >= tamano) return;

        if (v[i] == v[j]) {
            eliminarPos(j);
            eliminarRepetidosDe(i, j);
        } else {
            eliminarRepetidosDe(i, j + 1);
        }
    }
    void eliminarDuplicados(int i) {
        if (i >= tamano) return;

        eliminarRepetidosDe(i, i + 1);

        eliminarDuplicados(i + 1);
    }
    
    //e21
    void separarParImpar(int i) {
        if (i >= tamano) return;

        if (esPar(v[i])) {
            separarParImpar(i + 1);
            return;
        }

        int j = i + 1;
        

        while (j < tamano && !esPar(v[j])) {
            j++;
        }

        if (j == tamano) return;

        intercambiar(i, j);
        separarParImpar(i + 1);
    }
    // e22
    void rotarUnaPosicion(int i) {
        if (i == 0) return;

        intercambiar(i, i-1);
        rotarUnaPosicion(i-1);
    }
    
    void rotarKPosiciones(int k){
        if (tamano==0)return;
        
        k = k % tamano;
        
        if (k==0) return;
        
        rotarUnaPosicion(tamano-1);
        
        rotarKPosiciones(k-1);
    }
    
    //e23
    int longitudMax(int i, int &cont, int &may) {
        if (i >= tamano - 1) return may;

        if (v[i] < v[i+1]) {
            cont++;
        } else {
            cont = 1;
        }

        if (cont > may) may = cont;

        return longitudMax(i+1, cont, may);
    }
    
    //e24
    int encontrarSegundoMayor(int i, int& may, int&segundo){
        if(i >= tamano) return segundo;
        
        if(v[i] > may){
            segundo = may;
            may = v[i];
        }else if (v[i] < may && v[i] > segundo){
            segundo = v[i];
        }
        return encontrarSegundoMayor(i+1, may, segundo);
    }
    
    //e25
    int MaximaSumaDelSegmento(int i, int sumaActual, int sumaMax){
        if(i >= tamano) return sumaMax;
        
        if (sumaActual + v[i] > v[i]){
            sumaActual += v[i];
        }else{
            sumaActual = v[i]; // empieza desde v[i] si v[i] es mayor a la suma actual
        }
        
        if(sumaActual > sumaMax) sumaMax = sumaActual; // guarda el resultado por pasada
        
        return MaximaSumaDelSegmento(i+1, sumaActual, sumaMax);
    }
};

int main() {
    Vector v1;
    int sa=0;
    int sm=0;

    v1.cargar(8);
    v1.mostrar(0);
    cout << v1.MaximaSumaDelSegmento(0, sa, sm) << endl;
    return 0;
}
