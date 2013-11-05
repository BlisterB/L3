class Immeuble extends Batiment{
	private int nbAppart;
	private Personne[] tabLocataire;

	public Immeuble(String adresse, int surface, int nbAppart, Personne proprietaire){
		super(adresse, surface, proprietaire);
		this.nbAppart = nbAppart;
		this.tabLocataire = new Personne[nbAppart];
	}
	
	public String toString(){
		return (super.toString() + "\nNombre d'appartements : " + nbAppart);
	}
	
	public Personne[] getTabLocataire(){
		return tabLocataire;
	}
	
	public void setLocataire(int i, Personne locataire){
		if(i < nbAppart && this.tabLocataire[i] == null)
			tabLocataire[i] = locataire;
	}
}
