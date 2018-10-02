/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
	unordered_map<int, UndirectedGraphNode*> nodeMap;

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;

		if (nodeMap.find(node->label) == nodeMap.end())
		{
			UndirectedGraphNode* currentNode = new UndirectedGraphNode(node->label);
			nodeMap[node->label] = currentNode;
			for (const auto& negNode : node->neighbors)
			{
				currentNode->neighbors.push_back(cloneGraph(negNode));
			}
		}
		return nodeMap[node->label];
	}
};
