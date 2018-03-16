#include "Genes.h"
#include <vector>

class Organism {
public:
	Organism(const std::vector <Gene> &geno);
	bool get_male() const;

	double get_hunt() const;//hunting sucess rate
	void incr_food();
	void set_hunt();

	double get_mate() const;//product of probabilities of individual genes
	void set_mate(double mate);

	void set_max_reproductions();

	bool can_reproduce() const;

	//void set_gene(Gene g, int pos);
	//void add_gene(Gene g);
	void mate(std::vector<Gene> &n_geno) const;
	static Organism mate(Organism male, Organism female); // Makes a single child
private:
	int food;//keep track of amount of food
	std::vector<Gene> genes;
	double p_hunt;

	// These are for checking how many reproductions an organism can have
	unsigned reproductions;
	unsigned max_reproductions;
};
