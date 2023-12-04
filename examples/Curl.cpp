#include <code/code.h>

#include <minecraft/mc.h>
#include <xf/String.h>

int WriteCallback(char* contents, int size, int nmemb, xf::String<char>* userp) {
    for (int i = 0; i < (size * nmemb); i++) {
        userp->operator+=(contents[i]);
    }
    return size*nmemb;
}

bool hasSentMessage = false;
DECL_FUNCTION(void, LocalPlayer_swing, mc::LocalPlayer* player, int hand) {
    if (!hasSentMessage) {
        void* curl = curl_easy_init();
        if (curl) {
            xf::String<char> str = "";
             // Use HTTP with Port 80, Don't use HTTPS because Curl doesn't use SSL Certificates
            curl_easy_setopt(curl, CURLOPT_URL, "http://david-xf.de/logs");
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, (void*) WriteCallback);
            curl_easy_setopt(curl, CURLOPT_FILE, &str);
            int res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            mc_printf(L"Response: %d Content: %s", res, str.c_str());
            hasSentMessage = true;
        }
    }

    real_LocalPlayer_swing(player, hand);
}

int c_main(void*) {
    code::init();

    REPLACE(mc::LocalPlayer::_swing.addr(), LocalPlayer_swing);

    return 0;
}

void _main() {
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}