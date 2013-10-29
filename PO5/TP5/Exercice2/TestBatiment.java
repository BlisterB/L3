class TestBatiment{
	
	int surfaceHabitableTotalke(Batiment [] tabBat){
		int v = 0;
		for(Batiment i : tabBat){
			v += i.getSurfaceHabitable();
		}
		return v;
	}
	
	int surfaceJardinTotale(Batiment[] tabBat){
		int v = 0;
		for(Batiment i : tabBat){
			if (i instanceof Maison){
				v += ((Maison)i).getSurgaceJardin();
			}
		}
		return v;
	}
	
	public static void main(String[] arg){
		Personne mehdi = new Personne("Khelifi", "Mehdi");
		Batiment batiment = new Batiment("1 Rue du Tardis", 40, mehdi);
		Maison maison = new Maison("15ter rue Jean Coquelin", 100, 20, 4, mehdi);
		Immeuble immeuble = new Immeuble("20 Rue General Leclerc", 200, 8, mehdi);
		
		Batiment tab[] = new Batiment[10];
		tab[0] = batiment;
		tab[1] = maison;
		tab[2] = immeuble;
		
		for(int i = 0; i < tab.length; i++){
			System.out.println(tab[i]);
		}
	}
}
