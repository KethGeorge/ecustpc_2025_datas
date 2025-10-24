#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

int main()
{
    std::string model = "ECUST";
    auto dfs = [&](auto self, int at, std::string now) -> void
    {
        if (at == 5)
        {
            cout << now << endl;
            return;
        }
        self(self, at + 1, now + model[at]);
        self(self, at + 1, now + (char)std::tolower(model[at]));
    };

    dfs(dfs, 0, "");


    return 0;
}