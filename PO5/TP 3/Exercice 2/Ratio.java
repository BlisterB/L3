class Ratio{
	private int numera;
	private int denomi;
	
	Ratio(int numera, int denomi){
		int pgcd = pgcd(numera, denomi);
		this.numera = numera/pgcd;
		this.denomi = denomi/pgcd;
	}
	
	static int pgcd (int a, int b) { // début de pgcd ()
		if(a<b) // on veut le premier argument plus grand
			return (pgcd(b,a));
		else if(b==0) // condition d'arrêt
			return (a);
		else // on poursuit l'algorithme d'Euclide
			return (pgcd(b,a%b));
	}
	
	Ratio produit (Ratio a){
		Ratio produit = new Ratio(this.numera * a.numera, this.denomi * a.denomi);
		return produit;
	}
	
	Ratio addition(Ratio a){
			Ratio addition = new Ratio(
								this.numera*a.denomi + a.numera*this.denomi,
								this.denomi * a.denomi);
			return addition;
	}
	
	boolean equals(Ratio a){
		//Les fraction sont toujours réduites
		return this.numera == a.numera && this.denomi == a.denomi;
	}
	
	boolean plusGrand(Ratio a){
		return (float)a.numera/a.denomi > (float)this.numera/this.denomi;
	}
	
	public String toString(){
		return (this.numera + "/" + this.denomi);
	}
}
