public class Seminarraum{
    Integer plaetze;
    Uebung[] uebungen;
    Adresse adresse;

    public Seminarraum(Integer plaetze, Adresse adr, Uebung[] ueb) {
        this.adresse = adr;
        this.plaetze = plaetze;
        this.uebungen = ueb;
    }

    public Integer getPlaetze() {
        return plaetze;
    }

    public Uebung[] getUebungen() {
        return uebungen;
    }

    public Adresse getAdresse() {
        return adresse;
    }
}
