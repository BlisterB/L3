class Batiment{
	private String adresse;
	private int surface;
	private Personne proprietaire;
	
	public Batiment(String adresse, int surface, Personne proprietaire){
		this.adresse = adresse;
		this.surface = surface;
		this.proprietaire = proprietaire;
	}
	
	public String toString(){
		return ("**\nAdresse : " + adresse + "\nSurface : " + surface);
	}
	
	public int getSurfaceHabitable(){
		return surface;
	}
	
	public double impot(){
		return (5.6 * surface);
	}
	
	public Personne getProprietaire(){
		return proprietaire;
	}
}
