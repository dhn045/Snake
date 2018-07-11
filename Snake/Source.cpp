#include <armadillo.h>

#include "sl.h"
#include "snake_h.h"

using namespace std;

Network::Network(int * sizes) {
	this->sizes = sizes;
	while (sizes) {
		this->numLayers++;
		sizes++;
	}

	mat a;

}