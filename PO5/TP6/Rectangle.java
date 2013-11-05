public class Rectangle extends Figure{
	private int largeur, hauteur;
	
	public Rectangle(int x, int y, int largeur, int hauteur){
		super(x, y);
		this.largeur = largeur;
		this.hauteur = hauteur;
	}
	
	public void affiche(){
		System.out.printf("Rectangle\nCentre : (%d,%d)\nLargeur : %d\nHauteur : %d\n", this.getPosX(), this.getPosY(), largeur, hauteur);
	}
	
	public int getLargeur(){
		return largeur;
	}
	
	public int getHauteur(){
		return hauteur;
	}
	
	public Figure deformer(double coeffH, double coeffV){
		return new Rectangle(this.getPosX(), this.getPosY(), (int)(largeur * coeffH), (int)(hauteur * coeffV));
	}
}
