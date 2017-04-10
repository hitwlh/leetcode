class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        for(int i = 0; i< equations.size(); i++)
            cout << equations[i].first << "/" << equations[i].second << " = " << values[i] << endl;
        map<string, double> mymap;
        map<string, int> stringinset;
        vector<double> ret;
        int set = 1;
        bool nothing = true, old_nothing = true;
        do{
            old_nothing = nothing;
            if(old_nothing)
                set ++;
            nothing = true;
        for(int i=0; i<equations.size(); i++){
                double value = values[i];
                string fenzi = equations[i].first;
                string fenmu = equations[i].second;
                if(!mymap.count(fenmu) && mymap.count(fenzi)){
                    mymap[fenmu] = mymap[fenzi]/value;
                    stringinset[fenmu] = set;
                    nothing = false;
                }
                else if(mymap.count(fenmu) && !mymap.count(fenzi)){
                    mymap[fenzi] = mymap[fenmu]*value;
                    stringinset[fenzi] = set;
                    nothing = false;
                }
                else if(!mymap.count(fenmu) && !mymap.count(fenzi)){
                    if(old_nothing && nothing){
                        nothing = false;
                        stringinset[fenmu] = set;
                        stringinset[fenzi] = set;
                        mymap[fenmu] = 1;
                        mymap[fenzi] = mymap[fenmu]*value;
                    }
                }
        }
        }while(!nothing || !old_nothing);
        for(int i=0;i<queries.size(); i++){
            string fenmu = queries[i].first;
            string fenzi = queries[i].second;
            if(stringinset.count(fenzi) && stringinset.count(fenmu) && stringinset[fenzi] == stringinset[fenmu] && mymap.count(fenmu) && mymap.count(fenzi))
                ret.push_back(mymap[fenmu]/mymap[fenzi]);
            else
                ret.push_back(-1);
        }
        return ret;
    }