class Batiment{
	private String adresse;
	private int surface;
	
	public Batiment(String adresse, int surface){
		this.adresse = adresse;
		this.surface = surface;
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
}
