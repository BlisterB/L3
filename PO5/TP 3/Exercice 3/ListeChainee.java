class ListeChainee{
	private Maillon tete;
	
	public ListeChainee(){
		Maillon tete = null;
	}
	public ListeChainee(int val){
		Maillon tete = new Maillon(val);
	}
	
	public void ajoute(int a){
		if(tete == null){
			tete = new Maillon(a);
		}
		else{
			if(tete.get_val()>a){
				Maillon nouvelleTete = new Maillon(a, tete);
				tete = nouvelleTete;
			}
			else
				tete.ajoute(a);
		}
	}
	
	public void retire(int a){
		if(tete != null){
			if (tete.get_val() == a){
				tete = tete.get_suivant();
			}
			else{
				tete.retire(a);
			}
		}
	}
	
	public boolean est_dans(int a){
		if(tete != null){
			if(tete.get_val() == a)
				return true;
			else{
				if(tete!=null)
					return tete.est_dans(a);
			}
		}
		return false;
	}
	
	void union(Ensemble A){
		if (tete == null)
			tete = A.get_liste().get_tete();
		else{
			Maillon p = A.get_liste().get_tete();
			while(p != null){
				if(!(tete.est_dans(p.get_val())))
					this.ajoute(p.get_val());
				p = p.get_suivant();
			}
		}
	}
	
	void inter(Ensemble A){
		if (tete != null){
			Maillon p = tete;
			while(p != null){
				if(!(A.est_dans(p.get_val())))
					this.retire(p.get_val());
				p = p.get_suivant();
			}
		}		
	}	
	
	void diff(Ensemble A){
		if (tete != null){
			Maillon p = tete;
			while(p != null){
				if(A.est_dans(p.get_val()))
					this.retire(p.get_val());
				p = p.get_suivant();
			}
		}		
	}
	
	public String toString(){
		if(tete == null)
			return "Chaine vide";
		else
			return ("{ " + tete.toString() + " }");
	}
	
	//ACCESSEURS
	public Maillon get_tete(){
		return tete;
	}
}
