public abstract class Figure{
	//Coordonnées du centre approximatif de la figure
	private int posX;
	private int posY;
	
	public Figure(int x, int y){
		posX = x;
		posY = y;
	}
	
	public int getPosX(){
		return posX;
	}
	
	public int getPosY(){
		return posY;
	}
	
	public abstract void affiche();
}
