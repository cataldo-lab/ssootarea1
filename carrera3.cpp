#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <random>
#include <chrono>

using namespace std;

const int MAX_DISTANCIA = 100;
const int TOTAL_AUTOS = 3;

vector<int> progreso(TOTAL_AUTOS, 0);

mutex carreraMutex;

void correrAuto(int autoId) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> avanceAleatorio(1, 10);
    uniform_int_distribution<> pausaAleatoria(100, 500);

    while (progreso[autoId] < MAX_DISTANCIA) {
        int avance = avanceAleatorio(gen);
        this_thread::sleep_for(chrono::milliseconds(pausaAleatoria(gen)));

        lock_guard<mutex> lock(carreraMutex);
        progreso[autoId] += avance;
        cout << "Auto " << autoId << " avanza " << avance << " metros (total: " << progreso[autoId] << " metros)\n";
    }
}

int main() {
    vector<thread> hilos;
    for (int i = 0; i < TOTAL_AUTOS; ++i) {
        hilos.emplace_back(correrAuto, i); 
    }

    for (auto& hilo : hilos) {
        hilo.join();
    }

    cout << "¡La carrera ha terminado!\n";
    return 0;
}