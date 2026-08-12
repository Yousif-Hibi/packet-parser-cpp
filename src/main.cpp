#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream file("my_capture.pcap", std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // Determine file size
    file.seekg(0, std::ios::end);
    std::streamoff fsize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Buffer sized exactly to the file — one read gets everything, no loop needed
    std::size_t bufSize = static_cast<std::size_t>(fsize > 0 ? fsize : 1);
    std::vector<char> buffer(bufSize);

    file.read(buffer.data(), buffer.size());
    std::streamsize bytesRead = file.gcount();

    std::cout << "File size on disk: " << fsize << " bytes" << std::endl;
    std::cout << "Bytes read into buffer: " << bytesRead << " bytes" << std::endl;

    if (bytesRead != fsize) {
        std::cerr << "Warning: read size doesn't match file size!" << std::endl;
        return 1;
    }

    std::cout << "Task 2 checkpoint passed: buffer size matches file size." << std::endl;

    // buffer now holds the whole file — ready for Task 3 (struct casting)
    return 0;
}