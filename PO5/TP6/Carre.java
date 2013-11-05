public class Carre extends Figure implements Deformable{
	private int longueur;
	
	public Carre(int x, int y, int longueur){
		super(x, y);
		this.longueur = longueur;
	}
	
	public void affiche(){
		System.out.printf("Carre\nCentre : (%d,%d)\nLongueur : %d\n", this.getPosX(), this.getPosY(), longueur);		
	}
	
	public int getLongueur(){
		return longueur;
	}
	
	public Figure deformer(double coeffH, double coeffV){
		if(coeffH != coeffV)
			return new Rectangle(this.getPosX(), this.getPosY(), (int)(longueur * coeffH), (int)(longueur * coeffV));
		else
			return new Carre(this.getPosX(), this.getPosY(), (int)(longueur * coeffH));
	}
}
