#include <iostream>

#define BINSORT_TEST 1

#include "../list3.h"

class Node {
    friend ostream& operator<<(ostream&, const Node &);
    friend void BinSort(Chain<Node>&, int);

public:
    Node()
    {
    }

    Node(int score, char *name)
    {
        this->score = score;
        this->name = name;
    }

    int operator !=(Node x) const
    {
        return (score != x.score
                || name[0] != x.name[0]);
    }

    operator int() const { return score; }

private:
    int score;
    char *name;
};

ostream& operator<<(ostream& out, const Node& x)
{
    out<<"("<<x.score<<" "<<x.name[0]<<") ";
    return out;
}

//箱子排序
void BinSort(Chain<Node>& X, int range)
{
    //按分数排序
    int len = X.Length();
    Node x;
    Chain<Node> *bin;
    bin = new Chain<Node>[range+1];
    //分配到每个箱子中
    for (int i = 0; i < len; i++) {
        X.Delete(1, x);
        bin[x.score].Insert(0, x);
    }

    //从箱子中收集各元素
    for (int j = range; j >=0; j--) {
        while(!bin[j].IsEmpty()) {
            bin[j].Delete(1,x);
            X.Insert(0, x);
        }
    }
    delete[] bin;
}
    

int main(int argc, const char *argv[])
{
    Chain<Node> X;
    Node nodes[] = {
        {
            .score=3,
            .name="J",
        },
        {
            .score=4,
            .name="I",
        },
        {
            .score=3,
            .name="H",
        },
        {
            .score=4,
            .name="G",
        },
        {
            .score=0,
            .name="F",
        },
        {
            .score=3,
            .name="E",
        },
        {
            .score=4,
            .name="D",
        },
        {
            .score=5,
            .name="C",
        },
        {
            .score=4,
            .name="B",
        },
        {
            .score=2,
            .name="A",
        },
    };

    for (int i = 0; i < 10; i++)
        X.Insert(0, nodes[i]);
    std::cout<<"X is "<<X<<std::endl;
   // BinSort(X, 5);
    X.BinSort(5);
    std::cout<<"after BinSort, X is "<<X<<std::endl;
    return 0;
}


