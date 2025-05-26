#include <fstream>
#include <string>
using namespace std;

class FileManager {
private:
    ifstream in_fp;
    ofstream out_fp;

public:
    FileManager(const string& inputFileName, const string& outputFileName) {
        in_fp.open(inputFileName);
        out_fp.open(outputFileName);
        if (!in_fp.is_open() || !out_fp.is_open()) {
            throw runtime_error("파일을 열 수 없습니다.");
        }
    }

    ~FileManager() {
        in_fp.close();
        out_fp.close();
    }

    ifstream& getInputStream() {
        return in_fp;
    }

    ofstream& getOutputStream() {
        return out_fp;
    }

    void flushOutput() {
        out_fp.flush();
    }
};