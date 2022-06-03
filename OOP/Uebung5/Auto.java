public class Auto {
    String kennzeichen;
    int kilometerstand;
    int sitzplaetze;
    boolean antenneAusgefahren;

    Auto(){
        this.kennzeichen = "J-AA 01";
        this.kilometerstand = 0;
        this.sitzplaetze = 5;
        this.antenneAusgefahren = false;
    }

    Auto(String kennzeichen){
        this.kennzeichen = kennzeichen;
        this.kilometerstand = 0;
        this.sitzplaetze = 5;
        this.antenneAusgefahren = false;
    }

    String getKennzeichen(){
        return this.kennzeichen;
    }

    int getKilometerstand(){
        return this.kilometerstand;
    }

    int getSitzplaetze(){
        return this.sitzplaetze;
    }

    void fahre(int kilometer){
        System.out.println(kilometer + " km gefahren");
        this.kilometerstand += kilometer;
    }

    void fahreAntenneAus(){
        if(this.antenneAusgefahren){
            System.out.println("Antenne bereits ausgefahren");
        } else {
            System.out.println("Antenne ausgefahren");
            this.antenneAusgefahren = true;
        }
    }

    void fahreAntenneEin(){
        if(!this.antenneAusgefahren){
            System.out.println("Antenne bereits eingefahren");
        } else {
            System.out.println("Antenne eingefahren");
            this.antenneAusgefahren = false;
        }
    }

    void bereiteWaschenVor(){
        this.antenneAusgefahren = false;
    }

    void wasche(){
        this.bereiteWaschenVor();
        System.out.println("Auto wird gewaschen");
    }

    public String toString(){
        return "Kennzeichen: " + this.kennzeichen + "\tKilometerstand: " + this.kilometerstand + "\tSitzplaetze: " + this.sitzplaetze + "\tAntenne ausgefahren: " + this.antenneAusgefahren;
    }
}
