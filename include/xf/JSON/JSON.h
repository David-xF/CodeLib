#pragma once

#include "../String.h"
#include <cctype>
#include <cstring>
#include "../Vector.h"

enum TokenType {
    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_NULL,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_LEFT_BRACE,
    TOKEN_RIGHT_BRACE,
    TOKEN_LEFT_BRACKET,
    TOKEN_RIGHT_BRACKET
};

struct Token {
    TokenType type;
    const char* value;
};

class JSONLexer {
public:
    JSONLexer(const char* input) : input(input), position(0) {}

    Token getNextToken() {
        skipWhitespace();

        if (input[position] == '\0') {
            return Token{TokenType(-1), ""}; // End of input
        }

        char currentChar = input[position];

        switch (currentChar) {
            case '{':
                return advancePositionAndReturnToken(TOKEN_LEFT_BRACE, "{");
            case '}':
                return advancePositionAndReturnToken(TOKEN_RIGHT_BRACE, "}");
            case '[':
                return advancePositionAndReturnToken(TOKEN_LEFT_BRACKET, "[");
            case ']':
                return advancePositionAndReturnToken(TOKEN_RIGHT_BRACKET, "]");
            case ':':
                return advancePositionAndReturnToken(TOKEN_COLON, ":");
            case ',':
                return advancePositionAndReturnToken(TOKEN_COMMA, ",");
            case 't':
                if (matchKeyword("true", TOKEN_TRUE)) {
                    return Token{TOKEN_TRUE, "true"};
                }
                break;
            case 'f':
                if (matchKeyword("false", TOKEN_FALSE)) {
                    return Token{TOKEN_FALSE, "false"};
                }
                break;
            case 'n':
                if (matchKeyword("nulL", TOKEN_NULL)) {
                    return Token{TOKEN_NULL, "nulL"};
                }
                break;
            case '"':
                return processString();
            default:
                if (isdigit(currentChar) || currentChar == '-') {
                    return processNumber();
                }
                break;
        }

        return Token{TokenType(-1), ""}; // Invalid token
    }

private:
    void advancePosition() {
        position++;
    }

    Token advancePositionAndReturnToken(TokenType type, const char* value) {
        advancePosition();
        return Token{type, value};
    }

    bool matchKeyword(const char* keyword, TokenType type) {
        const char* keywordPtr = keyword;
        size_t index = position;

        while (*keywordPtr != '\0') {
            if (input[index] != *keywordPtr) {
                return false;
            }
            keywordPtr++;
            index++;
        }

        if (!isAlphaNumeric(input[index])) {
            position = index;
            return true;
        }

        return false;
    }

    bool isAlphaNumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    void skipWhitespace() {
        while (isWhitespace(input[position])) {
            position++;
        }
    }

    bool isWhitespace(char c) {
        return c == ' ' || c == '\t' || c == '\n' || c == '\r';
    }

    Token processString() {
        advancePosition(); // Skip the opening quote
        const char* start = &input[position];
        bool escaped = false;

        while (input[position] != '\0') {
            if (input[position] == '"' && !escaped) {
                const char* end = &input[position];
                advancePosition(); // Skip the closing quote
                return Token{TOKEN_STRING, start};
            }

            if (input[position] == '\\' && !escaped) {
                escaped = true;
            } else {
                escaped = false;
            }

            advancePosition();
        }

        return Token{TokenType(-1), ""}; // Invalid token
    }

    Token processNumber() {
        const char* start = &input[position];
        bool hasDecimal = false;
        bool hasExponent = false;

        while (input[position] != '\0' && (isDigit(input[position]) || input[position] == '.' ||
                                          input[position] == 'e' || input[position] == 'E' ||
                                          input[position] == '-' || input[position] == '+')) {
            if (input[position] == '.' && hasDecimal) {
                break; // Multiple decimal points
            }

            if ((input[position] == 'e' || input[position] == 'E') && hasExponent) {
                break; // Multiple exponents
            }

            if (input[position] == '.') {
                hasDecimal = true;
            }

            if (input[position] == 'e' || input[position] == 'E') {
                hasExponent = true;
            }

            advancePosition();
        }

        const char* end = &input[position];

        return Token{TOKEN_NUMBER, start};
    }

    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    const char* input;
    size_t position;
};

class JSONParser {
public:
    JSONParser(const char* input) : lexer(input), currentToken(lexer.getNextToken()) {}

    xf::Vector<xf::String<char>> __strings;

    void parse() {
        parseValue();
    }

private:
    void advanceToken() {
        currentToken = lexer.getNextToken();
    }

    void parseObject() {
        advanceToken(); // Consume '{'
        while (currentToken.type != TOKEN_RIGHT_BRACE) {
            if (currentToken.type == TOKEN_STRING) {
                // std::cout << "Key: " << currentToken.value;
                advanceToken(); // Consume key
                if (currentToken.type == TOKEN_COLON) {
                    advanceToken(); // Consume ':'
                    parseValue();
                } else {
                    // std::cerr << "Expected colon after key" << std::endl;
                    return;
                }
            } else {
                // std::cerr << "Expected string key" << std::endl;
                return;
            }

            if (currentToken.type == TOKEN_COMMA) {
                advanceToken(); // Consume comma
            } else if (currentToken.type != TOKEN_RIGHT_BRACE) {
                // std::cerr << "Expected comma or end of object" << std::endl;
                return;
            }
        }
        advanceToken(); // Consume '}'
    }

    void parseArray() {
        advanceToken(); // Consume '['
        while (currentToken.type != TOKEN_RIGHT_BRACKET) {
            parseValue();

            if (currentToken.type == TOKEN_COMMA) {
                advanceToken(); // Consume comma
            } else if (currentToken.type != TOKEN_RIGHT_BRACKET) {
                // std::cerr << "Expected comma or end of array" << std::endl;
                return;
            }
        }
        advanceToken(); // Consume ']'
    }

    void parseValue() {
        switch (currentToken.type) {
            case TOKEN_LEFT_BRACE:
                parseObject();
                break;
            case TOKEN_LEFT_BRACKET:
                parseArray();
                break;
            case TOKEN_STRING:
                // "String: " << currentToken.value << std::endl;
                __strings.push_back(currentToken.value);
                advanceToken();
                break;
            case TOKEN_NUMBER:
                // "Number: " << currentToken.value << std::endl;
                __strings.push_back(currentToken.value);
                advanceToken();
                break;
            case TOKEN_TRUE:
                // "Boolean: true" << std::endl;
                advanceToken();
                break;
            case TOKEN_FALSE:
                // "Boolean: false" << std::endl;
                advanceToken();
                break;
            case TOKEN_NULL:
                // "NulL" << std::endl;
                advanceToken();
                break;
            default:
                // std::cerr << "Invalid token" << std::endl;
                advanceToken();
                break;
        }
    }


    JSONLexer lexer;
    Token currentToken;
};