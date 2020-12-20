#include <catch2/catch.hpp>
#include <stack>


std::vector<int> daily_temperatures_1(std::vector<int>& daily_temperatures) {
    std::vector<int> days_to_wait(daily_temperatures.size(), 0);

    for (int i = 0; i < daily_temperatures.size(); ++i) {
        for (int j = i + 1; j < daily_temperatures.size(); ++j) {
            if (daily_temperatures[i] < daily_temperatures[j]) {
                days_to_wait[i] = j - i;
                break;
            }
        }
    }

    return days_to_wait;
}

std::vector<int> daily_temperatures_2(std::vector<int>& temperatures) {
    std::vector<int> result(temperatures.size(), 0);
    std::stack<std::pair<int, int>> s; //First is the number while second is the position

    for (int i = temperatures.size() - 1; i >= 0; i--) {
        int curr = temperatures[i];
        while (!s.empty() && s.top().first <= curr) {
            s.pop();
        }

        result[i] = s.empty() ? 0 : s.top().second - i;

        s.push({curr, i});
    }

    return result;
}

TEST_CASE("Daily Temperatures", "[Data Structures]") {

    std::vector<int>daily_temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    REQUIRE_THAT(daily_temperatures_1(daily_temperatures), Catch::Matchers::Equals(std::vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
    REQUIRE_THAT(daily_temperatures_2(daily_temperatures), Catch::Matchers::Equals(std::vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));

}
