#include <string>
#include <algorithm>

std::string sortCharacter(std::string &s) {
    unsigned freq[128]{0};
    unsigned order[128];

    unsigned o = 0;
    for (auto &c : s) {
        freq[c]++;
        order[c] = o++;
    }

    std::sort(s.begin(), s.end(),
              [&](const char &left, const char &right) {
                  return (freq[left] == freq[right]) ? order[left] < order[right] : freq[left] > freq[right];
              });

    return s;
}

int main() {
    std::string input = "Mymommaalwayssaid,\"Lifewaslikeaboxofchocolates.Youneverknowwhatyou'regonnaget.";
    std::cout << sortCharacter(input) << std::endl;
}