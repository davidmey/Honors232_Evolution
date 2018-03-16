#include "Organisms.h"

class Population {
public:
	int size() const;
	void next_gen();
private:
	vector<Organism> males, females;
	int env_cap;
	void distrib_food();
	void mate();
};
