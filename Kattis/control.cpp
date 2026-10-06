#include <iostream>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>

// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind
class UnionFind
{
      struct UF { int p; int rank; };

   public:
      UnionFind(int n) {          // constructor
	 howMany = n;
	 uf = new UF[howMany];
	 for (int i = 0; i < howMany; i++) {
	    uf[i].p = i;
	    uf[i].rank = 0;
	 }
      }

      ~UnionFind() {
         delete[] uf;
      }

      int find(int x) { return find(uf,x); }        // for client use
      
      bool merge(int x, int y) {
	 int res1, res2;
	 res1 = find(uf, x);
	 res2 = find(uf, y);
	 if (res1 != res2) {
	    if (uf[res1].rank > uf[res2].rank) {
	       uf[res2].p = res1;
	    }
	    else {
	       uf[res1].p = res2;
	       if (uf[res1].rank == uf[res2].rank) {
		  uf[res2].rank++;
	       }
	    }
	    return true;
	 }
	 return false;
      }
      
   private:
      int howMany;
      UF* uf;

      int find(UF uf[], int x) {     // recursive funcion for internal use
	 if (uf[x].p != x) {
	    uf[x].p = find(uf, uf[x].p);
	 }
	 return uf[x].p;
      }
};

std::vector<int> getCauldronIds(UnionFind&, const std::vector<int>&);
int getTotalSize(const std::vector<int>&, const std::vector<int>&);
void mergeIngredients(const std::vector<int>&, UnionFind&, std::vector<int>&, int);

int main() {

    int num_of_recipes = 0;
    std::cin >> num_of_recipes;
    const int MAX_INGREDIENTS = 500001;

    // initialize cauldron UF and keep track of cauldron sizes
    UnionFind cauldrons(MAX_INGREDIENTS);
    std::vector<int> cauldron_size(MAX_INGREDIENTS, 1);

    int potions_made = 0;

    for (int i = 0; i < num_of_recipes; ++i) {
        int num_of_ingredients = 0;
        std::cin >> num_of_ingredients;
        std::vector<int> ingredients(num_of_ingredients);

        for (int j = 0; j < num_of_ingredients; ++j) {
            std::cin >> ingredients[j];
        }
        
        std::vector<int> cauldron_ids = getCauldronIds(cauldrons, ingredients);

        // if the number of ingredients is equal to the sum of sizes of
        // cauldrons containing relevant ingredients, we have no more
        // or no less ingredients than we need (i.e. no "extra" ingredients,
        // and no missing ingredients)
        int total_size = getTotalSize(cauldron_ids, cauldron_size);
        bool can_brew = (total_size == num_of_ingredients);

        if (!can_brew) continue; // if we cant brew, skip
        potions_made++; // increment count otherwise
        
        mergeIngredients(ingredients, cauldrons, cauldron_size, total_size);
    }
    
    std::cout << potions_made;
    
    return 0;
}

// get the ids of relevant cauldrons, for each ingredient get its cauldron
// and then remove duplicates (sort first as unique requires sorted container)
std::vector<int> getCauldronIds(UnionFind& cauldrons, const std::vector<int>& ingredients) {
    std::vector<int> cauldron_ids;
    cauldron_ids.reserve(ingredients.size());

    for (int ingredient : ingredients) {
        cauldron_ids.push_back(cauldrons.find(ingredient));
    }
    std::sort(cauldron_ids.begin(), cauldron_ids.end());
    // unique returns an iterator to the last kept element + 1, trim tail
    cauldron_ids.erase(std::unique(cauldron_ids.begin(), cauldron_ids.end()), cauldron_ids.end());

    return cauldron_ids;
}

// get the total size of all cauldrons containing required ingredients
int getTotalSize(const std::vector<int>& cauldron_ids, const std::vector<int>& cauldron_size) {
    int total_size = 0;
    for (int id : cauldron_ids) {
        total_size += cauldron_size[id];
    }
    return total_size;
}

// merge all of the cauldrons into a single cauldron, after, 
// get the id of the final merged cauldron and set its
// size to the size of the recipe
void mergeIngredients(const std::vector<int>& ingredients, UnionFind& cauldrons, std::vector<int>& cauldron_size, int total_size) {
    // merge all the ingredients into a single cauldron
    int first_ingredient = ingredients[0];
    for (int j = 1; j < ingredients.size(); ++j) {
        cauldrons.merge(first_ingredient, ingredients[j]);
    }
    // assign the new size of the cauldron id we end with
    cauldron_size[cauldrons.find(first_ingredient)] = total_size;
}