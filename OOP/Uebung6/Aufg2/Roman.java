class Roman {
    private int arabic;
    private String roman;

    public Roman(int arabic) {
        this.arabic = arabic;
        this.roman = arabicToRoman(arabic);
    }

    public Roman(String roman) {
        this.roman = roman;
        this.arabic = romanToArabic(roman);
    }

    public Roman add(Roman r) {
        return new Roman(this.arabic + r.arabic);
    }

    public Roman subtract(Roman r) {
        int number = this.arabic - r.arabic;
        if (number <= 0) {
            System.out.println("Error: Subtraction results in non positive number.");
            return new Roman(1);
        }
        return new Roman(number);
    }

    public Roman multiply(Roman r) {
        return new Roman(this.arabic * r.arabic);
    }

    public Roman divide(Roman r) {
        int number = this.arabic / r.arabic;
        if (number <= 0) {
            System.out.println("Error: Division results in 0.");
            return new Roman(1);
        }
        return new Roman(number);
    }

    @Override
    public String toString() {
        return Integer.toString(this.arabic) + "\t" + this.roman;
    }

    @Override
    public boolean equals(Object object) {
        if (object instanceof Roman) {
            Roman r = (Roman) object;
            return this.arabic == r.arabic;
        }
        return false;
    }

    @Override
    public int hashCode() {
        return this.arabic;
    }

    private int romanToArabic(String roman) {
        int arabic = 0;
        for (int i = 0; i < roman.length() - 1; i++) {
            int current = romanDigitToArabic(roman.charAt(i));
            int next = romanDigitToArabic(roman.charAt(i + 1));
            if (current >= next) {
                arabic += current;
            } else {
                arabic -= current;
            }

        }
        arabic += romanDigitToArabic(roman.charAt(roman.length() - 1));
        return arabic;
    }

    private int romanDigitToArabic(char c) {
        if (c == 'I') {
            return 1;
        } else if (c == 'V') {
            return 5;
        } else if (c == 'X') {
            return 10;
        } else if (c == 'L') {
            return 50;
        } else if (c == 'C') {
            return 100;
        } else if (c == 'D') {
            return 500;
        } else if (c == 'M') {
            return 1000;
        }
        return 0;
    }

    private String arabicToRoman(int arabic) {
        roman = "";
        while (arabic > 0) {
            if (arabic - 1000 >= 0) {
                roman = roman + "M";
                arabic = arabic - 1000;
            } else if (arabic - 500 >= 0) {
                roman = roman + "D";
                arabic = arabic - 500;
            } else if (arabic - 400 >= 0) {
                roman = roman + "CD";
                arabic = arabic - 400;
            } else if (arabic - 100 >= 0) {
                roman = roman + "C";
                arabic = arabic - 100;
            } else if (arabic - 90 >= 0) {
                roman = roman + "XC";
                arabic = arabic - 90;
            } else if (arabic - 50 >= 0) {
                roman = roman + "L";
                arabic = arabic - 50;
            } else if (arabic - 40 >= 0) {
                roman = roman + "XL";
                arabic = arabic - 40;
            } else if (arabic - 10 >= 0) {
                roman = roman + "X";
                arabic = arabic - 10;
            } else if (arabic - 9 >= 0) {
                roman = roman + "IX";
                arabic = arabic - 9;
            } else if (arabic - 5 >= 0) {
                roman = roman + "V";
                arabic = arabic - 5;
            } else if (arabic - 4 >= 0) {
                roman = roman + "IV";
                arabic = arabic - 4;
            } else if (arabic - 1 >= 0) {
                roman = roman + "I";
                arabic = arabic - 1;
            }
        }
        return roman;
    }
}
