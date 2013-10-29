class Immeuble extends Batiment{
	private int nbAppart;

	public Immeuble(String adresse, int surface, int nbAppart){
		super(adresse, surface);
		this.nbAppart = nbAppart;
	}
	
	public String toString(){
		return (super.toString() + "\nNombre d'appartements : " + nbAppart);
	}
}
