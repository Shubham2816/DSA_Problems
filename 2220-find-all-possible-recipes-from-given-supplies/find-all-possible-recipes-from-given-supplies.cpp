class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
         unordered_map<string, vector<string>> graph; // ingredient -> recipes
        unordered_map<string, int> indegree; // recipe -> count of required ingredients
        unordered_set<string> available(supplies.begin(), supplies.end());
        vector<string> result;


// Step 1: Build graph and indegree map
        for (int i = 0; i < recipes.size(); i++) {
            string recipe = recipes[i];
            indegree[recipe] = ingredients[i].size();

            for (string& ing : ingredients[i]) {
                graph[ing].push_back(recipe);
            }
        }


      /*
 indegree["bread"] = 2   // needs "yeast" and "flour"
graph["yeast"].push_back("bread")  // yeast → bread
graph["flour"].push_back("bread")  // flour → bread

yeast  → [bread]  //Graph (Adjacency List)
flour  → [bread]

bread  = 2  (requires "yeast" and "flour")*/


// Step 2: Perform BFS
        queue<string> q(supplies.begin(), supplies.end());
        // q = ["yeast", "flour", "corn"]


        while (!q.empty()) {
            string item = q.front();
            q.pop();
            if (!graph.count(item)) continue;

            for (string& recipe : graph[item]) {
                indegree[recipe]--;
                if (indegree[recipe] == 0) {
                    result.push_back(recipe);
                    q.push(recipe);
                }
            }
        }

        return result;

    }
};