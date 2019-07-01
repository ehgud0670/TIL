
import java.util.*;

public class 베스트앨범 {
	
	class MusicComparator implements Comparator<Music>{

		@Override
		public int compare(Music arg0, Music arg1) {
			if(arg0.plays == arg1.plays) {
				return Integer.compare(arg0.no, arg1.no);
			} else {
				return -Integer.compare(arg0.plays, arg1.plays);
			}
			
		}
		
		
	}
	
	
	class SamesDescending implements Comparator<Sames>{

		@Override
		public int compare(Sames arg0, Sames arg1) {
			
			return -Integer.compare(arg0.sum, arg1.sum);
		}
		
	}
	
	class Music{
		
		int no;
		int plays;
		
		Music(int no, int plays){
			this.no = no;
			this.plays = plays;
		}
	}
	
	class Sames{
		
	   List<Music> musics;
	   int sum;
	   
	   Sames(){
		   musics = new ArrayList();
		   sum = 0;
	   }
	   
	   Sames addMusic(int no, int plays){
		   
		   musics.add(new Music(no,plays));
		   sum += plays;
		   return this;
	   }
	   
	}
	
	
	public int[] solution(String[] genres, int[] plays) {
		
		HashMap<String,Sames> hm = new HashMap<>(); 
		int len = genres.length;
		
		for(int i=0; i<len; i++) {
			String genre = genres[i];
			hm.put(genre, hm.getOrDefault(genre, new Sames()).addMusic(i, plays[i]));
		}
		
		Collection<Sames> co = hm.values();
		List<Sames> list = new ArrayList<>(co);
		list.sort(new SamesDescending());
		
		List<Integer> answerList = new ArrayList<>();
		for(Sames same : list) {
			List<Music> musics = same.musics;
			musics.sort( new MusicComparator());
			int j=0;
			for(Music music : musics) {
				if(j==2) {
					break;
				}
				answerList.add(music.no);
				j++;
			}
			
		}
		int[] answer = new int[answerList.size()];
		
		int i=0;
		for(int no : answerList) {
			answer[i++] = no;
		}
	    
	    return answer;
	}
	
	public static void main(String[] args) {
		String[] genres = {"classic", "pop", "classic", "classic", "pop"};
		int[] plays = {500, 600,150,800,2500};
		베스트앨범 test = new 베스트앨범();
		
		
		System.out.println(Arrays.toString(test.solution(genres, plays)));
	}
}
