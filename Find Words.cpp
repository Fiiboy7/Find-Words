#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> matrix = {
    "AAFLKHPFSSUFICICLESGNNH",
    "SFVREOMRWLRTTSXOQQNAOAO",
    "QEIAIFXAEIRFVFYSXIMINJI",
    "WSTRLGOCAPBIAFIWIWTUACM",
    "FEYAEAISTPCRLUJKOAKCERS",
    "RVDAKPNDEEHDEMSNCKKFOAH",
    "MRNEDSLCRRIWNRSAAFITMMI",
    "YAAECIEAHYMOTAVHRSSTISB",
    "RJSEWELCCENNIETOHWSGLSE",
    "ATANYYMOIEESNESIOIRELTR",
    "UTENEWEBHMYBETNNRAIEBEN",
    "RCLKUTEAEQJLSGSHTGDSKOA",
    "BHOICATNRRSDDECEHOOLGIT",
    "ENSLUARIRSETALOCOHCTOHE",
    "FZFUDQJYMADOYIWYGLOVESU",
    "TEKALFWONSNAEBMIEJTZNTG",
    "ESWPOSJXEUTAYOZUWAKEZHM",
    "KZUHBPEZEERFLMSNOWBALLH",
    "NSNOWBOARDYTVWYCLEVOHSA",
    "ACOCRQLGZIYCHODRAZZILBI",
    "LBVKKWANZAAQINWOLPWONSL",
    "BFREEZINGRAINSLILGTMELT",
    "HQPYLWHFMNFFUFPSWXNUMMV",
};

bool searchHorizontal(string word) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int len = word.size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= cols - len; ++j) {
            if (matrix[i].substr(j, len) == word)
                return true;
        }
    }

    return false;
}
bool searchVertical(string word) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int len = word.size();

    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i <= rows - len; ++i) {
            string colString = "";
            for (int k = i; k < i + len; ++k) {
                colString += matrix[k][j];
            }
            if (colString == word)
                return true;
        }
    }

    return false;
}

bool searchDiagonal(string word) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int len = word.size();

    for (int i = 0; i <= rows - len; ++i) {
        for (int j = 0; j <= cols - len; ++j) {
            string diagString = "";
            for (int k = 0; k < len; ++k) {
                diagString += matrix[i + k][j + k];
            }
            if (diagString == word)
                return true;
        }
    }

    for (int i = 0; i <= rows - len; ++i) {
        for (int j = len - 1; j < cols; ++j) {
            string diagString = "";
            for (int k = 0; k < len; ++k) {
                diagString += matrix[i + k][j - k];
            }
            if (diagString == word)
                return true;
        }
    }

    return false;
}

bool searchWord(string word) {
    return searchHorizontal(word) || searchVertical(word) || searchDiagonal(word);
}
