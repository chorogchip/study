#include<bits/stdc++.h>
using namespace std;

template<typename K, K epsilon>
struct NFA {
    int n;
    struct state {
        bool isAccept;
        bool hasContext;
        multimap<K, int> arrows;
    };
    vector<state> v;

    NFA(int size): n(size), v(size+1) {}

    void accept(int target) {
        v[target].isAccept = true;
    }

    void connect(int source, K alphabet, int target) {
        v[source].arrows.insert({alphabet, target});
    }

    bool start(int start_state) {
        bool res = false;
        vector<int> st;
        st.push_back(start_state);
        while(!v.empty()) {
            int o = st.back(); st.pop_back();
            if (!v[o].hasContext) {
                res |= v[o].isAccept;
                v[o].hasContext = true;
                auto it = v[o].arrows[epsilon];
                // TODO insert // TODO change to step epsilon
            }
        }
        return res;
    }

    bool step(K alphabet) {
        return false;
    }
};

int main() {
    NFA<char, '#'> k(3);
}
/*




*/