#pragma once

namespace xf {
    class FileHelper {
    public:
        FileHelper(String<wchar_t> filePath) {
            file = mc::File(filePath.c_str());
        }

        FileHelper() = default;

        FileHelper* write(Vector<char> data, bool usePreData = true) {
            Vector<char> preData;
            if (usePreData) {
                Vector<char>* n = read();
                for (int i = 0; i < n->getSize(); i++) {
                    preData.push_back(n->operator[](i));
                }
            }

            for (char c : data) {
                preData.push_back(c);
            }

            mc::FileOutputStream out = mc::FileOutputStream(file);
            for (char c : preData) out.write(c);
            out.close();

            return this;
        }

        FileHelper* writeString(xf::String<char> string, bool usePreData = true) {
            Vector<char> preData;
            if (usePreData) {
                Vector<char>* n = read();
                for (int i = 0; i < n->getSize(); i++) {
                    preData.push_back(n->operator[](i));
                }
            }

            for (int i = 0; i < string.length(); i++) {
                preData.push_back(string[i]);
            }

            mc::FileOutputStream out = mc::FileOutputStream(file);
            for (char c : preData) out.write(c);
            out.close();

            return this;
        }

        Vector<char>* read() {
            Vector<char>* ret = new Vector<char>;
            if (!file.exists()) return ret;
            mc::FileInputStream* istr = new mc::FileInputStream(file);
            for (int i = 0; i < istr->filesize(); i++) ret->push_back(istr->read());
            istr->close();

            return ret;
        }

    private:
        mc::File file;
    };
}