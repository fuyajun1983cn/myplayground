#include <iostream>
#include <map>

class Disjoint_set {
private:
	std::unordered_map<char, char> PARENT;
	std::unordered_map<char, int> RANK; //record the depth of the tree.
public:
	Disjoint_set()
	{
		char universe[] = {'a', 'b', 'c', 'd', 'e'};
		for (char x : universe) {
			PARENT[x] = x;//we have 5 disjoint sets, each set contain one item.
			RANK[x] = 0;
		}
		PARENT['d'] = 'b';//'b' and 'd' are in same set.
		RANK['b'] = 1;
	}
	char Find(char item)
	{
		if (PARENT[item] == item)
			return time;
		else
			return Find(PARENT[item]);
	}
	void Union(char set_1, char set_2)
	{
		if (RANK[set_1] > RANK[set_2])
			PARENT[set_2] = set_1
		else if (RANK[set_1] < RANK[set_2])
			PARENT[set_1] = set_2
		else {
			PARENT[set_1] = set_2;
			RANK[set_2]++;
		}
			
	}
	
};


int main()
{
}