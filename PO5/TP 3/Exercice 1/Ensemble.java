class Ensemble{
	private ListeChainee liste;
	
	public Ensemble(){
		liste = new ListeChainee();
	}
	
	public void ajoute(int a){
		liste.ajoute(a);
	}
	public void retire(int a){
		liste.retire(a);
	}
	public boolean est_dans(int a){
		return liste.est_dans(a);
	}
	void union(Ensemble A){
		liste.union(A);
	}
	
	public String toString(){
		return liste.toString();
	}
	
	void inter(Ensemble A){
		liste.inter(A);
	}
	
	void diff(Ensemble A){
		liste.diff(A);
	}
	
	//ACCESSEURS
	public ListeChainee get_liste(){
		return liste;
	}
}
