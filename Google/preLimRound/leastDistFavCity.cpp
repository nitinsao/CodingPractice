#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;



int leastDistFavCity(map<int, set<pair<int, int>>>& mp, vector<int> favCities)
{
    set<pair<int, int>> queue;  // dist -> cityID
    queue.insert({0,0});
    vector<bool> visited(mp.size(), false);

    while(queue.size() != 0)
    {
        pair<int, int> city = *(queue.begin());
        int cityID = city.second;
        int dist = city.first;
        if(find(favCities.begin(), favCities.end(), cityID) != favCities.end())
            return cityID;
        queue.erase(queue.begin());
        visited[cityID] = true;
        for(const pair<int, int>& p : mp[cityID])
        {
            if(visited[p.first] == false)
                queue.insert({(p.second + dist), p.first});
        }
    }
    return -1;
}


int main()
{
    map<int, set<pair<int, int>>> mp;
    vector<int> favCities;
    mp[0].insert({1, 20});
    mp[0].insert({2, 10});
    mp[1].insert({4, 4});
    mp[2].insert({6, 10});
    mp[2].insert({7, 2});
    // mp[3].insert({7, 2});
    // mp[4].insert({7, 2});
    // mp[5].insert({7, 2});
    mp[6].insert({1, 7});
    mp[6].insert({3, 6});
    mp[7].insert({0, 8});
    mp[7].insert({5, 3});

    // favCities.push_back(2);
    // favCities.push_back(7);
    // favCities.push_back(5);
    // favCities.push_back(1);
    // favCities.push_back(6);
    // favCities.push_back(4);
    favCities.push_back(3);
    cout << "Min Dist City: " << leastDistFavCity(mp, favCities) << endl;
    return 0; 
}