package kr.ac.ajou.programmers.algo0619;

import java.util.*;


public class 베스트앨범 {

    class SamesDescending implements Comparator<Sames> {


        @Override
        public int compare(Sames o1, Sames o2) {
            return -Integer.compare(o1.sum, o2.sum);
        }
    }

    class MusicsDescending implements Comparator<Music> {

        @Override
        public int compare(Music o1, Music o2) {
            if(o1.plays == o2.plays){
                return Integer.compare(o1.no,o2.no);
            } else{
                return -Integer.compare(o1.plays,o2.plays);
            }
        }
    }


    class Music {
        int no;
        int plays;

        Music(int no, int plays) {
            this.no = no;
            this.plays = plays;
        }

    }

    class Sames {
        int sum;
        List<Music> musics;

        Sames() {
            musics = new ArrayList<>();
            sum = 0;
        }
        Sames addMusic(int no, int plays) {
            this.musics.add(new Music(no, plays));
            sum += plays;
            return this;
        }
    }

    public int[] solution(String[] genres, int[] plays) {
        HashMap<String, Sames> hashMap = new HashMap<>();

        int len = genres.length;
        for (int i = 0; i < len; i++) {
            hashMap.put(genres[i], hashMap.getOrDefault(genres[i], new Sames()).addMusic(i, plays[i]));
        }
        Collection<Sames> co = hashMap.values();
        List<Sames> list = new ArrayList<>(co);
        list.sort(new SamesDescending());

        List<Integer> nums = new ArrayList<>();
        MusicsDescending musicsDescending = new MusicsDescending();
        for (Sames same : list) {
            List<Music> musics = same.musics;
            musics.sort(musicsDescending);
            int j = 0;
            for (Music music : musics) {
                if (j == 2) {
                    break;
                }
                nums.add(music.no);
                j++;
            }
        }

        int[] answer = new int[nums.size()];
        int i = 0;
        for (int num : nums) {
            answer[i++] = num;
        }

        return answer;
    }

    public static void main(String[] args) {
        베스트앨범 test = new 베스트앨범();

        String[] genres = {"classic", "pop", "classic",
                "classic", "pop"};

        int[] plays = {500, 600, 150, 800, 2500};

        System.out.println(Arrays.toString(test.solution(genres, plays)));
    }
}
