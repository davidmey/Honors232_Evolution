#include "Organisms.h"

Organism::Organism(const vector <Gene> &geno) : genes(geno), p_hunt(0.5), reproductions(0) { };


double Organism::get_hunt() const {
	return p_hunt;
}

void Organism::set_hunt() {
	for (auto i : genes) {
		p_hunt *= i.get_hunt();
	}
}

void Organism::incr_food() {
	++food;
}

//void Organism::set_gene(Gene g, int pos) {
//	genes[pos] = g;
//}

//void Organism::add_gene(Gene g) {
//	genes.push_back(g);
//}

bool Organism::can_reproduce() const {
	return reproductions < max_reproductions;
}

/* void Organism::mate(vector<Gene> &new_geno) const {
	size_t new_geno_size = new_geno.size();
	size_t current_geno_size = genes.size();
	for (size_t i = 0; i != new_geno_size; ++i) {
		new_geno[i].set_geno(genes[i].pass_on(), (int) is_male);
		//is_male was used to keep track of indices, but we eliminated is_male
		//and now just have one vector of all males and one of all the females
		//TO DO: find workaround.
	}
	for (size_t i = new_geno_size; i < current_geno_size; ++i) {
		Gene n;
		n.set_geno(genes[i].pass_on(), (int) is_male);
		new_geno.push_back(n);
	}
} */


//my compiler objects at the use of static here--I don't think it should be here
Organism Organism::mate(Organism male, Organism female) {
	vector<Gene> child_genes;
	child_genes.resize(male.genes.size());

	// Pass on all genes
	for (size_t i = 0; i != male.genes.size(); ++i) {
		child_genes[i].set_geno(male.genes[i].pass_on(), true);
		child_genes[i].set_geno(female.genes[i].pass_on(), false);
	}

	++male.reproductions;
	++female.reproductions;

	return Organism(child_genes);
}
