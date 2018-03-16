#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

class Allele {
public:
	Allele();
	Allele(bool d, double s);
	bool get_dominiant() const;
	double get_hunt() const;//probability of hunting success if you have said gene
	void make_dominant();
	void set_hunt(double s);
private:
	bool dominant;
	double p_hunt;
};

class Gene {
public:
	Gene();
	Gene(Allele t1, Allele t2);
	double get_hunt() const;
	Allele get_pheno() const;
	Allele pass_on() const;
	void set_geno(Allele t, bool left);
private:
	Allele pheno;//checks phenotype that's exhibited, via dominant vs. recessive
	Allele geno[2];//all possibilities for this gene
};

bool rtest(double percent);//random number generator: percent is 0 to 1
void seed();//random number