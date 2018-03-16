#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include "Population.h"

using namespace std;

const int threshold;

int Population::size() const {
	return males.size() + females.size();
}

void Population::next_gen() {
	distrib_food();
	mate();
}


void Population::distrib_food() {

	int total_food = 100;
	while (total_food) {
		if (rand() % 2) {
			int member = rand() % males.size();
			if (rtest(males[member].get_hunt())) {
				--total_food;
				males[member].incr_food();
			} else {
				--total_food;
				females[member].incr_food();
			}
		}
	}

	//for statistics reasons, it'd be nice to know the different members
	//of a given genotype or phenotype
	//so either do any recording of net statistics at this point
	//or move over to another vector


	//remove those who don't meet food threshold
	males = remove_if(males.begin(), males.end(), smaller_than_threshold)
		females = remove_if(females.begin(), males.end(), smaller_than_threshold)




		//max reproductions proportional to food
		//TO DO: research if that is actually is the case, or non-linear
		for (auto i : males) {
			i.set_max_reproductions(int(i.get_food() / threshold));
		}
	for (auto i : females) {
		i.set_max_reproductions(int(i.food() / threshold));
	}
}

bool smaller_than_threshold(int i) {
	return i < threshold;
}

void Population::mate() {
	size_t minimum = min(males.size(), females.size());

	// Generate random non-repeating indices
	vector<size_t> indices(minimum);
	iota(indices.begin(), indices.end(), 0);
	random_shuffle(indices.begin(), indices.end());

	for (size_t index : indices) {
		// TODO: Mate, add, and remove
	}
}

