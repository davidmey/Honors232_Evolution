#include "Genes.h"

Allele::Allele() : dominant(false), p_hunt(0) { };

Allele::Allele(bool d, double s) : dominant(d), p_hunt(s) { };

bool Allele::get_dominiant() const {
	return dominant;
}

double Allele::get_hunt() const {
	return p_hunt;
}

void Allele::make_dominant() {
	dominant = true;
}

void Allele::set_hunt(double s) {
	p_hunt = s;
}

Gene::Gene() { };

Gene::Gene(Allele t1, Allele t2) {
	set_geno(t1, 0);
	set_geno(t2, 1);
};

double Gene::get_hunt() const {
	return pheno.get_hunt();
}

Allele Gene::get_pheno() const {
	return pheno;
}

Allele Gene::pass_on() const {
	return geno[rtest(.5)];
}

void Gene::set_geno(Allele t, bool left) {
	int pos = 1;
	if (left) pos = 0;
	geno[pos] = t;
	if (geno[0].get_dominiant()) {
		pheno = geno[0];
	} else if (geno[1].get_dominiant()) {
		pheno = geno[1];
	} else {
		pheno = geno[0];
	}
}

bool rtest(double percent) {
	double val = (rand() % 100) / (double) 100;
	return percent > val;
}

void seed() {
	srand(time(NULL));
}
