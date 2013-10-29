class Maillon{
	private Maillon suivant;
	private int val;
	
	public Maillon(int val){
		this.val = val;
		this.suivant = null;
	}
	public Maillon(int val, Maillon suivant){
		this.val = val;
		this.suivant = suivant;
	}
	
	//METHODES
	
	public void ajoute(int a){
		if (this.suivant != null){
			if(suivant.get_val() > a){
				Maillon nouveauSuivant = new Maillon(a, suivant);
				this.suivant = nouveauSuivant;
			}
			else
				suivant.ajoute(a);
		}
		else{
			Maillon nouveauSuivant = new Maillon(a);
			this.suivant = nouveauSuivant;
		}
	}
	
	public void retire(int a){
		if(this.suivant != null){
			if(this.suivant.get_val() == a)
				this.suivant = this.suivant.suivant;
			else
				this.suivant.retire(a);
		}
	}
	
	public String toString(){
		if(suivant == null)
			return ""+ val;
		else
			return (val + ", " + suivant.toString());
	}
	
	public boolean est_dans(int a){
		if(this.val == a)
			return true;
		if(suivant == null)
			return false;
		else
			return suivant.est_dans(a);
	}
	
	//ACCESSEURS
	public int get_val(){
		return this.val;
	}
	public Maillon get_suivant(){
		return suivant;
	}
}
