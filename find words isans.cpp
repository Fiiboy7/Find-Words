int main() {
    int N;
    cout << "Masukkan jumlah kata yang ingin dicari: ";
    cin >> N;
    vector<string> words(N);
    cout << "Masukkan kata-kata yang ingin dicari:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    

    cout << "Hasil Pencarian:" << endl;
    for (const string& word : words) {
        if (searchWord(word)) {
            cout << word << ": Ada" << endl;
        } else {
            cout << word << ": Tidak Ada" << endl;
        }
    }

    return 0;
}