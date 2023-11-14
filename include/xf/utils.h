#pragma once

#define S1(N) #N 
#define S2(N) S1(N) 
#define LINESTR S2(__LINE__)

template<typename... T>
void sendMessageFormated16(xf::String<wchar_t> msg, T... t) {
    wchar_t* tmp = _new<wchar_t>(0x60);
    swprintf(tmp, 0x60, msg.c_str(), t...);
    mc::Minecraft::getInstance()->gui->addMessage(tmp, 0, false, false, false, false);
}

template<typename... T>
void xf_assert_send(xf::String<wchar_t> msg, bool b, T... t) {
    if (b) return;
    sendMessageFormated16(L"Assert Failed at Line %s in %s \"%s\"", t...);
}

#define xf_assert(a) xf_assert_send(L"Assert Failed at Line %s in %s \"%s\"", a, LINESTR, __FILE__, #a)