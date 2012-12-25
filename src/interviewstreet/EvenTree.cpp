/**@file
 * Copyright (C), 1998-2012, Tencent Technology Company Limited
 * 
 * @author	bensonzhang <bensonzhang@tencent.com>
 * @date	2012-12-23
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Tree
{
public:
    typedef std::vector<int> Nodes;
    void Add(int u, int v)
    {
        AddNode(u);
        AddNode(v);
        m_nodes[u].push_back(v);
        m_nodes[v].push_back(u);
    }
    void Clear()
    {
        m_nodes.clear();
    }
    std::size_t NumNodes() const
    {
        return m_nodes.size();
    }
    std::size_t EvenTree() const
    {
        if (NumNodes() % 2) return 0;
        std::pair<std::size_t, std::size_t> res = EvenTree(0, 0);
        return res.first;
    }
    std::string ToString() const
    {
        std::stringstream ss;
        for (std::size_t i = 0; i < m_nodes.size(); ++i)
        {
            ss << "[" << i << "]";
            for (std::size_t j = 0; j < m_nodes[i].size(); ++j)
            {
                ss << " " << m_nodes[i][j];
            }
            ss << "\n";
        }
        return ss.str();
    }
private:
    std::vector<Nodes> m_nodes;

    void AddNode(std::size_t u)
    {
        while (m_nodes.size() <= u)
        {
            m_nodes.push_back(Nodes());
        }
    }
    std::pair<std::size_t, std::size_t> EvenTree(std::size_t v, std::size_t parent) const
    {
        std::size_t cnt = 0;
        std::size_t nnodes = 1;
        for (std::size_t i = 0; i < m_nodes[v].size(); ++i)
        {
            std::size_t u = m_nodes[v][i];
            if (u == parent) continue;
            std::pair<std::size_t, std::size_t> res = EvenTree(u, v);
            cnt += res.first;
            nnodes += res.second;
            if (res.second % 2 == 0)
            {
                ++cnt;
            }
        }
        return std::make_pair(cnt, nnodes);
    }
};

int main()
{
	Tree tree;
	int nv;
	int ne;
	while (std::cin >> nv >> ne)
	{
	    tree.Clear();
	    for (int i = 0; i < ne; ++i)
	    {
	        int u, v;
	        std::cin >> u >> v;
	        tree.Add(u - 1, v - 1);
	    }
	    std::cout << tree.EvenTree() << std::endl;
	}

    return 0;
}
