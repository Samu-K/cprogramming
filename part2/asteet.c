#include "asteet.h"

float muunna(Lampotila a, Asteikko b) {
    if (a.asteikko == b) {
        return a.lampotila;
    }

    switch (a.asteikko) {
        case Celsius:
            switch (b) {
                case Fahrenheit:
                    return (a.lampotila * 1.8) + 32;
                case Kelvin:
                    return a.lampotila + 273.15;
                case Celsius:
                    return (a.lampotila);
            }
            break;
        case Fahrenheit:
            switch (b) {
                case Celsius:
                    return (a.lampotila - 32) / 1.8;
                case Kelvin:
                    return (a.lampotila + 459.67) * 5 / 9;
                case Fahrenheit:
                    return (a.lampotila);
            }
            break;
        case Kelvin:
            switch (b) {
                case Celsius:
                    return a.lampotila - 273.15;
                case Fahrenheit:
                    return (a.lampotila * 9 / 5) - 459.67;
                case Kelvin:
                    return (a.lampotila);
            }
            break;
    }

    return 0;
}

float erotus(Lampotila a, Lampotila b, Asteikko c) {
    float aasteet = muunna(a, c);
    float basteet = muunna(b, c);
    return aasteet - basteet;
}
