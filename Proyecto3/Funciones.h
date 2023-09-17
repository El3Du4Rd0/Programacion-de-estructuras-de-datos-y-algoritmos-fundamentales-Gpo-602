#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

#include <vector>
#include <iostream>

template <class T>
class Funciones{
    public:
        void swap(std::vector<T>&, int, int);
        void sort_cost(std::vector<T>&);
        void sort_vida(std::vector<T>&);
        void sort_ataq(std::vector<T>&);
        T search_cost(std::vector<T>&, int);
        T search_vida(std::vector<T>&, int);
        T search_ataq(std::vector<T>&, int);
};

template <class T> void Funciones<T>::swap(std::vector<T> &vec, int i, int j){
    T aux = vec[i];
    vec[i] = vec[j];
    vec[j] = aux;
}

template <class T> void Funciones<T>::sort_cost(std::vector<T> &vec) {
	for (int i = vec.size() - 1; i > 0; i--) {
		int pos = 0;
		for (int j = 1; j <= i; j++) {
			if ( vec[j].cost > vec[pos].cost ) {
				pos = j;
		    }
	    }
		if (pos != i) {
			swap(vec, i, pos);
		}
	}
}

template <class T> void Funciones<T>::sort_vida(std::vector<T> &vec) {
	for (int i = vec.size() - 1; i > 0; i--) {
		int pos = 0;
		for (int j = 1; j <= i; j++) {
			if ( vec[j].vida > vec[pos].vida ) {
				pos = j;
		    }
	    }
		if (pos != i) {
			swap(vec, i, pos);
		}
	}
}

template <class T> void Funciones<T>::sort_ataq(std::vector<T> &vec) {
	for (int i = vec.size() - 1; i > 0; i--) {
		int pos = 0;
		for (int j = 1; j <= i; j++) {
			if ( vec[j].ataq > vec[pos].ataq ) {
				pos = j;
		    }
	    }
		if (pos != i) {
			swap(vec, i, pos);
		}
	}
}

template <class T> T Funciones<T>:: search_cost( std::vector<T>&vec, int val){
    int mid, low, high;
	low = 0; high = vec.size()-1;

	while (low <= high) {
		mid = (high + low) / 2;
		if (val == vec[mid].cost) {
			return vec[mid];
		} else if (val < vec[mid].cost) {
			high = mid - 1;
		} else if (val > vec[mid].cost) {
			low = mid + 1;
		}
    }

    T estructura;
    return estructura;
}

template <class T> T Funciones<T>:: search_vida( std::vector<T>&vec, int val){
    int mid, low, high;
	low = 0; high = vec.size()-1;

	while (low <= high) {
		mid = (high + low) / 2;
		if (val == vec[mid].vida) {
			return vec[mid];
		} else if (val < vec[mid].vida) {
			high = mid - 1;
		} else if (val > vec[mid].vida) {
			low = mid + 1;
		}
    }

    T estructura;
    return estructura;
}

template <class T> T Funciones<T>:: search_ataq( std::vector<T>&vec, int val){
    int mid, low, high;
	low = 0; high = vec.size()-1;

	while (low <= high) {
		mid = (high + low) / 2;
		if (val == vec[mid].ataq) {
			return vec[mid];
		} else if (val < vec[mid].ataq) {
			high = mid - 1;
		} else if (val > vec[mid].ataq) {
			low = mid + 1;
		}
    }

    T estructura;
    return estructura;
}

#endif