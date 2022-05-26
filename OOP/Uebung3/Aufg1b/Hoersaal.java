public class Hoersaal {
    Integer plaetze;
    Vorlesung[] vorlesungen;
    Adresse adresse;

    public Hoersaal(Integer plaetze, Adresse adr, Vorlesung[] vlg) {
        this.adresse = adr;
        this.plaetze = plaetze;
        this.vorlesungen = vlg;
    }

    public Integer getPlaetze() {
        return plaetze;
    }

    public Vorlesung[] getVorlesungen() {
        return vorlesungen;
    }

    public Adresse getAdresse() {
        return adresse;
    }
    
}
