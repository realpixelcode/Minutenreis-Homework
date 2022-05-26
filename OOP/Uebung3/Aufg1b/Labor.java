public class Labor{
    Integer plaetze;
    Praktikum[] praktika;
    Adresse adresse;

    public Labor(Integer plaetze, Adresse adr, Praktikum[] prk) {
        this.adresse = adr;
        this.plaetze = plaetze;
        this.praktika = prk;
    }

    public Integer getPlaetze() {
        return plaetze;
    }

    public Praktikum[] getPraktika() {
        return praktika;
    }

    public Adresse getAdresse() {
        return adresse;
    }
}
