class Immeuble extends Batiment{
	private int nbAppart;

	public Immeuble(String adresse, int surface, int nbAppart, Personne proprietaire){
		super(adresse, surface, proprietaire);
		this.nbAppart = nbAppart;
	}
	
	public String toString(){
		return (super.toString() + "\nNombre d'appartements : " + nbAppart);
	}
}
